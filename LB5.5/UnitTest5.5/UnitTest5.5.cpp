#include "pch.h"
#include "CppUnitTest.h"
#include "../LB5.5/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
	TEST_CLASS(UnitTest55)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double result = f(3);
			Assert::AreEqual(result, 1.13111, 0.001);
		}
	};
}
