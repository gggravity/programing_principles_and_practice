#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_p_and_x (char *p, int x)
{
  printf ("p is \"%s\" and x is %d\n", p, x);
}

int main (int argc, char *argv[])
{
  printf ("Hello, World!\n\n");

  char *hello = "Hello";
  char *world = "World";

  char hello_world[strlen (hello) + strlen (world) + 4];

  strcpy (hello_world, hello);
  strcat (hello_world, " ");
  strcat (hello_world, world);
  strcat (hello_world, "!!!");

  printf ("%s\n", hello_world);

  print_p_and_x (hello_world, 123);

  print_p_and_x (hello, 1111);

  print_p_and_x (world, 321);

  print_p_and_x ("Another test!!!", 911);

  return EXIT_SUCCESS;
}
