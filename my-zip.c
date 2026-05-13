#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/*
This is a run length encoding compressor. Takes in a text file and compresses it, resulting in a binary file. 
Run like: ./my-zip <input.txt> > output.bin
*/
int main(int argc, char *argv[]){
  if(argc != 2){
    fprintf(stderr,"my-zip: <input.txt>\n");
    return 1;
  }

  // Opening the read file
  FILE *fileIn = fopen(argv[1],"rb");
  if(fileIn == NULL){
    fprintf(stderr,"my-zip: cannot open file\n");
    exit(1);
  }

  // Setting out variables for the character and counting the amount of it
  int read; 
  int previous = fgetc(fileIn);
  if(previous == EOF){
    fclose(fileIn);
    exit(0);
  }
  int charCount = 1;
  
  // Going through all the characters
  while((read = fgetc(fileIn)) != EOF){
    if(read == previous){
      charCount++;
    } else{
      // Writing in binary, the character and the amount
      fwrite(&charCount, sizeof(int), 1, stdout);
      fwrite(&previous, sizeof(char),1,stdout);
      charCount = 1;
      previous = read;
    }
  }
  // Writing the final pair
  fwrite(&charCount, sizeof(int), 1, stdout);
  fwrite(&previous, sizeof(char),1,stdout);
  fclose(fileIn);
  exit(0);
}
