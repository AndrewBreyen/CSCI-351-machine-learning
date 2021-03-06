#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


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


    //allocates more memory: for storage of user input
    double * const userRating = malloc(numOfMovies*sizeof(*userRating));
    assert(userRating);

    //user input
    for (size_t j = 0; j<numOfMovies-1; j++){
      printf("Enter rating for movie %zu: ", j+1);
      scanf("%lf", &userRating[j]);
    }

    //allocate memory to store distances
    double * distance = calloc(numOfViewers, sizeof(*distance));

    //make sure allocation worked
    assert(distance);

    //compute the distances
    //i=viewers; j=movies
    for (size_t i = 0; i<numOfViewers; i++){
      for (size_t j = 0; j<numOfMovies-1; j++){
        //distance[i] = fabs(ratings[i*numOfMovies+j]-userRating[j]);
        distance[i] += fabs(userRating[j] - ratings[i*numOfMovies + j]);
      }
    }

    printf("ID     Distance\n");
    printf("****************\n");

    for (size_t i = 0;  i < numOfViewers ;   i++){
      printf("%9zu      %8.1lf\n", i+1, distance[i]);
    }
    printf("****************\n");


    int const ret = fclose(fp); // closing file
    assert(!ret);

    free(ratings);
    free(userRating);
    free(distance);

    return 0;
 }
