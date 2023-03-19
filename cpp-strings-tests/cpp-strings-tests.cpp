#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "cppstrings.h"
using namespace pcs;


namespace cppstringstests
{
	TEST_CLASS(cppstringstests_PART_3)
	{
	public:
		
		TEST_METHOD(constructor_empty)
		{
			pcs::CppString s;
			Assert::IsTrue(s.empty());

			pcs::CppWString ws;
			Assert::IsTrue(ws.empty());
		}


	};
}
