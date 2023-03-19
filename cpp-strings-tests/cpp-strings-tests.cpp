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

		TEST_METHOD(constructor_06)
		{
			pcs::CppString s(10, '-');
			Assert::AreEqual(std::size_t(10), s.size());
			Assert::AreEqual(pcs::CppString("----------").c_str(), s.c_str());

			pcs::CppWString ws(8, '=');
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"========").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_07)
		{
			pcs::CppString cs("abcDEfgh");
			pcs::CppString s(cs, 3);
			Assert::AreEqual(std::size_t(5), s.size());
			Assert::AreEqual(pcs::CppString("DEfgh").c_str(), s.c_str());

			pcs::CppWString wcs(L"ABCdefGH");
			pcs::CppWString ws(wcs, 4);
			Assert::AreEqual(std::size_t(4), ws.size());
			Assert::AreEqual(pcs::CppWString(L"efGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_08)
		{
			pcs::CppString cs("abcDEfgh");
			pcs::CppString s(cs, 3, 2);
			Assert::AreEqual(std::size_t(2), s.size());
			Assert::AreEqual(pcs::CppString("DE").c_str(), s.c_str());

			pcs::CppWString wcs(L"ABCdefGH");
			pcs::CppWString ws(wcs, 4, 6);
			Assert::AreEqual(std::size_t(4), ws.size());
			Assert::AreEqual(pcs::CppWString(L"efGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_09)
		{
			pcs::CppString s("abcDEfgh");
			Assert::AreEqual(std::size_t(8), s.size());
			Assert::AreEqual(pcs::CppString("abcDEfgh").c_str(), s.c_str());

			pcs::CppWString ws(L"ABCdefGH");
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefGH").c_str(), ws.c_str());
		}


	};
}
