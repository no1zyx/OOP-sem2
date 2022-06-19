#include "pch.h"

#include "InsertionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

class SortTest : public ::testing::Test {
protected:

public:
    std::vector<int> arr{ 3, 1, 2, 6, 6, 3 };
    std::vector<int> correctArr{1, 2, 3, 3, 6, 6};
    const int size = 6;
};

TEST_F(SortTest, CheckInsertionSortResultSize) {
    InsertionSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr.size(), size);
}

TEST_F(SortTest, CheckInsertionSortResultVector) {
    InsertionSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr, correctArr);
}

TEST_F(SortTest, CheckBubbleSortResultSize) {
    BubbleSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr.size(), size);
}

TEST_F(SortTest, CheckBubbleSortResultVector) {
    BubbleSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr, correctArr);
}

TEST_F(SortTest, CheckQuickSortResultSize) {
    QuickSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr.size(), size);
}

TEST_F(SortTest, CheckQuickSortResultVector) {
    QuickSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr, correctArr);
}

TEST_F(SortTest, CheckHeapSortResultSize) {
    HeapSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr.size(), size);
}

TEST_F(SortTest, CheckHeapSortResultVector) {
    HeapSort sort;
    sort.sort(arr);
    EXPECT_EQ(arr, correctArr);
}
