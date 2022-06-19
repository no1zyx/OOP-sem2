#pragma once
#include "AbstractSort.h"

// heap sort class
class HeapSort :
    public AbstractSort
{
public:
    void sort(std::vector<int>& inArray) override;
private:
    void heapSort(std::vector<int>& inArray, int n);
    void heapify(std::vector<int>& inArray, int n, int i);
};

