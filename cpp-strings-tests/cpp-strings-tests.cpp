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
			Assert::AreEqual(pcs::CppWString(L"##zyxwvutsrqp##").c_str(), ws.center(15, L'#').c_str(), L"--11--");
			Assert::AreEqual(pcs::CppWString(L"#zyxwvutsrqp##").c_str(), ws.center(14, L'#').c_str(), L"--12--");
			Assert::AreEqual(pcs::CppWString(L"#zyxwvutsrqp#").c_str(), ws.center(13, L'#').c_str(), L"--13--");
			Assert::AreEqual(pcs::CppWString(L"zyxwvutsrqp#").c_str(), ws.center(12, L'#').c_str(), L"--14--");
			Assert::AreEqual(pcs::CppWString(L"zyxwvutsrqp").c_str(), ws.center(11, L'#').c_str(), L"--15--");
			Assert::AreEqual(pcs::CppWString(L"zyxwvutsrqp").c_str(), ws.center(10, L'#').c_str(), L"--16--");
		}

		TEST_METHOD(count)
		{
			pcs::CppString s("abcabcabcdefabca bca bcabca");
			Assert::AreEqual(3ULL, s.count("abca"));
			Assert::AreEqual(6ULL, s.count("bca"));
			Assert::AreEqual(0ULL, s.count("A"));
			Assert::AreEqual(2ULL, s.count("abca", 4));
			Assert::AreEqual(5ULL, s.count("bca", 2));
			Assert::AreEqual(0ULL, s.count("A", 3));
			Assert::AreEqual(1ULL, s.count("abca", 4, s.size() - 5));
			Assert::AreEqual(4ULL, s.count("bca", 2, s.size() - 2));
			Assert::AreEqual(0ULL, s.count("A", 3, s.size() + 4));

			pcs::CppWString ws(L"abcabcabcdefabca bca bcabca");
			Assert::AreEqual(3ULL, ws.count(L"abca"));
			Assert::AreEqual(6ULL, ws.count(L"bca"));
			Assert::AreEqual(0ULL, ws.count(L"A"));
			Assert::AreEqual(2ULL, ws.count(L"abca", 4));
			Assert::AreEqual(5ULL, ws.count(L"bca", 2));
			Assert::AreEqual(0ULL, ws.count(L"A", 3));
			Assert::AreEqual(1ULL, ws.count(L"abca", 4, s.size() - 5));
			Assert::AreEqual(4ULL, ws.count(L"bca", 2, s.size() - 2));
			Assert::AreEqual(0ULL, ws.count(L"A", 3, s.size() + 4));
		}

		TEST_METHOD(count_n)
		{
			pcs::CppString s("abcabcabcdefabca bca bcabca");
			const pcs::CppString::size_type len{ s.size() };
			Assert::AreEqual(3ULL, s.count_n("abca", 0, len));
			Assert::AreEqual(6ULL, s.count_n("bca", 0, len));
			Assert::AreEqual(0ULL, s.count_n("A", 0, len));
			Assert::AreEqual(2ULL, s.count_n("abca", 4, len - 4));
			Assert::AreEqual(5ULL, s.count_n("bca", 2, len - 2));
			Assert::AreEqual(0ULL, s.count_n("A", 3, len - 3));
			Assert::AreEqual(1ULL, s.count_n("abca", 4, len - 5));
			Assert::AreEqual(4ULL, s.count_n("bca", 2, len - 3));
			Assert::AreEqual(0ULL, s.count_n("A", 3, len + 4));

			pcs::CppWString ws(L"abcabcabcdefabca bca bcabca");
			const pcs::CppWString::size_type wlen{ ws.size() };
			Assert::AreEqual(3ULL, ws.count_n(L"abca", 0, wlen));
			Assert::AreEqual(6ULL, ws.count_n(L"bca", 0, wlen));
			Assert::AreEqual(0ULL, ws.count_n(L"A", 0, wlen));
			Assert::AreEqual(2ULL, ws.count_n(L"abca", 4, wlen - 4));
			Assert::AreEqual(5ULL, ws.count_n(L"bca", 2, wlen - 2));
			Assert::AreEqual(0ULL, ws.count_n(L"A", 3, wlen - 3));
			Assert::AreEqual(1ULL, ws.count_n(L"abca", 4, wlen - 5));
			Assert::AreEqual(4ULL, ws.count_n(L"bca", 2, wlen - 3));
			Assert::AreEqual(0ULL, ws.count_n(L"A", 3, wlen + 4));
		}

		TEST_METHOD(endswith)
		{
			pcs::CppString s("abcabcabcdefabca bca bcabca");
			const pcs::CppString::size_type len{ s.size() };
			Assert::IsTrue(s.endswith("abca"));
			Assert::IsFalse(s.endswith("abcabca"));
			Assert::IsTrue(s.endswith("abc", len - 1));
			Assert::IsFalse(s.endswith("bcabca", len - 1));
			Assert::IsTrue(s.endswith("abca", len - 4, len));
			Assert::IsFalse(s.endswith("abca", len - 4, len - 2));
			Assert::IsTrue(s.endswith({ "def", "ghi", "abca" }, len - 4, len));
			Assert::IsFalse(s.endswith({ "def", "ghi" }, len - 4, len));
			Assert::IsFalse(s.endswith({ "def", "ghi", "abca" }, len - 4, len - 2));

			pcs::CppWString ws(L"abcabcabcdefabca bca bcabca");
			const pcs::CppWString::size_type wlen{ ws.size() };
			Assert::IsTrue(ws.endswith(L"abca"));
			Assert::IsFalse(ws.endswith(L"abcabca"));
			Assert::IsTrue(ws.endswith(L"abc", wlen - 1));
			Assert::IsFalse(ws.endswith(L"bcabca", wlen - 1));
			Assert::IsTrue(ws.endswith(L"abca", wlen - 4, wlen));
			Assert::IsFalse(ws.endswith(L"abca", wlen - 4, wlen - 2));
			Assert::IsTrue(ws.endswith({ L"def", L"ghi", L"abca" }, len - 4, len));
			Assert::IsFalse(ws.endswith({ L"def", L"ghi" }, len - 4, len));
			Assert::IsFalse(ws.endswith({ L"def", L"ghi", L"abca" }, len - 4, len - 2));
		}

		TEST_METHOD(endswith_n)
		{
			pcs::CppString s("abcabcabcdefabca bca bcabca");
			const pcs::CppString::size_type len{ s.size() };
			Assert::IsTrue(s.endswith_n("abc", len - 1));
			Assert::IsFalse(s.endswith_n("bcabca", len - 1));
			Assert::IsTrue(s.endswith_n("abca", len - 4, 4));
			Assert::IsFalse(s.endswith_n("abca", len - 4, 3));
			Assert::IsTrue(s.endswith_n({ "def", "ghi", "abca" }, len - 4, 4));
			Assert::IsFalse(s.endswith_n({ "def", "ghi" }, len - 4, 4));
			Assert::IsFalse(s.endswith_n({ "def", "ghi", "abca" }, len - 4, 3));

			pcs::CppWString ws(L"abcabcabcdefabca bca bcabca");
			const pcs::CppWString::size_type wlen{ ws.size() };
			Assert::IsTrue(ws.endswith_n(L"abc", wlen - 1));
			Assert::IsFalse(ws.endswith_n(L"bcabca", wlen - 1));
			Assert::IsTrue(ws.endswith_n(L"abca", wlen - 4, 4));
			Assert::IsFalse(ws.endswith_n(L"abca", wlen - 4, 3));
			Assert::IsTrue(ws.endswith_n({ L"def", L"ghi", L"abca" }, len - 4, 4));
			Assert::IsFalse(ws.endswith_n({ L"def", L"ghi" }, len - 4, 4));
			Assert::IsFalse(ws.endswith_n({ L"def", L"ghi", L"abca" }, len - 4, 3));
		}

		TEST_METHOD(expand_tabs)
		{
			pcs::CppString s("a\tbc\tdef\tghij\t\r\tk\nl\tm\r\nno\tpqr \ts.");
			pcs::CppString ts = s.expand_tabs(4);
			Assert::AreEqual(CppString("a   bc  def ghij    \r    k\nl   m\r\nno  pqr     s.").c_str(), ts.c_str());
			ts = s.expand_tabs(3);
			Assert::AreEqual(CppString("a  bc def   ghij  \r   k\nl  m\r\nno pqr   s.").c_str(), ts.c_str());
			ts = s.expand_tabs(2);
			Assert::AreEqual(CppString("a bc  def ghij  \r  k\nl m\r\nno  pqr   s.").c_str(), ts.c_str());
			ts = s.expand_tabs(1);
			Assert::AreEqual(CppString("a bc def ghij \r k\nl m\r\nno pqr  s.").c_str(), ts.c_str());

			pcs::CppWString ws(L"a\tbc\tdef\tghij\t\r\tk\nl\tm\r\nno\tpqr \ts.");
			pcs::CppWString wts = ws.expand_tabs(4);
			Assert::AreEqual(CppWString(L"a   bc  def ghij    \r    k\nl   m\r\nno  pqr     s.").c_str(), wts.c_str());
			wts = ws.expand_tabs(3);
			Assert::AreEqual(CppWString(L"a  bc def   ghij  \r   k\nl  m\r\nno pqr   s.").c_str(), wts.c_str());
			wts = ws.expand_tabs(2);
			Assert::AreEqual(CppWString(L"a bc  def ghij  \r  k\nl m\r\nno  pqr   s.").c_str(), wts.c_str());
			wts = ws.expand_tabs(1);
			Assert::AreEqual(CppWString(L"a bc def ghij \r k\nl m\r\nno pqr  s.").c_str(), wts.c_str());
		}

	};
}
