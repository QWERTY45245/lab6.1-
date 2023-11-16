#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTestlab61
{
	TEST_CLASS(UnitTestlab61)
	{
	public:

		// Тест для функції generateArray
		TEST_METHOD(GenerateArrayTest)
		{
			const int testSize = 10;
			int testArray[testSize];
			generateArray(testArray, testSize);

			for (int i = 0; i < testSize; ++i) {
				Assert::IsTrue(testArray[i] >= LOWER_BOUND && testArray[i] <= UPPER_BOUND);
			}
		}

		// Тест для функції processArray
		TEST_METHOD(ProcessArrayTest)
		{
			const int testSize = 5;
			int testArray[testSize] = { -5, -4, -3, -2, -1 };
			int testCount, testSum;
			processArray(testArray, testSize, testCount, testSum);

			Assert::AreEqual(testCount, 2);
			Assert::AreEqual(testSum, -6);
		}

		// Тест для функції modifyArray
		TEST_METHOD(ModifyArrayTest)
		{
			const int testSize = 6;
			int testArray[testSize] = { -2, -3, 4, 5, -6, 7 };
			modifyArray(testArray, testSize);

			for (int i = 0; i < testSize; ++i) {
				if (testArray[i] <= 0 && testArray[i] % 2 == 0) {
					Assert::AreEqual(testArray[i], 0);
				}
			}
		}
	};
}

