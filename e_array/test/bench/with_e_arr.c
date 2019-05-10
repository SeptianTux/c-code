#include <stdio.h>

#include "../../src/e_arr.h"

#include "bench-data.h"

int main (void)
{
    E_ARR *v;
    int i, j;
    
    v = e_arr_init (E_ARR_TYPE_STRING);
    
    assignData ();
    
    for (i=0; i<400; i++)
    {
        for (j=0; j<ARR_SIZE; j++)
        {
            e_arr_add_end (&v, data[j]);
            j++;
        }
    }
    
    e_arr_destroy (&v);
    
    return 0;
}
    
    
