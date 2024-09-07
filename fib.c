// Helen Ngo
// September 4, 2024
// Creating a Fibonacci Sequence

#include <stdio.h>
#include <stdlib.h>

int fib_recursive(int fib_nth) {
   if (fib_nth <= 1) {
      return fib_nth;
   }
   return fib_recursive(fib_nth - 1) + fib_recursive(fib_nth - 2);
}

int main (int argc, char *argv[]) {

   if (argc != 4) {
      printf("Parameters: ./fib <input_num> <r> <file_name>\n");
      return 1;
   }
   
   int input_num = atoi(argv[1]); //atoi - converts string to integer
   FILE *file = fopen(argv[3], "r"); //open file for reading
   
   int file_number;
   fscanf(file, "%d", &file_number); //read the file
   fclose(file);

   int fib_nth = input_num + file_number - 1;
   int result = fib_recursive(fib_nth);

   printf("%d\n", result);
}

