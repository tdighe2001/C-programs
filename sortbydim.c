//
//  sortbydim.c
//  
//
//  Created by Tanisha Dighe on 19/08/20.
//

#include <stdio.h>
int shellsort(int barray[], int n);

int main()
{
    int i, n, array[10];
    
    printf("enter the no. of elements\n");
    scanf("%d", &n);

    
    printf("enter the array elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &array[i]);
    
    shellsort(array,n);
    printf("Sorted Array is:\n");

    for(i = 0; i <n; i++)
    {
        printf("%d\n", array[i]);
    }
}

int shellsort(int barray[], int n)
{
    int inc = n-1, current, previous, j, k, x, inserted;
    
    while (inc>1)
    {
        inc = inc/2;
        for(j = 0; j<=inc; ++j)
        {
            k = j+inc;
            while(k<n)
            {
                inserted = 0;
                x = barray[k];
                current = k;
                previous = current - inc;
                while((previous>=j)&&(inserted != 1))
                {
                    if (x< barray[previous])
                    {
                        barray[current] = barray[previous];
                        current = previous;
                        previous = previous - inc;
                    }
                    else (inserted = 1);
                }
                barray[current] = x;
                k = k + inc;
            }
        }
    }
    return 0;
}
