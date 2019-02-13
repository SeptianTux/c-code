#include <stdio.h>

#include "e_arr.h"

int main (void)
{
    E_ARR *e_arr;
    int add, i=0;
    
    /*
    // string test
    e_arr = e_arr_init (E_ARR_TYPE_STRING);
    
    add = e_arr_add_end (&e_arr, "satu");
    add = e_arr_add_end (&e_arr, "dua");
    add = e_arr_add_end (&e_arr, "tiga");
    add = e_arr_add_end (&e_arr, "empat");
    add = e_arr_add_end (&e_arr, "lima");
    add = e_arr_add_end (&e_arr, "enam");
    add = e_arr_add_end (&e_arr, "tujuh");
    
    //add = e_arr_add_pos (&e_arr, 0, "nol");
    //add = e_arr_add_first (&e_arr, "hehe");
    //add = e_arr_del_pos (&e_arr, 5);
    //add = e_arr_add_pos (&e_arr, 9, "anu");
    //add = e_arr_replace (&e_arr, 1, "replace");
    
    
    while (e_arr->value[i] != NULL)
        printf ("%s\n", (char *)e_arr->value[i++]);
    */
    
    
    // int test
    e_arr = e_arr_init (E_ARR_TYPE_INT);
    
    add = e_arr_add_pos (&e_arr, 0, 7);
    add = e_arr_add_pos (&e_arr, 1, 8);
    add = e_arr_add_pos (&e_arr, 2, 9);
    add = e_arr_add_pos (&e_arr, 1, -7);
    add = e_arr_add_first (&e_arr, -8);
    
    while (e_arr->value[i] != NULL)
        printf ("%d\n", *(int *)e_arr->value[i++]);
    
    
    add = e_arr_destroy (&e_arr);
    
    //printf ("%d\n", add);
    
    return 0;
}
