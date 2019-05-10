#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define E_ARR_ALLOCATE_SIZE   256

typedef enum
{
    E_ARR_TYPE_INT
    , E_ARR_TYPE_UNSIGNED_INT
    , E_ARR_TYPE_DOUBLE
    , E_ARR_TYPE_CHAR
    , E_ARR_TYPE_UNSIGNED_CHAR
    , E_ARR_TYPE_STRING
} E_ARR_TYPE;

typedef struct
{
    unsigned int size;
    unsigned int allocated_size;
    E_ARR_TYPE type;
    void **value;
} E_ARR;

E_ARR *e_arr_init (E_ARR_TYPE type);
int e_arr_realloc (E_ARR **ptr, unsigned int new_size);
int e_arr_add_pos (E_ARR **ptr, unsigned int pos, ...);
int e_arr_add_end (E_ARR **ptr, ...);
int e_arr_add_first (E_ARR **ptr, ...);
int e_arr_del_pos (E_ARR **ptr, unsigned int pos);
int e_arr_del_end (E_ARR **ptr);
int e_arr_del_first (E_ARR **ptr);
int e_arr_replace (E_ARR **ptr, unsigned int pos, ...);
int e_arr_destroy (E_ARR **ptr);  
