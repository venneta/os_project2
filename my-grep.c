#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
The fuctionality of this is to find the first instance of a text script in a text file. So this is a basic grep clone.
Input parameters is a text script and a text file, output goes to command line.
*/
int main(int argc, char *argv[]){
  // 
  if(argc == 1){
    fprintf(stderr, "my-grep: searchterm [file ...]\n");
    exit(1);
  }
  
  // In case no files are given, takes input from stdin
  if(argc == 2){
   FILE *fileIn = stdin;
   char *line = NULL;
   ssize_t read;
   size_t len = 0;
   while((read = getline(&line,&len,fileIn)) != -1){
      char *ptr = strstr(line,argv[1]);
      if(ptr != NULL){
        printf("%s",line);
      }
  }
  free(line);
   
  } else{
  
  for (int i = 2; i < argc; i++){
    // Opening the read file
    FILE *fileIn = fopen(argv[i],"r");
    if(fileIn == NULL){
      fprintf(stderr, "my-grep cannot open file %s\n", argv[i]);
      exit(1);
    }

    // Reading the file
    char *line = NULL;
    ssize_t read;
    size_t len = 0;
    while((read = getline(&line,&len,fileIn)) != -1){
      char *ptr = strstr(line,argv[1]);
      if(ptr != NULL){
        printf("%s",line);
      }
    }
    free(line);
    fclose(fileIn);
  }
  }
  return 0;
}
