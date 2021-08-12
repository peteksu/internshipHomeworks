#include <stdio.h>
#include <stdlib.h>

int main()
{
   long int firstNumber = 1;
   long int secondNumber = 1;
   long int nextNumber = 0;
   long int sum = 0;

   while (nextNumber < 4000000){

        if(nextNumber % 2 == 0){
            sum += nextNumber;
        }
        nextNumber = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = nextNumber;

   }
   printf("%ld", sum);

    return 0;
}
