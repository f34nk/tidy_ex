#include "tidy_workspace.h"

TidyOptionId str2enum(const char* string)
{
  int j;
  for (j = 0;  j < sizeof (conversion) / sizeof (conversion[0]);  ++j)
    if (!strcmp (string, conversion[j].string)) {
      return conversion[j].value;
    }
  // error_message ("no such string");
  fprintf(stderr, "str2enum() - Enum not found for string '%s'\n", string);
  return TidyUnknownOption;
}

tidy_workspace_t* tidy_init(tidy_map_str_t* options)
{
  size_t workspace_size = sizeof(struct tidy_workspace);

#ifdef TIDY_HTML_DEBUG
  printf("tidy_init() - Size of workspace is %d\n", (int)workspace_size);
#endif

  tidy_workspace_t* workspace = NULL;
  workspace = (tidy_workspace_t*)tidy_malloc(workspace_size);
  if(workspace == NULL) {
    fprintf(stderr, "tidy_init() - Failed to allocate doc\n");
    return NULL;
  }

#ifdef TIDY_HTML_USE_DMT
  printf("tidy_init() - Current memory usage: %u bytes\n", (unsigned int)dmt_usage());
#endif

  Bool ok = 0;
  TidyDoc tdoc = tidyCreate();

  // do not inject meta tag "generator"
  ok = tidyOptSetBool(tdoc, TidyMark, no) && tidyOptSetBool(tdoc, TidyQuiet, yes);

  // set options

  const char* key;
  map_iter_t iter = tidy_map_iter(options);
  while ((key = tidy_map_next(options, &iter))) {
    char* value = (char*)*tidy_map_get(options, key);
    TidyOptionId option = str2enum(key);
    if(option != TidyUnknownOption) {
#ifdef TIDY_HTML_DEBUG
      printf("\t%s = %s\n", key, value);
#endif
      if(strcmp(value, "yes") == 0) {
        ok = ok && tidyOptSetBool(tdoc, option, yes);
      }
      else if(strcmp(value, "no") == 0) {
        ok = ok && tidyOptSetBool(tdoc, option, no);
      }
      else {
        ok = ok && tidyOptSetValue(tdoc, option, value);
      }
    }
  }

  if(!ok) {
    fprintf(stderr, "tidy_init() - Failed to set options\n");
    tidyRelease(tdoc);
    return NULL;
  }

  workspace->doc = tdoc;

  return workspace;
}

void tidy_destroy(tidy_workspace_t* workspace)
{
  tidyRelease(workspace->doc);

  tidy_free(workspace);
  workspace = NULL;

#ifdef TIDY_HTML_USE_DMT
  dmt_dump(stdout);
#endif
}