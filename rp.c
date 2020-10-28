/*
Copyright (c) 2016-2020 Jeremy Iverson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/* assert */
#include <assert.h>

/* printf, fopen, fclose, fscanf */
#include <stdio.h>

/* EXIT_SUCCESS, malloc, free */
#include <stdlib.h>

int
main(int argc, char * argv[])
{
  size_t n, m;

  /* Validate command line arguments. */
  assert(2 == argc);

  /* ... */
  char const * const fn = argv[1];

  /* Validate input. */
  assert(fn);

  /* Open file. */
  FILE * const fp = fopen(fn, "r");
  assert(fp);

  /* Read file. */
  fscanf(fp, "%zu %zu", &n, &m);

  /* Allocate memory. */
  double * const movie1 = malloc(n * sizeof(*movie1));
  double * const movie2 = malloc(n * sizeof(*movie2));
  double * const movie3 = malloc(n * sizeof(*movie3));
  double * const movie4 = malloc(n * sizeof(*movie4));
  double * const movie5 = malloc(n * sizeof(*movie5));

  /* Check for success. */
  assert(movie1);
  assert(movie2);
  assert(movie3);
  assert(movie4);
  assert(movie5);

  for (size_t i = 0; i < n; i++) {
    fscanf(fp, "%lf %lf %lf %lf %lf", &movie1[i], &movie2[i], &movie3[i],
      &movie4[i], &movie5[i]);
  }

  /* Close file. */
  int const ret = fclose(fp);
  assert(!ret);

  /* Echo contents of file. */
  printf("%zu %zu\n", n, m);

  for (size_t i = 0; i < n; i++) {
    printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n", movie1[i], movie2[i], movie3[i],
      movie4[i], movie5[i]);
  }

  /* Deallocate memory. */
  free(movie1);
  free(movie2);
  free(movie3);
  free(movie4);
  free(movie5);

  return EXIT_SUCCESS;
}