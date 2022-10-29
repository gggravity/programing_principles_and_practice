//
// Created by martin on 10/29/22.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int compare (const void *a, const void *b)
{
  // setting up rules for comparison
  return strcmp (*(const char **)a, *(const char **)b);
}

int main (int argc, char *argv[])
{
  FILE *file_ptr;
  char *line = NULL;
  size_t len = 0;
  ssize_t n_read;

  file_ptr = fopen ("../input.txt", "r");

  if (file_ptr == NULL)
    {
      fprintf (stderr, "error opening file");
      exit (EXIT_FAILURE);
    }

  char *pch;
  const char *list_of_words[10000]; // don't use a long list
  int i = 0;

  while ((n_read = getline (&line, &len, file_ptr)) != -1)
    {
      pch = strtok (line, " ,.-");
      while (pch != NULL)
        {
//          printf ("%s\n", pch);
          pch = strtok (NULL, " ,.-");
          list_of_words[i] = pch;
          i++;
        }
    }

  qsort (list_of_words, i - 1, sizeof (const char *), compare);

  for (int j = 0 ; j < i - 1 ; j++)
    {
      printf ("%s\n", list_of_words[j]);
    }

  fclose (file_ptr);

  return EXIT_SUCCESS;
}
