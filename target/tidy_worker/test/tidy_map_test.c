#include "tidy_html.h"
/*
To check for memory leaks execute test with valgrind.

  valgrind --leak-check=yes test/tidy_map_test

*/
int main(int argc, char const* argv[])
{
  int i = 0;
  tidy_map_str_t m;
  tidy_map_init(&m);

  tidy_map_set(&m, "a", "123");
  tidy_map_set(&m, "b", "456");

  char* result = (char*)*tidy_map_get(&m, "a");
  printf("-> %s\n", result);
  if(strcmp(result, "123") != 0) {
    tidy_map_deinit(&m);
    TIDY_HTML_LOG_ERROR
    return 1;
  }

  result = (char*)tidy_map_join(&m, "=", "|");
  printf("-> %s\n", result);
  if(strcmp(result, "a=123|b=456") != 0) {
    tidy_free(result);
    tidy_map_deinit(&m);
    TIDY_HTML_LOG_ERROR
    return 1;
  }
  tidy_free(result);

  tidy_map_deinit(&m);
  dmt_dump(stdout);

  printf("done\n");
  return 0;
}