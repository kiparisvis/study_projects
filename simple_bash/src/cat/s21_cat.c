#include "s21_cat.h"

int main(int argc, char **argv) {
    s21_cat(argc, argv);
    return 0;
}

void s21_cat(int argc, char **argv) {
    if (argc > 1) {
        char **files = malloc(sizeof(char *) * argc);
        if (files) {
            int size_of_file = 0;
            int flag = parse_flag(argc, argv, files, &size_of_file);
            if (flag != INCORRECT_SET) {
                if ((IS_SET(flag, NUM_OF_NON_BLANK) && IS_SET(flag, NUM_OF_LINES))) {
                    CLEAR_BIT(flag, NUM_OF_LINES);
                }
            for (int i = 0; i < size_of_file; i++) {
                FILE *file = fopen(files[i], "r");
                if (errno)  //  in case errors
                    perror("Error: ");
                if (file) {
                    start_working_file(file, flag);
                    start_working_file(file, RESET_FILE);
                    fclose(file);
                }
            }
            } else {
                printf("Error! Incorrect flag!\n");
            }
            free(files);
        }
    }
}

int parse_flag(int argc, char **argv, char **files, int *size_of_file) {
    int flag = 0;
    for (int i = 1; i < argc; i++) {
        char *argument = argv[i];
        int flag1 = parse_one_flag(argument, &flag);
        int flag2 = parse_more_flags(argument, &flag);
        if (flag1 == -1 || flag2 == -1) {
            flag = INCORRECT_SET;
            break;
        }
        if (!flag1 && !flag2) {
            files[*size_of_file] = argument;
            (*size_of_file)++;
        }
    }
    return flag;
}

int parse_one_flag(char *argument, int *flag) {
    int kind_of_error = 0;
    if (strspn(argument, "-") == 1) {
        kind_of_error = 1;
        if (strchr(argument, 'e') || strchr(argument, 'E')) {
            SET_BIT(*flag, DOLLAR_FLAG_B);
        } else {
            if (strchr(argument, 'n')) {
                SET_BIT(*flag, NUM_OF_LINES);
            } else {
                if (strchr(argument, 'b')) {
                    SET_BIT(*flag, NUM_OF_NON_BLANK);
                } else {
                    if (strchr(argument, 's')) {
                        SET_BIT(*flag, SQUEEZE_ADJ);
                    } else {
                        if (strchr(argument, 't') || strchr(argument, 'T')) {
                            SET_BIT(*flag, TABS);
                        } else {
                            if (strchr(argument, 'e') || strchr(argument, 't') || strchr(argument, 'v')) {
                                SET_BIT(*flag, VERBOSE);
                            } else {
                                kind_of_error = -1;
                            }
                        }
                    }
                }
            }
        }
    }
    return kind_of_error;
}

int parse_more_flags(char *argument, int *flag) {
    int result = 0;
    if (strspn(argument, "--") == 2) {
        result = 1;
        if (strstr(argument, "num-of-non-blank")) {
            SET_BIT(*flag, NUM_OF_NON_BLANK);
        } else {
            if (strstr(argument, "num")) {
                SET_BIT(*flag, NUM_OF_LINES);
            } else {
                if (strstr(argument, "squeeze")) {
                    SET_BIT(*flag, SQUEEZE_ADJ);
                } else {
                    result = -1;
                }
            }
        }
    }
    return result;
}

void start_working_file(FILE *file, int flag) {
    static struct cat_state st = {
        .buffer = {'\0'}, .line = 1, .nl = 1, .nb = 0, .prev_prev = 0, .prev = 0};
    if (flag == RESET_FILE)
        reset(&st);
    while (feof(file) != EOF && file && flag != RESET_FILE) {
        int ch = getc(file);
        if (ch == EOF) {
            break;
        }
        if (apply_squeeze_flag(ch, &st, flag)) {
            continue;
        }
        st.prev_prev = st.prev;
        st.prev = ch;
        apply_eol_flag(ch, &st, flag);
        apply_num_of_lines_flag(&st, flag);
        st.buffer[0] = ch;
        handle_char(ch, &st, flag);
        apply_num_of_non_blank_flag(&st, flag);
        apply_spec_symbols_flag(ch, &st, flag);
        apply_tab_flag(ch, &st, flag);
        fprintf(stdout, "%s", st.buffer);
        memset(st.buffer, '\0', MAX_CHAR_LEN);
    }
    if (errno) {
        perror("Error: ");
    }
}

int apply_squeeze_flag(char ch, struct cat_state *config, int flag) {
    return (IS_SET(flag, SQUEEZE_ADJ) && config->prev_prev == '\n' &&
            config->prev == '\n' && ch == '\n');
}

void reset(struct cat_state *st) {
    #if defined(__MACH__) || defined(__APPLE__)  //  for Linux and MacOS
        st->line = 1;
    #endif
        st->nl = 1;
        st->nb = 0;
        st->prev_prev = 0;
        st->prev = 0;
        st->iter = 0;
}

void apply_eol_flag(char ch, struct cat_state *st, int flag) {
    if (IS_SET(flag, DOLLAR_FLAG_B) && ch == '\0') {
        st->buffer[0] = '$';
        st->buffer[1] = '\n';
    }
}

void apply_num_of_lines_flag(struct cat_state *st, int flag) {
    if (IS_SET(flag, NUM_OF_LINES) && st->nl) {
        fprintf(stdout, "%6d\t", st->line);
        st->line++;
        st->nl = 0;
    }
}

void handle_char(char ch, struct cat_state *st, int flag) {
    if (ch == '\n') {
        st->nl = 1, st->nb = 0;
        if (IS_SET(flag, DOLLAR_FLAG_B)) {
            st->buffer[0] = '$';
            st->buffer[1] = '\n';
        }
    } else {
        st->nb = 1;
    }
}

void apply_num_of_non_blank_flag(struct cat_state *st, int flag) {
    if (IS_SET(flag, NUM_OF_NON_BLANK) && st->nb && st->nl) {
        fprintf(stdout, "%6d\t", st->line);
        st->line++;
        st->nl = 0;
    }
}

void apply_spec_symbols_flag(int ch, struct cat_state *st, int flag) {
    if (IS_SET(flag, VERBOSE) && ((ch >= 0 && ch <= 32) || (ch >= 127 && ch <= 255)) && ch != '\n') {
        for (size_t i = 0; i < strlen(s21_cat_spec_sym[ch]); i++) {
            st->buffer[i] = s21_cat_spec_sym[ch][i];
        }
    }
}

void apply_tab_flag(char ch, struct cat_state *st, int flag) {
    if (IS_SET(flag, TABS) && ch == '\t') {
        st->buffer[0] = '^';
        st->buffer[1] = 'I';
    }
}
