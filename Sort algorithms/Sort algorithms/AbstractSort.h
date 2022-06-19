#pragma once
#include <vector>

// abstract class for sort
class AbstractSort
{
public:
	// sorts input array
	virtual void sort(std::vector<int>& inArray) = 0;
};