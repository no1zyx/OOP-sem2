#include "HeapSort.h"

void HeapSort::sort(std::vector<int>& inArray)
{
	heapSort(inArray, inArray.size() - 1);
}

// heap sort realization
void HeapSort::heapSort(std::vector<int>& inArray, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(inArray, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(inArray[0], inArray[i]);

        heapify(inArray, i, 0);
    }
}

// help function for building heaps
void HeapSort::heapify(std::vector<int>& inArray, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && inArray[l] > inArray[largest])
        largest = l;

    if (r < n && inArray[r] > inArray[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(inArray[i], inArray[largest]);

        heapify(inArray, n, largest);
    }
}
