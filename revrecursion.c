//
//  revrecursion.c
//  
//
//  Created by Tanisha Dighe on 04/08/20.
//

#include <stdio.h>
#define MAXLEN 50

char reversestring[MAXLEN];
int sindex;

void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];

    printf("enter the string\n");
    scanf("%s", &s);
    
    sindex = 0;
    reverse(s,0);

    printf("%s\n",reversestring);

    return 0;
}


 /* printd:  print n in decimal */
void reverse(char s[], int startindex)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        myitoa(n / 10);
    s[sindex++] = n % 10 + '0';
    s[sindex] = '\0';
}

