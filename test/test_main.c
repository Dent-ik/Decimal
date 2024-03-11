#include <check.h>

#include "test.h"

int main(void) {
  Suite *tests[] = {test_s21_arif(), test_s21_equals(), test_s21_converter(),
                    test_s21_func(), NULL};
  int number_failed = 0;
  for (int i = 0; tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(tests[i]);
    printf("%03d", i);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("Total failed %d ", number_failed);
  return number_failed;
}
