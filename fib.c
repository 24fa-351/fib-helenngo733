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

int fib_iterative(int fib_nth) {
   int prev_num = 0, current_num = 1, temp_next_num;
   for (int ix = 2; ix <= fib_nth; ix++) {
      temp_next_num = prev_num + current_num;
      prev_num = current_num;
      current_num = temp_next_num;
   }
   return current_num;
}

int main (int argc, char *argv[]) {
   int input_num = atoi(argv[1]); //atoi - converts string to integer
   FILE *file = fopen(argv[3], "r"); //open file for reading
   
   int file_number;
   fscanf(file, "%d", &file_number); //read the file
   fclose(file);

   int fib_nth = input_num + file_number - 1;
   int result;
   
   if (argv[2][0] == 'r') {
      result = fib_recursive(fib_nth);
   } else if (argv[2][0] == 'i') {
      result = fib_iterative(fib_nth);
   }

   printf("%d\n", result);
}

