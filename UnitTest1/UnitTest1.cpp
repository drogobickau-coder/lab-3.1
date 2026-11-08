#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-3.1/Complex.h" 
#include "../lab-3.1/Pair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestComplexMultiplication)
        {
            Complex c1(1.0, 2.0);
            Complex c2(3.0, 4.0);

            Complex result = c1 * c2;

            Assert::AreEqual(-5.0, result.getFirst());
            Assert::AreEqual(10.0, result.getSecond());
        }

        TEST_METHOD(TestComplexSubtraction)
        {
            Complex c1(5.5, 6.5);
            Complex c2(2.0, 3.0);

            Complex result = c1 - c2;

            Assert::AreEqual(3.5, result.getFirst());
            Assert::AreEqual(3.5, result.getSecond());
        }

        TEST_METHOD(TestPairMultiplyFields)
        {
            Pair p(4.0, 2.5);

            double result = p.multiplyFields();

            Assert::AreEqual(10.0, result);
        }
    };
}