
#include "tidy_html.h"

// int clean_and_repair_html_empty_test(tidy_workspace_t* w)
// {
//   TIDY_HTML_LOG

//   const char* html = "";
//   char* result = tidy_clean_and_repair(w, html);
//   printf("-> '%s'\n", result);
//   if(strcmp(result, "") != 0) {
//     tidy_free(result);
//     TIDY_HTML_LOG_ERROR
//     return 1;
//   }
//   tidy_free(result);

//   return 0;
// }

// int clean_and_repair_html_string_test(tidy_workspace_t* w)
// {
//   TIDY_HTML_LOG

//   const char* html = "<p>Hello</p><p>World</p>";
//   char* result = tidy_clean_and_repair(w, html);
//   printf("-> '%s'\n", result);
//   if(strcmp(result, "<p>Hello</p><p>World</p>") != 0) {
//     tidy_free(result);
//     TIDY_HTML_LOG_ERROR
//     return 1;
//   }
//   tidy_free(result);

//   return 0;
// }

int run_diagnostics_broken_html_test(tidy_workspace_t* w)
{
  TIDY_HTML_LOG

  const char* html = "<a hre=www.google.de>Hello<pp>World";
  char* result = tidy_diagnostics(w, html);
  printf("-> '%s'\n", result);
  if(strcmp(result, "<p>Hello</p><p>World</p>") != 0) {
    tidy_free(result);
    TIDY_HTML_LOG_ERROR
    return 1;
  }
  tidy_free(result);

  return 0;
}

#define max_tests 1
int (*test[max_tests])() = {run_diagnostics_broken_html_test};

int main(int argc, char const* argv[])
{
  tidy_map_str_t opt;
  tidy_map_init(&opt);

  tidy_map_set(&opt, "TidyShowWarnings", "no");
  tidy_map_set(&opt, "TidyBodyOnly", "yes");
  // minify
  tidy_map_set(&opt, "TidyVertSpace", "auto");
  tidy_map_set(&opt, "TidyIndentSpaces", "0");

  tidy_workspace_t* w = tidy_init(&opt);

  int i = 0;
  int result = 0;
  while(i < max_tests && result == 0) {
    result = test[i](w);
    i += 1;
  }

  tidy_map_deinit(&opt);
  tidy_destroy(w);
  printf("done\n");
  return result;
}