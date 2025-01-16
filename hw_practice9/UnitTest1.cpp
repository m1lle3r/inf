#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        int sumOfDigits(int num) {
            int b = 0;
            while (num != 0) {
                b += num % 10;
                num /= 10;
            }
            return b;
        }

        TEST_METHOD(isSumCorrect)
        {
            int a = 1234;
            int expectedSum = 10;
            Assert::AreEqual(sumOfDigits(a), expectedSum);
        }

        TEST_METHOD(isSumForZero)
        {
            int a = 0;
            int expectedSum = 0;
            Assert::AreEqual(sumOfDigits(a), expectedSum);
        }

        TEST_METHOD(isSumForSingleDigit)
        {
            int a = 5;
            int expectedSum = 5;
            Assert::AreEqual(sumOfDigits(a), expectedSum);
        }

        TEST_METHOD(isSumForLargeNumber)
        {
            int a = 987654321;
            int expectedSum = 45;
            Assert::AreEqual(sumOfDigits(a), expectedSum);
        }

        TEST_METHOD(isSumForNegativeNumber)
        {
            int a = -123;
            int expectedSum = 6;
            Assert::AreEqual(sumOfDigits(a), expectedSum);
        }

        TEST_METHOD(isInputProcessingCorrect)
        {
            std::string input = "5678";
            std::istringstream inputStream(input);
            int num;
            inputStream >> num;
            int expectedSum = 26;
            Assert::AreEqual(sumOfDigits(num), expectedSum);
        }
    };
}
