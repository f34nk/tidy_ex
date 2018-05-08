
#include "tidy_html.h"
#include "test_utils.h"

// int parse_html_empty_test(tidy_workspace_t* w)
// {
//   TIDY_HTML_LOG

//   const char* html = "";
//   char* result = tidy_parse(w, html);
//   printf("-> '%s'\n", result);
//   if(strcmp(result, "") != 0) {
//     tidy_free(result);
//     TIDY_HTML_LOG_ERROR
//     return 1;
//   }
//   tidy_free(result);

//   return 0;
// }

int run_diagnostics_test(tidy_workspace_t* w, const char* filename)
{
  TIDY_HTML_LOG

  char* html = read_file(filename);
  if(html == NULL) {
    TIDY_HTML_LOG_ERROR
    return 1;
  }

  char* result = tidy_run_diagnostics(w, html);
  printf("-> '%s'\n", result);
  if(strcmp(result, "asdasd") != 0) {
    tidy_free(result);
    free(html);
    TIDY_HTML_LOG_ERROR
    return 1;
  }
  tidy_free(result);
  free(html);

  return 0;
}

#define max_tests 1
int (*test[max_tests])() = {run_diagnostics_test};

const char* filename = "../../tidy-html5-tests/cases/testbase/case-1002509.html";

int main(int argc, char const* argv[])
{

  tidy_map_str_t opt;
  tidy_map_init(&opt);

  // tidy_map_set(&opt, "TidyShowWarnings", "no");
  // tidy_map_set(&opt, "TidyBodyOnly", "yes");
  // // minify
  // tidy_map_set(&opt, "TidyVertSpace", "auto");
  // tidy_map_set(&opt, "TidyIndentSpaces", "0");

  tidy_workspace_t* w = tidy_init(&opt);

  int i = 0;
  int result = 0;
  while(i < max_tests && result == 0) {
    result = test[i](w, filename);
    i += 1;
  }

  tidy_map_deinit(&opt);
  tidy_destroy(w);
  printf("done\n");
  return result;
}
