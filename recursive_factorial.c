//
//  factorial.c
//  
//
//  Created by Tanisha Dighe on 16/07/20.
//

#include <stdio.h>
int factorial (int number);

int main()
{
 int i,number = 0;
 
    printf ("Input the number: ");
    scanf("%d",&number);

    printf("Factorial of %d is: %d\n",number, factorial(number));

}
int factorial (int fnumber)
{
    if (fnumber == 0)
        return 1;
    else return fnumber * factorial (fnumber -1);
    
}
