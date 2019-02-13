#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bench-data.h"

int main (void)
{
    int h, i, j;
    
    char **a = malloc(sizeof (*a)*(ARR_SIZE*400));
    
    h = 0;
    for (i=0; i<400; i++)
    {
        for (j=0; j<ARR_SIZE; j++)
        {
            a[h] = strdup (data[j]);
            h++;
        }
    }
    a[h] = NULL;
    
    int stop = ARR_SIZE*400;
    
    for (h=0; h<stop; h++)
    {
        free (a[h]);
    }
    free (a);
    a = NULL;
    
    return 0;
}
