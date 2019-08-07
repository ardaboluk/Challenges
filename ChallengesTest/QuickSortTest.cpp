#include "pch.h"
#include "CppUnitTest.h"
#include "..//Challenges/QuickSort.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ChallengesTest
{
	TEST_CLASS(QuickSortTest)
	{

	private:

		void dynamicArrayToVector(vector<int> result_vector, int* p_array, int p_size) {
			for (int i = 0; i < p_size; i++) {
				result_vector.push_back(p_array[i]);
			}
		}

	public:

		int numTestCases = 10;
		int testArrayLength = 50;
		int MAX_INT = 10000;

		TEST_METHOD(TestMethod1)
		{
			QuickSort myQuickSort;

			int* randArrayUnsorted = new int[testArrayLength];
			int* randArraySorted = new int[testArrayLength];
			vector<int> randVectorUnsorted;
			vector<int> randVectorSorted;

			for (int i = 0; i < numTestCases; i++) {
				srand((unsigned int)time(0));
				for (int j = 0; j < testArrayLength; j++) {
					randArrayUnsorted[j] = rand() % MAX_INT;
				}

				copy(randArraySorted, randArraySorted + testArrayLength, randArrayUnsorted);
				myQuickSort.sort(randArraySorted, 0, testArrayLength);

				dynamicArrayToVector(randVectorUnsorted, randArrayUnsorted, testArrayLength);
				dynamicArrayToVector(randVectorSorted, randArraySorted, testArrayLength);
				Assert::AreEqual(true, randVectorUnsorted == randVectorSorted);				
			}

			delete[] randArrayUnsorted;
			delete[] randArraySorted;
		}
	};
}
