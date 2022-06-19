#pragma once
#include "AbstractSort.h"

// quick sort class
class QuickSort :
    public AbstractSort
{
public:
    void sort(std::vector<int>& inArray) override;
private:
    void quickSort(std::vector<int>& inArray, int l, int r);
};

