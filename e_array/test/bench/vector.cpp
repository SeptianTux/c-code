#include <iostream> 
#include <vector>

#include "bench-data.h"

int main ()
{
    int i, j;
    std::vector<std::string> *s = new std::vector<std::string>;

    assignData();

    for (i=0; i<400; i++)
    {
        for (j=0; j<ARR_SIZE; j++)
        {
            s->push_back (data[j]);
        }
    }
    
    delete s;
    
    return 0;
}
