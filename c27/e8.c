//
// Created by martin on 10/28/22.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char character;
    int number;
} char_int;

int compare (const void *s1, const void *s2)
{
  char_int *num1 = (char_int *)s1;
  char_int *num2 = (char_int *)s2;

  return num1->number > num2->number;
}

int main (int argc, char *argv[])
{
  char *keyboard = "½1234567890+wertyuiopåäsdfghjklæø'<zxcvbnm,.-";

  size_t keyboard_len = strlen (keyboard);

  char_int list[keyboard_len];

  for (size_t i = 0 ; i < keyboard_len ; ++i)
    {
      list[i].number = (int)keyboard[i];
      list[i].character = keyboard[i];
    }

//  for (size_t i = 0 ; i < keyboard_len ; ++i)
//    {
//      printf ("%d\t%c\n", list[i].number, list[i].character);
//    }

  qsort (list, keyboard_len, sizeof (char_int), compare);

  for (size_t i = 0 ; i < keyboard_len ; ++i)
    {
      if (list[i].number > 0)
        {
          printf ("%d\t%c\n", list[i].number, list[i].character);
        }
    }

  return EXIT_SUCCESS;
}

