#pragma once
#include "AbstractSort.h"

// Bubble sort class
class BubbleSort:
    public AbstractSort
{
public:
    void sort(std::vector<int>& inArray) override;
};

