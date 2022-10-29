//
// Created by martin on 10/29/22.
//

#define N 99

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct
{
    int smallest;
    int largest;
    int median;
    double mean;
} Result;

static int compare (const void *a, const void *b)
{
  int int_a = *((int *)a);
  int int_b = *((int *)b);

  if (int_a == int_b)
    {
      return 0;
    }
  else if (int_a < int_b)
    {
      return -1;
    }
  else
    {
      return 1;
    }
}

Result array_info (int numbers[], int n)
{
  Result result;
  result.smallest = INT_MAX;
  result.largest = INT_MIN;
  result.median = 0;
  result.mean = 0;

  for (int i = 0 ; i < n ; i++)
    {
      if (result.smallest > numbers[i])
        {
          result.smallest = numbers[i];
        }
      if (result.largest < numbers[i])
        {
          result.largest = numbers[i];
        }
      result.mean += numbers[i];
    }
  result.mean /= n;
  qsort (numbers, N, sizeof (int), compare);
  result.median = numbers[n / 2];

  return result;
}

int *get_numbers ()
{
  static int numbers[N];

  srand (time (NULL));
  for (int i = 0 ; i < N ; i++)
    {
      int num = (rand () % (N + 1));
      numbers[i] = num;
    }
  return numbers;
}

void print_numbers (int *numbers)
{
  for (int i = 0 ; i < N ; i++)
    {
      printf ("%d ", numbers[i]);
    }
}

int main (int argc, char *argv[])
{
  int *numbers = get_numbers ();

  printf ("### Numbers ###\n");

  print_numbers (numbers);

  Result result = array_info (numbers, N);

  printf ("\n\n### Numbers sorted ###\n");

  print_numbers (numbers);

  printf ("\n\n### Results ###\n");
  printf ("smallest: %.2f\n", (float)result.smallest);
  printf ("largest: %.2f\n", (float)result.largest);
  printf ("mean: %.2f\n", result.mean);
  printf ("median: %.2f\n", (float)result.median);

  return EXIT_SUCCESS;
}
