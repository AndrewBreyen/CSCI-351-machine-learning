#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


struct distance_metric{
  size_t viewer_id;
  double distance;
}


static int cmp(const void * ap, const void * bp) {
  struct distance_metric const a = *((struct distance_method*)ap);
  struct distance_metric const b = *((struct distance_method*)bp);

  if (a.distance<b.distance) {
    return -1;
  }
  else if (a.distance==b.distance) {
    return 0;
  }
  else {
    return 1;
  }
}

int main(int argc, char *argv[]) {
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



    double * const userRating = malloc(numOfMovies*sizeof(*userRating));
    assert(userRating);

    for (size_t j = 0; j<numOfMovies-1; j++){
      printf("Enter rating for movie %zu: ", j+1);
      scanf("%lf", &userRating[j]);
    }

    double * const distance = calloc(numOfViewers, sizeof(*distance));
    assert(distance);

    //find distance
    for (size_t i = 0; i<numOfViewers; i++){
      for (size_t j = 0; j<numOfMovies-1; j++){
        distance[i] += fabs(userRating[j] - ratings[i*numOfMovies + j]);
      }
    }

    //print distances
    printf("ID     Distance\n");
    printf("****************\n");

    for (size_t i = 0;  i < numOfViewers ;   i++){
      printf("%9zu      %8.1lf\n", i+1, distance[i]);
    }
    printf("****************\n");


    //sort!
    qsort(distance, numOfViewers, sizeof(*distance), &cmp);

    for (size_t i = 0; i < numOfViewers; i++){
      printf("distance[%zu] = %lf\n", i, distance[i]);
    }


  printf("The most similar viewer was viewer #%zu and the distance calculated was %.1lf.\n",);
  printf("the predicted rating for movie 5 is %.1lf.\n", ratings[minI*numOfMovies+(numOfMovies-1)]);


    int const ret = fclose(fp); // closing file
    assert(!ret);

    free(ratings);
    free(userRating);
    free(distance);

    return 0;
 }
