#include "pch.h"
#include "CppUnitTest.h"
#include "D:/PROJECT/lab6.4(1)/lab6.4(1)/lab6.4(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			double a[n] = { -1.5, 4.86, 6.5, -3.9, 10.5 };
			int indexmin = 0;
			double min = a[0];
			IndMin(a, n, indexmin, min);

			Assert::AreEqual(0, indexmin);
		}
	};
}
