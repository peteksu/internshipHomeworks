#include <stdio.h>
#include <stdlib.h>
#define SIZEOFDIVISORLIST 2

enum Operations{
        Addition,
        Multiplication
    };
typedef enum Operations operationOptions;

int main()
{
    int limit = 6;
    int divisorList[SIZEOFDIVISORLIST] = {2,3};
    operationOptions operation = Addition;
    sumOrMultiplicationOfAllMultiplesOfaNumber(limit,divisorList,operation);
    return 0;
}
void sumOrMultiplicationOfAllMultiplesOfaNumber(int limit, int divisorList[], operationOptions operation ){
    int sum = 0;
    int multiplied = 1;
    int result = 0;
    if(SIZEOFDIVISORLIST == 0){
        printf("Divisor list can not be empty!");
    }else if(limit <= 0){
        printf("Limit have to be greater than zero!");
    }else{
        for(int i = 1; i <= limit; i++){
            for (int j = 0; j < SIZEOFDIVISORLIST; j++){
                if(i % divisorList[j] == 0){
                    if(operation == Addition){
                        sum = sum + i;
                        result = sum;
                    }else if(operation == Multiplication){
                        multiplied = multiplied * i;
                        result = multiplied;
                    }
                    break;
                }
            }
        }
        printf("%d",result);
    }
}
