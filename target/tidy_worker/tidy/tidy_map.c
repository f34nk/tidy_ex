#include "tidy_map.h"
#include "tidy_memory.h"

char* tidy_map_join(tidy_map_str_t* map, const char* delimiter1, const char* delimiter2)
{
  char* data = (char*)tidy_calloc(1, 1);

  const char* key;
  map_iter_t iter = tidy_map_iter(map);

  key = tidy_map_next(map, &iter);
  while(key != NULL) {
    char* value = *tidy_map_get(map, key);
    if(key == NULL || value == NULL) {
      continue;
    }

    int prev = (int)strlen(data);

    int length = (int)strlen(key) + (int)strlen(delimiter1) + (int)strlen(value) + 1;
    char* temp = (char*)tidy_malloc(length * sizeof(char));
    sprintf(temp, "%s%s%s", key, delimiter1, value);

    char* new_data = (char*)tidy_realloc(data, prev + length * sizeof(char));
    if(new_data == NULL) {
      tidy_free(temp);
      tidy_free(data);
      return NULL;
    }

    strcpy((char*)&new_data[prev], temp);
    data = new_data;
    tidy_free(temp);

    key = tidy_map_next(map, &iter);
    if(key != NULL) {
      prev = strlen(data);
      length = strlen(delimiter2) + 1;

      new_data = (char*)tidy_realloc(data, prev + length * sizeof(char));
      if(new_data == NULL) {
        tidy_free(data);
        return NULL;
      }

      strcpy((char*)&new_data[prev], delimiter2);
      data = new_data;
    }
  }

  // User must free this data
  return data;
}