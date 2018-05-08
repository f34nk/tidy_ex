#include "tidy_parse.h"

char* tidy_parse(tidy_workspace_t* workspace, const char* data)
{
  // if(data == NULL || strlen(data) == 0) {
  //   return NULL;
  // }

  TidyBuffer output = {0};
  // TidyBuffer errors = {0};

  // tidySetErrorBuffer(workspace->doc, &errors);

  int result = tidyParseString(workspace->doc, data);
  if(result >= 0) {
    result = tidySaveBuffer(workspace->doc, &output);
  }

  char *copy;
  tidy_string_copy((char*)output.bp, copy)

  // Tidy always appends a carriage return - even on empty input strings.
  // Remove it.
  if(strlen(copy) > 0) {
    if(copy[strlen(copy) - 1] == '\n') {
      copy[strlen(copy) - 1] = '\0';
    }
    if(copy[strlen(copy) - 1] == '\n') {
      copy[strlen(copy) - 1] = '\0';
    }
  }

  // free tidy buffer
  tidyBufFree(&output);
  // tidyBufFree(&errors);

  return copy;
}