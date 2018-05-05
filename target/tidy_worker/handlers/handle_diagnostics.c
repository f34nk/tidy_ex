#include "erl_interface.h"
#include "ei.h"
#include "eterm_vec.h"

#include "tidy_html.h"

void run_diagnostics(tidy_workspace_t* workspace, const char* html, vec_eterm_t* term_array)
{
  char* result = tidy_diagnostics(workspace, html);
  if(result == NULL) {
    return;
  }
  eterm_vec_push(term_array, erl_mk_binary(result, strlen(result)));
  tidy_free(result);
}

ETERM* handle_diagnostics(ErlMessage* emsg)
{
  ETERM* response = NULL;
  ETERM* pattern = erl_format("{run_diagnostics, Html, Options}");

  tidy_map_str_t options;
  tidy_map_init(&options);

  if (erl_match(pattern, emsg->msg)) {
    ETERM* html_term = erl_var_content(pattern, "Html");
    ETERM* options_term = erl_var_content(pattern, "Options");
    char* html = (char*)ERL_BIN_PTR(html_term);
    if(strlen(html) == 0) {
      response = erl_format("{run_diagnostics, []}");
    }
    else {

      if(ERL_IS_LIST(options_term)) {
        ETERM* list = options_term;
        int length = erl_length(options_term);

        for(int i = 0; i < length; i++) {
          ETERM* tuple = (ETERM*)ERL_CONS_HEAD(list);

          if(ERL_IS_TUPLE(tuple) && ERL_TUPLE_SIZE(tuple) == 2) {
            ETERM* key_term = erl_element(1, tuple);
            ETERM* value_term = erl_element(2, tuple);
            char* key = erl_iolist_to_string(key_term);
            char* value = erl_iolist_to_string(value_term);

            tidy_map_set(&options, key, value);
          }

          if(i < length - 1 ) {
            list = (ETERM*)ERL_CONS_TAIL(list);
            erl_free_term(tuple);
          }
        }
      }

      tidy_workspace_t* workspace = tidy_init(&options);

      vec_eterm_t term_array;
      eterm_vec_init(&term_array);
      run_diagnostics(workspace, html, &term_array);
      ETERM* term_list = eterm_vec_to_list(term_array);
      response = erl_format("{run_diagnostics, ~w}", term_list);

      // char* result = tidy_parse(workspace, html);
      // response = erl_format("{run_diagnostics, ~w}", erl_mk_binary(result, strlen(result)));
      // tidy_free(result);

      // free allocated resources
      // eterm_vec_destroy(&term_array);
      // erl_free_term(term_list);
      // tidy_map_deinit(&options);
      // tidy_destroy(workspace);
      // erl_free_term(html_term);
      // erl_free_term(options_term);
    }
  }

  erl_free_term(pattern);
  return response;
}