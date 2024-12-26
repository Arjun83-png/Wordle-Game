#include "wordle_lib.h"
#include "string.h"
#include <stdlib.h>


bool score_guess(char *secret, char *guess, char *result) {
  int len = strlen(secret);
  for (int i = 0; i < len; i++) {
	  if (guess[i] == secret[i]) {
		  result[i] = 'g';
	  } else {
		  for (int j = 0; j < len; j++) {
			  if ((guess[i] == secret[j]) && (result[j] != 'g') && (result[j] != 'y')) {
				  result[i] = 'y';
				  break;
			  } else {
				  result[i] = 'x';
			  }
		  }
	  }
  }

  int len2 = strlen(result);
  for (int k = 0; k < len2; k++) {
	  if (result[k] != 'g') {
		  return false;
	  }
  }
  return true;
}


bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
 for (size_t i = 0; i < num_words; i++) {
	 if (strcmp(vocabulary[i], guess) == 0) {
		 return true;
	 }
 }
 return false;
}


char **load_vocabulary(char *filename, size_t *num_words) {
  char **out = NULL;
  // TODO(you): finish this function
  *num_words = 0;
  char buffer[7];
  FILE *open = fopen(filename, "r");
  while (fgets(buffer, 7, open)) {
	  buffer[5] = '\0';
	  *num_words = *num_words + 1;
	  out = realloc(out, *num_words * sizeof(char *));
	  out[*num_words - 1] = strdup(buffer);
  }
  fclose(open);
  return out;
}


void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
	  free(vocabulary[i]);
  }
  free(vocabulary);
}
