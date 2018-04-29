#include "tidy_doc.h"

tidy_doc_t* tidy_init(html_map_str_t* options)
{
  Bool ok = 0;
  TidyDoc tdoc = tidyCreate();

  // do not inject meta tag "generator"
  ok = tidyOptSetBool(tdoc, TidyMark, no) && tidyOptSetBool(tdoc, TidyQuiet, yes);

  // set options

  const char* key;
  map_iter_t iter = html_map_iter(options);
  while ((key = html_map_next(options, &iter))) {
    char* value = (char*)*html_map_get(options, key);
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

  return (tidy_doc_t*)&tdoc;
}

void tidy_destroy(tidy_doc_t* doc)
{
#ifdef TIDY_HTML_USE_DMT
  printf("tidy_destroy() - Current memory usage: %u bytes\n", (unsigned int)dmt_usage());
#endif

  tidyRelease((TidyDoc)*doc);

#ifdef TIDY_HTML_USE_DMT
  dmt_dump(stdout);
#endif
}