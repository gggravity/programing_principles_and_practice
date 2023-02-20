//
// Created by martin on 10/28/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t string_length (char *str)
{
  size_t n = 0;

  while (*str++)
    {
      n++;
    }

  return n;
}

int string_compare (const char *left, const char *right)
{
  if (*left > *right)
    {
      return 1;
    }
  else if (*left < *right)
    {
      return -1;
    }
  else
    {
      return 0;
    }
}

char *string_copy (char *destination, const char *source)
{
  while ((*destination++ = *source++))
    {
      /* empty*/
    }

  return destination;
}

int main (int argc, char *argv[])
{
  char *some_string = "some string test TEST";

  printf ("%zu\n", strlen (some_string));

  printf ("%zu\n", string_length (some_string));

  printf ("%d\n", strcmp ("AAA", "AAA"));
  printf ("%d\n", strcmp ("AAA", "BBB"));
  printf ("%d\n", strcmp ("BBB", "AAA"));

  printf ("%d\n", string_compare ("AAA", "AAA"));
  printf ("%d\n", string_compare ("AAA", "BBB"));
  printf ("%d\n", string_compare ("BBB", "AAA"));

  char dest1[strlen (some_string)];
  char dest2[strlen (some_string)];

  strcpy (dest1, some_string);
  string_copy (dest2, some_string);

  printf ("%s\n", dest1);
  printf ("%s\n", dest2);

  return EXIT_SUCCESS;
}
