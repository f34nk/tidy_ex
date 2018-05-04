#include "tidy_clean_and_repair.h"

char* tidy_clean_and_repair(tidy_workspace_t* workspace, const char* data)
{
  TidyBuffer output = {0};
  int result = tidyParseString(workspace->doc, data);
  if(result >= 0) {
    result = tidyCleanAndRepair(workspace->doc);
  }
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

  return copy;
}