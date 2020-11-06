//
//  matrixmulti.c
//  
//
//  Created by Tanisha Dighe on 26/07/20.
//


#include <stdio.h>
#define Size 100000

int main()
{
    int a[3][3],b[3][3],c[3][3],i,j,k,sum;
    
    
    printf("matrix elements of A\n");
    for(i=0;i < Size;i++)
    {
        for(j=0;j < Size;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("matrix elements of B\n");
    for(i=0;i < Size;i++)
    {
        for(j=0;j < Size;j++)
        {
            scanf("%d",&b[i][j]);
        }
        printf("\n");
    }

    for(i=0;i< Size;i++)
    {
        for(j=0;j< Size;j++)
        {
            sum=0;
            for(k=0;k< Size;k++)
            {
                sum=sum+a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }

     printf("\nProduct of two matrices is:\n\n");
    for(i=0;i< Size;i++)
    {
        for(j=0;j< Size;j++)
        {
            printf("%d",c[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}
