#include "BubbleSort.h"

// bubble sort realization
void BubbleSort::sort(std::vector<int>& inArray)
{
    int i, j;

    for (i = 1; i < inArray.size(); i++) 
    {
        for (j = 0; j < inArray.size() - i; j++) 
        {
            if (inArray[j] > inArray[j + 1]) 
            {
                std::swap(inArray[j], inArray[j + 1]);
            }
        }
    }
}
