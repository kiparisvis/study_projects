#include "test_s21_string.h"

#include <check.h>
#include <stdlib.h>

int main(void) {
    int no_failed = 0;

    SRunner *runner;

    runner = srunner_create(make_sprintf_suite());
    srunner_add_suite(runner, make_mem_suite());
    srunner_add_suite(runner, make_str_suite());
    srunner_add_suite(runner, make_sharp_suite());
    srunner_add_suite(runner, make_sscanf_suite());

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_VERBOSE);  // CK_SILENT CK_MINIMAL CK_NORMAL CK_VERBOSE
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
