#include "QuickSort.h"

void QuickSort::sort(std::vector<int>& inArray)
{
    quickSort(inArray, 0, inArray.size() - 1);
}

// recursion quick sort function
void QuickSort::quickSort(std::vector<int>& inArray, int l, int r)
{
    int i = l, j = r;
    int pivot = inArray[(l + r) / 2];

    /* partition */
    while (i <= j) 
    {
        while (inArray[i] < pivot)
            i++;
        while (inArray[j] > pivot)
            j--;
        if (i <= j) 
        {
            std::swap(inArray[i], inArray[j]);
            i++;
            j--;
        }
    };

    /* recursion */
    if (l < j)
        quickSort(inArray, l, j);
    if (i < r)
        quickSort(inArray, i, r);
}
