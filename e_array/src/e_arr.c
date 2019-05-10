#include "e_arr.h"

E_ARR *e_arr_init (E_ARR_TYPE typ)
{
    E_ARR *e_arr;
    
    e_arr = malloc (sizeof (*e_arr));
    e_arr->value = malloc (sizeof (*e_arr->value)*E_ARR_ALLOCATE_SIZE);
    
    e_arr->size = 0;
    e_arr->allocated_size = E_ARR_ALLOCATE_SIZE;
    e_arr->type = typ;
    e_arr->value[0] = NULL;
    
    return e_arr;
}

int e_arr_realloc (E_ARR **ptr, unsigned int new_size)
{
    unsigned int n_size = new_size < E_ARR_ALLOCATE_SIZE ? E_ARR_ALLOCATE_SIZE : new_size;
    
    (*ptr)->value = realloc ((*ptr)->value, sizeof (*(*ptr)->value)*n_size);
    
    (*ptr)->allocated_size = n_size;
    
    return 0;
}

int e_arr_add_pos (E_ARR **ptr, unsigned int pos, ...)
{
    va_list ap;
    
    va_start (ap, pos);
    
    if (pos > ((*ptr)->size))
        return -1;
    
    if (((*ptr)->size+2) >= (*ptr)->allocated_size)
    {
        int ralloc = e_arr_realloc (&(*ptr), (*ptr)->allocated_size+E_ARR_ALLOCATE_SIZE);
        
        if (ralloc != 0)
            return ralloc;
    }
    
    if (pos <= (*ptr)->size)
    {
        int i = (*ptr)->size == 0 ? (*ptr)->size+1 : (*ptr)->size;
        
        while (i>pos)
        {
            (*ptr)->value[i] = (*ptr)->value[i-1];
            i--;
        }
        
        switch ((*ptr)->type)
        {
            case E_ARR_TYPE_UNSIGNED_INT        :   (*ptr)->value[pos] = malloc (sizeof (unsigned int));
                                                    (*(unsigned int *)(*ptr)->value[pos]) = (unsigned int)va_arg (ap, int);
                                                    break;
            case E_ARR_TYPE_INT                 :   (*ptr)->value[pos] = malloc (sizeof (int));
                                                    (*(int *)(*ptr)->value[pos]) = va_arg (ap, int);
                                                    break;
            case E_ARR_TYPE_DOUBLE              :   (*ptr)->value[pos] = malloc (sizeof (double));
                                                    (*(double *)(*ptr)->value[pos]) = va_arg (ap, double);
                                                    break;
            case E_ARR_TYPE_CHAR                :   (*ptr)->value[pos] = malloc (sizeof (char));
                                                    (*(char *)(*ptr)->value[pos]) = (char)va_arg (ap, int);
                                                    break;
            case E_ARR_TYPE_UNSIGNED_CHAR       :   (*ptr)->value[pos] = malloc (sizeof (unsigned char));
                                                    (*(unsigned char *)(*ptr)->value[pos]) = (unsigned char)va_arg (ap, int);
                                                    break;
            case E_ARR_TYPE_STRING              :   (*ptr)->value[pos] = (void *)strdup (va_arg (ap, char *));
                                                    break;
            default                             :   return -69;
                                                    break;
        }
    }
    
    (*ptr)->value[(*ptr)->size+1] = NULL;
    (*ptr)->size++;
    
    va_end (ap);
    
    return 0;
}

int e_arr_add_end (E_ARR **ptr, ...)
{
    va_list ap;
    
    va_start (ap, ptr);
    
    if (((*ptr)->size+2) >= (*ptr)->allocated_size)
    {
        int ralloc = e_arr_realloc (&(*ptr), (*ptr)->allocated_size+E_ARR_ALLOCATE_SIZE);
        
        if (ralloc != 0)
            return ralloc;
        
    }
    
    switch ((*ptr)->type)
    {
        case E_ARR_TYPE_UNSIGNED_INT        :   (*ptr)->value[(*ptr)->size] = malloc (sizeof (unsigned int));
                                                (*(unsigned int *)(*ptr)->value[(*ptr)->size]) = (unsigned int)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_INT                 :   (*ptr)->value[(*ptr)->size] = malloc (sizeof (int));
                                                (*(int *)(*ptr)->value[(*ptr)->size]) = va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_DOUBLE              :   (*ptr)->value[(*ptr)->size] = malloc (sizeof (double));
                                                (*(double *)(*ptr)->value[(*ptr)->size]) = va_arg (ap, double);
                                                break;
        case E_ARR_TYPE_CHAR                :   (*ptr)->value[(*ptr)->size] = malloc (sizeof (char));
                                                (*(char *)(*ptr)->value[(*ptr)->size]) = (char)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_UNSIGNED_CHAR       :   (*ptr)->value[(*ptr)->size] = malloc (sizeof (unsigned char));
                                                (*(unsigned char *)(*ptr)->value[(*ptr)->size]) = (unsigned char)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_STRING              :   (*ptr)->value[(*ptr)->size] = (void *)strdup (va_arg (ap, char *));
                                                break;
        default                             :   return -69;
                                                break;
    }
    
    (*ptr)->size++;
    (*ptr)->value[(*ptr)->size] = NULL;
    
    return 0;
}

