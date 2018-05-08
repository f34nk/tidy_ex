
#include "test_includes.h"
int main(int argc, const char * argv[])
{
  // initialize all of Erl_Interface
  erl_init(NULL, 0);

  tidy_map_str_t opt;
  tidy_map_init(&opt);

  tidy_map_set(&opt, "TidyShowWarnings", "no");
  tidy_map_set(&opt, "TidyBodyOnly", "yes");
  // minify
  tidy_map_set(&opt, "TidyVertSpace", "auto");
  tidy_map_set(&opt, "TidyIndentSpaces", "0");

  tidy_workspace_t* w = tidy_init(&opt);

  const char *html = "<a hre=www.google.de>Hello<pp>World";
  vec_eterm_t term_array;
  eterm_vec_init(&term_array);
  run_diagnostics(w, html, &term_array);
  char* result = eterm_vec_join(&term_array, "|");
  printf("-> '%s'\n", result);
  if(strcmp(result, "line 1 column 27 - Error: <pp> is not recognized!\nThis document has errors that must be fixed before\nusing HTML Tidy to generate a tidied up version.") != 0){
    eterm_vec_destroy(&term_array);
    free(result);
    tidy_map_deinit(&opt);
    tidy_destroy(w);
    TEST_ERROR
    return 1;
  }
  eterm_vec_destroy(&term_array);
  free(result);

  html = "";
  eterm_vec_init(&term_array);
  run_diagnostics(w, html, &term_array);
  result = eterm_vec_join(&term_array, "|");
  printf("-> %s\n", result);
  if(result != NULL){
    eterm_vec_destroy(&term_array);
    tidy_destroy(w);
    TEST_ERROR
    return 1;
  }
  eterm_vec_destroy(&term_array);


  tidy_map_deinit(&opt);
  tidy_destroy(w);

  printf("ok\n");
  return 0;
}