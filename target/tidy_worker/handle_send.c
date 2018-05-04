#include "handle_send.h"

ETERM* handle_clean_and_repair(ErlMessage* emsg);
ETERM* handle_parse(ErlMessage* emsg);

#define MAX_HANDLERS 2
ETERM* (*HANDLERS[MAX_HANDLERS])() = {handle_parse, handle_clean_and_repair};

ETERM*
err_term(const char* error_atom)
{
  return erl_format("{error, ~w}", erl_mk_atom(error_atom));
}

void
handle_emsg(state_t* state, ErlMessage* emsg)
{
  switch(emsg->type) {
  case ERL_REG_SEND:
  case ERL_SEND:
    handle_send(state, emsg);
    break;
  case ERL_LINK:
  case ERL_UNLINK:
    break;
  case ERL_EXIT:
    break;
  }

  // its our responsibility to free these pointers
  erl_free_compound(emsg->msg);
  erl_free_compound(emsg->to);
  erl_free_compound(emsg->from);
}

void
handle_send(state_t* state, ErlMessage* emsg)
{
  ETERM* response = NULL;
  int i = 0;
  while(i < MAX_HANDLERS && response == NULL) {
    response = HANDLERS[i](emsg);
    i += 1;
  }

  if(response == NULL) {
    response = err_term("unknown_call");
    return;
  }

  // send response
  erl_send(state->fd, emsg->from, response);

  // free allocated resources
  erl_free_compound(response);

  // free the free-list
  erl_eterm_release();

  return;
}