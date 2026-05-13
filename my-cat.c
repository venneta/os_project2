#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
The fuctionality of this is to take in text files and print out their contents. So this is a basic cat clone.
Input parameters are text files, output goes to command line.
*/
int main(int argc, char *argv[]){
  // If no files given as parameters, exits
  if(argc == 1){
    exit(0);
  }

  // Can take in multiple files, so goes over all of them
  for (int i = 0; i < argc-1; i++){
    // Opening the read file, check if everything ok
    FILE *fileIn = fopen(argv[i+1],"r");
    if(fileIn == NULL){
      fprintf(stderr, "my-cat: cannot open file %s\n",argv[i+1]);
      exit(1);
    }

    // Reading the file and printing it out at the same time
    char *line = NULL;
    ssize_t read;
    size_t len = 0;
    while((read = getline(&line,&len,fileIn)) != -1){
      printf("%s",line);
    }
    fclose(fileIn);
    free(line);
  }
  exit(0);
}
