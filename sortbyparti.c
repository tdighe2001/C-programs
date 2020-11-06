//
//  sortbyparti.c
//  
//
//  Created by Tanisha Dighe on 19/08/20.
//

#include <stdio.h>
int quicksort(int barray[], int n);

int main()
{
    int i, n, array[10];
    
    printf("enter the no. of elements\n");
    scanf("%d", &n);

    printf("enter the array elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    quicksort(array,n);
    printf("Sorted Array is:\n");
    for(i = 0; i <n; i++)
    {
        printf("%d\n", array[i]);
    }
}

int quicksort(int barray[], int n)
{
    int left, right, newleft, newright, middle, mguess, temp, stacktop, stack[100];
    
    stacktop = 1;
    stack[0] = 0;
    stack[1] = n-1;
    while(stacktop>0)
    {
        right = stack[stacktop];
        left = stack[stacktop -1];
        stacktop = stacktop -2;
        
        while(left<right)
        {
            
            newleft = left;
            newright = right;
            middle = (left+right)/2;
            mguess = barray[middle];
            while(barray[newleft]<mguess)
                newleft = newleft+1;
            while(mguess<barray[newright])
                newright = newright -1;
            while(newleft<newright-1)
            
            {
                temp = barray[newleft];
                barray[newleft] = barray[newright];
                barray[newright] = temp;
                newleft = newleft +1;
                newright = newright -1;
                while(barray[newleft]<mguess)
                    newleft = newleft +1;
                while(mguess<barray[newright])
                    newright = newright -1;
            }
            
        if(newleft<= newright)
        {
            if(newleft<newright)
            {
                temp = barray[newleft];
                barray[newleft] = barray[newright];
                barray[newright] = temp;
            }
            newleft = newleft+1;
            newright = newright-1;
        }
        if(newright<middle)
        {
            stack[stacktop+1] = newleft;
            stacktop = stacktop+2;
            stack[stacktop] = right;
            right = newright;
        }
        else {
            stack[stacktop+1] = left;
            stacktop = stacktop+2;
            stack[stacktop] = newright;
            left = newleft;
        }
    }
    }
    return 0;
}
