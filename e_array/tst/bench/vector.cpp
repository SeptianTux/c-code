#include <iostream> 
#include <vector>

#include "bench-data.h"

using namespace std; 

int main ()
{
    int i, j;
    vector<string> *s = new vector<string>;
    
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
