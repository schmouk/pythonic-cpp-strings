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

		TEST_METHOD(find)
		{
			size_t found_pos;

			pcs::CppString test{ "ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test.MyBaseClass::find(ch), test.find(ch));

				found_pos = test.substr(2).MyBaseClass::find(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.find(ch, 2));
				else
					Assert::AreEqual(found_pos, test.find(ch, 2) - 2);
				
				found_pos = test.substr(2, 5).MyBaseClass::find(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.find(ch, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test.find(ch, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				CppString s(ch);
				Assert::AreEqual(test.MyBaseClass::find(s), test.find(s));
				found_pos = test.substr(2).MyBaseClass::find(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.find(s, 2));
				else
					Assert::AreEqual(found_pos, test.find(s, 2) - 2);

				found_pos = test.substr(2, 5).MyBaseClass::find(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.find(s, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test.find(s, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				if (c > 0) {
					char str[2]{ ch, 0 };
					Assert::AreEqual(test.MyBaseClass::find(str), test.find(str));

					found_pos = test.substr(2).MyBaseClass::find(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test.find(str, 2));
					else
						Assert::AreEqual(found_pos, test.find(str, 2) - 2);

					found_pos = test.substr(2, 5).MyBaseClass::find(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test.find(str, 2, pcs::CppString::size_type(5 + 2 - 1)));
					else
						Assert::AreEqual(found_pos, test.find(str, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);
				}
			}
			Assert::AreEqual(pcs::CppString::npos, test.find("A", 1));
			Assert::AreEqual(size_t(0), test.find(""));
			Assert::AreEqual(pcs::CppString::npos, test.find(".", 14));
			Assert::AreEqual(size_t(13), test.find(".", 13));

			pcs::CppWString wtest{ L"ABC0123456789." };
			for (int wc = 0; wc <=0xffff; ++wc) {
				wchar_t wch{ wchar_t(wc) };

				found_pos = wtest.substr(2).MyBaseClass::find(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find(wch, 2));
				else
					Assert::AreEqual(found_pos, wtest.find(wch, 2) - 2);

				found_pos = wtest.substr(2, 5).MyBaseClass::find(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find(wch, 2, pcs::CppWString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, wtest.find(wch, 2, pcs::CppWString::size_type(5 + 2 - 1)) - 2);

				CppWString ws(wch);
				Assert::AreEqual(wtest.MyBaseClass::find(ws), wtest.find(ws));

				found_pos = wtest.substr(2).MyBaseClass::find(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find(ws, 2));
				else
					Assert::AreEqual(found_pos, wtest.find(ws, 2) - 2);

				found_pos = wtest.substr(2, 5).MyBaseClass::find(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find(ws, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, wtest.find(ws, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);


				if (wc > 0) {
					wchar_t wstr[2]{ wch, 0 };
					Assert::AreEqual(wtest.MyBaseClass::find(wstr), wtest.find(wstr));

					found_pos = wtest.substr(2).MyBaseClass::find(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.find(wstr, 2));
					else
						Assert::AreEqual(found_pos, wtest.find(wstr, 2) - 2);

					found_pos = wtest.substr(2, 5).MyBaseClass::find(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.find(wstr, 2, pcs::CppString::size_type(5 + 2 - 1)));
					else
						Assert::AreEqual(found_pos, wtest.find(wstr, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);
				}
			}
			Assert::AreEqual(pcs::CppString::npos, wtest.find(L"A", 1));
			Assert::AreEqual(size_t(0), wtest.find(L""));
			Assert::AreEqual(pcs::CppString::npos, wtest.find(L".", 14));
			Assert::AreEqual(size_t(13), wtest.find(L".", 13));
		}

		TEST_METHOD(find_n)
		{
			// notice: find_n() is fully tested via TEST_METHOD(find)
			pcs::CppString test{ "ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test.substr(2).MyBaseClass::find(ch), test.find_n(ch, 2, -1));
				Assert::AreEqual(test.substr(0, 2).MyBaseClass::find(ch), test.find_n(ch, 2));
				Assert::AreEqual(test.substr(2, 5).MyBaseClass::find(ch), test.find_n(ch, 2, 5));

				CppString s(ch);
				Assert::AreEqual(test.substr(2).MyBaseClass::find(s), test.find_n(s, 2, -1));
				Assert::AreEqual(test.substr(0, 2).MyBaseClass::find(s), test.find_n(s, 2));
				Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(s), test.find_n(s, 3, 5));

				char str[2]{ ch, 0 };
				Assert::AreEqual(test.substr(2).MyBaseClass::find(str), test.find_n(str, 2, -1));
				Assert::AreEqual(test.substr(0, 2).MyBaseClass::find(str), test.find_n(str, 2));
				Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(str), test.find_n(str, 3, 5));
			}

			pcs::CppWString wtest{ L"ABC0123456789." };
			for (int wc = 0; wc <= 0xffff; ++wc) {
				wchar_t wch{ wchar_t(wc) };
				Assert::AreEqual(wtest.substr(2).MyBaseClass::find(wch), wtest.find_n(wch, 2, -1));
				Assert::AreEqual(wtest.substr(0, 2).MyBaseClass::find(wch), wtest.find_n(wch, 2));
				Assert::AreEqual(wtest.substr(2, 5).MyBaseClass::find(wch), wtest.find_n(wch, 2, 5));

				CppWString ws(wch);
				Assert::AreEqual(wtest.substr(2).MyBaseClass::find(ws), wtest.find_n(ws, 2, -1));
				Assert::AreEqual(wtest.substr(0, 2).MyBaseClass::find(ws), wtest.find_n(ws, 2));
				Assert::AreEqual(wtest.substr(3, 5).MyBaseClass::find(ws), wtest.find_n(ws, 3, 5));

				wchar_t wstr[2]{ wch, 0 };
				Assert::AreEqual(wtest.substr(2).MyBaseClass::find(wstr), wtest.find_n(wstr, 2, -1));
				Assert::AreEqual(wtest.substr(0, 2).MyBaseClass::find(wstr), wtest.find_n(wstr, 2));
				Assert::AreEqual(wtest.substr(3, 5).MyBaseClass::find(wstr), wtest.find_n(wstr, 3, 5));
			}
		}

		TEST_METHOD(index_char)
		{
			using string_type = pcs::CppString;

			string_type test{ "ABC0123456789." };
			char ch{ '3' };
			Assert::AreEqual(test.MyBaseClass::find(ch), test.index(ch));
			Assert::AreEqual(test.substr(2).MyBaseClass::find(ch), test.index(ch, 2));
			Assert::AreEqual(test.substr(2, 5).MyBaseClass::find(ch), test.index(ch, 2, string_type::size_type(5 + 2 - 1)));
			try {
				const string_type::size_type pos = test.index('z');
				Assert::IsTrue(pos != pcs::CppString::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index('z', 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index('z', 2, 5+2-1);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test.MyBaseClass::find(s), test.index(s));
			Assert::AreEqual(test.substr(2).MyBaseClass::find(s), test.index(s, 2));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(s), test.index(s, 3, string_type::size_type(5 + 3 - 1)));
			s = 'z';
			try {
				const string_type::size_type pos = test.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			char str[2]{ ch, 0 };
			Assert::AreEqual(test.MyBaseClass::find(str), test.index(str));
			Assert::AreEqual(test.substr(2).MyBaseClass::find(str), test.index(str, 2));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(str), test.index(str, 3, string_type::size_type(5 + 3 - 1)));
			str[0] = 'z';
			try {
				const string_type::size_type pos = test.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(index_wchart)
		{
			using string_type = pcs::CppWString;

			string_type test( L"ABC0123456789." );
			wchar_t ch{ L'3' };
			Assert::AreEqual(test.MyBaseClass::find(ch), test.index(ch));
			Assert::AreEqual(test.substr(2).MyBaseClass::find(ch), test.index(ch, 2));
			Assert::AreEqual(test.substr(2, 5).MyBaseClass::find(ch), test.index(ch, 2, string_type::size_type(5 + 2 - 1)));
			try {
				const string_type::size_type pos = test.index('z');
				Assert::IsTrue(pos != pcs::CppString::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index('z', 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index('z', 2, 5 + 2 - 1);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test.MyBaseClass::find(s), test.index(s));
			Assert::AreEqual(test.substr(2).MyBaseClass::find(s), test.index(s, 2));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(s), test.index(s, 3, string_type::size_type(5 + 3 - 1)));
			s = 'z';
			try {
				const string_type::size_type pos = test.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			wchar_t str[2]{ ch, 0 };
			Assert::AreEqual(test.MyBaseClass::find(str), test.index(str));
			Assert::AreEqual(test.substr(2).MyBaseClass::find(str), test.index(str, 2));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(str), test.index(str, 3, string_type::size_type(5 + 3 - 1)));
			str[0] = 'z';
			try {
				const string_type::size_type pos = test.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(index_n_char)
		{
			using string_type = pcs::CppString;

			pcs::CppString test{ "ABC0123456789." };
			char ch{ '3' };
			Assert::AreEqual(test.substr(0, 20).MyBaseClass::find(ch), test.index_n(ch, 20));
			Assert::AreEqual(test.substr(2, 5).MyBaseClass::find(ch), test.index_n(ch, 2, 5));
			try {
				const string_type::size_type pos = test.index_n('z', 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index_n('z', 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			CppString s(ch);
			Assert::AreEqual(test.substr(0, 20).MyBaseClass::find(s), test.index_n(s, 20));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(s), test.index_n(s, 3, 5));
			s = 'z';
			try {
				const string_type::size_type pos = test.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			char str[2]{ ch, 0 };
			Assert::AreEqual(test.substr(0, 20).MyBaseClass::find(str), test.index_n(str, 20));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(str), test.index_n(str, 3, 5));
			str[0] = 'z';
			try {
				const string_type::size_type pos = test.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(index_n_wchar_t)
		{
			using string_type = pcs::CppWString;

			string_type test{ L"ABC0123456789." };
			wchar_t ch{ L'3'};
			Assert::AreEqual(test.substr(0, 20).MyBaseClass::find(ch), test.index_n(ch, 20));
			Assert::AreEqual(test.substr(2, 5).MyBaseClass::find(ch), test.index_n(ch, 2, 5));
			try {
				const string_type::size_type pos = test.index_n('z', 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index_n('z', 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test.substr(0, 20).MyBaseClass::find(s), test.index_n(s, 20));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(s), test.index_n(s, 3, 5));
			try {
				const string_type::size_type pos = test.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			wchar_t str[2]{ ch, 0 };
			Assert::AreEqual(test.substr(0, 20).MyBaseClass::find(str), test.index_n(str, 20));
			Assert::AreEqual(test.substr(3, 5).MyBaseClass::find(str), test.index_n(str, 3, 5));
			str[0] = L'z';
			try {
				const string_type::size_type pos = test.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(isalnum)
		{
			Assert::IsTrue(pcs::CppString("aA25").isalnum());
			Assert::IsFalse(pcs::CppString("0123456789az,").isalnum());
			Assert::IsTrue(pcs::CppWString(L"aA25").isalnum());
			Assert::IsFalse(pcs::CppWString(L"0123456789az,").isalnum());
		}

		TEST_METHOD(isalpha)
		{
			Assert::IsFalse(CppString().isalpha());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(3, ch);
				Assert::AreEqual(pcs::is_alpha(ch), s.isalpha());
			}

			Assert::IsFalse(CppWString().isalpha());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(3, wch);
				Assert::AreEqual(pcs::is_alpha(wch), ws.isalpha());
			}
		}

		TEST_METHOD(isascii)
		{
			Assert::IsTrue(CppString().isascii());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(3, ch);
				Assert::AreEqual(pcs::is_ascii(ch), s.isascii());
			}

			Assert::IsTrue(CppWString().isascii());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(3, wch);
				Assert::AreEqual(pcs::is_ascii(wch), ws.isascii());
			}
		}

		TEST_METHOD(isdecimal)
		{
			Assert::IsFalse(CppString().isdecimal());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_decimal(ch), s.isdecimal());
			}

			Assert::IsFalse(CppWString().isdecimal());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_decimal(wch), ws.isdecimal());
			}
		}

		TEST_METHOD(isdigit)
		{
			Assert::IsFalse(CppString().isdigit());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_digit(ch), s.isdigit());
			}

			Assert::IsFalse(CppWString().isdigit());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_digit(wch), ws.isdigit());
			}
		}

		TEST_METHOD(isidentifier)
		{
			Assert::IsTrue(pcs::CppString("_").isidentifier());
			Assert::IsTrue(pcs::CppString("A").isidentifier());
			Assert::IsTrue(pcs::CppString("b").isidentifier());
			Assert::IsTrue(pcs::CppString("_abcdefghijklmnopqrstuvwxyz0123456789_").isidentifier());
			Assert::IsTrue(pcs::CppString("abcdefghijklmnopqrstuvwxyz0123456789_").isidentifier());
			Assert::IsTrue(pcs::CppString("_0123456789").isidentifier());
			Assert::IsTrue(pcs::CppString("__").isidentifier());
			Assert::IsFalse(pcs::CppString("_abcdefghijklmnopqrstuvwxyz0123456789.").isidentifier());
			Assert::IsFalse(pcs::CppString("0a").isidentifier());

			Assert::IsTrue(pcs::CppWString(L"_").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"A").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"b").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"_0123456789abcdefghijklmnopqrstuvwxyz_").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"abcdefghijk0123456789lmnopqrstuvwxyz_").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"_0123456789").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"__").isidentifier());
			Assert::IsFalse(pcs::CppWString(L"_0123456789abcdefghijklmnopqrstuvwxyz.").isidentifier());
			Assert::IsFalse(pcs::CppWString(L"9z").isidentifier());
		}

		TEST_METHOD(islower)
		{
			Assert::IsFalse(CppString().islower());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_lower(ch), s.islower());
			}

			Assert::IsFalse(CppWString().islower());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_lower(wch), ws.islower());
			}
		}

		TEST_METHOD(isnumeric)
		{
			Assert::IsFalse(CppString().isnumeric());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_numeric(ch), s.isnumeric());
			}

			Assert::IsFalse(CppWString().isnumeric());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_numeric(wch), ws.isnumeric());
			}
		}

		TEST_METHOD(isprintable)
		{
			Assert::IsTrue(CppString().isprintable());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_printable(ch), s.isprintable());
			}

			Assert::IsTrue(CppWString().isprintable());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_printable(wch), ws.isprintable());
			}
		}

		TEST_METHOD(ispunctuation)
		{
			Assert::IsFalse(CppString().ispunctuation());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(3, ch);
				Assert::IsFalse(s.ispunctuation());
				Assert::AreEqual(pcs::is_punctuation(ch), CppString(ch).ispunctuation());
			}

			Assert::IsFalse(CppWString().ispunctuation());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(3, wch);
				Assert::IsFalse(ws.ispunctuation());
				Assert::AreEqual(pcs::is_punctuation(wch), CppWString(wch).ispunctuation());
			}
		}

		TEST_METHOD(isspace)
		{
			Assert::IsFalse(CppString().isspace());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_space(ch), s.isspace());
			}

			Assert::IsFalse(CppWString().isspace());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_space(wch), ws.isspace());
			}
		}

		TEST_METHOD(istitle)
		{
			pcs::CppString s("abc, defgh ijklm nop. qrs 1 tuvwx2345 = yz!");
			Assert::IsFalse(s.istitle());
			Assert::IsTrue(s.title().istitle());

			pcs::CppWString ws(L"abc, defgh ijklm nop. qrs 1 tuvwx2345 = yz!");
			Assert::IsFalse(ws.istitle());
			Assert::IsTrue(ws.title().istitle());
		}

		TEST_METHOD(isupper)
		{
			Assert::IsFalse(CppString().isupper());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_upper(ch), s.isupper());
			}

			Assert::IsFalse(CppWString().isupper());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_upper(wch), ws.isupper());
			}
		}

		TEST_METHOD(is_words_sep)
		{
			Assert::IsFalse(CppString().is_words_sep());
			for (int c = 32; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_space(ch) || pcs::is_punctuation(ch), s.is_words_sep());
			}

			Assert::IsFalse(CppWString().is_words_sep());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_space(wch) || pcs::is_punctuation(wch), ws.is_words_sep());
			}
		}

		TEST_METHOD(join)
		{
			pcs::CppString s("##");
			std::array<CppString, 2> arr{ "abcd", "efg" };
			Assert::AreEqual(pcs::CppString("abcd##efg").c_str(), s.join(arr).c_str());
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789").c_str(), s.join(std::array<CppString, 3>{ "abcd", "efg", "123456789" }).c_str());

			pcs::CppWString ws(L"##");
			std::array<CppWString, 2> warr{ L"abcd", L"efg" };
			Assert::AreEqual(pcs::CppWString(L"abcd##efg").c_str(), ws.join(warr).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789").c_str(), ws.join(std::array<CppWString, 3>{ L"abcd", L"efg", L"123456789" }).c_str());

			std::vector<CppString> vec{ "abcd", "efg" };
			Assert::AreEqual(pcs::CppString("abcd##efg").c_str(), s.join(vec).c_str());
			vec.push_back("123456789");
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789").c_str(), s.join(vec).c_str());

			std::vector<CppWString> wvec{ L"abcd", L"efg" };
			Assert::AreEqual(pcs::CppWString(L"abcd##efg").c_str(), ws.join(wvec).c_str());
			wvec.push_back(L"123456789");
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789").c_str(), ws.join(wvec).c_str());

			Assert::AreEqual(pcs::CppString("abcd##efg").c_str(), s.join(pcs::CppString("abcd"), pcs::CppString("efg")).c_str());
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789").c_str(), s.join(pcs::CppString("abcd"), pcs::CppString("efg"), pcs::CppString("123456789")).c_str());
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789##0").c_str(), s.join("abcd", "efg", "123456789", "0").c_str());
			Assert::AreEqual(pcs::CppString("abcd# #efg# #123456789# #0").c_str(), "# #"cs.join("abcd", "efg", "123456789", "0").c_str());
			Assert::AreEqual("abcdE", "##"cs.join("abcdE").c_str());
			Assert::AreEqual("##", "##"cs.join().c_str());
			Assert::AreEqual("", "##"cs.join("").c_str());

			Assert::AreEqual(pcs::CppWString(L"abcd##efg").c_str(), ws.join(pcs::CppWString(L"abcd"), pcs::CppWString(L"efg")).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789").c_str(), ws.join(pcs::CppWString(L"abcd"), pcs::CppWString(L"efg"), pcs::CppWString(L"123456789")).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789##0").c_str(), ws.join(L"abcd"cs, L"efg"cs, L"123456789"cs, L"0"cs).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd# #efg# #123456789# #0").c_str(), L"# #"csv.join(L"abcd", L"efg"cs, L"123456789"cs, L"0"cs).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcdE").c_str(), L"##"cs.join(L"abcdE").c_str());
			Assert::AreEqual(pcs::CppWString(L"##").c_str(), L"##"cs.join().c_str());
			Assert::AreEqual(pcs::CppWString(L"").c_str(), L"##"cs.join(L"").c_str());
		}

		TEST_METHOD(ljust)
		{
			pcs::CppString s("abc");
			Assert::AreEqual("abc", s.ljust(1).c_str());
			Assert::AreEqual("abc", s.ljust(2).c_str());
			Assert::AreEqual("abc", s.ljust(3).c_str());
			Assert::AreEqual("abc ", s.ljust(4).c_str());
			Assert::AreEqual("abc  ", s.ljust(5).c_str());
			Assert::AreEqual("abc", s.ljust(1).c_str());
			Assert::AreEqual("abc", s.ljust(2).c_str());
			Assert::AreEqual("abc", s.ljust(3).c_str());
			Assert::AreEqual("abc.", s.ljust(4, '.').c_str());
			Assert::AreEqual("abc..", s.ljust(5, '.').c_str());

			pcs::CppWString ws(L"abc");
			Assert::AreEqual(L"abc", ws.ljust(1).c_str());
			Assert::AreEqual(L"abc", ws.ljust(2).c_str());
			Assert::AreEqual(L"abc", ws.ljust(3).c_str());
			Assert::AreEqual(L"abc ", ws.ljust(4).c_str());
			Assert::AreEqual(L"abc  ", ws.ljust(5).c_str());
			Assert::AreEqual(L"abc", ws.ljust(1).c_str());
			Assert::AreEqual(L"abc", ws.ljust(2).c_str());
			Assert::AreEqual(L"abc", ws.ljust(3).c_str());
			Assert::AreEqual(L"abc.", ws.ljust(4, '.').c_str());
			Assert::AreEqual(L"abc..", ws.ljust(5, '.').c_str());
		}

		TEST_METHOD(lower)
		{
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				constexpr int N{ 5 };
				pcs::CppString s(N, ch);
				s.lower();
				for (int i=0; i < N; ++i)
					Assert::AreEqual(pcs::to_lower(ch), s[i]);
				Assert::AreEqual(char(std::tolower(ch)), pcs::CppString::lower(ch));
			}

			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				constexpr int N{ 5 };
				pcs::CppWString ws(N, wch);
				ws.lower();
				for (int i = 0; i < N; ++i)
					Assert::AreEqual(pcs::to_lower(wch), ws[i]);
				Assert::AreEqual(wchar_t(std::tolower(wch)), pcs::CppWString::lower(wch));
			}
		}

		TEST_METHOD(lstrip)
		{
			pcs::CppString s("abcd");
			Assert::AreEqual("cd", s.lstrip("baCD").c_str());
			Assert::AreEqual("abcd", s.lstrip("xyz").c_str());
			Assert::AreEqual("abcd", s.lstrip("").c_str());
			Assert::AreEqual("cd", "abbabaabcd"cs.lstrip("baCD").c_str());
			Assert::AreEqual("cdab", "abbabaabcdab"cs.lstrip("baCD").c_str());
			Assert::AreEqual("abcd", " abcd"cs.lstrip().c_str());
			Assert::AreEqual("abcd", "  abcd"cs.lstrip().c_str());
			Assert::AreEqual("abcd", "       abcd"cs.lstrip().c_str());
			Assert::AreEqual("a  bcd", "         a  bcd"cs.lstrip().c_str());
			Assert::AreEqual("a  bcd   ", "         a  bcd   "cs.lstrip().c_str());

			pcs::CppWString ws(L"abcd");
			Assert::AreEqual(L"cd", ws.lstrip(L"baCD").c_str());
			Assert::AreEqual(L"abcd", ws.lstrip(L"xyz").c_str());
			Assert::AreEqual(L"abcd", ws.lstrip(L"").c_str());
			Assert::AreEqual(L"cd", L"abbabaabcd"cs.lstrip(L"baCD").c_str());
			Assert::AreEqual(L"cdab", L"abbabaabcdab"cs.lstrip(L"baCD").c_str());
			Assert::AreEqual(L"abcd", L" abcd"cs.lstrip().c_str());
			Assert::AreEqual(L"abcd", L"  abcd"cs.lstrip().c_str());
			Assert::AreEqual(L"abcd", L"       abcd"cs.lstrip().c_str());
			Assert::AreEqual(L"a  bcd", L"         a  bcd"cs.lstrip().c_str());
			Assert::AreEqual(L"a  bcd   ", L"         a  bcd   "cs.lstrip().c_str());
		}

		TEST_METHOD(partition)
		{
			pcs::CppString s("abcd#123efg");
			std::vector<CppString> res{ s.partition("#123") };
			Assert::AreEqual("abcd", res[0].c_str());
			Assert::AreEqual("#123", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());

			s = "abcd#123";
			res = s.partition("#123");
			Assert::AreEqual("abcd", res[0].c_str());
			Assert::AreEqual("#123", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			res = s.partition("XYZ");
			Assert::AreEqual("abcd#123", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			res = ""cs.partition("A");
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			pcs::CppWString ws(L"abcd#123efg");
			std::vector<CppWString> wres{ ws.partition(L"#123") };
			Assert::AreEqual(L"abcd", wres[0].c_str());
			Assert::AreEqual(L"#123", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());

			ws = L"abcd#123";
			wres = ws.partition(L"#123");
			Assert::AreEqual(L"abcd", wres[0].c_str());
			Assert::AreEqual(L"#123", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());

			wres = ws.partition(L"XYZ");
			Assert::AreEqual(L"abcd#123", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());

			wres = L""cs.partition(L"A");
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
		}

		TEST_METHOD(removeprefix)
		{
			pcs::CppString s("abcd");
			Assert::AreEqual("cd", s.removeprefix("ab").c_str());
			Assert::AreEqual("abcd", s.removeprefix("ba").c_str());
			Assert::AreEqual("abcd", s.removeprefix("").c_str());
			Assert::AreEqual("abaabcd", "abbabaabcd"cs.removeprefix("abb").c_str());
			Assert::AreEqual("cdab", "abcdab"cs.removeprefix("ab").c_str());

			pcs::CppWString ws(L"abcd");
			Assert::AreEqual(L"cd", ws.removeprefix(L"ab").c_str());
			Assert::AreEqual(L"abcd", ws.removeprefix(L"ba").c_str());
			Assert::AreEqual(L"abcd", ws.removeprefix(L"").c_str());
			Assert::AreEqual(L"abaabcd", L"abbabaabcd"cs.removeprefix(L"abb").c_str());
			Assert::AreEqual(L"cdab", L"abcdab"cs.removeprefix(L"ab").c_str());
		}

		TEST_METHOD(removesuffix)
		{
			pcs::CppString s("abcd");
			Assert::AreEqual("ab", s.removesuffix("cd").c_str());
			Assert::AreEqual("abcd", s.removesuffix("dc").c_str());
			Assert::AreEqual("abcd", s.removesuffix("").c_str());
			Assert::AreEqual("abbaba", "abbabaabcd"cs.removesuffix("abcd").c_str());
			Assert::AreEqual("abcd", "abcdab"cs.removesuffix("ab").c_str());

			pcs::CppWString ws(L"abcd");
			Assert::AreEqual(L"ab", ws.removesuffix(L"cd").c_str());
			Assert::AreEqual(L"abcd", ws.removesuffix(L"dc").c_str());
			Assert::AreEqual(L"abcd", ws.removesuffix(L"").c_str());
			Assert::AreEqual(L"abbaba", L"abbabaabcd"cs.removesuffix(L"abcd").c_str());
			Assert::AreEqual(L"abcd", L"abcdab"cs.removesuffix(L"ab").c_str());
		}

		TEST_METHOD(replace)
		{
			pcs::CppString s("abbaa");
			Assert::AreEqual("abbaa", s.replace("e", "fff").c_str());
			Assert::AreEqual("AAbbAAAA", s.replace("a", "AA").c_str());
			Assert::AreEqual("aBBaa", s.replace("b", "B").c_str());

			Assert::AreEqual("abbaa", s.replace("e", "fff", 0).c_str());
			Assert::AreEqual("abbaa", s.replace("a", "AA", 0).c_str());
			Assert::AreEqual("abbaa", s.replace("b", "B", 0).c_str());

			Assert::AreEqual("abbaa", s.replace("e", "fff", 1).c_str());
			Assert::AreEqual("AAbbaa", s.replace("a", "AA", 1).c_str());
			Assert::AreEqual("aBbaa", s.replace("b", "B", 1).c_str());

			Assert::AreEqual("abbaa", s.replace("e", "fff", 2).c_str());
			Assert::AreEqual("AAbbAAAA", s.replace("a", "AA", 3).c_str());
			Assert::AreEqual("aBBaa", s.replace("b", "B", 5).c_str());

			pcs::CppWString ws(L"abbaa");
			Assert::AreEqual(L"abbaa", ws.replace(L"e", L"fff").c_str());
			Assert::AreEqual(L"AAbbAAAA", ws.replace(L"a", L"AA").c_str());
			Assert::AreEqual(L"aBBaa", ws.replace(L"b", L"B").c_str());

			Assert::AreEqual(L"abbaa", ws.replace(L"e", L"fff", 0).c_str());
			Assert::AreEqual(L"abbaa", ws.replace(L"a", L"AA", 0).c_str());
			Assert::AreEqual(L"abbaa", ws.replace(L"b", L"B", 0).c_str());

			Assert::AreEqual(L"abbaa", ws.replace(L"e", L"fff", 1).c_str());
			Assert::AreEqual(L"AAbbaa", ws.replace(L"a", L"AA", 1).c_str());
			Assert::AreEqual(L"aBbaa", ws.replace(L"b", L"B", 1).c_str());

			Assert::AreEqual(L"abbaa", ws.replace(L"e", L"fff", 2).c_str());
			Assert::AreEqual(L"AAbbAAAA", ws.replace(L"a", L"AA", 3).c_str());
			Assert::AreEqual(L"aBBaa", ws.replace(L"b", L"B", 5).c_str());
		}

		TEST_METHOD(rfind)
		{
			size_t found_pos;

			pcs::CppString test{ "ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test.MyBaseClass::rfind(ch), test.rfind(ch));

				found_pos = test.substr(2).MyBaseClass::rfind(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.rfind(ch, 2));
				else
					Assert::AreEqual(found_pos, test.rfind(ch, 2) - 2);

				found_pos = test.substr(2, 5).MyBaseClass::rfind(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.rfind(ch, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test.rfind(ch, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				CppString s(ch);
				Assert::AreEqual(test.MyBaseClass::rfind(s), test.rfind(s));
				found_pos = test.substr(2).MyBaseClass::rfind(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.rfind(s, 2));
				else
					Assert::AreEqual(found_pos, test.rfind(s, 2) - 2);

				found_pos = test.substr(2, 5).MyBaseClass::rfind(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test.rfind(s, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test.rfind(s, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				if (c > 0) {
					char str[2]{ ch, 0 };
					Assert::AreEqual(test.MyBaseClass::rfind(str), test.rfind(str));

					found_pos = test.substr(2).MyBaseClass::rfind(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test.rfind(str, 2));
					else
						Assert::AreEqual(found_pos, test.rfind(str, 2) - 2);

					found_pos = test.substr(2, 5).MyBaseClass::rfind(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test.rfind(str, 2, pcs::CppString::size_type(5 + 2 - 1)));
					else
						Assert::AreEqual(found_pos, test.rfind(str, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);
				}
			}
			Assert::AreEqual(pcs::CppString::npos, test.rfind("A", 1));
			Assert::AreEqual(test.size(), test.rfind(""));
			Assert::AreEqual(pcs::CppString::npos, test.rfind(".", 14));
			Assert::AreEqual(size_t(13), test.rfind(".", 13));

			pcs::CppWString wtest{ L"ABC0123456789." };
			for (int wc = 0; wc <= 0xffff; ++wc) {
				wchar_t wch{ wchar_t(wc) };

				found_pos = wtest.substr(2).MyBaseClass::rfind(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind(wch, 2));
				else
					Assert::AreEqual(found_pos, wtest.rfind(wch, 2) - 2);

				found_pos = wtest.substr(2, 5).MyBaseClass::rfind(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind(wch, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, wtest.rfind(wch, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				CppWString ws(wch);
				Assert::AreEqual(wtest.MyBaseClass::rfind(ws), wtest.rfind(ws));

				found_pos = wtest.substr(2).MyBaseClass::rfind(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind(ws, 2));
				else
					Assert::AreEqual(found_pos, wtest.rfind(ws, 2) - 2);

				found_pos = wtest.substr(2, 5).MyBaseClass::rfind(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind(ws, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, wtest.rfind(ws, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);


				if (wc > 0) {
					wchar_t wstr[2]{ wch, 0 };
					Assert::AreEqual(wtest.MyBaseClass::rfind(wstr), wtest.rfind(wstr));

					found_pos = wtest.substr(2).MyBaseClass::rfind(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.rfind(wstr, 2));
					else
						Assert::AreEqual(found_pos, wtest.rfind(wstr, 2) - 2);

					found_pos = wtest.substr(2, 5).MyBaseClass::rfind(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.rfind(wstr, 2, pcs::CppString::size_type(5 + 2 - 1)));
					else
						Assert::AreEqual(found_pos, wtest.rfind(wstr, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);
				}
			}
			Assert::AreEqual(pcs::CppString::npos, wtest.rfind(L"A", 1));
			Assert::AreEqual(wtest.size(), wtest.rfind(L""));
			Assert::AreEqual(pcs::CppString::npos, wtest.rfind(L".", 14));
			Assert::AreEqual(size_t(13), wtest.rfind(L".", 13));
		}

	};
}
