#include "erl_interface.h"
#include "ei.h"
#include "eterm_vec.h"

#include "tidy_html.h"

void parse(html_workspace_t* w, const char* html, /*const char* scope_name,*/ vec_eterm_t* term_array)
{
  // int buffer_index = html_parse(w, html);

  // html_vec_str_t* buffer = html_get_buffer(w, buffer_index);
  // int i; char* val;
  // html_vec_foreach(buffer, val, i) {
  //   eterm_vec_push(term_array, erl_mk_binary(val, strlen(val)));
  // }
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

    // html_map_str_t options;
    // html_map_init(&options);

    // html_map_set(&options, "TidyShowWarnings", "no");
    // html_map_set(&options, "TidyBodyOnly", "yes");
    // html_map_set(&options, "TidyNewline", "no");

    // html_workspace_t* workspace = html_init(&options);

    // vec_eterm_t term_array;
    // eterm_vec_init(&term_array);
    // parse(workspace, html, /*scope,*/ &term_array);
    // ETERM* term_list = eterm_vec_to_list(term_array);
    // response = erl_format("{parse, ~w}", term_list);

    // free allocated resources
    // eterm_vec_destroy(&term_array);
    // erl_free_term(term_list);
    // html_map_deinit(&options);
    // html_destroy(workspace);
    erl_free_term(html_term);
    // erl_free_term(scope_term);
  }

  erl_free_term(pattern);
  return response;
}