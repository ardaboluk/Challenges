
#pragma once

class QuickSort {

private:
	void mySwap(int*, int, int);
	int myPartition(int*, int, int);

public:
	void sort(int* p_array, int startInd, int endInd);
};
