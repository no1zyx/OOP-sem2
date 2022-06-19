#include "InsertionSort.h"

// insertion sort realization
void InsertionSort::sort(std::vector<int>& inArray)
{
    int i, j;
    for (i = 1; i < inArray.size(); i++) 
    {
        j = i;
        while (j > 0 && inArray[j - 1] > inArray[j]) 
        {
            std::swap(inArray[j], inArray[j - 1]);
            j--;
        }
    }
}
