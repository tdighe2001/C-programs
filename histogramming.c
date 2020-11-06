//
//  histogramming.c
//  
//
//  Created by Tanisha Dighe on 13/08/20.
//

#include <stdio.h>
/*int histogram(int freq[], 10);*/


int main()
{
    int i = 0, n, frequency = 0, marks[10], slno, freqCountArray[11];
    printf("how many students?\n");
    scanf("%d", &n);

    printf("enter the marks of the students\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &marks[i]);
   
    /*initialising of frequency array : */
    for (frequency = 0; frequency< 11; ++frequency)
    freqCountArray[frequency] = 0;
    
    /* this is alotting the frequencies : */
    for(i = 0; i<n; ++i)
        ++freqCountArray[marks[i]];
    
        /* this is making the "table" : */
    for (frequency=0; frequency<11; ++frequency)
    {
        printf("%d |", frequency);
        for (slno = 0;
            slno < freqCountArray[frequency]; ++slno)
            printf("-");
            printf("\n");
    }
}