int e_arr_add_first (E_ARR **ptr, ...)
{
    va_list ap;
    
    va_start (ap, ptr);
    
    if (((*ptr)->size+2) >= (*ptr)->allocated_size)
    {
        int ralloc = e_arr_realloc (&(*ptr), (*ptr)->allocated_size+E_ARR_ALLOCATE_SIZE);
        
        if (ralloc != 0)
            return ralloc;
    }
    

    unsigned int i = (*ptr)->size == 0 ? (*ptr)->size+1 : (*ptr)->size;
    
    while (i>0)
    {
        (*ptr)->value[i] = (*ptr)->value[i-1];
        i--;
    }
    
    switch ((*ptr)->type)
    {
        case E_ARR_TYPE_UNSIGNED_INT        :   (*ptr)->value[0] = malloc (sizeof (unsigned int));
                                                (*(unsigned int *)(*ptr)->value[0]) = (unsigned int)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_INT                 :   (*ptr)->value[0] = malloc (sizeof (int));
                                                (*(int *)(*ptr)->value[0]) = va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_DOUBLE              :   (*ptr)->value[0] = malloc (sizeof (double));
                                                (*(double *)(*ptr)->value[0]) = va_arg (ap, double);
                                                break;
        case E_ARR_TYPE_CHAR                :   (*ptr)->value[0] = malloc (sizeof (char));
                                                (*(char *)(*ptr)->value[0]) = (char)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_UNSIGNED_CHAR       :   (*ptr)->value[0] = malloc (sizeof (unsigned char));
                                                (*(unsigned char *)(*ptr)->value[0]) = (unsigned char)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_STRING              :   (*ptr)->value[0] = (void *)strdup (va_arg (ap, char *));
                                                break;
        default                             :   return -69;
                                                break;
    }
    
    (*ptr)->value[(*ptr)->size+1] = NULL;
    (*ptr)->size++;
    
    va_end (ap);
    
    return 0;
}

int e_arr_del_pos (E_ARR **ptr, unsigned int pos)
{
    int i=pos;
    
    if (i >= ((*ptr)->size))
        return -1;
    
    free ((*ptr)->value[i]);
    
    while (i<((*ptr)->size-1))
    {
        (*ptr)->value[i] = (*ptr)->value[i+1];
        i++;
    }
    
    (*ptr)->value[(*ptr)->size-1] = NULL;
    
    (*ptr)->size--;
    
    if (((*ptr)->size+E_ARR_ALLOCATE_SIZE) < (*ptr)->allocated_size)
    {
        if (e_arr_realloc (&(*ptr), (*ptr)->allocated_size-E_ARR_ALLOCATE_SIZE) != 0)
            return -2;
    }
    
    return i;
}

int e_arr_del_end (E_ARR **ptr)
{
    return e_arr_del_pos (&(*ptr), (*ptr)->size-1);
}

int e_arr_del_first (E_ARR **ptr)
{
    return e_arr_del_pos (&(*ptr), 0);
}

int e_arr_replace (E_ARR **ptr, unsigned int pos, ...)
{
    va_list ap;
    
    if (pos >= ((*ptr)->size))
        return -1;
    
    free ((*ptr)->value[pos]);
    
    va_start (ap, pos);
    
    switch ((*ptr)->type)
    {
        case E_ARR_TYPE_UNSIGNED_INT        :   (*ptr)->value[pos] = malloc (sizeof (unsigned int));
                                                (*(unsigned int *)(*ptr)->value[pos]) = (unsigned int)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_INT                 :   (*ptr)->value[pos] = malloc (sizeof (int));
                                                (*(int *)(*ptr)->value[pos]) = va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_DOUBLE              :   (*ptr)->value[pos] = malloc (sizeof (double));
                                                (*(double *)(*ptr)->value[pos]) = va_arg (ap, double);
                                                break;
        case E_ARR_TYPE_CHAR                :   (*ptr)->value[pos] = malloc (sizeof (char));
                                                (*(char *)(*ptr)->value[pos]) = (char)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_UNSIGNED_CHAR       :   (*ptr)->value[pos] = malloc (sizeof (unsigned char));
                                                (*(unsigned char *)(*ptr)->value[pos]) = (unsigned char)va_arg (ap, int);
                                                break;
        case E_ARR_TYPE_STRING              :   (*ptr)->value[pos] = (void *)strdup (va_arg (ap, char *));
                                                break;
        default                             :   return -69;
                                                break;
    }
    
    va_end (ap);
    
    return pos;
}

int e_arr_destroy (E_ARR **ptr)
{
    int i;
    
    if (!(*ptr))
        return -1;
    
    for (i=0; i<(*ptr)->size; i++)
        free ((*ptr)->value[i]);
    
    free ((*ptr)->value);
    free (*ptr);
    
    *ptr = NULL;
    
    return i;
}
 
    
