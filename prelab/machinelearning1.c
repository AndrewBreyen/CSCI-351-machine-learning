#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[])
 {
    size_t numOfViewers,numOfMovies;
    double movie1, movie2, movie3, movie4, movie5;

    assert(2==argc);

    char const * const fn = argv[1];
    assert(fn);

    FILE * const fp = fopen(fn,"r");// opening of file
    assert(fp);

    fscanf(fp, "%zu %zu", &numOfViewers, &numOfMovies);
    printf("%zu %zu\n",numOfViewers, numOfMovies);

    for (size_t i = 0; i<numOfMovies; i++){
      fscanf(fp, "%lf %lf %lf %lf %lf", &movie1, &movie2, &movie3, &movie4, &movie5);
      printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n", movie1, movie2, movie3, movie4, movie5);
    }


    int const ret = fclose(fp); // closing file
    assert(!ret);
    return 0;
 }
