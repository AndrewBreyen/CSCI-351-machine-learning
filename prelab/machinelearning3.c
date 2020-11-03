#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[])
 {
    size_t numOfViewers,numOfMovies;


    assert(2==argc);

    char const * const fn = argv[1];
    assert(fn);

    FILE * const fp = fopen(fn,"r");// opening of file
    assert(fp);

    fscanf(fp, "%zu %zu", &numOfViewers, &numOfMovies);

    double * const ratings = malloc(numOfViewers * numOfMovies * sizeof(*ratings));
    assert(ratings);

    for (size_t i = 0; i<numOfViewers; i++){
      for(size_t j = 0; j<numOfMovies; j++){
        fscanf(fp, "%lf", &ratings[i*numOfMovies+j]);
      }
    }

    printf("%zu %zu\n", numOfViewers, numOfMovies);

    for (size_t i = 0; i<numOfViewers; i++){
      for (size_t j=0; j<numOfMovies-1; j++){
        printf("%.1lf ", ratings[i*numOfMovies+j]);
      }
      printf("%.1lf\n", ratings[i*numOfMovies+numOfMovies-1]);
    }


    int const ret = fclose(fp); // closing file
    assert(!ret);

    free(ratings);

    return 0;
 }
