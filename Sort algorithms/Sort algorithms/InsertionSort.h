#pragma once
#include "AbstractSort.h"

// insertion sort class
class InsertionSort :
    public AbstractSort
{
public:
    void sort(std::vector<int>& inArray) override;
};

