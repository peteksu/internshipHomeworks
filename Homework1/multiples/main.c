#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,i,sum;
    printf("please enter a number:");
    scanf("%d,", &number);
    sum=0;
    for(i=0; i<number+1; i++){
        if(i%2==0 || i%3==0){
            sum=sum+i;

        }

    }
    printf("sum = %d",sum);
    return 0;
}
