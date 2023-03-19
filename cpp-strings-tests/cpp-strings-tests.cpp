#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "cppstrings.h"
using namespace pcs;


namespace cppstringstests
{
	TEST_CLASS(cppstringstests_PART_4)
	{
	public:
		
		TEST_METHOD(capitalize)
		{
			pcs::CppString s("abc def GHi jKl 032, JHGF/");
			Assert::AreEqual(pcs::CppString("Abc def ghi jkl 032, jhgf/").c_str(), s.capitalize().c_str());

			s = "capitalize Capitalize. CAPITALIZE";
			Assert::AreEqual(pcs::CppString("Capitalize capitalize. capitalize").c_str(), s.capitalize().c_str());

			pcs::CppWString ws(L"123AHBl!");
			Assert::AreEqual(pcs::CppWString(L"123ahbl!").c_str(), ws.capitalize().c_str());
		}

		TEST_METHOD(center)
		{
			pcs::CppString s("zyxwvutsrqp");
			Assert::AreEqual(pcs::CppString("  zyxwvutsrqp  ").c_str(), s.center(15).c_str(), L"--1--");
			Assert::AreEqual(pcs::CppString(" zyxwvutsrqp  ").c_str(), s.center(14).c_str(), L"--2--");
			Assert::AreEqual(pcs::CppString(" zyxwvutsrqp ").c_str(), s.center(13).c_str(), L"--3--");
			Assert::AreEqual(pcs::CppString("zyxwvutsrqp ").c_str(), s.center(12).c_str(), L"--4--");
			Assert::AreEqual(pcs::CppString("zyxwvutsrqp").c_str(), s.center(11).c_str(), L"--5--");
			Assert::AreEqual(pcs::CppString("zyxwvutsrqp").c_str(), s.center(10).c_str(), L"--6--");

			pcs::CppWString ws(L"zyxwvutsrqp");
			Assert::AreEqual(pcs::CppWString(L"  zyxwvutsrqp  ").c_str(), ws.center(15).c_str(), L"--1--");
			Assert::AreEqual(pcs::CppWString(L" zyxwvutsrqp  ").c_str(), ws.center(14).c_str(), L"--2--");
			Assert::AreEqual(pcs::CppWString(L" zyxwvutsrqp ").c_str(), ws.center(13).c_str(), L"--3--");
			Assert::AreEqual(pcs::CppWString(L"zyxwvutsrqp ").c_str(), ws.center(12).c_str(), L"--4--");
			Assert::AreEqual(pcs::CppWString(L"zyxwvutsrqp").c_str(), ws.center(11).c_str(), L"--5--");
			Assert::AreEqual(pcs::CppWString(L"zyxwvutsrqp").c_str(), ws.center(10).c_str(), L"--6--");
		}


	};
}
