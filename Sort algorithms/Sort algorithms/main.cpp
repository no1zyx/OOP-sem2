#pragma once
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

#include <memory>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 2)
		return 0;
	
	std::vector<std::unique_ptr<AbstractSort>> sorts;

	sorts.push_back(std::make_unique<InsertionSort>());
	sorts.push_back(std::make_unique<BubbleSort>());
	sorts.push_back(std::make_unique<QuickSort>());
	sorts.push_back(std::make_unique<HeapSort>());
	
	std::vector<int> arr{ 3, 1, 5, 2, 6, 5 };

	int num;

	// check input args
	try
	{
		num = std::stoi(argv[1]);
	}
	catch(...)
	{
		return 0;
	}

	if (num < 0 || num > sorts.size() - 1)
		return 0;

	// sort array
	sorts[num]->sort(arr);

	// print result array
	for (auto el : arr)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;

	return 1;
}