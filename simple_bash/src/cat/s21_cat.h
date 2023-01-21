#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../common/s21_common.h"

#define MAX_CHAR_LEN 6
#define FLAG_SET_SIZE 6
#define ERRBUF_SIZE 512

#define IS_SET(A, N) ((A) & (1 << (N)))
#define SET_BIT(A, N) ((A) |= (1 << (N)))
#define CLEAR_BIT(A, N) ((A) &= ~(1 << (N)))
#define FLIP_BIT(A, N) ((A) ^= (1 << (N)))

typedef enum cats_flag {
    NUM_OF_NON_BLANK,
    DOLLAR_FLAG_B,
    NUM_OF_LINES,
    SQUEEZE_ADJ,
    TABS,
    VERBOSE,
    RESET_FILE = 900,
    INCORRECT_SET = 1000,
} cats_flag;

struct cat_state {
    char buffer[MAX_CHAR_LEN];
    int line;
    int nl;
    int nb;
    int prev_prev;
    int prev;
    int iter;
};

void s21_cat(int argc, char **argv);
int parse_flag(int argc, char **argv, char **files, int *size_of_file);
void start_working_file(FILE *file, int flag);
int parse_one_flag(char *argument, int * flag);
int parse_more_flags(char *argument, int *flag);
int apply_squeeze_flag(char ch, struct cat_state *config, int flag);
void reset(struct cat_state *st);
void apply_eol_flag(char ch, struct cat_state *st, int flag);
void apply_num_of_lines_flag(struct cat_state *st, int flag);
void handle_char(char ch, struct cat_state *st, int flag);
void apply_num_of_non_blank_flag(struct cat_state *st, int flag);
void apply_spec_symbols_flag(int ch, struct cat_state *st, int flag);
void apply_tab_flag(char ch, struct cat_state *st, int flag);

static const char *const s21_cat_spec_sym[255] = {
    [0] = "^@",
    [1] = "^A",
    [2] = "^B",
    [3] = "^C",
    [4] = "^D",
    [5] = "^E",
    [6] = "^F",
    [7] = "^G",
    [8] = "^H",
    [9] = " ",
    [10] = "\n",
    [11] = "^K",
    [12] = "^L",
    [13] = "^M",
    [14] = "^N",
    [15] = "^O",
    [16] = "^P",
    [17] = "^Q",
    [18] = "^R",
    [19] = "^S",
    [20] = "^T",
    [21] = "^U",
    [22] = "^V",
    [23] = "^W",
    [24] = "^X",
    [25] = "^Y",
    [26] = "^Z",
    [27] = "^[",
    [28] = "^\\",
    [29] = "^]",
    [30] = "^^",
    [31] = "^_",
    [32] = " ",
    [33] = "!",
    [34] = "\"",
    [35] = "#",
    [36] = "$",
    [37] = "%",
    [38] = "&",
    [39] = "'",
    [40] = "(",
    [41] = ")",
    [42] = "*",
    [43] = "+",
    [44] = ",",
    [45] = "-",
    [46] = ".",
    [47] = "/",
    [48] = "0",
    [49] = "1",
    [50] = "2",
    [51] = "3",
    [52] = "4",
    [53] = "5",
    [54] = "6",
    [55] = "7",
    [56] = "8",
    [57] = "9",
    [58] = ":",
    [59] = ";",
    [60] = "<",
    [61] = "=",
    [62] = ">",
    [63] = "?",
    [64] = "@",
    [65] = "A",
    [66] = "B",
    [67] = "C",
    [68] = "D",
    [69] = "E",
    [70] = "F",
    [71] = "G",
    [72] = "H",
    [73] = "I",
    [74] = "J",
    [75] = "K",
    [76] = "L",
    [77] = "M",
    [78] = "N",
    [79] = "O",
    [80] = "P",
    [81] = "Q",
    [82] = "R",
    [83] = "S",
    [84] = "T",
    [85] = "U",
    [86] = "V",
    [87] = "W",
    [88] = "X",
    [89] = "Y",
    [90] = "Z",
    [91] = "[",
    [92] = "\\",
    [93] = "]",
    [94] = "^",
    [95] = "_",
    [96] = "`",
    [97] = "a",
    [98] = "b",
    [99] = "c",
    [100] = "d",
    [101] = "e",
    [102] = "f",
    [103] = "g",
    [104] = "h",
    [105] = "i",
    [106] = "j",
    [107] = "k",
    [108] = "l",
    [109] = "m",
    [110] = "n",
    [111] = "o",
    [112] = "p",
    [113] = "q",
    [114] = "r",
    [115] = "s",
    [116] = "t",
    [117] = "u",
    [118] = "v",
    [119] = "w",
    [120] = "x",
    [121] = "y",
    [122] = "z",
    [123] = "{",
    [124] = "|",
    [125] = "}",
    [126] = "~",
    [127] = "^?",
    [128] = "M-^@",
    [129] = "M-^A",
    [130] = "M-^B",
    [131] = "M-^C",
    [132] = "M-^D",
    [133] = "M-^E",
    [134] = "M-^F",
    [135] = "M-^G",
    [136] = "M-^H",
    [137] = "M-^I",
    [138] = "M-^J",
    [139] = "M-^K",
    [140] = "M-^L",
    [141] = "M-^M",
    [142] = "M-^N",
    [143] = "M-^O",
    [144] = "M-^P",
    [145] = "M-^Q",
    [146] = "M-^R",
    [147] = "M-^S",
    [148] = "M-^T",
    [149] = "M-^U",
    [150] = "M-^V",
    [151] = "M-^W",
    [152] = "M-^X",
    [153] = "M-^Y",
    [154] = "M-^Z",
    [155] = "M-^[",
    [156] = "M-^\\",
    [157] = "M-^]",
    [158] = "M-^^",
    [159] = "M-^_",
};

#endif  // SRC_CAT_S21_CAT_H_
