#include "pch.h"
#include "CppUnitTest.h"
#include "..//Challenges/TimeConversion.h"
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ChallengesTest
{
	TEST_CLASS(TimeConversionTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			TimeConversion timeConerter;
			vector<string> test_vector_12;
			vector<string> test_vector_24;

			Assert::AreEqual(timeConerter.timeConversion("12:00:00AM"), string("00:00:00"));
			Assert::AreEqual(timeConerter.timeConversion("12:01:10AM"), string("00:01:10"));
			Assert::AreEqual(timeConerter.timeConversion("01:00:10AM"), string("01:00:10"));
			Assert::AreEqual(timeConerter.timeConversion("02:45:12AM"), string("02:45:12"));
			Assert::AreEqual(timeConerter.timeConversion("03:59:59AM"), string("03:59:59"));
			Assert::AreEqual(timeConerter.timeConversion("04:01:00AM"), string("04:01:00"));
			Assert::AreEqual(timeConerter.timeConversion("05:10:00AM"), string("05:10:00"));
			Assert::AreEqual(timeConerter.timeConversion("11:05:00AM"), string("11:05:00"));
			Assert::AreEqual(timeConerter.timeConversion("11:59:00AM"), string("11:59:00"));
			Assert::AreEqual(timeConerter.timeConversion("12:00:00PM"), string("12:00:00"));
			Assert::AreEqual(timeConerter.timeConversion("12:01:01PM"), string("12:01:01"));
			Assert::AreEqual(timeConerter.timeConversion("01:00:00PM"), string("13:00:00"));
			Assert::AreEqual(timeConerter.timeConversion("02:01:01PM"), string("14:01:01"));
			Assert::AreEqual(timeConerter.timeConversion("03:10:10PM"), string("15:10:10"));
			Assert::AreEqual(timeConerter.timeConversion("04:15:12PM"), string("16:15:12"));
			Assert::AreEqual(timeConerter.timeConversion("05:59:59PM"), string("17:59:59"));
			Assert::AreEqual(timeConerter.timeConversion("11:59:00PM"), string("23:59:00"));
		}
	};
}
