#include <stdio.h>

int main()
 {
    FILE *fp; // declaration of file pointer
    char con[1000]; // variable to read the content
    fp =fopen("ML-ratings-small.txt","r");// opening of file
    if (!fp)// checking for error
    return 1;
    while (fgets(con,1000, fp)!=NULL)// reading file content
    printf("%s",con);
    fclose(fp); // closing file
    return 0;
 }
