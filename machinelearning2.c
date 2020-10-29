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

    double * const movieArr1 = malloc(numOfViewers * sizeof(*movieArr1));
    double * const movieArr2 = malloc(numOfViewers * sizeof(*movieArr2));
    double * const movieArr3 = malloc(numOfViewers * sizeof(*movieArr3));
    double * const movieArr4 = malloc(numOfViewers * sizeof(*movieArr4));
    double * const movieArr5 = malloc(numOfViewers * sizeof(*movieArr5));

    assert(movieArr1);
    assert(movieArr2);
    assert(movieArr3);
    assert(movieArr4);
    assert(movieArr5);

    for (size_t i = 0; i<numOfViewers; i++){
      fscanf(fp, "%lf %lf %lf %lf %lf", &movieArr1[i], &movieArr2[i], &movieArr3[i], &movieArr4[i], &movieArr5[i]);
    }

    printf("%zu %zu\n", numOfViewers, numOfMovies);

    for(size_t i = 0; i<numOfViewers; i++){
      printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n", movieArr1[i], movieArr2[i], movieArr3[i], movieArr4[i], movieArr5[i]);
    }


    int const ret = fclose(fp); // closing file
    assert(!ret);

    free(movieArr1);
    free(movieArr2);
    free(movieArr3);
    free(movieArr4);
    free(movieArr5);

    return 0;
 }
