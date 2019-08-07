
#include <iostream>
#include "QuickSort.h"

using namespace std;

void QuickSort::mySwap(int* p_array, int ind1, int ind2) {
	int tmp = p_array[ind1];
	p_array[ind1] = p_array[ind2];
	p_array[ind2] = tmp;
}

int QuickSort::myPartition(int* p_array, int startInd, int endInd) {
	int pivot = p_array[endInd];
	int i = startInd - 1;
	for (int j = startInd; j <= endInd - 1; j++) {
		if (p_array[j] <= pivot) {
			i++;
			mySwap(p_array, i, j);
		}
	}
	mySwap(p_array, i + 1, endInd);
	return i + 1;
}

void QuickSort::sort(int* p_array, int startInd, int endInd) {
	if (startInd < endInd) {
		int pi = myPartition(p_array, startInd, endInd);
		sort(p_array, startInd, pi - 1);
		sort(p_array, pi + 1, endInd);
	}
}
