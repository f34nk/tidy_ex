#include "tidy_diagnostics.h"

char* tidy_diagnostics(tidy_workspace_t* workspace, const char* data)
{
  TidyBuffer output = {0};
  TidyBuffer errors = {0};

  tidySetErrorBuffer(workspace->doc, &errors);

  int result = tidyParseString(workspace->doc, data);
  if(result < 0) {
    return NULL;
  }

  if(result >= 0) {
    result = tidyRunDiagnostics(workspace->doc);
    // tidyOptSetBool(workspace->doc, TidyForceOutput, yes);
  }
  // if(result >= 0) {
  //   result = tidySaveBuffer(workspace->doc, &output);
  // }

  // printf("errors '%s'\n", errors.bp);
  // printf("output '%s'\n", output.bp);
  char *copy;
  // tidy_string_copy((char*)output.bp, copy)
  tidy_string_copy((char*)errors.bp, copy)

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
  // tidyBufFree(&output);
  tidyBufFree(&errors);

  return copy;
}