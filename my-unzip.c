#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
This is a run length decoding. Takes in a compressed binary file and returns it as text file. 
Run like: ./my-unzip <input.bin> > output.txt
*/
int main(int argc, char *argv[]){
  if(argc != 2){
    fprintf(stderr,"my-unzip takes in 1 argument\n");
    exit(1);
  }

  // Opening the read file
  FILE *fileIn = fopen(argv[1],"rb");
  if(fileIn == NULL){
    fprintf(stderr,"my-unzip: cannot open file\n");
    exit(1);
  }

  // Reading the file
  // There are 2 variables used now, the count (How many times character appears in row), and the actual character
  char character;
  int count = 0;
  
  // The file can be read in pairs, always first reading th count, then the character
  while((fread(&count,sizeof(int),1,fileIn)) == 1){
    if(fread(&character, sizeof(char),1,fileIn) != 1){
      fprintf(stderr,"Error occurred when reading character\n");
      fclose(fileIn);
      exit(1);
    }
    // Printing the character to stdout
    for(int i = 0; i < count; i++){
      fprintf(stdout,"%c", character);
    }
  }
  fclose(fileIn);
  exit(0);
}
