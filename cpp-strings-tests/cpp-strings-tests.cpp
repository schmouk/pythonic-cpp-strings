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

		TEST_METHOD(constructor_copy)
		{
			pcs::CppString cs("ABCde");
			pcs::CppString s(cs);
			Assert::AreEqual(cs.c_str(), s.c_str());

			pcs::CppWString wcs(L"abcDE");
			pcs::CppWString ws(wcs);
			Assert::AreEqual(wcs.c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_move)
		{
			pcs::CppString cs("ABCde");
			pcs::CppString s(std::move(cs));
			Assert::AreEqual(pcs::CppString("ABCde").c_str(), s.c_str());

			pcs::CppWString wcs(L"abcDE");
			pcs::CppWString ws(std::move(wcs));
			Assert::AreEqual(pcs::CppWString(L"abcDE").c_str(), ws.c_str());
		}

	};
}
