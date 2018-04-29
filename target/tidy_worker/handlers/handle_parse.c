#include "erl_interface.h"
#include "ei.h"
#include "eterm_vec.h"

#include "tidy_html.h"

void parse(tidy_workspace_t* workspace, const char* html, /*const char* scope_name,*/ vec_eterm_t* term_array)
{
  char* result = tidy_parse(workspace, html);
  eterm_vec_push(term_array, erl_mk_binary(result, strlen(result)));
  tidy_free(result);
}

ETERM* handle_parse(ErlMessage* emsg)
{
  ETERM* response = NULL;
  // ETERM* pattern = erl_format("{parse, Html, Scope}");
  ETERM* pattern = erl_format("{parse, Html}");

  if (erl_match(pattern, emsg->msg)) {
    ETERM* html_term = erl_var_content(pattern, "Html");
    // ETERM* scope_term = erl_var_content(pattern, "Scope");
    char* html = (char*)ERL_BIN_PTR(html_term);
    // char* scope = (char*)ERL_BIN_PTR(scope_term);

    tidy_map_str_t options;
    tidy_map_init(&options);

    tidy_map_set(&options, "TidyShowWarnings", "no");
    tidy_map_set(&options, "TidyBodyOnly", "yes");
    tidy_map_set(&options, "TidyQuiet", "yes");
    // minify
    tidy_map_set(&options, "TidyVertSpace", "auto");
    tidy_map_set(&options, "TidyIndentSpaces", "0");

    tidy_workspace_t* workspace = tidy_init(&options);

    vec_eterm_t term_array;
    eterm_vec_init(&term_array);
    parse(workspace, html, /*scope,*/ &term_array);
    ETERM* term_list = eterm_vec_to_list(term_array);
    response = erl_format("{parse, ~w}", term_list);

    // free allocated resources
    eterm_vec_destroy(&term_array);
    erl_free_term(term_list);
    tidy_map_deinit(&options);
    tidy_destroy(workspace);
    erl_free_term(html_term);
    // erl_free_term(scope_term);
  }

  erl_free_term(pattern);
  return response;
}