/**
	Library cppstrings
	"What if c++ strings where as easy to use as Python strings?"
	Unit tests part of the library.

	Copyright (C) 2025 Philippe Schmouker
	contact - ph (dot) schmouker (at) gmail (dot) com

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation,  either version 3  of the License,  or
	(at your option) any later version.

	This program is distributed in the hope  that  it  will  be  useful,
	but  WITHOUT  ANY  WARRANTY;  without  even  the implied warranty of
	MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the
	GNU General Public License for more details.

	You should have received a copy  of  the  GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "cppstrings.h"


namespace cppstringstests
{

	//=====   PART 1   ============================================
	TEST_CLASS(cppstringstests_PART_1)
	{
	public:

		TEST_METHOD(_cs)
		{
			using namespace pcs;
			using namespace pcs;
			auto abcd = "abcD"_cs;
			auto wabcd = L"abcD"_cs;
			Assert::AreEqual(abcd.c_str(), pcs::CppString(abcd).c_str());
			Assert::AreEqual(wabcd.c_str(), pcs::CppWString(wabcd).c_str());
		}

		TEST_METHOD(is_alpha)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isalpha(ch), pcs::is_alpha(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswalpha(ch), pcs::is_alpha(ch));
		}

		TEST_METHOD(is_ascii)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual(ch < 128, pcs::is_ascii(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual(int(ch) < 128, pcs::is_ascii(ch));
		}

		TEST_METHOD(is_decimal)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isdigit(ch), pcs::is_decimal(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswdigit(ch), pcs::is_decimal(ch));
		}

		TEST_METHOD(is_id_continue)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isdigit(ch) || (const bool)std::isalpha(ch) || ch == '_', pcs::is_id_continue(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswdigit(ch) || (const bool)std::iswalpha(ch) || ch == L'_', pcs::is_id_continue(ch));
		}

		TEST_METHOD(is_id_start)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isalpha(ch) || ch == '_', pcs::is_id_start(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswalpha(ch) || ch == L'_', pcs::is_id_start(ch));
		}

		TEST_METHOD(is_lower)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::islower(static_cast<unsigned char>(ch)), pcs::is_lower(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswlower(ch), pcs::is_lower(ch));
		}

		TEST_METHOD(is_printable)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isprint(static_cast<unsigned char>(ch)), pcs::is_printable(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswprint(ch), pcs::is_printable(ch));
		}

		TEST_METHOD(is_punctuation)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::ispunct(static_cast<unsigned char>(ch)), pcs::is_punctuation(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswpunct(ch), pcs::is_punctuation(ch));
		}

		TEST_METHOD(is_space)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isspace(static_cast<unsigned char>(ch)), pcs::is_space(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswspace(ch), pcs::is_space(ch));
		}

		TEST_METHOD(is_upper)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isupper(static_cast<unsigned char>(ch)), pcs::is_upper(char(ch)));
			for (wchar_t ch = 0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswupper(ch), pcs::is_upper(ch));
		}

		TEST_METHOD(swap_case)
		{
			for (int ch = 0; ch <= 255; ++ch) {
				const char sw_ch = pcs::swap_case(static_cast<char>(ch));
				if (std::islower(ch))
					Assert::IsTrue((const bool)std::isupper(static_cast<unsigned char>(sw_ch)));
				else if (std::isupper(ch))
					Assert::IsTrue((const bool)std::islower(static_cast<unsigned char>(sw_ch)), std::format(L"ch {}, sw_ch {}", ch, sw_ch).c_str());
				else
					Assert::AreEqual(sw_ch, static_cast<char>(ch));
			}

			for (wchar_t ch = 0; ch < L'\uffff'; ++ch) {
				const wchar_t sw_ch = pcs::swap_case(ch);
				if (std::islower(ch))
					Assert::IsTrue((const bool)std::isupper(sw_ch));
				else if (std::isupper(ch))
					Assert::IsTrue((const bool)std::islower(sw_ch), std::format(L"ch {}, sw_ch {}", ch, sw_ch).c_str());
				else
					Assert::AreEqual(sw_ch, ch);
			}
		}

		TEST_METHOD(to_lower)
		{
			for (int ch = 0; ch <= 255; ++ch) {
				const char l_ch = pcs::to_lower(static_cast<char>(ch));
				if (std::isupper(ch))
					Assert::IsTrue(std::islower(l_ch));
				else
					Assert::AreEqual(l_ch, static_cast<char>(ch));
			}

			for (wchar_t ch = 0; ch < L'\uffff'; ++ch) {
				const wchar_t l_ch = pcs::to_lower(ch);
				if (std::isupper(ch))
					Assert::IsTrue(std::iswlower(l_ch));
				else
					Assert::AreEqual(l_ch, ch);
			}
		}

		TEST_METHOD(to_upper)
		{
			for (int ch = 0; ch <= 255; ++ch) {
				const char l_ch = pcs::to_upper(static_cast<char>(ch));
				if (std::islower(ch))
					Assert::IsTrue(std::isupper(l_ch));
				else
					Assert::AreEqual(l_ch, static_cast<char>(ch));
			}

			for (wchar_t ch = 0; ch < L'\uffff'; ++ch) {
				const wchar_t l_ch = pcs::to_upper(ch);
				if (std::islower(ch))
					Assert::IsTrue(std::iswupper(l_ch));
				else
					Assert::AreEqual(l_ch, ch);
			}
		}
	};


	//=====   PART 2   ============================================
	TEST_CLASS(cppstringstests_PART_2)
	{
	public:

		TEST_METHOD(constructor_01)
		{
			using namespace pcs;
			std::map<char, pcs::CppString> table{ {'a', "b"_cs}, {'b', "a"_cs} };
			Assert::AreEqual("b"_cs.c_str(), table['a'].c_str());
			Assert::AreEqual("a"_cs.c_str(), table['b'].c_str());

			std::map<wchar_t, pcs::CppWString> wtable{ {L'a', L"b"_cs}, {L'b', L"a"_cs} };
			Assert::AreEqual(L"b"_cs.c_str(), wtable['a'].c_str());
			Assert::AreEqual(L"a"_cs.c_str(), wtable['b'].c_str());
		}

		TEST_METHOD(constructor_02)
		{
			pcs::CppString keys("abcdE");
			pcs::CppString values("ABCDe");
			pcs::CppString::TransTable t(keys, values);
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString('D').c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString('e').c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wt(pcs::CppWString(L"abcdE"), pcs::CppWString(L"ABCDe"));
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString(L'D').c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString(L'e').c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(constructor_03)
		{
			pcs::CppString::TransTable t(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wt(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(constructor_04)
		{
			pcs::CppString::TransTable t(pcs::CppString("abc"), { pcs::CppString("AA"), pcs::CppString("BBB"), pcs::CppString("C") });
			Assert::AreEqual(pcs::CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString('z').c_str(), t['z'].c_str());

			pcs::CppWString::TransTable wt(pcs::CppWString(L"abc"), { pcs::CppWString(L"AA"), pcs::CppWString(L"BBB"), pcs::CppWString(L"C") });
			Assert::AreEqual(pcs::CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L"C").c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString(L'9').c_str(), wt[L'9'].c_str());
		}

		TEST_METHOD(constructor_05)
		{
			using namespace pcs;
			pcs::CppString::TransTable t(pcs::CppString("abc"), { pcs::CppString("AA"), pcs::CppString("BBB"), pcs::CppString("C") }, "dE"_cs);
			Assert::AreEqual(pcs::CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('z').c_str(), t['z'].c_str());

			pcs::CppWString::TransTable wt(pcs::CppWString(L"abc"), { pcs::CppWString(L"AA"), pcs::CppWString(L"BBB"), pcs::CppWString(L"C") }, L"dE"_cs);
			Assert::AreEqual(pcs::CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L"C").c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'e').c_str(), wt[L'e'].c_str());
		}

		TEST_METHOD(constructor_06)
		{
			pcs::CppString::TransTable t("abC", "ABc");
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('c').c_str(), t['C'].c_str());
			Assert::AreEqual(pcs::CppString('c').c_str(), t['c'].c_str());

			pcs::CppWString::TransTable wt(L"abC", L"ABc");
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'c').c_str(), wt[L'C'].c_str());
			Assert::AreEqual(pcs::CppWString(L'c').c_str(), wt[L'c'].c_str());
		}

		TEST_METHOD(constructor_07)
		{
			pcs::CppString::TransTable t("abc", "ABC", "dE");
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('e').c_str(), t['e'].c_str());

			pcs::CppWString::TransTable wt(L"abc", L"ABC", L"dE");
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'A'].c_str());
		}

		TEST_METHOD(constructor_08)
		{
			std::string keys("abC");
			std::vector<std::string> values{ "AA", "BBB", "c" };
			pcs::CppString::TransTable t(keys.begin(), keys.end(), values.begin(), values.end());
			Assert::AreEqual(pcs::CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('c').c_str(), t['C'].c_str());
			Assert::AreEqual(pcs::CppString('c').c_str(), t['c'].c_str());

			std::wstring wkeys(L"abC");
			std::vector<std::wstring> wvalues{ L"AA", L"BBB", L"c" };
			pcs::CppWString::TransTable wt(wkeys.begin(), wkeys.end(), wvalues.begin(), wvalues.end());
			Assert::AreEqual(pcs::CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'c').c_str(), wt[L'C'].c_str());
			Assert::AreEqual(pcs::CppWString(L'c').c_str(), wt[L'c'].c_str());
		}

		TEST_METHOD(constructor_09)
		{
			std::string keys("abC");
			std::vector<std::string> values{ "AA", "BBB", "c" };
			std::string not_translated("dE");
			pcs::CppString::TransTable t(keys.begin(), keys.end(), values.begin(), values.end(), not_translated.cbegin(), not_translated.cend());
			Assert::AreEqual(pcs::CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('c').c_str(), t['C'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('c').c_str(), t['c'].c_str());

			std::wstring wkeys(L"abC");
			std::vector<std::wstring> wvalues{ L"AA", L"BBB", L"c" };
			std::wstring wnot_translated(L"dE");
			pcs::CppWString::TransTable wt(wkeys.begin(), wkeys.end(), wvalues.begin(), wvalues.end(), wnot_translated.cbegin(), wnot_translated.cend());
			Assert::AreEqual(pcs::CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'c').c_str(), wt[L'C'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'c').c_str(), wt[L'c'].c_str());
		}

		TEST_METHOD(constructor_empty)
		{
			pcs::CppString::TransTable t;
			Assert::IsTrue(t.get_table().empty());

			pcs::CppWString::TransTable wt;
			Assert::IsTrue(wt.get_table().empty());
		}

		TEST_METHOD(constructor_copy)
		{
			pcs::CppString::TransTable ct(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			pcs::CppString::TransTable t(ct);
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wct(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			pcs::CppWString::TransTable wt(wct);
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(constructor_move)
		{
			pcs::CppString::TransTable mt(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			pcs::CppString::TransTable t(std::move(mt));
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wmt(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			pcs::CppWString::TransTable wt(std::move(wmt));
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(assign_copy)
		{
			pcs::CppString::TransTable ct(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			pcs::CppString::TransTable t = ct;
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wct(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			pcs::CppWString::TransTable wt = wct;
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(assign_move)
		{
			pcs::CppString::TransTable mt(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			pcs::CppString::TransTable t = std::move(mt);
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wmt(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			pcs::CppWString::TransTable wt = std::move(wmt);
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(assign_map)
		{
			pcs::CppString::TransTable ct(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			pcs::CppString::TransTable t = ct.get_table();
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wct(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			pcs::CppWString::TransTable wt = wct.get_table();
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(indexing)
		{
			pcs::CppString::TransTable t(pcs::CppString("abc"), pcs::CppString("ABC"), pcs::CppString("dE"));
			Assert::AreEqual(pcs::CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(pcs::CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(pcs::CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(pcs::CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(pcs::CppString(',').c_str(), t[','].c_str());

			pcs::CppWString::TransTable wt(pcs::CppWString(L"abc"), pcs::CppWString(L"ABC"), pcs::CppWString(L"dE"));
			Assert::AreEqual(pcs::CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(pcs::CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(pcs::CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(pcs::CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(pcs::CppWString(L'\n').c_str(), wt[L'\n'].c_str());
		}
	};


	//=====   PART 3   ============================================
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

			pcs::CppString s0(nullptr);
			Assert::AreEqual(std::size_t(0), s0.size());
			Assert::AreEqual("", s0.c_str());

			pcs::CppWString ws0(nullptr);
			Assert::AreEqual(std::size_t(0), ws0.size());
			Assert::AreEqual(L"", ws0.c_str());
		}

		TEST_METHOD(constructor_10)
		{
			pcs::CppString s("abcDEfgh", 5);
			Assert::AreEqual(std::size_t(5), s.size());
			Assert::AreEqual(pcs::CppString("abcDE").c_str(), s.c_str());

			pcs::CppWString ws(L"ABCdefGH", 7);
			Assert::AreEqual(std::size_t(7), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefG").c_str(), ws.c_str());

			pcs::CppString s0(nullptr, 0);
			Assert::AreEqual(std::size_t(0), s0.size());
			Assert::AreEqual("", s0.c_str());

			pcs::CppWString ws0(nullptr, 7);
			Assert::AreEqual(std::size_t(7), ws0.size());
			Assert::AreEqual(L"", ws0.c_str());
		}

		TEST_METHOD(constructor_11)
		{
			pcs::CppString s({ 'a', 'b', 'c', 'D' });
			Assert::AreEqual(std::size_t(4), s.size());
			Assert::AreEqual(pcs::CppString("abcD").c_str(), s.c_str());

			pcs::CppWString ws({ L'A', L'B', L'C', L'd', L'e' });
			Assert::AreEqual(std::size_t(5), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCde").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_12)
		{
			std::string cs("abcDEfgh");
			pcs::CppString s(cs);
			Assert::AreEqual(std::size_t(8), s.size());
			Assert::AreEqual(pcs::CppString("abcDEfgh").c_str(), s.c_str());

			std::wstring wcs(L"ABCdefGH");
			pcs::CppWString ws(wcs);
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_13)
		{
			std::string cs("abcDEfgh");
			pcs::CppString s(cs, cs.get_allocator());
			Assert::AreEqual(std::size_t(8), s.size());
			Assert::AreEqual(pcs::CppString("abcDEfgh").c_str(), s.c_str());

			std::wstring wcs(L"ABCdefGH");
			pcs::CppWString ws(wcs, wcs.get_allocator());
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_14)
		{
			std::string cs("abcDEfgh");
			pcs::CppString s(std::move(cs));
			Assert::AreEqual(std::size_t(8), s.size());
			Assert::AreEqual(pcs::CppString("abcDEfgh").c_str(), s.c_str());

			std::wstring wcs(L"ABCdefGH");
			pcs::CppWString ws(std::move(wcs));
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_15)
		{
			std::string cs("abcDEfgh");
			pcs::CppString s(std::move(cs), cs.get_allocator());
			Assert::AreEqual(std::size_t(8), s.size());
			Assert::AreEqual(pcs::CppString("abcDEfgh").c_str(), s.c_str());

			std::wstring wcs(L"ABCdefGH");
			pcs::CppWString ws(std::move(wcs), wcs.get_allocator());
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_16)
		{
			std::string cs("abcDEfgh");
			pcs::CppString s(cs.cbegin(), cs.cend());
			Assert::AreEqual(std::size_t(8), s.size());
			Assert::AreEqual(pcs::CppString("abcDEfgh").c_str(), s.c_str());

			std::wstring wcs(L"ABCdefGH");
			pcs::CppWString ws(wcs.begin(), wcs.end());
			Assert::AreEqual(std::size_t(8), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefGH").c_str(), ws.c_str());
		}

		TEST_METHOD(constructor_19)
		{
			pcs::CppString s('z');
			Assert::AreEqual(std::size_t(1), s.size());
			Assert::AreEqual(pcs::CppString("z").c_str(), s.c_str());

			pcs::CppWString ws(L'Z');
			Assert::AreEqual(std::size_t(1), ws.size());
			Assert::AreEqual(pcs::CppWString(L"Z").c_str(), ws.c_str());
		}
	};


	//=====   PART 4   ========================================
	TEST_CLASS(cppstringstests_PART_4)
	{
	public:

		TEST_METHOD(slice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::Slice<long long> slc(0, 5, 1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::Slice<long long> slc(0, 5UL, char(1));

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::Slice slc(0, 11);  // Slice here defaults to Slice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::Slice slc(0, 3);  // Slice here defaults to Slice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::Slice slc(0);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
				;
				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::Slice<long> slc;

				long index{ slc.begin(txt) };
				Assert::AreEqual(long(0), index);

				long k{ 0 };
				for (long index = slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);

				k = 0;
				for (long index = slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);
			}

			{
				pcs::Slice<long long> slc(-1, 0, -1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(4LL, index);

				long long k{ (long long)txt.size() - 1 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0LL, *slc);

				k = txt.size() - 1;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0LL, *slc);
			}

			{
				pcs::Slice slc(-2, 1, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(3, index);

				int k{ int(txt.size()) - 2 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);

				k = int(txt.size()) - 2;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);
			}

			{
				pcs::Slice slc(-2, -3, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(3, index);

				int k{ int(txt.size()) - 2 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(2, *slc);

				k = int(txt.size()) - 2;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(2, *slc);
			}

			{
				pcs::Slice slc(-4, -2, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(1, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);
			}

			{
				pcs::Slice slc(-4, -2, 1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(1, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::Slice slc(5, -7, 0);

				int index{ slc.begin(txt) };
				Assert::AreEqual(5, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::Slice slc(5, -7, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::Slice slc(-11, 7, 1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

		}

		TEST_METHOD(startslice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::StartSlice<long long> slc;

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StartSlice slc(0);  // Slice here defaults to Slice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartSlice<long long> slc(-1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(4LL, index);

				long long k{ (long long)txt.size() - 1 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = txt.size() - 1;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StartSlice slc(-2);

				int index{ slc.begin(txt) };
				Assert::AreEqual(3, index);

				int k{ int(txt.size()) - 2 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = int(txt.size()) - 2;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartSlice slc(-4);

				int index{ slc.begin(txt) };
				Assert::AreEqual(1, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartSlice slc(5);

				int index{ slc.begin(txt) };
				Assert::AreEqual(5, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5   , *slc);
			}

			{
				pcs::StartSlice slc(-11);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

		}

		TEST_METHOD(startstepslice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::StartStepSlice<long long> slc(0, 1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StartStepSlice<long long> slc(0, char(1));

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StartStepSlice slc(0, 11);  // StartStepSlice here defaults to StartStepSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, k += 11)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(11, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, k += 11)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(11, *slc);
			}

			{
				pcs::StartStepSlice slc(0, 3);  // StartStepSlice here defaults to StartStepSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, k += 3)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, k += 3)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);
			}

			{
				pcs::StartStepSlice slc(0);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
				;
				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartStepSlice<long> slc;

				long index{ slc.begin(txt) };
				Assert::AreEqual(long(0), index);

				long k{ 0 };
				for (long index = slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);

				k = 0;
				for (long index = slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);
			}

			{
				pcs::StartStepSlice<long long> slc(-1, -1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(4LL, index);

				long long k{ (long long)txt.size() - 1 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0LL, *slc);

				k = (long long)txt.size() - 1;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0LL, *slc);
			}

			{
				pcs::StartStepSlice slc(-2, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(3, index);

				int k{ int(txt.size()) - 2 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = int(txt.size()) - 2;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StartStepSlice slc(-9, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StartStepSlice slc(-4, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(1, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StartStepSlice slc(-4, 1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(1, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartStepSlice slc(5, -7);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, k -= 7)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(-3, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, k -= 7)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(-3, *slc);
			}

			{
				pcs::StartStepSlice slc(5, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StartStepSlice slc(-11, 1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

		}

		TEST_METHOD(startstopslice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::StartStopSlice<long long> slc(0, 5);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StartStopSlice<long long> slc(0, 5UL);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StartStopSlice slc(0, 11);  // StartStopSlice here defaults to StartStopSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartStopSlice slc(0, 3);  // StartStopSlice here defaults to StartStopSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::StartStopSlice slc(0);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
				;
				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartStopSlice<long> slc;

				long index{ slc.begin(txt) };
				Assert::AreEqual(long(0), index);

				long k{ 0 };
				for (long index = slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);

				k = 0;
				for (long index = slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);
			}

			{
				pcs::StartStopSlice<long long> slc(-1, 0);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(4LL, index);

				long long k{ (long long)txt.size() - 1 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4LL, *slc);

				k = txt.size() - 1;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4LL, *slc);
			}

			{
				pcs::StartStopSlice slc(-2, 1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(3, index);

				int k{ int(txt.size()) - 2 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = int(txt.size()) - 2;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::StartStopSlice slc(-2, 3);

				int index{ slc.begin(txt) };
				Assert::AreEqual(3, index);

				int k{ int(txt.size()) - 2 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = int(txt.size()) - 2;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::StartStopSlice slc(-4, -2);

				int index{ slc.begin(txt) };
				Assert::AreEqual(1, index);

				int k{ int(txt.size()) - 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(int(txt.size() - 2), *slc);

				k = int(txt.size()) - 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(int(txt.size() - 2), *slc);
			}

			{
				pcs::StartStopSlice slc(5, -7);

				int index{ slc.begin(txt) };
				Assert::AreEqual(5, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StartStopSlice slc(-11, 7);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

		}

		TEST_METHOD(stepslice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::StepSlice<long long> slc;

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StepSlice slc(1);  // StepSlice here defaults to StepSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StepSlice slc(3);  // StepSlice here defaults to StepSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, k+=3)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, k+=3)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);
			}

			{
				pcs::StepSlice slc(0);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
				;
				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StepSlice<long> slc;

				long index{ slc.begin(txt) };
				Assert::AreEqual(long(0), index);

				long k{ 0 };
				for (long index = slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);

				k = 0;
				for (long index = slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);
			}

			{
				pcs::StepSlice<long long> slc(-1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(4LL, index);

				long long k{ (long long)txt.size() - 1 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0LL, *slc);

				k = txt.size() - 1;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0LL, *slc);
			}

			{
				pcs::StepSlice slc(-2);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, k-=2)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, k-=2)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StepSlice slc(-4);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, k-=4)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, k-=4)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StepSlice slc(-11);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, k-=11)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(-7, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, k-=11)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(-7, *slc);
			}
		}

		TEST_METHOD(stopslice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::StopSlice<long long> slc;

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StopSlice slc(7);  // Slice here defaults to Slice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StopSlice<long long> slc(-1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4LL, *slc);
			}

			{
				pcs::StopSlice slc(-2);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::StopSlice slc(-4);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);
			}

			{
				pcs::StopSlice slc(5);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StopSlice slc(-11);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

		}

		TEST_METHOD(stopstepslice_iteration)
		{
			pcs::CppString txt("aBcDe");

			{
				pcs::StopStepSlice<long long> slc( 5, 1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StopStepSlice<long long> slc(5UL, char(1));

				long long index{ slc.begin(txt) };
				Assert::AreEqual(0LL, index);

				long long k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5LL, *slc);
			}

			{
				pcs::StopStepSlice slc(11, 3);  // StopStepSlice here defaults to StopStepSlice<int>

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, k+=3)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, k+=3)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);
			}

			{
				pcs::StopStepSlice slc(3, 2);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, k+=2)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, k+=2)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4, *slc);
			}

			{
				pcs::StopStepSlice slc(7);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
				;
				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5, *slc);
			}

			{
				pcs::StopStepSlice<long> slc;

				long index{ slc.begin(txt) };
				Assert::AreEqual(long(0), index);

				long k{ 0 };
				for (long index = slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);

				k = 0;
				for (long index = slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(5L, *slc);
			}

			{
				pcs::StopStepSlice<long long> slc(-1, -1);

				long long index{ slc.begin(txt) };
				Assert::AreEqual(4LL, index);

				long long k{ (long long)txt.size() - 1 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4LL, *slc);

				k = txt.size() - 1;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(4LL, *slc);
			}

			{
				pcs::StopStepSlice slc(-2, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::StopStepSlice slc(-4, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(1, *slc);
			}

			{
				pcs::StopStepSlice slc(-2, 1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(3, *slc);
			}

			{
				pcs::StopStepSlice slc(-7, 0);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, ++k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StopStepSlice slc(-7, -1);

				int index{ slc.begin(txt) };
				Assert::AreEqual(4, index);

				int k{ 4 };
				for (slc.begin(txt); !slc.end(); slc++, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);

				k = 4;
				for (slc.begin(txt); !slc.end(); ++slc, --k)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(0, *slc);
			}

			{
				pcs::StopStepSlice slc(7, 2);

				int index{ slc.begin(txt) };
				Assert::AreEqual(0, index);

				int k{ 0 };
				for (slc.begin(txt); !slc.end(); slc++, k+=2)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);

				k = 0;
				for (slc.begin(txt); !slc.end(); ++slc, k+=2)
					Assert::AreEqual(*slc, k);
				Assert::AreEqual(6, *slc);
			}

		}

	};


	//=====   PART 5   ========================================
	TEST_CLASS(cppstringstests_PART_5)
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

		TEST_METHOD(contains)
		{
			using namespace pcs;
			pcs::CppString text("Abcd. Efgh ij!");
			for (std::size_t index = 0; index < text.size(); ++index) {
				Assert::IsTrue(text.contains(text.substr(index)));
				for (std::size_t count = 0; count < text.size() - index; ++count)
					Assert::IsTrue(text.contains(text.substr(index, count)));
			}
			Assert::IsFalse(text.contains("zzz"_cs));
			Assert::IsFalse(text.contains("abc"_cs));
			Assert::IsFalse(text.contains("Abcd. Efgh ij!!"_cs));
			Assert::IsTrue(text.contains(""_cs));

			pcs::CppWString wtext(L"Abcd. Efgh ij!");
			for (std::size_t index = 0; index < wtext.size(); ++index) {
				Assert::IsTrue(wtext.contains(wtext.substr(index)));
				for (std::size_t count = 0; count < text.size() - index; ++count)
					Assert::IsTrue(wtext.contains(wtext.substr(index, count)));
			}
			Assert::IsFalse(wtext.contains(L"zzz"_cs));
			Assert::IsFalse(wtext.contains(L"abc"_cs));
			Assert::IsFalse(wtext.contains(L"Abcd. Efgh ij!!"_cs));
			Assert::IsTrue(wtext.contains(L""_cs));

			for (std::size_t index = 0; index < text.size(); ++index) {
				Assert::IsTrue(text.contains(text.substr(index).c_str()));
				for (std::size_t count = 0; count < text.size() - index; ++count)
					Assert::IsTrue(text.contains(text.substr(index, count).c_str()));
			}
			Assert::IsFalse(text.contains("z"));
			Assert::IsFalse(text.contains("a"));
			Assert::IsFalse(text.contains("Abcd. Efgh ij!!"));
			Assert::IsTrue(text.contains(""));
			Assert::IsTrue(text.contains(nullptr));

			for (std::size_t index = 0; index < wtext.size(); ++index) {
				Assert::IsTrue(wtext.contains(wtext.substr(index).c_str()));
				for (std::size_t count = 0; count < text.size() - index; ++count)
					Assert::IsTrue(wtext.contains(wtext.substr(index, count).c_str()));
			}
			Assert::IsFalse(wtext.contains(L"zzz"));
			Assert::IsFalse(wtext.contains(L"abc"));
			Assert::IsFalse(wtext.contains(L"Abcd. Efgh ij!!"));
			Assert::IsTrue(wtext.contains(L""));
			Assert::IsTrue(wtext.contains(nullptr));

			for (auto const ch : text)
				Assert::IsTrue(text.contains(ch));
			Assert::IsFalse(text.contains('z'));
			Assert::IsFalse(text.contains('a'));

			for (auto const wch : wtext)
				Assert::IsTrue(wtext.contains(wch));
			Assert::IsFalse(wtext.contains(L'z'));
			Assert::IsFalse(wtext.contains(L'a'));
		}

		TEST_METHOD(contains_n)
		{
			using namespace pcs;
			pcs::CppString text("Abcd. Efgh ij!");
			for (std::size_t index = 0; index < text.size(); ++index) {
				Assert::IsTrue(text.contains_n(text.substr(index), index));
				for (std::size_t count = 0; count < text.size() - index; ++count) {
					Assert::IsTrue(text.contains_n(text.substr(index, count), index, count));
					Assert::IsTrue(text.contains_n(text.substr(index, count), index, count + 1));
					if (count > 0)
						Assert::IsFalse(text.contains_n(text.substr(index, count), index, count - 1));
				}
			}
			Assert::IsFalse(text.contains_n("zzz"_cs, 0));
			Assert::IsFalse(text.contains_n("abc"_cs, 0));
			Assert::IsFalse(text.contains_n("Abcd. Efgh ij!!"_cs, 0));
			Assert::IsTrue(text.contains_n(""_cs, 6));
			Assert::IsFalse(text.contains_n(". Ef"_cs, 10, 4));
			Assert::IsFalse(text.contains_n(". Ef"_cs, 4, 3));

			pcs::CppWString wtext(L"Abcd. Efgh ij!");
			for (std::size_t index = 0; index < wtext.size(); ++index) {
				Assert::IsTrue(wtext.contains_n(wtext.substr(index), index));
				for (std::size_t count = 0; count < text.size() - index; ++count) {
					Assert::IsTrue(wtext.contains_n(wtext.substr(index, count), index, count));
					Assert::IsTrue(wtext.contains_n(wtext.substr(index, count), index, count + 1));
					if (count > 0)
						Assert::IsFalse(wtext.contains_n(wtext.substr(index, count), index, count - 1));
				}
			}
			Assert::IsFalse(wtext.contains_n(L"zzz"_cs, 0));
			Assert::IsFalse(wtext.contains_n(L"abc"_cs, 0));
			Assert::IsFalse(wtext.contains_n(L"Abcd. Efgh ij!!"_cs, 0));
			Assert::IsTrue(wtext.contains_n(L""_cs, 6));
			Assert::IsFalse(wtext.contains_n(L". Ef"_cs, 10, 4));
			Assert::IsFalse(wtext.contains_n(L". Ef"_cs, 4, 3));

			for (std::size_t index = 0; index < text.size(); ++index) {
				Assert::IsTrue(text.contains_n(text.substr(index), index));
				for (std::size_t count = 0; count < text.size() - index; ++count) {
					Assert::IsTrue(text.contains_n(text.substr(index, count).c_str(), index, count));
					Assert::IsTrue(text.contains_n(text.substr(index, count).c_str(), index, count + 1));
					if (count > 0)
						Assert::IsFalse(text.contains_n(text.substr(index, count).c_str(), index, count - 1));
				}
			}
			Assert::IsFalse(text.contains_n("z", 0));
			Assert::IsFalse(text.contains_n("a", 0));
			Assert::IsFalse(text.contains_n("Abcd. Efgh ij!!", 0));
			Assert::IsTrue(text.contains_n("", 6));
			Assert::IsTrue(text.contains_n(nullptr, 5));
			Assert::IsFalse(text.contains_n(". Ef", 10, 4));
			Assert::IsFalse(text.contains_n(". Ef", 4, 3));

			for (std::size_t index = 0; index < text.size(); ++index) {
				Assert::IsTrue(wtext.contains_n(wtext.substr(index), index));
				for (std::size_t count = 0; count < wtext.size() - index; ++count) {
					Assert::IsTrue(wtext.contains_n(wtext.substr(index, count).c_str(), index, count));
					Assert::IsTrue(wtext.contains_n(wtext.substr(index, count).c_str(), index, count + 1));
					if (count > 0)
						Assert::IsFalse(wtext.contains_n(wtext.substr(index, count).c_str(), index, count - 1));
				}
			}
			Assert::IsFalse(wtext.contains_n(L"z", 0));
			Assert::IsFalse(wtext.contains_n(L"a", 0));
			Assert::IsFalse(wtext.contains_n(L"Abcd. Efgh ij!!", 0));
			Assert::IsTrue(wtext.contains_n(L"", 6));
			Assert::IsTrue(wtext.contains_n(nullptr, 3));
			Assert::IsFalse(wtext.contains_n(L". Ef", 10, 4));
			Assert::IsFalse(wtext.contains_n(L". Ef", 4, 3));

			for (auto const ch : text)
				Assert::IsTrue(text.contains_n(ch, 0));
			Assert::IsFalse(text.contains_n('z', 0, 21));
			Assert::IsFalse(text.contains_n('a', 0));

			for (auto const wch : wtext)
				Assert::IsTrue(wtext.contains_n(wch, 0));
			Assert::IsFalse(wtext.contains_n(L'z', 0));
			Assert::IsFalse(wtext.contains_n(L'a', 0, 21));
		}

		TEST_METHOD(count)
		{
			pcs::CppString s("abcabcabcdefabca bca bcabca");
			Assert::AreEqual(pcs::CppString::size_type(3), s.count("abca"));
			Assert::AreEqual(pcs::CppString::size_type(6), s.count("bca"));
			Assert::AreEqual(pcs::CppString::size_type(0), s.count("A"));
			Assert::AreEqual(pcs::CppString::size_type(2), s.count("abca", 4));
			Assert::AreEqual(pcs::CppString::size_type(5), s.count("bca", 2));
			Assert::AreEqual(pcs::CppString::size_type(0), s.count("A", 3));
			Assert::AreEqual(pcs::CppString::size_type(1), s.count("abca", 4, s.size() - 5));
			Assert::AreEqual(pcs::CppString::size_type(4), s.count("bca", 2, s.size() - 2));
			Assert::AreEqual(pcs::CppString::size_type(0), s.count("A", 3, s.size() + 4));

			pcs::CppWString ws(L"abcabcabcdefabca bca bcabca");
			Assert::AreEqual(pcs::CppString::size_type(3), ws.count(L"abca"));
			Assert::AreEqual(pcs::CppString::size_type(6), ws.count(L"bca"));
			Assert::AreEqual(pcs::CppString::size_type(0), ws.count(L"A"));
			Assert::AreEqual(pcs::CppString::size_type(2), ws.count(L"abca", 4));
			Assert::AreEqual(pcs::CppString::size_type(5), ws.count(L"bca", 2));
			Assert::AreEqual(pcs::CppString::size_type(0), ws.count(L"A", 3));
			Assert::AreEqual(pcs::CppString::size_type(1), ws.count(L"abca", 4, s.size() - 5));
			Assert::AreEqual(pcs::CppString::size_type(4), ws.count(L"bca", 2, s.size() - 2));
			Assert::AreEqual(pcs::CppString::size_type(0), ws.count(L"A", 3, s.size() + 4));
		}

		TEST_METHOD(count_n)
		{
			pcs::CppString s("abcabcabcdefabca bca bcabca");
			const pcs::CppString::size_type len{ s.size() };
			Assert::AreEqual(pcs::CppString::size_type(3), s.count_n("abca", 0, len));
			Assert::AreEqual(pcs::CppString::size_type(6), s.count_n("bca", 0, len));
			Assert::AreEqual(pcs::CppString::size_type(0), s.count_n("A", 0, len));
			Assert::AreEqual(pcs::CppString::size_type(2), s.count_n("abca", 4, len - 4));
			Assert::AreEqual(pcs::CppString::size_type(5), s.count_n("bca", 2, len - 2));
			Assert::AreEqual(pcs::CppString::size_type(0), s.count_n("A", 3, len - 3));
			Assert::AreEqual(pcs::CppString::size_type(1), s.count_n("abca", 4, len - 5));
			Assert::AreEqual(pcs::CppString::size_type(4), s.count_n("bca", 2, len - 3));
			Assert::AreEqual(pcs::CppString::size_type(0), s.count_n("A", 3, len + 4));

			pcs::CppWString ws(L"abcabcabcdefabca bca bcabca");
			const pcs::CppWString::size_type wlen{ ws.size() };
			Assert::AreEqual(pcs::CppString::size_type(3), ws.count_n(L"abca", 0, wlen));
			Assert::AreEqual(pcs::CppString::size_type(6), ws.count_n(L"bca", 0, wlen));
			Assert::AreEqual(pcs::CppString::size_type(0), ws.count_n(L"A", 0, wlen));
			Assert::AreEqual(pcs::CppString::size_type(2), ws.count_n(L"abca", 4, wlen - 4));
			Assert::AreEqual(pcs::CppString::size_type(5), ws.count_n(L"bca", 2, wlen - 2));
			Assert::AreEqual(pcs::CppString::size_type(0), ws.count_n(L"A", 3, wlen - 3));
			Assert::AreEqual(pcs::CppString::size_type(1), ws.count_n(L"abca", 4, wlen - 5));
			Assert::AreEqual(pcs::CppString::size_type(4), ws.count_n(L"bca", 2, wlen - 3));
			Assert::AreEqual(pcs::CppString::size_type(0), ws.count_n(L"A", 3, wlen + 4));
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
			Assert::AreEqual(pcs::CppString("a   bc  def ghij    \r    k\nl   m\r\nno  pqr     s.").c_str(), ts.c_str());
			ts = s.expand_tabs(3);
			Assert::AreEqual(pcs::CppString("a  bc def   ghij  \r   k\nl  m\r\nno pqr   s.").c_str(), ts.c_str());
			ts = s.expand_tabs(2);
			Assert::AreEqual(pcs::CppString("a bc  def ghij  \r  k\nl m\r\nno  pqr   s.").c_str(), ts.c_str());
			ts = s.expand_tabs(1);
			Assert::AreEqual(pcs::CppString("a bc def ghij \r k\nl m\r\nno pqr  s.").c_str(), ts.c_str());

			pcs::CppWString ws(L"a\tbc\tdef\tghij\t\r\tk\nl\tm\r\nno\tpqr \ts.");
			pcs::CppWString wts = ws.expand_tabs(4);
			Assert::AreEqual(pcs::CppWString(L"a   bc  def ghij    \r    k\nl   m\r\nno  pqr     s.").c_str(), wts.c_str());
			wts = ws.expand_tabs(3);
			Assert::AreEqual(pcs::CppWString(L"a  bc def   ghij  \r   k\nl  m\r\nno pqr   s.").c_str(), wts.c_str());
			wts = ws.expand_tabs(2);
			Assert::AreEqual(pcs::CppWString(L"a bc  def ghij  \r  k\nl m\r\nno  pqr   s.").c_str(), wts.c_str());
			wts = ws.expand_tabs(1);
			Assert::AreEqual(pcs::CppWString(L"a bc def ghij \r k\nl m\r\nno pqr  s.").c_str(), wts.c_str());
		}

		TEST_METHOD(find)
		{
			size_t found_pos;

			pcs::CppString test_str{ "ABC0123456789.ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test_str.MyBaseClass::find(ch), test_str.find(ch));

				found_pos = test_str.substr(2).MyBaseClass::find(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find(ch, 2));
				else
					Assert::AreEqual(found_pos, test_str.find(ch, 2) - 2);
				
				found_pos = test_str.substr(2, 5).MyBaseClass::find(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find(ch, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test_str.find(ch, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				pcs::CppString s(ch);
				Assert::AreEqual(test_str.MyBaseClass::find(s), test_str.find(s));
				found_pos = test_str.substr(2).MyBaseClass::find(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find(s, 2));
				else
					Assert::AreEqual(found_pos, test_str.find(s, 2) - 2);

				found_pos = test_str.substr(2, 5).MyBaseClass::find(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find(s, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test_str.find(s, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				if (c > 0) {
					char str[2]{ ch, 0 };
					Assert::AreEqual(test_str.MyBaseClass::find(str), test_str.find(str));

					found_pos = test_str.substr(2).MyBaseClass::find(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.find(str, 2));
					else
						Assert::AreEqual(found_pos, test_str.find(str, 2) - 2);

					found_pos = test_str.substr(2, 5).MyBaseClass::find(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.find(str, 2, pcs::CppString::size_type(5 + 2 - 1)));
					else
						Assert::AreEqual(found_pos, test_str.find(str, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);
				}
			}
			Assert::AreEqual(size_t(14), test_str.find("A", 1));
			Assert::AreEqual(pcs::CppString::npos, test_str.find("A", 15));
			Assert::AreEqual(size_t(0), test_str.find(""));
			Assert::AreEqual(size_t(27), test_str.find(".", 14));
			Assert::AreEqual(pcs::CppString::npos, test_str.find(".", 28));
			Assert::AreEqual(size_t(13), test_str.find(".", 13));

			pcs::CppWString wtest{ L"ABC0123456789.ABC0123456789." };
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

				pcs::CppWString ws(wch);
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
			Assert::AreEqual(size_t(14), wtest.find(L"A", 1));
			Assert::AreEqual(pcs::CppString::npos, wtest.find(L"A", 15));
			Assert::AreEqual(size_t(0), wtest.find(L""));
			Assert::AreEqual(size_t(27), wtest.find(L".", 14));
			Assert::AreEqual(pcs::CppString::npos, wtest.find(L".", 28));
			Assert::AreEqual(size_t(13), wtest.find(L".", 13));
		}

		TEST_METHOD(find_n)
		{
			size_t found_pos;

			pcs::CppString test_str{ "ABC0123456789.ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test_str.MyBaseClass::find(ch), test_str.find_n(ch, size_t(-1)));

				found_pos = test_str.substr(2).MyBaseClass::find(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find_n(ch, 2));
				else
					Assert::AreEqual(found_pos, test_str.substr(2).find_n(ch, test_str.size() - 2));

				found_pos = test_str.substr(2, 5).MyBaseClass::find(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find_n(ch, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, test_str.find_n(ch, 2, pcs::CppString::size_type(5)) - 2);

				pcs::CppString s(ch);
				Assert::AreEqual(test_str.MyBaseClass::find(s), test_str.find_n(s, size_t(-1)));
				found_pos = test_str.substr(2).MyBaseClass::find(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find_n(s, 2));
				else
					Assert::AreEqual(found_pos, test_str.substr(2).find_n(s, test_str.size() - 2));

				found_pos = test_str.substr(2, 5).MyBaseClass::find(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.find_n(s, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, test_str.find_n(s, 2, pcs::CppString::size_type(5)) - 2);

				if (c > 0) {
					char str[2]{ ch, 0 };
					Assert::AreEqual(test_str.MyBaseClass::find(str), test_str.find_n(str, size_t(-1)));

					found_pos = test_str.substr(2).MyBaseClass::find(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.find_n(str, test_str.size() - 2));
					else
						Assert::AreEqual(found_pos, test_str.substr(2).find_n(str, test_str.size() - 2));

					found_pos = test_str.substr(2, 5).MyBaseClass::find(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.find_n(str, 2, pcs::CppString::size_type(5)));
					else
						Assert::AreEqual(found_pos, test_str.find_n(str, 2, pcs::CppString::size_type(5)) - 2);
				}
			}
			Assert::AreEqual(size_t(14), test_str.find_n("A", 1, test_str.size() - 1));
			Assert::AreEqual(pcs::CppString::npos, test_str.find_n("A", 15, 1));
			Assert::AreEqual(size_t(0), test_str.find_n("", size_t(-1)));
			Assert::AreEqual(size_t(27), test_str.find_n(".", 14, test_str.size() - 14));
			Assert::AreEqual(pcs::CppString::npos, test_str.find_n(".", 28, 1));
			Assert::AreEqual(size_t(13), test_str.find_n(".", 13, test_str.size() - 13));

			pcs::CppWString wtest{ L"ABC0123456789.ABC0123456789." };
			for (int wc = 0; wc <= 0xffff; ++wc) {
				wchar_t wch{ wchar_t(wc) };
				Assert::AreEqual(wtest.MyBaseClass::find(wch), wtest.find_n(wch, size_t(-1)));

				found_pos = wtest.substr(2).MyBaseClass::find(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find_n(wch, 2));
				else
					Assert::AreEqual(found_pos, wtest.substr(2).find_n(wch, wtest.size() - 2));

				found_pos = wtest.substr(2, 5).MyBaseClass::find(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find_n(wch, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, wtest.find_n(wch, 2, pcs::CppString::size_type(5)) - 2);

				pcs::CppWString ws(wch);
				Assert::AreEqual(wtest.MyBaseClass::find(ws), wtest.find_n(ws, size_t(-1)));
				found_pos = wtest.substr(2).MyBaseClass::find(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find_n(ws, 2));
				else
					Assert::AreEqual(found_pos, wtest.substr(2).find_n(ws, wtest.size() - 2));

				found_pos = wtest.substr(2, 5).MyBaseClass::find(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.find_n(ws, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, wtest.find_n(ws, 2, pcs::CppString::size_type(5)) - 2);

				if (wc > 0) {
					wchar_t wstr[2]{ wch, 0 };
					Assert::AreEqual(wtest.MyBaseClass::find(wstr), wtest.find_n(wstr, size_t(-1)));

					found_pos = wtest.substr(2).MyBaseClass::find(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.find_n(wstr, wtest.size() - 2));
					else
						Assert::AreEqual(found_pos, wtest.substr(2).find_n(wstr, wtest.size() - 2));

					found_pos = wtest.substr(2, 5).MyBaseClass::find(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.find_n(wstr, 2, pcs::CppString::size_type(5)));
					else
						Assert::AreEqual(found_pos, wtest.find_n(wstr, 2, pcs::CppString::size_type(5)) - 2);
				}
			}
			Assert::AreEqual(size_t(14), wtest.find_n(L"A", 1, wtest.size() - 1));
			Assert::AreEqual(pcs::CppString::npos, wtest.find_n(L"A", 15, 1));
			Assert::AreEqual(size_t(0), wtest.find_n(L"", size_t(-1)));
			Assert::AreEqual(size_t(27), wtest.find_n(L".", 14, wtest.size() - 14));
			Assert::AreEqual(pcs::CppString::npos, wtest.find_n(L".", 28, 1));
			Assert::AreEqual(size_t(13), wtest.find_n(L".", 13, wtest.size() - 13));

		}

		TEST_METHOD(format)
		{
			pcs::CppString s;
			s.format("{:d}, {:d}, {:s}", 1, 2, "Abc");
			Assert::AreEqual("1, 2, Abc", s.c_str());

			const int x{ 5 };
			const unsigned long long y{ 6 };
			const double pi{ 3.141592653529 };
			const std::string t{ "abc." };
			Assert::AreEqual("56 3.1415927abc.", (s.format("{}{}{:10.7f}{:s}", x, y, pi, t)).c_str());

			pcs::CppWString ws;
			ws.format(L"{:d}, {:d}, {}", 1, 2, L"Abc");
			Assert::AreEqual(L"1, 2, Abc", ws.c_str());

			const std::wstring wt{ L"abc." };
			Assert::AreEqual(L"56 3.1415927abc.", (ws.format(L"{}{}{:10.7f}{:s}", x, y, pi, wt)).c_str());
		}

		TEST_METHOD(index_char)
		{
			using string_type = pcs::CppString;

			string_type test_str{ "ABC0123456789." };
			char ch{ '3' };
			Assert::AreEqual(test_str.MyBaseClass::find(ch), test_str.index(ch));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::find(ch), test_str.index(ch, 2) - 2);
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::find(ch), test_str.index(ch, 2, string_type::size_type(5 + 2 - 1)) - 2);
			try {
				const string_type::size_type pos = test_str.index('z');
				Assert::IsTrue(pos != pcs::CppString::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index('z', 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index('z', 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test_str.MyBaseClass::find(s), test_str.index(s));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::find(s), test_str.index(s, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(s), test_str.index(s, 3, string_type::size_type(5 + 3 - 1)) - 3);
			s = 'z';
			try {
				const string_type::size_type pos = test_str.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			char str[2]{ ch, 0 };
			Assert::AreEqual(test_str.MyBaseClass::find(str), test_str.index(str));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::find(str), test_str.index(str, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(str), test_str.index(str, 3, string_type::size_type(5 + 3 - 1)) - 3);
			str[0] = 'z';
			try {
				const string_type::size_type pos = test_str.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(index_wchart)
		{
			using string_type = pcs::CppWString;

			string_type test_str( L"ABC0123456789." );
			wchar_t ch{ L'3' };
			Assert::AreEqual(test_str.MyBaseClass::find(ch), test_str.index(ch));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::find(ch), test_str.index(ch, 2) - 2);
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::find(ch), test_str.index(ch, 2, string_type::size_type(5 + 2 - 1)) - 2);
			try {
				const string_type::size_type pos = test_str.index('z');
				Assert::IsTrue(pos != pcs::CppString::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index('z', 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index('z', 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test_str.MyBaseClass::find(s), test_str.index(s));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::find(s), test_str.index(s, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(s), test_str.index(s, 3, string_type::size_type(5 + 3 - 1)) - 3);
			s = 'z';
			try {
				const string_type::size_type pos = test_str.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			wchar_t str[2]{ ch, 0 };
			Assert::AreEqual(test_str.MyBaseClass::find(str), test_str.index(str));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::find(str), test_str.index(str, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(str), test_str.index(str, 3, string_type::size_type(5 + 3 - 1)) - 3);
			str[0] = 'z';
			try {
				const string_type::size_type pos = test_str.index(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.index(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(index_n_char)
		{
			using string_type = pcs::CppString;

			pcs::CppString test_str{ "ABC0123456789." };
			char ch{ '3' };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::find(ch), test_str.index_n(ch, 20));
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::find(ch), test_str.index_n(ch, 2, 5) - 2);
			try {
				const string_type::size_type pos = test_str.index_n('z', 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.index_n('z', 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			pcs::CppString s(ch);
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::find(s), test_str.index_n(s, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(s), test_str.index_n(s, 3, 5) - 3);
			s = 'z';
			try {
				const string_type::size_type pos = test_str.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			char str[2]{ ch, 0 };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::find(str), test_str.index_n(str, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(str), test_str.index_n(str, 3, 5) - 3);
			str[0] = 'z';
			try {
				const string_type::size_type pos = test_str.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(index_n_wchar_t)
		{
			using string_type = pcs::CppWString;

			string_type test_str{ L"ABC0123456789." };
			wchar_t ch{ L'3'};
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::find(ch), test_str.index_n(ch, 20));
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::find(ch), test_str.index_n(ch, 2, 5) - 2);
			try {
				const string_type::size_type pos = test_str.index_n('z', 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.index_n('z', 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::find(s), test_str.index_n(s, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(s), test_str.index_n(s, 3, 5) - 3);
			try {
				const string_type::size_type pos = test_str.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.index_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			wchar_t str[2]{ ch, 0 };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::find(str), test_str.index_n(str, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::find(str), test_str.index_n(str, 3, 5) - 3);
			str[0] = L'z';
			try {
				const string_type::size_type pos = test_str.index_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.index_n(s, 2, 5);
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
			Assert::IsFalse(pcs::CppString().isalpha());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(3, ch);
				Assert::AreEqual(pcs::is_alpha(ch), s.isalpha());
			}

			Assert::IsFalse(pcs::CppWString().isalpha());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(3, wch);
				Assert::AreEqual(pcs::is_alpha(wch), ws.isalpha());
			}
		}

		TEST_METHOD(isascii)
		{
			Assert::IsTrue(pcs::CppString().isascii());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(3, ch);
				Assert::AreEqual(pcs::is_ascii(ch), s.isascii());
			}

			Assert::IsTrue(pcs::CppWString().isascii());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(3, wch);
				Assert::AreEqual(pcs::is_ascii(wch), ws.isascii());
			}
		}

		TEST_METHOD(isdecimal)
		{
			Assert::IsFalse(pcs::CppString().isdecimal());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_decimal(ch), s.isdecimal());
			}

			Assert::IsFalse(pcs::CppWString().isdecimal());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_decimal(wch), ws.isdecimal());
			}
		}

		TEST_METHOD(isdigit)
		{
			Assert::IsFalse(pcs::CppString().isdigit());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_digit(ch), s.isdigit());
			}

			Assert::IsFalse(pcs::CppWString().isdigit());
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
			Assert::IsTrue(pcs::CppString("abcdefghijklmnopqrstuvwxyz_0123456789").isidentifier());
			Assert::IsTrue(pcs::CppString("_0123456789").isidentifier());
			Assert::IsTrue(pcs::CppString("__").isidentifier());
			Assert::IsFalse(pcs::CppString("_abcdefghijklmnopqrstuvwxyz0123456789.").isidentifier());
			Assert::IsFalse(pcs::CppString("0a").isidentifier());

			Assert::IsTrue(pcs::CppWString(L"_").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"A").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"b").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"_0123456789abcdefghijklmnopqrstuvwxyz_").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"abcdefghijk0123456789lmnopqrstuvwxyz_").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"abcdefghijk0123456789_lmnopqrstuvwxyz").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"_0123456789").isidentifier());
			Assert::IsTrue(pcs::CppWString(L"__").isidentifier());
			Assert::IsFalse(pcs::CppWString(L"_0123456789abcdefghijklmnopqrstuvwxyz.").isidentifier());
			Assert::IsFalse(pcs::CppWString(L"9z").isidentifier());
		}

		TEST_METHOD(islower)
		{
			Assert::IsFalse(pcs::CppString().islower());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_lower(ch), s.islower());
			}

			Assert::IsFalse(pcs::CppWString().islower());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_lower(wch), ws.islower());
			}
		}

		TEST_METHOD(isnumeric)
		{
			Assert::IsFalse(pcs::CppString().isnumeric());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_numeric(ch), s.isnumeric());
			}

			Assert::IsFalse(pcs::CppWString().isnumeric());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_numeric(wch), ws.isnumeric());
			}
		}

		TEST_METHOD(isprintable)
		{
			Assert::IsTrue(pcs::CppString().isprintable());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_printable(ch), s.isprintable());
			}

			Assert::IsTrue(pcs::CppWString().isprintable());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_printable(wch), ws.isprintable());
			}
		}

		TEST_METHOD(ispunctuation)
		{
			Assert::IsFalse(pcs::CppString().ispunctuation());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(3, ch);
				Assert::IsFalse(s.ispunctuation());
				Assert::AreEqual(pcs::is_punctuation(ch), pcs::CppString(ch).ispunctuation());
			}

			Assert::IsFalse(pcs::CppWString().ispunctuation());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(3, wch);
				Assert::IsFalse(ws.ispunctuation());
				Assert::AreEqual(pcs::is_punctuation(wch), pcs::CppWString(wch).ispunctuation());
			}
		}

		TEST_METHOD(isspace)
		{
			Assert::IsFalse(pcs::CppString().isspace());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_space(ch), s.isspace());
			}

			Assert::IsFalse(pcs::CppWString().isspace());
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
			Assert::IsFalse(pcs::CppString().isupper());
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_upper(ch), s.isupper());
			}

			Assert::IsFalse(pcs::CppWString().isupper());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_upper(wch), ws.isupper());
			}
		}

		TEST_METHOD(is_words_sep)
		{
			Assert::IsFalse(pcs::CppString().is_words_sep());
			for (int c = 32; c <= 255; ++c) {
				const char ch{ char(c) };
				pcs::CppString s(5, ch);
				Assert::AreEqual(pcs::is_space(ch) || pcs::is_punctuation(ch), s.is_words_sep());
			}

			Assert::IsFalse(pcs::CppWString().is_words_sep());
			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				pcs::CppWString ws(5, wch);
				Assert::AreEqual(pcs::is_space(wch) || pcs::is_punctuation(wch), ws.is_words_sep());
			}
		}

		TEST_METHOD(join)
		{
			pcs::CppString s("##");
			std::array<pcs::CppString, 2> arr{ "abcd", "efg" };
			Assert::AreEqual(pcs::CppString("abcd##efg").c_str(), s.join(arr).c_str());
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789").c_str(), s.join(std::array<pcs::CppString, 3>{ "abcd", "efg", "123456789" }).c_str());

			pcs::CppWString ws(L"##");
			std::array<pcs::CppWString, 2> warr{ L"abcd", L"efg" };
			Assert::AreEqual(pcs::CppWString(L"abcd##efg").c_str(), ws.join(warr).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789").c_str(), ws.join(std::array<pcs::CppWString, 3>{ L"abcd", L"efg", L"123456789" }).c_str());

			std::vector<pcs::CppString> vec{ "abcd", "efg" };
			Assert::AreEqual(pcs::CppString("abcd##efg").c_str(), s.join(vec).c_str());
			vec.push_back("123456789");
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789").c_str(), s.join(vec).c_str());

			std::vector<pcs::CppWString> wvec{ L"abcd", L"efg" };
			Assert::AreEqual(pcs::CppWString(L"abcd##efg").c_str(), ws.join(wvec).c_str());
			wvec.push_back(L"123456789");
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789").c_str(), ws.join(wvec).c_str());

			using namespace pcs;
			Assert::AreEqual(pcs::CppString("abcd##efg").c_str(), s.join(pcs::CppString("abcd"), pcs::CppString("efg")).c_str());
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789").c_str(), s.join(pcs::CppString("abcd"), pcs::CppString("efg"), pcs::CppString("123456789")).c_str());
			Assert::AreEqual(pcs::CppString("abcd##efg##123456789##0").c_str(), s.join("abcd", "efg", "123456789", "0").c_str());
			Assert::AreEqual(pcs::CppString("abcd# #efg# #123456789# #0").c_str(), "# #"_cs.join("abcd", "efg", "123456789", "0").c_str());
			Assert::AreEqual("abcdE", "##"_cs.join("abcdE").c_str());
			Assert::AreEqual("##", "##"_cs.join().c_str());
			Assert::AreEqual("", "##"_cs.join("").c_str());

			Assert::AreEqual(pcs::CppWString(L"abcd##efg").c_str(), ws.join(pcs::CppWString(L"abcd"), pcs::CppWString(L"efg")).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789").c_str(), ws.join(pcs::CppWString(L"abcd"), pcs::CppWString(L"efg"), pcs::CppWString(L"123456789")).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd##efg##123456789##0").c_str(), ws.join(L"abcd"_cs, L"efg"_cs, L"123456789"_cs, L"0"_cs).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcd# #efg# #123456789# #0").c_str(), L"# #"_cs.join(L"abcd", L"efg"_cs, L"123456789"_cs, L"0"_cs).c_str());
			Assert::AreEqual(pcs::CppWString(L"abcdE").c_str(), L"##"_cs.join(L"abcdE").c_str());
			Assert::AreEqual(pcs::CppWString(L"##").c_str(), L"##"_cs.join().c_str());
			Assert::AreEqual(pcs::CppWString(L"").c_str(), L"##"_cs.join(L"").c_str());
		}

		TEST_METHOD(ljust)
		{
			pcs::CppString s("abc");
			Assert::AreEqual("abc", s.ljust(1).c_str());
			Assert::AreEqual("abc", s.ljust(2).c_str());
			Assert::AreEqual("abc", s.ljust(3).c_str());
			Assert::AreEqual(" abc", s.ljust(4).c_str());
			Assert::AreEqual("  abc", s.ljust(5).c_str());
			Assert::AreEqual("abc", s.ljust(1).c_str());
			Assert::AreEqual("abc", s.ljust(2).c_str());
			Assert::AreEqual("abc", s.ljust(3).c_str());
			Assert::AreEqual(".abc", s.ljust(4, '.').c_str());
			Assert::AreEqual("..abc", s.ljust(5, '.').c_str());

			pcs::CppWString ws(L"abc");
			Assert::AreEqual(L"abc", ws.ljust(1).c_str());
			Assert::AreEqual(L"abc", ws.ljust(2).c_str());
			Assert::AreEqual(L"abc", ws.ljust(3).c_str());
			Assert::AreEqual(L" abc", ws.ljust(4).c_str());
			Assert::AreEqual(L"  abc", ws.ljust(5).c_str());
			Assert::AreEqual(L"abc", ws.ljust(1).c_str());
			Assert::AreEqual(L"abc", ws.ljust(2).c_str());
			Assert::AreEqual(L"abc", ws.ljust(3).c_str());
			Assert::AreEqual(L".abc", ws.ljust(4, '.').c_str());
			Assert::AreEqual(L"..abc", ws.ljust(5, '.').c_str());
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

			pcs::CppString s(255, '\0');
			for (int i : std::views::iota(0, 256))
				s[i] = pcs::CppString::value_type(i);
			pcs::CppString res{ s.lower() };
			for (auto const [cs, cr] : std::views::zip(s, res)) {
				if (std::islower(cs))
					Assert::IsTrue(std::islower(cr));
				else if (std::isupper(cs))
					Assert::IsTrue(std::islower(cr));
				else
					Assert::AreEqual(cs, cr);
			}

			pcs::CppWString ws(0xffff, '\0');
			for (int i : std::views::iota(0, 0x1'0000))
				ws[i] = pcs::CppWString::value_type(i);
			pcs::CppWString wres{ ws.lower() };
			for (auto const [wcs, wcr] : std::views::zip(ws, wres)) {
				if (std::islower(wcs))
					Assert::IsTrue(std::islower(wcr));
				else if (std::isupper(wcs))
					Assert::IsTrue(std::islower(wcr));
				else
					Assert::AreEqual(wcs, wcr);
			}

		}

		TEST_METHOD(lstrip)
		{
			using namespace pcs;
			pcs::CppString s("abcd");
			Assert::AreEqual("cd", s.lstrip("baCD").c_str());
			Assert::AreEqual("abcd", s.lstrip("xyz").c_str());
			Assert::AreEqual("abcd", s.lstrip("").c_str());
			Assert::AreEqual("cd", "abbabaabcd"_cs.lstrip("baCD").c_str());
			Assert::AreEqual("cdab", "abbabaabcdab"_cs.lstrip("baCD").c_str());
			Assert::AreEqual("abcd", " abcd"_cs.lstrip().c_str());
			Assert::AreEqual("abcd", "  abcd"_cs.lstrip().c_str());
			Assert::AreEqual("abcd", "       abcd"_cs.lstrip().c_str());
			Assert::AreEqual("a  bcd", "         a  bcd"_cs.lstrip().c_str());
			Assert::AreEqual("a  bcd   ", "         a  bcd   "_cs.lstrip().c_str());

			pcs::CppWString ws(L"abcd");
			Assert::AreEqual(L"cd", ws.lstrip(L"baCD").c_str());
			Assert::AreEqual(L"abcd", ws.lstrip(L"xyz").c_str());
			Assert::AreEqual(L"abcd", ws.lstrip(L"").c_str());
			Assert::AreEqual(L"cd", L"abbabaabcd"_cs.lstrip(L"baCD").c_str());
			Assert::AreEqual(L"cdab", L"abbabaabcdab"_cs.lstrip(L"baCD").c_str());
			Assert::AreEqual(L"abcd", L" abcd"_cs.lstrip().c_str());
			Assert::AreEqual(L"abcd", L"  abcd"_cs.lstrip().c_str());
			Assert::AreEqual(L"abcd", L"       abcd"_cs.lstrip().c_str());
			Assert::AreEqual(L"a  bcd", L"         a  bcd"_cs.lstrip().c_str());
			Assert::AreEqual(L"a  bcd   ", L"         a  bcd   "_cs.lstrip().c_str());
		}

		TEST_METHOD(operator_slice)
		{
			pcs::CppString text("AbcdefGhijklm");
			int text_size{ int(text.size()) };

			Assert::AreEqual(text(0, text_size).c_str(), text(pcs::Slice<int>()).c_str());
			Assert::AreEqual(text.c_str(), text(0, text_size).c_str());
			Assert::AreEqual(text.c_str(), text(pcs::StartSlice(0)).c_str());
			Assert::AreEqual(text.c_str(), text(pcs::StopSlice(123)).c_str());
			Assert::AreEqual(text.c_str(), text(pcs::StepSlice(1)).c_str());
			Assert::AreEqual(text.c_str(), text(pcs::StartStopSlice(0, 111)).c_str());
			Assert::AreEqual(text.c_str(), text(pcs::StartStepSlice(0, 1)).c_str());
			Assert::AreEqual(text.c_str(), text(pcs::StopStepSlice(text_size, 1)).c_str());

			Assert::AreEqual("AceGikm", text(pcs::Slice(0, text_size + 2, 2)).c_str());
			Assert::AreEqual("behk", text(pcs::Slice(1, text_size, 3)).c_str());

			Assert::AreEqual("", text(pcs::Slice(5, 4, 1)).c_str());
			Assert::AreEqual("", text(pcs::Slice(text_size, text_size + 1, 1)).c_str());
			Assert::AreEqual("", text(pcs::Slice(text_size + 2, text_size + 5, 1)).c_str());
			Assert::AreEqual("", text(pcs::Slice(5, 3, 2)).c_str());

			pcs::CppString reversed_text{ text };
			std::ranges::reverse(reversed_text);
			Assert::AreEqual(reversed_text.c_str(), text(text_size, 0, -1).c_str());
			Assert::AreEqual(reversed_text.c_str(), text(pcs::StartStepSlice(text_size, -1)).c_str());
			Assert::AreEqual(reversed_text.c_str(), text(pcs::StopStepSlice(0, -1)).c_str());
			Assert::AreEqual(reversed_text.c_str(), text(pcs::StepSlice(-1)).c_str());

			Assert::AreEqual("mkiGec", text(pcs::Slice(text_size, 0, -2)).c_str());
			Assert::AreEqual("mjGd", text(pcs::Slice(text_size-1, 1, -3)).c_str());

			Assert::AreEqual("", text(pcs::Slice(4, 5, -1)).c_str());
			Assert::AreEqual("", text(pcs::Slice(text_size + 1, text_size, -1)).c_str());
			Assert::AreEqual("", text(pcs::Slice(text_size + 5, text_size + 2, -1)).c_str());
			Assert::AreEqual("", text(pcs::Slice(3, 5, -2)).c_str());


			pcs::CppWString wtext(L"AbcdefGhijklm");
			text_size = int(wtext.size());

			Assert::AreEqual(wtext(0, text_size).c_str(), wtext(pcs::Slice<int>()).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(0, text_size).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(pcs::StartSlice(0)).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(pcs::StopSlice(123)).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(pcs::StepSlice(1)).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(pcs::StartStopSlice(0, 111)).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(pcs::StartStepSlice(0, 1)).c_str());
			Assert::AreEqual(wtext.c_str(), wtext(pcs::StopStepSlice(text_size, 1)).c_str());

			Assert::AreEqual(L"AceGikm", wtext(pcs::Slice(0, text_size + 2, 2)).c_str());
			Assert::AreEqual(L"behk", wtext(pcs::Slice(1, text_size, 3)).c_str());

			Assert::AreEqual(L"", wtext(pcs::Slice(5, 4, 1)).c_str());
			Assert::AreEqual(L"", wtext(pcs::Slice(text_size, text_size + 1, 1)).c_str());
			Assert::AreEqual(L"", wtext(pcs::Slice(text_size + 2, text_size + 5, 1)).c_str());
			Assert::AreEqual(L"", wtext(pcs::Slice(5, 3, 2)).c_str());

			pcs::CppWString wreversed_text{ wtext };
			std::ranges::reverse(wreversed_text);
			Assert::AreEqual(wreversed_text.c_str(), wtext(text_size, 0, -1).c_str());
			Assert::AreEqual(wreversed_text.c_str(), wtext(pcs::StartStepSlice(text_size, -1)).c_str());
			Assert::AreEqual(wreversed_text.c_str(), wtext(pcs::StopStepSlice(0, -1)).c_str());
			Assert::AreEqual(wreversed_text.c_str(), wtext(pcs::StepSlice(-1)).c_str());

			Assert::AreEqual(L"mkiGec", wtext(pcs::Slice(text_size, 0, -2)).c_str());
			Assert::AreEqual(L"mjGd", wtext(pcs::Slice(text_size - 1, 1, -3)).c_str());

			Assert::AreEqual(L"", wtext(pcs::Slice(4, 5, -1)).c_str());
			Assert::AreEqual(L"", wtext(pcs::Slice(text_size + 1, text_size, -1)).c_str());
			Assert::AreEqual(L"", wtext(pcs::Slice(text_size + 5, text_size + 2, -1)).c_str());
			Assert::AreEqual(L"", wtext(pcs::Slice(3, 5, -2)).c_str());
		}

		TEST_METHOD(operator_times)
		{
			pcs::CppString text("Abcd,");
			Assert::AreEqual("", (text * -1).c_str());
			Assert::AreEqual("", (text * 0).c_str());
			Assert::AreEqual(text.c_str(), (text * 1).c_str());
			Assert::AreEqual((text + text).c_str(), (text * 2).c_str());
			Assert::AreEqual((text + text + text).c_str(), (text * 3).c_str());

			pcs::CppWString wtext(L"Abcd,");
			Assert::AreEqual(L"", (wtext * -1).c_str());
			Assert::AreEqual(L"", (wtext * 0).c_str());
			Assert::AreEqual(wtext.c_str(), (wtext * 1).c_str());
			Assert::AreEqual((wtext + wtext).c_str(), (wtext * 2).c_str());
			Assert::AreEqual((wtext + wtext + wtext).c_str(), (wtext * 3).c_str());
		}

		TEST_METHOD(partition)
		{
			pcs::CppString s("abcd#123efg");
			std::vector<pcs::CppString> res{ s.partition("#123") };
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

			using namespace pcs;
			res = ""_cs.partition("A");
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			pcs::CppWString ws(L"abcd#123efg");
			std::vector<pcs::CppWString> wres{ ws.partition(L"#123") };
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

			wres = L""_cs.partition(L"A");
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
		}

		TEST_METHOD(removeprefix)
		{
			using namespace pcs;
			pcs::CppString s("abcd");
			Assert::AreEqual("cd", s.removeprefix("ab").c_str());
			Assert::AreEqual("abcd", s.removeprefix("ba").c_str());
			Assert::AreEqual("abcd", s.removeprefix("").c_str());
			Assert::AreEqual("abaabcd", "abbabaabcd"_cs.removeprefix("abb").c_str());
			Assert::AreEqual("cdab", "abcdab"_cs.removeprefix("ab").c_str());

			pcs::CppWString ws(L"abcd");
			Assert::AreEqual(L"cd", ws.removeprefix(L"ab").c_str());
			Assert::AreEqual(L"abcd", ws.removeprefix(L"ba").c_str());
			Assert::AreEqual(L"abcd", ws.removeprefix(L"").c_str());
			Assert::AreEqual(L"abaabcd", L"abbabaabcd"_cs.removeprefix(L"abb").c_str());
			Assert::AreEqual(L"cdab", L"abcdab"_cs.removeprefix(L"ab").c_str());
		}

		TEST_METHOD(removesuffix)
		{
			using namespace pcs;
			pcs::CppString s("abcd");
			Assert::AreEqual("ab", s.removesuffix("cd").c_str());
			Assert::AreEqual("abcd", s.removesuffix("dc").c_str());
			Assert::AreEqual("abcd", s.removesuffix("").c_str());
			Assert::AreEqual("abbaba", "abbabaabcd"_cs.removesuffix("abcd").c_str());
			Assert::AreEqual("abcd", "abcdab"_cs.removesuffix("ab").c_str());

			pcs::CppWString ws(L"abcd");
			Assert::AreEqual(L"ab", ws.removesuffix(L"cd").c_str());
			Assert::AreEqual(L"abcd", ws.removesuffix(L"dc").c_str());
			Assert::AreEqual(L"abcd", ws.removesuffix(L"").c_str());
			Assert::AreEqual(L"abbaba", L"abbabaabcd"_cs.removesuffix(L"abcd").c_str());
			Assert::AreEqual(L"abcd", L"abcdab"_cs.removesuffix(L"ab").c_str());
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

			pcs::CppString test_str{ "ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test_str.MyBaseClass::rfind(ch), test_str.rfind(ch));

				found_pos = test_str.substr(2).MyBaseClass::rfind(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind(ch, 2));
				else
					Assert::AreEqual(found_pos, test_str.rfind(ch, 2) - 2);

				found_pos = test_str.substr(2, 5).MyBaseClass::rfind(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind(ch, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test_str.rfind(ch, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				pcs::CppString s(ch);
				Assert::AreEqual(test_str.MyBaseClass::rfind(s), test_str.rfind(s));
				found_pos = test_str.substr(2).MyBaseClass::rfind(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind(s, 2));
				else
					Assert::AreEqual(found_pos, test_str.rfind(s, 2) - 2);

				found_pos = test_str.substr(2, 5).MyBaseClass::rfind(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind(s, 2, pcs::CppString::size_type(5 + 2 - 1)));
				else
					Assert::AreEqual(found_pos, test_str.rfind(s, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);

				if (c > 0) {
					char str[2]{ ch, 0 };
					Assert::AreEqual(test_str.MyBaseClass::rfind(str), test_str.rfind(str));

					found_pos = test_str.substr(2).MyBaseClass::rfind(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.rfind(str, 2));
					else
						Assert::AreEqual(found_pos, test_str.rfind(str, 2) - 2);

					found_pos = test_str.substr(2, 5).MyBaseClass::rfind(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.rfind(str, 2, pcs::CppString::size_type(5 + 2 - 1)));
					else
						Assert::AreEqual(found_pos, test_str.rfind(str, 2, pcs::CppString::size_type(5 + 2 - 1)) - 2);
				}
			}
			Assert::AreEqual(pcs::CppString::npos, test_str.rfind("A", 1));
			Assert::AreEqual(test_str.size(), test_str.rfind(""));
			Assert::AreEqual(pcs::CppString::npos, test_str.rfind(".", 14));
			Assert::AreEqual(size_t(13), test_str.rfind(".", 13));

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

				pcs::CppWString ws(wch);
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

		TEST_METHOD(rfind_n)
		{
			size_t found_pos;

			pcs::CppString test_str{ "ABC0123456789.ABC0123456789." };
			for (int c = 0; c <= 255; ++c) {
				char ch{ char(c) };
				Assert::AreEqual(test_str.MyBaseClass::rfind(ch), test_str.rfind_n(ch, size_t(-1)));

				found_pos = test_str.substr(2).MyBaseClass::rfind(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind_n(ch, 2));
				else
					Assert::AreEqual(found_pos, test_str.substr(2).rfind_n(ch, test_str.size() - 2));

				found_pos = test_str.substr(2, 5).MyBaseClass::rfind(ch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind_n(ch, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, test_str.rfind_n(ch, 2, pcs::CppString::size_type(5)) - 2);

				pcs::CppString s(ch);
				Assert::AreEqual(test_str.MyBaseClass::rfind(s), test_str.rfind_n(s, size_t(-1)));
				found_pos = test_str.substr(2).MyBaseClass::rfind(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind_n(s, 2));
				else
					Assert::AreEqual(found_pos, test_str.substr(2).rfind_n(s, test_str.size() - 2));

				found_pos = test_str.substr(2, 5).MyBaseClass::rfind(s);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, test_str.rfind_n(s, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, test_str.rfind_n(s, 2, pcs::CppString::size_type(5)) - 2);

				if (c > 0) {
					char str[2]{ ch, 0 };
					Assert::AreEqual(test_str.MyBaseClass::rfind(str), test_str.rfind_n(str, size_t(-1)));

					found_pos = test_str.substr(2).MyBaseClass::rfind(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.rfind_n(str, test_str.size() - 2));
					else
						Assert::AreEqual(found_pos, test_str.substr(2).rfind_n(str, test_str.size() - 2));

					found_pos = test_str.substr(2, 5).MyBaseClass::rfind(str);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, test_str.rfind_n(str, 2, pcs::CppString::size_type(5)));
					else
						Assert::AreEqual(found_pos, test_str.rfind_n(str, 2, pcs::CppString::size_type(5)) - 2);
				}
			}
			Assert::AreEqual(size_t(14), test_str.rfind_n("A", 1, test_str.size() - 1));
			Assert::AreEqual(pcs::CppString::npos, test_str.rfind_n("A", 15, 1));
			Assert::AreEqual(size_t(0), test_str.rfind_n("", size_t(-1)));
			Assert::AreEqual(size_t(27), test_str.rfind_n(".", 14, test_str.size() - 14));
			Assert::AreEqual(pcs::CppString::npos, test_str.rfind_n(".", 28, 1));
			Assert::AreEqual(size_t(27), test_str.rfind_n(".", 13, test_str.size() - 13));

			pcs::CppWString wtest{ L"ABC0123456789.ABC0123456789." };
			for (int wc = 0; wc <= 0xffff; ++wc) {
				wchar_t wch{ wchar_t(wc) };
				Assert::AreEqual(wtest.MyBaseClass::rfind(wch), wtest.rfind_n(wch, size_t(-1)));

				found_pos = wtest.substr(2).MyBaseClass::rfind(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind_n(wch, 2));
				else
					Assert::AreEqual(found_pos, wtest.substr(2).rfind_n(wch, wtest.size() - 2));

				found_pos = wtest.substr(2, 5).MyBaseClass::rfind(wch);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind_n(wch, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, wtest.rfind_n(wch, 2, pcs::CppString::size_type(5)) - 2);

				pcs::CppWString ws(wch);
				Assert::AreEqual(wtest.MyBaseClass::rfind(ws), wtest.rfind_n(ws, size_t(-1)));
				found_pos = wtest.substr(2).MyBaseClass::rfind(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind_n(ws, 2));
				else
					Assert::AreEqual(found_pos, wtest.substr(2).rfind_n(ws, wtest.size() - 2));

				found_pos = wtest.substr(2, 5).MyBaseClass::rfind(ws);
				if (found_pos == pcs::CppString::npos)
					Assert::AreEqual(found_pos, wtest.rfind_n(ws, 2, pcs::CppString::size_type(5)));
				else
					Assert::AreEqual(found_pos, wtest.rfind_n(ws, 2, pcs::CppString::size_type(5)) - 2);

				if (wc > 0) {
					wchar_t wstr[2]{ wch, 0 };
					Assert::AreEqual(wtest.MyBaseClass::rfind(wstr), wtest.rfind_n(wstr, size_t(-1)));

					found_pos = wtest.substr(2).MyBaseClass::rfind(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.rfind_n(wstr, wtest.size() - 2));
					else
						Assert::AreEqual(found_pos, wtest.substr(2).rfind_n(wstr, wtest.size() - 2));

					found_pos = wtest.substr(2, 5).MyBaseClass::rfind(wstr);
					if (found_pos == pcs::CppString::npos)
						Assert::AreEqual(found_pos, wtest.rfind_n(wstr, 2, pcs::CppString::size_type(5)));
					else
						Assert::AreEqual(found_pos, wtest.rfind_n(wstr, 2, pcs::CppString::size_type(5)) - 2);
				}
			}
			Assert::AreEqual(size_t(14), wtest.rfind_n(L"A", 1, wtest.size() - 1));
			Assert::AreEqual(pcs::CppString::npos, wtest.rfind_n(L"A", 15, 1));
			Assert::AreEqual(size_t(0), wtest.rfind_n(L"", size_t(-1)));
			Assert::AreEqual(size_t(27), wtest.rfind_n(L".", 14, wtest.size() - 14));
			Assert::AreEqual(pcs::CppString::npos, wtest.rfind_n(L".", 28, 1));
			Assert::AreEqual(size_t(27), wtest.rfind_n(L".", 13, wtest.size() - 13));
		}

		TEST_METHOD(rindex_char)
		{
			using string_type = pcs::CppString;

			string_type test_str{ "ABC0123456789." };
			char ch{ '3' };
			Assert::AreEqual(test_str.MyBaseClass::rfind(ch), test_str.rindex(ch));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::rfind(ch), test_str.rindex(ch, 2) - 2);
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::rfind(ch), test_str.rindex(ch, 2, string_type::size_type(5 + 2 - 1)) - 2);

			try {
				const string_type::size_type pos = test_str.rindex('z');
				Assert::IsTrue(pos != pcs::CppString::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex('z', 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex('z', 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test_str.MyBaseClass::rfind(s), test_str.rindex(s));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::rfind(s), test_str.rindex(s, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(s), test_str.rindex(s, 3, string_type::size_type(5 + 3 - 1)) - 3);
			s = 'z';
			try {
				const string_type::size_type pos = test_str.rindex(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			char str[2]{ ch, 0 };
			Assert::AreEqual(test_str.MyBaseClass::rfind(str), test_str.rindex(str));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::rfind(str), test_str.rindex(str, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(str), test_str.rindex(str, 3, string_type::size_type(5 + 3 - 1)) - 3);
			str[0] = 'z';
			try {
				const string_type::size_type pos = test_str.rindex(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(rindex_wchart)
		{
			using string_type = pcs::CppWString;

			string_type test_str(L"ABC0123456789.");
			wchar_t ch{ L'3' };
			Assert::AreEqual(test_str.MyBaseClass::rfind(ch), test_str.rindex(ch));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::rfind(ch), test_str.rindex(ch, 2) - 2);
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::rfind(ch), test_str.rindex(ch, 2, string_type::size_type(5 + 2 - 1)) - 2);
			try {
				const string_type::size_type pos = test_str.rindex('z');
				Assert::IsTrue(pos != pcs::CppString::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex('z', 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex('z', 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test_str.MyBaseClass::rfind(s), test_str.rindex(s));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::rfind(s), test_str.rindex(s, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(s), test_str.rindex(s, 3, string_type::size_type(5 + 3 - 1)) - 3);
			s = 'z';
			try {
				const string_type::size_type pos = test_str.rindex(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			wchar_t str[2]{ ch, 0 };
			Assert::AreEqual(test_str.MyBaseClass::rfind(str), test_str.rindex(str));
			Assert::AreEqual(test_str.substr(2).MyBaseClass::rfind(str), test_str.rindex(str, 2) - 2);
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(str), test_str.rindex(str, 3, string_type::size_type(5 + 3 - 1)) - 3);
			str[0] = 'z';
			try {
				const string_type::size_type pos = test_str.rindex(s);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			try {
				const string_type::size_type pos = test_str.rindex(s, 2, string_type::size_type(5 + 2 - 1));
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(rindex_n_char)
		{
			using string_type = pcs::CppString;

			pcs::CppString test_str{ "ABC0123456789." };
			char ch{ '3' };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::rfind(ch), test_str.rindex_n(ch, 20));
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::rfind(ch), test_str.rindex_n(ch, 2, 5) - 2);
			try {
				const string_type::size_type pos = test_str.rindex_n('z', 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.rindex_n('z', 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			pcs::CppString s(ch);
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::rfind(s), test_str.rindex_n(s, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(s), test_str.rindex_n(s, 3, 5) - 3);
			s = 'z';
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			char str[2]{ ch, 0 };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::rfind(str), test_str.rindex_n(str, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(str), test_str.rindex_n(str, 3, 5) - 3);
			str[0] = 'z';
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(rindex_n_wchar_t)
		{
			using string_type = pcs::CppWString;

			string_type test_str{ L"ABC0123456789." };
			wchar_t ch{ L'3' };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::rfind(ch), test_str.rindex_n(ch, 20));
			Assert::AreEqual(test_str.substr(2, 5).MyBaseClass::rfind(ch), test_str.rindex_n(ch, 2, 5) - 2);
			try {
				const string_type::size_type pos = test_str.rindex_n('z', 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.rindex_n('z', 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			string_type s(ch);
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::rfind(s), test_str.rindex_n(s, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(s), test_str.rindex_n(s, 3, 5) - 3);
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }

			wchar_t str[2]{ ch, 0 };
			Assert::AreEqual(test_str.substr(0, 20).MyBaseClass::rfind(str), test_str.rindex_n(str, 20));
			Assert::AreEqual(test_str.substr(3, 5).MyBaseClass::rfind(str), test_str.rindex_n(str, 3, 5) - 3);
			str[0] = L'z';
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 20);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
			try {
				const string_type::size_type pos = test_str.rindex_n(s, 2, 5);
				Assert::IsTrue(pos != string_type::npos);
			}
			catch (const string_type::NotFoundException e) { /* ok case! */ }
		}

		TEST_METHOD(rjust)
		{
			pcs::CppString s("abc");
			Assert::AreEqual("abc", s.rjust(1).c_str());
			Assert::AreEqual("abc", s.rjust(2).c_str());
			Assert::AreEqual("abc", s.rjust(3).c_str());
			Assert::AreEqual("abc ", s.rjust(4).c_str());
			Assert::AreEqual("abc  ", s.rjust(5).c_str());
			Assert::AreEqual("abc", s.rjust(1).c_str());
			Assert::AreEqual("abc", s.rjust(2).c_str());
			Assert::AreEqual("abc", s.rjust(3).c_str());
			Assert::AreEqual("abc.", s.rjust(4, '.').c_str());
			Assert::AreEqual("abc..", s.rjust(5, '.').c_str());

			pcs::CppWString ws(L"abc");
			Assert::AreEqual(L"abc", ws.rjust(1).c_str());
			Assert::AreEqual(L"abc", ws.rjust(2).c_str());
			Assert::AreEqual(L"abc", ws.rjust(3).c_str());
			Assert::AreEqual(L"abc ", ws.rjust(4).c_str());
			Assert::AreEqual(L"abc  ", ws.rjust(5).c_str());
			Assert::AreEqual(L"abc", ws.rjust(1).c_str());
			Assert::AreEqual(L"abc", ws.rjust(2).c_str());
			Assert::AreEqual(L"abc", ws.rjust(3).c_str());
			Assert::AreEqual(L"abc.", ws.rjust(4, '.').c_str());
			Assert::AreEqual(L"abc..", ws.rjust(5, '.').c_str());
		}

		TEST_METHOD(rpartition)
		{
			pcs::CppString s("abcd#123efg#123hij");
			std::vector<pcs::CppString> res{ s.rpartition("#123") };
			Assert::AreEqual("abcd#123efg", res[0].c_str());
			Assert::AreEqual("#123", res[1].c_str());
			Assert::AreEqual("hij", res[2].c_str());

			s = "abcd#123fgh#123";
			res = s.rpartition("#123");
			Assert::AreEqual("abcd#123fgh", res[0].c_str());
			Assert::AreEqual("#123", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			res = s.rpartition("XYZ");
			Assert::AreEqual("abcd#123fgh#123", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			using namespace pcs;
			res = ""_cs.rpartition("A");
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			pcs::CppWString ws(L"abcd#123efg#123hij");
			std::vector<pcs::CppWString> wres{ ws.rpartition(L"#123") };
			Assert::AreEqual(L"abcd#123efg", wres[0].c_str());
			Assert::AreEqual(L"#123", wres[1].c_str());
			Assert::AreEqual(L"hij", wres[2].c_str());

			ws = L"abcd#123fgh#123";
			wres = ws.rpartition(L"#123");
			Assert::AreEqual(L"abcd#123fgh", wres[0].c_str());
			Assert::AreEqual(L"#123", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());

			wres = ws.rpartition(L"XYZ");
			Assert::AreEqual(L"abcd#123fgh#123", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());

			wres = L""_cs.rpartition(L"A");
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
		}

		TEST_METHOD(rsplit)
		{
			pcs::CppString s(" abcd efg   hij klmn  ");
			std::vector<pcs::CppString> res{ s.rsplit() };
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.rsplit(0);
			Assert::AreEqual(pcs::CppString::size_type(1), res.size());
			Assert::AreEqual(" abcd efg   hij klmn  ", res[0].c_str());

			res = s.rsplit(1);
			Assert::AreEqual(pcs::CppString::size_type(2), res.size());
			Assert::AreEqual(" abcd efg   hij klmn ", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());

			res = s.rsplit(2);
			Assert::AreEqual(pcs::CppString::size_type(3), res.size());
			Assert::AreEqual(" abcd efg   hij klmn", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			res = s.rsplit(3);
			Assert::AreEqual(pcs::CppString::size_type(4), res.size());
			Assert::AreEqual(" abcd efg   hij", res[0].c_str());
			Assert::AreEqual("klmn", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());

			res = s.rsplit(4);
			Assert::AreEqual(pcs::CppString::size_type(5), res.size());
			Assert::AreEqual(" abcd efg  ", res[0].c_str());
			Assert::AreEqual("hij", res[1].c_str());
			Assert::AreEqual("klmn", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());

			res = s.rsplit(5);
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual(" abcd efg ", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("hij", res[2].c_str());
			Assert::AreEqual("klmn", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());

			res = s.rsplit(6);
			Assert::AreEqual(pcs::CppString::size_type(7), res.size());
			Assert::AreEqual(" abcd efg", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("hij", res[3].c_str());
			Assert::AreEqual("klmn", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("", res[6].c_str());

			res = s.rsplit(7);
			Assert::AreEqual(pcs::CppString::size_type(8), res.size());
			Assert::AreEqual(" abcd", res[0].c_str());
			Assert::AreEqual("efg", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("hij", res[4].c_str());
			Assert::AreEqual("klmn", res[5].c_str());
			Assert::AreEqual("", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());

			res = s.rsplit(8);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.rsplit(9);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.rsplit(10);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			s = pcs::CppString(5, ' ');  //"     "_cs;
			res = s.rsplit();
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());


			using namespace pcs;
			s = " abcd#123efg#123hij #123#123klmn  "_cs;
			res = s.rsplit("#123");
			Assert::AreEqual(pcs::CppString::size_type(5), res.size());
			Assert::AreEqual(" abcd", res[0].c_str());
			Assert::AreEqual("efg", res[1].c_str());
			Assert::AreEqual("hij ", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("klmn  ", res[4].c_str());

			s = "#123#123abcd#123123efg#123hij #123#123klmn  #123#123"_cs;
			res = s.rsplit("#123");
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("123efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.rsplit("#123", 1);
			Assert::AreEqual(pcs::CppString::size_type(2), res.size());
			Assert::AreEqual("#123#123abcd#123123efg#123hij #123#123klmn  #123", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());

			res = s.rsplit("#123", 2);
			Assert::AreEqual(pcs::CppString::size_type(3), res.size());
			Assert::AreEqual("#123#123abcd#123123efg#123hij #123#123klmn  ", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			res = s.rsplit("#123", 3);
			Assert::AreEqual(pcs::CppString::size_type(4), res.size());
			Assert::AreEqual("#123#123abcd#123123efg#123hij #123", res[0].c_str());
			Assert::AreEqual("klmn  ", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());

			res = s.rsplit("#123", 4);
			Assert::AreEqual(pcs::CppString::size_type(5), res.size());
			Assert::AreEqual("#123#123abcd#123123efg#123hij ", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("klmn  ", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());

			res = s.rsplit("#123", 5);
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual("#123#123abcd#123123efg", res[0].c_str());
			Assert::AreEqual("hij ", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("klmn  ", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());

			res = s.rsplit("#123", 6);
			Assert::AreEqual(pcs::CppString::size_type(7), res.size());
			Assert::AreEqual("#123#123abcd", res[0].c_str());
			Assert::AreEqual("123efg", res[1].c_str());
			Assert::AreEqual("hij ", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("klmn  ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("", res[6].c_str());

			res = s.rsplit("#123", 7);
			Assert::AreEqual(pcs::CppString::size_type(8), res.size());
			Assert::AreEqual("#123", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("123efg", res[2].c_str());
			Assert::AreEqual("hij ", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("klmn  ", res[5].c_str());
			Assert::AreEqual("", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());

			res = s.rsplit("#123", 8);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("123efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.rsplit("#123", 9);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("123efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.rsplit("#123", 10);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("123efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());


			pcs::CppWString ws(L" abcd efg   hij klmn  ");
			std::vector<pcs::CppWString> wres{ ws.rsplit() };
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.rsplit(0);
			Assert::AreEqual(pcs::CppWString::size_type(1), wres.size());
			Assert::AreEqual(L" abcd efg   hij klmn  ", wres[0].c_str());

			wres = ws.rsplit(1);
			Assert::AreEqual(pcs::CppWString::size_type(2), wres.size());
			Assert::AreEqual(L" abcd efg   hij klmn ", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());

			wres = ws.rsplit(2);
			Assert::AreEqual(pcs::CppWString::size_type(3), wres.size());
			Assert::AreEqual(L" abcd efg   hij klmn", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());

			wres = ws.rsplit(3);
			Assert::AreEqual(pcs::CppWString::size_type(4), wres.size());
			Assert::AreEqual(L" abcd efg   hij", wres[0].c_str());
			Assert::AreEqual(L"klmn", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());

			wres = ws.rsplit(4);
			Assert::AreEqual(pcs::CppWString::size_type(5), wres.size());
			Assert::AreEqual(L" abcd efg  ", wres[0].c_str());
			Assert::AreEqual(L"hij", wres[1].c_str());
			Assert::AreEqual(L"klmn", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());

			wres = ws.rsplit(5);
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L" abcd efg ", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"hij", wres[2].c_str());
			Assert::AreEqual(L"klmn", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());

			wres = ws.rsplit(6);
			Assert::AreEqual(pcs::CppWString::size_type(7), wres.size());
			Assert::AreEqual(L" abcd efg", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"hij", wres[3].c_str());
			Assert::AreEqual(L"klmn", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"", wres[6].c_str());

			wres = ws.rsplit(7);
			Assert::AreEqual(pcs::CppWString::size_type(8), wres.size());
			Assert::AreEqual(L" abcd", wres[0].c_str());
			Assert::AreEqual(L"efg", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"hij", wres[4].c_str());
			Assert::AreEqual(L"klmn", wres[5].c_str());
			Assert::AreEqual(L"", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());

			wres = ws.rsplit(8);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.rsplit(9);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.rsplit(10);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			ws = pcs::CppWString(5, ' ');  //L"     "_cs;
			wres = ws.rsplit();
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());

			ws = L" abcd#123efg#123hij #123#123klmn  "_cs;
			wres = ws.rsplit(L"#123");
			Assert::AreEqual(pcs::CppWString::size_type(5), wres.size());
			Assert::AreEqual(L" abcd", wres[0].c_str());
			Assert::AreEqual(L"efg", wres[1].c_str());
			Assert::AreEqual(L"hij ", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"klmn  ", wres[4].c_str());

			ws = L"#123#123abcd#123123efg#123hij #123#123klmn  #123#123"_cs;
			wres = ws.rsplit(L"#123");
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"123efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.rsplit(L"#123", 1);
			Assert::AreEqual(pcs::CppWString::size_type(2), wres.size());
			Assert::AreEqual(L"#123#123abcd#123123efg#123hij #123#123klmn  #123", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());

			wres = ws.rsplit(L"#123", 2);
			Assert::AreEqual(pcs::CppWString::size_type(3), wres.size());
			Assert::AreEqual(L"#123#123abcd#123123efg#123hij #123#123klmn  ", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());

			wres = ws.rsplit(L"#123", 3);
			Assert::AreEqual(pcs::CppWString::size_type(4), wres.size());
			Assert::AreEqual(L"#123#123abcd#123123efg#123hij #123", wres[0].c_str());
			Assert::AreEqual(L"klmn  ", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());

			wres = ws.rsplit(L"#123", 4);
			Assert::AreEqual(pcs::CppWString::size_type(5), wres.size());
			Assert::AreEqual(L"#123#123abcd#123123efg#123hij ", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"klmn  ", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());

			wres = ws.rsplit(L"#123", 5);
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L"#123#123abcd#123123efg", wres[0].c_str());
			Assert::AreEqual(L"hij ", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"klmn  ", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());

			wres = ws.rsplit(L"#123", 6);
			Assert::AreEqual(pcs::CppWString::size_type(7), wres.size());
			Assert::AreEqual(L"#123#123abcd", wres[0].c_str());
			Assert::AreEqual(L"123efg", wres[1].c_str());
			Assert::AreEqual(L"hij ", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"klmn  ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"", wres[6].c_str());

			wres = ws.rsplit(L"#123", 7);
			Assert::AreEqual(pcs::CppWString::size_type(8), wres.size());
			Assert::AreEqual(L"#123", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"123efg", wres[2].c_str());
			Assert::AreEqual(L"hij ", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"klmn  ", wres[5].c_str());
			Assert::AreEqual(L"", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());

			wres = ws.rsplit(L"#123", 8);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"123efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.rsplit(L"#123", 9);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"123efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.rsplit(L"#123", 10);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"123efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());
		}

		TEST_METHOD(rstrip)
		{
			pcs::CppString s(" abcd efg   ");
			pcs::CppString sres{ s.rstrip() };
			Assert::AreEqual(" abcd efg", sres.c_str());

			using namespace pcs;
			s = " abcd efg  hij"_cs;
			sres = s.rstrip();
			Assert::AreEqual(" abcd efg  hij", sres.c_str());

			s = ""_cs;
			sres = s.rstrip();
			Assert::AreEqual("", sres.c_str());

			s = "     "_cs;
			sres = s.rstrip();
			Assert::AreEqual("", sres.c_str());

			s = "#124abcd#124efg#1241#24#142"_cs;
			sres = s.rstrip("#124");
			Assert::AreEqual("#124abcd#124efg", sres.c_str());

			s = "#124abcd#124efg#124#124hij"_cs;
			sres = s.rstrip("#124");
			Assert::AreEqual("#124abcd#124efg#124#124hij", sres.c_str());

			s = "#124#142#241124#421#";
			sres = s.rstrip("#124");
			Assert::AreEqual("", sres.c_str());

			pcs::CppWString ws(L" abcd efg   ");
			pcs::CppWString wsres{ ws.rstrip() };
			Assert::AreEqual(L" abcd efg", wsres.c_str());

			ws = L" abcd efg  hij"_cs;
			wsres = ws.rstrip();
			Assert::AreEqual(L" abcd efg  hij", wsres.c_str());

			ws = L""_cs;
			wsres = ws.rstrip();
			Assert::AreEqual(L"", wsres.c_str());

			ws = L"     "_cs;
			wsres = ws.rstrip();
			Assert::AreEqual(L"", wsres.c_str());

			ws = L"#124abcd#124efg#124#124#124"_cs;
			wsres = ws.rstrip(L"#124");
			Assert::AreEqual(L"#124abcd#124efg", wsres.c_str());

			ws = L"#124abcd#124efg#124#124hij"_cs;
			wsres = ws.rstrip(L"#124");
			Assert::AreEqual(L"#124abcd#124efg#124#124hij", wsres.c_str());

			ws = L"#124#124#124#124#124";
			wsres = ws.rstrip(L"#124");
			Assert::AreEqual(L"", wsres.c_str());
		}

		TEST_METHOD(split)
		{
			pcs::CppString s(" abcd efg   hij klmn  ");
			std::vector<pcs::CppString> res{ s.rsplit() };
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.split(0);
			Assert::AreEqual(pcs::CppString::size_type(1), res.size());
			Assert::AreEqual(" abcd efg   hij klmn  ", res[0].c_str());

			res = s.split(1);
			Assert::AreEqual(pcs::CppString::size_type(2), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd efg   hij klmn  ", res[1].c_str());

			res = s.split(2);
			Assert::AreEqual(pcs::CppString::size_type(3), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg   hij klmn  ", res[2].c_str());

			res = s.split(3);
			Assert::AreEqual(pcs::CppString::size_type(4), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("  hij klmn  ", res[3].c_str());

			res = s.split(4);
			Assert::AreEqual(pcs::CppString::size_type(5), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual(" hij klmn  ", res[4].c_str());

			res = s.split(5);
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij klmn  ", res[5].c_str());

			res = s.split(6);
			Assert::AreEqual(pcs::CppString::size_type(7), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());

			res = s.split(7);
			Assert::AreEqual(pcs::CppString::size_type(8), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual(" ", res[7].c_str());

			res = s.split(8);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.split(9);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.split(10);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("abcd", res[1].c_str());
			Assert::AreEqual("efg", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("hij", res[5].c_str());
			Assert::AreEqual("klmn", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			s = pcs::CppString(5, ' ');
			res = s.split();
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());


			using namespace pcs;
			s = " abcd#124efg#124hij #124#124klmn  "_cs;
			res = s.split("#124");
			Assert::AreEqual(" abcd", res[0].c_str());
			Assert::AreEqual("efg", res[1].c_str());
			Assert::AreEqual("hij ", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("klmn  ", res[4].c_str());

			s = "#124#124abcd#124124efg#124hij #124#124klmn  #124#124"_cs;
			res = s.split("#124");
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.split("#124", 1);
			Assert::AreEqual(pcs::CppString::size_type(2), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("#124abcd#124124efg#124hij #124#124klmn  #124#124", res[1].c_str());

			res = s.split("#124", 2);
			Assert::AreEqual(pcs::CppString::size_type(3), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd#124124efg#124hij #124#124klmn  #124#124", res[2].c_str());

			res = s.split("#124", 3);
			Assert::AreEqual(pcs::CppString::size_type(4), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg#124hij #124#124klmn  #124#124", res[3].c_str());

			res = s.split("#124", 4);
			Assert::AreEqual(pcs::CppString::size_type(5), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij #124#124klmn  #124#124", res[4].c_str());

			res = s.split("#124", 5);
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("#124klmn  #124#124", res[5].c_str());

			res = s.split("#124", 6);
			Assert::AreEqual(pcs::CppString::size_type(7), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  #124#124", res[6].c_str());

			res = s.split("#124", 7);
			Assert::AreEqual(pcs::CppString::size_type(8), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("#124", res[7].c_str());

			res = s.split("#124", 8);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.split("#124", 9);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());

			res = s.split("#124", 10);
			Assert::AreEqual(pcs::CppString::size_type(9), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("abcd", res[2].c_str());
			Assert::AreEqual("124efg", res[3].c_str());
			Assert::AreEqual("hij ", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());
			Assert::AreEqual("klmn  ", res[6].c_str());
			Assert::AreEqual("", res[7].c_str());
			Assert::AreEqual("", res[8].c_str());


			pcs::CppWString ws(L" abcd efg   hij klmn  ");
			std::vector<pcs::CppWString> wres{ ws.split() };
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.split(0);
			Assert::AreEqual(pcs::CppWString::size_type(1), wres.size());
			Assert::AreEqual(L" abcd efg   hij klmn  ", wres[0].c_str());

			wres = ws.split(1);
			Assert::AreEqual(pcs::CppWString::size_type(2), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd efg   hij klmn  ", wres[1].c_str());


			wres = ws.split(2);
			Assert::AreEqual(pcs::CppWString::size_type(3), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg   hij klmn  ", wres[2].c_str());

			wres = ws.split(3);
			Assert::AreEqual(pcs::CppWString::size_type(4), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"  hij klmn  ", wres[3].c_str());

			wres = ws.split(4);
			Assert::AreEqual(pcs::CppWString::size_type(5), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L" hij klmn  ", wres[4].c_str());

			wres = ws.split(5);
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij klmn  ", wres[5].c_str());

			wres = ws.split(6);
			Assert::AreEqual(pcs::CppWString::size_type(7), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());

			wres = ws.split(7);
			Assert::AreEqual(pcs::CppWString::size_type(8), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L" ", wres[7].c_str());

			wres = ws.split(8);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.split(9);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.split(10);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"abcd", wres[1].c_str());
			Assert::AreEqual(L"efg", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"hij", wres[5].c_str());
			Assert::AreEqual(L"klmn", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			ws = pcs::CppWString(5, ' ');  //L"     "_cs;
			wres = ws.split();
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());

			ws = L" abcd#124efg#124hij #124#124klmn  "_cs;
			wres = ws.split(L"#124");
			Assert::AreEqual(L" abcd", wres[0].c_str());
			Assert::AreEqual(L"efg", wres[1].c_str());
			Assert::AreEqual(L"hij ", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"klmn  ", wres[4].c_str());

			ws = L"#124#124abcd#124124efg#124hij #124#124klmn  #124#124"_cs;
			wres = ws.split(L"#124");
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.split(L"#124", 1);
			Assert::AreEqual(pcs::CppWString::size_type(2), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"#124abcd#124124efg#124hij #124#124klmn  #124#124", wres[1].c_str());

			wres = ws.split(L"#124", 2);
			Assert::AreEqual(pcs::CppWString::size_type(3), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd#124124efg#124hij #124#124klmn  #124#124", wres[2].c_str());

			wres = ws.split(L"#124", 3);
			Assert::AreEqual(pcs::CppWString::size_type(4), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg#124hij #124#124klmn  #124#124", wres[3].c_str());

			wres = ws.split(L"#124", 4);
			Assert::AreEqual(pcs::CppWString::size_type(5), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij #124#124klmn  #124#124", wres[4].c_str());

			wres = ws.split(L"#124", 5);
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"#124klmn  #124#124", wres[5].c_str());

			wres = ws.split(L"#124", 6);
			Assert::AreEqual(pcs::CppWString::size_type(7), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  #124#124", wres[6].c_str());

			wres = ws.split(L"#124", 7);
			Assert::AreEqual(pcs::CppWString::size_type(8), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"#124", wres[7].c_str());

			wres = ws.split(L"#124", 8);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.split(L"#124", 9);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());

			wres = ws.split(L"#124", 10);
			Assert::AreEqual(pcs::CppWString::size_type(9), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"abcd", wres[2].c_str());
			Assert::AreEqual(L"124efg", wres[3].c_str());
			Assert::AreEqual(L"hij ", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());
			Assert::AreEqual(L"klmn  ", wres[6].c_str());
			Assert::AreEqual(L"", wres[7].c_str());
			Assert::AreEqual(L"", wres[8].c_str());
		}

		TEST_METHOD(splitline)
		{
#pragma warning(push)
#pragma warning(disable: 4566)  // to get no warning when current page code is not compatible with next unicode points
			{
				pcs::CppString wtext{ "\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r" };
				std::vector<pcs::CppString> lines{ wtext.splitlines() };
				std::vector<pcs::CppString> expected{ "", "abc", "cde", "efg", "ghi", "ijk", "klm", "mno", "", "opq", "qrs", "stu", "uvw", "wxy", "zzz", "." };
				auto exp_it{ expected.cbegin() };
				auto lin_it{ lines.cbegin() };
				for (; lin_it != lines.cend() && exp_it != expected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != lines.cend());
				Assert::IsFalse(exp_it != expected.cend());
			}

			{
				pcs::CppString wtext{ "\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r\n" };
				std::vector<pcs::CppString> lines{ wtext.splitlines() };
				std::vector<pcs::CppString> expected{ "", "abc", "cde", "efg", "ghi", "ijk", "klm", "mno", "", "opq", "qrs", "stu", "uvw", "wxy", "zzz", "." };
				auto exp_it{ expected.cbegin() };
				auto lin_it{ lines.cbegin() };
				for (; lin_it != lines.cend() && exp_it != expected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != lines.cend());
				Assert::IsFalse(exp_it != expected.cend());
			}

			{
				pcs::CppString wtext{ "\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\n\r" };
				std::vector<pcs::CppString> lines{ wtext.splitlines() };
				std::vector<pcs::CppString> expected{ "", "abc", "cde", "efg", "ghi", "ijk", "klm", "mno", "", "opq", "qrs", "stu", "uvw", "wxy", "zzz", ".", "" };
				auto exp_it{ expected.cbegin() };
				auto lin_it{ lines.cbegin() };
				for (; lin_it != lines.cend() && exp_it != expected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != lines.cend());
				Assert::IsFalse(exp_it != expected.cend());
			}

			{
				pcs::CppString wtext{ "\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r" };
				std::vector<pcs::CppString> lines{ wtext.splitlines(true) };
				std::vector<pcs::CppString> expected{
					"\v", "abc\013", "cde\f", "efg\x0c", "ghi\x1c", "ijk\x1d", "klm\x1d", "mno\r\n",
					"\n", "opq\r", "qrs\v", "stu\r", "uvw\n", "wxy\r\n", "zzz\x0c", ".\r"
				};
				auto exp_it{ expected.cbegin() };
				auto lin_it{ lines.cbegin() };
				for (; lin_it != lines.cend() && exp_it != expected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != lines.cend());
				Assert::IsFalse(exp_it != expected.cend());
			}

			{
				pcs::CppString wtext{ "\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r\n" };
				std::vector<pcs::CppString> lines{ wtext.splitlines(true) };
				std::vector<pcs::CppString> expected{
					"\v", "abc\013", "cde\f", "efg\x0c", "ghi\x1c", "ijk\x1d", "klm\x1d", "mno\r\n",
					"\n", "opq\r", "qrs\v", "stu\r", "uvw\n", "wxy\r\n", "zzz\x0c", ".\r\n"
				};
				auto exp_it{ expected.cbegin() };
				auto lin_it{ lines.cbegin() };
				for (; lin_it != lines.cend() && exp_it != expected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != lines.cend());
				Assert::IsFalse(exp_it != expected.cend());
			}

			{
				pcs::CppString wtext{ "\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\n\r" };
				std::vector<pcs::CppString> lines{ wtext.splitlines(true) };
				std::vector<pcs::CppString> expected{
					"\v", "abc\013", "cde\f", "efg\x0c", "ghi\x1c", "ijk\x1d", "klm\x1d", "mno\r\n",
					"\n", "opq\r", "qrs\v", "stu\r", "uvw\n", "wxy\r\n", "zzz\x0c", ".\n", "\r"
				};
				auto exp_it{ expected.cbegin() };
				auto lin_it{ lines.cbegin() };
				for (; lin_it != lines.cend() && exp_it != expected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != lines.cend());
				Assert::IsFalse(exp_it != expected.cend());
			}


			{
				pcs::CppWString wtext{ L"\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r" };
				std::vector<pcs::CppWString> wlines{ wtext.splitlines() };
				std::vector<pcs::CppWString> wexpected{ L"", L"abc", L"cde", L"efg", L"ghi", L"ijk", L"klm", L"mno", L"", L"opq", L"qrs", L"stu", L"uvw", L"wxy", L"zzz", L"."};
				auto exp_it{ wexpected.cbegin() };
				auto lin_it{ wlines.cbegin() };
				for (; lin_it != wlines.cend() && exp_it != wexpected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != wlines.cend());
				Assert::IsFalse(exp_it != wexpected.cend());
			}

			{
				pcs::CppWString wtext{ L"\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r\n" };
				std::vector<pcs::CppWString> wlines{ wtext.splitlines() };
				std::vector<pcs::CppWString> wexpected{ L"", L"abc", L"cde", L"efg", L"ghi", L"ijk", L"klm", L"mno", L"", L"opq", L"qrs", L"stu", L"uvw", L"wxy", L"zzz", L"."};
				auto exp_it{ wexpected.cbegin() };
				auto lin_it{ wlines.cbegin() };
				for (; lin_it != wlines.cend() && exp_it != wexpected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != wlines.cend());
				Assert::IsFalse(exp_it != wexpected.cend());
			}

			{
				pcs::CppWString wtext{ L"\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\n\r" };
				std::vector<pcs::CppWString> wlines{ wtext.splitlines() };
				std::vector<pcs::CppWString> wexpected{ L"", L"abc", L"cde", L"efg", L"ghi", L"ijk", L"klm", L"mno", L"", L"opq", L"qrs", L"stu", L"uvw", L"wxy", L"zzz", L".", L""};
				auto exp_it{ wexpected.cbegin() };
				auto lin_it{ wlines.cbegin() };
				for (; lin_it != wlines.cend() && exp_it != wexpected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != wlines.cend());
				Assert::IsFalse(exp_it != wexpected.cend());
			}

			{
				pcs::CppWString wtext{ L"\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r" };
				std::vector<pcs::CppWString> wlines{ wtext.splitlines(true) };
				std::vector<pcs::CppWString> wexpected{
					L"\v", L"abc\013", L"cde\f", L"efg\x0c", L"ghi\x1c", L"ijk\x1d", L"klm\x1d", L"mno\r\n",
					L"\n", L"opq\r", L"qrs\v", L"stu\r", L"uvw\n", L"wxy\r\n", L"zzz\x0c", L".\r"
				};
				auto exp_it{ wexpected.cbegin() };
				auto lin_it{ wlines.cbegin() };
				for (; lin_it != wlines.cend() && exp_it != wexpected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != wlines.cend());
				Assert::IsFalse(exp_it != wexpected.cend());
			}

			{
				pcs::CppWString wtext{ L"\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\r\n" };
				std::vector<pcs::CppWString> wlines{ wtext.splitlines(true) };
				std::vector<pcs::CppWString> wexpected{
					L"\v", L"abc\013", L"cde\f", L"efg\x0c", L"ghi\x1c", L"ijk\x1d", L"klm\x1d", L"mno\r\n",
					L"\n", L"opq\r", L"qrs\v", L"stu\r", L"uvw\n", L"wxy\r\n", L"zzz\x0c", L".\r\n"
				};
				auto exp_it{ wexpected.cbegin() };
				auto lin_it{ wlines.cbegin() };
				for (; lin_it != wlines.cend() && exp_it != wexpected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != wlines.cend());
				Assert::IsFalse(exp_it != wexpected.cend());
			}

			{
				pcs::CppWString wtext{ L"\vabc\013cde\fefg\x0cghi\x1cijk\x1dklm\x1dmno\r\n\nopq\rqrs\vstu\ruvw\nwxy\r\nzzz\x0c.\n\r" };
				std::vector<pcs::CppWString> wlines{ wtext.splitlines(true) };
				std::vector<pcs::CppWString> wexpected{
					L"\v", L"abc\013", L"cde\f", L"efg\x0c", L"ghi\x1c", L"ijk\x1d", L"klm\x1d", L"mno\r\n",
					L"\n", L"opq\r", L"qrs\v", L"stu\r", L"uvw\n", L"wxy\r\n", L"zzz\x0c", L".\n", L"\r"
				};
				auto exp_it{ wexpected.cbegin() };
				auto lin_it{ wlines.cbegin() };
				for (; lin_it != wlines.cend() && exp_it != wexpected.cend(); ++lin_it, ++exp_it) {
					Assert::AreEqual(exp_it->c_str(), lin_it->c_str());
				}
				Assert::IsFalse(lin_it != wlines.cend());
				Assert::IsFalse(exp_it != wexpected.cend());
			}

#pragma warning(pop)

		}

		TEST_METHOD(startswith)
		{
			pcs::CppString text("Abcdef");
			const size_t len{ text.size() };

			Assert::IsTrue(text.startswith("A"));
			Assert::IsTrue(text.startswith("Ab"));
			Assert::IsTrue(text.startswith("Abc"));
			Assert::IsTrue(text.startswith("Abcd"));
			Assert::IsTrue(text.startswith("Abcde"));
			Assert::IsTrue(text.startswith("Abcdef"));
			Assert::IsFalse(text.startswith("Abcdefg"));
			Assert::IsFalse(text.startswith("a"));
			Assert::IsFalse(text.startswith("def"));

			Assert::IsTrue(text.startswith("b", 1));
			Assert::IsTrue(text.startswith("bc", 1));
			Assert::IsTrue(text.startswith("bcd", 1));
			Assert::IsFalse(text.startswith("bcdefg", 1));
			Assert::IsFalse(text.startswith("A", 1));
			Assert::IsFalse(text.startswith("def", 1));

			Assert::IsTrue(text.startswith("c", 2));
			Assert::IsTrue(text.startswith("cd", 2));
			Assert::IsTrue(text.startswith("cde", 2));
			Assert::IsFalse(text.startswith("cdefg", 2));
			Assert::IsFalse(text.startswith("Ab", 2));
			Assert::IsFalse(text.startswith("def", 2));

			Assert::IsTrue(text.startswith("d", 3));
			Assert::IsTrue(text.startswith("de", 3));
			Assert::IsTrue(text.startswith("def", 3));
			Assert::IsFalse(text.startswith("defg", 3));
			Assert::IsFalse(text.startswith("Abc", 3));
			Assert::IsFalse(text.startswith("ef", 3));

			Assert::IsTrue(text.startswith("e", 4));
			Assert::IsTrue(text.startswith("ef", 4));
			Assert::IsFalse(text.startswith("efg", 4));
			Assert::IsFalse(text.startswith("Abcd", 4));
			Assert::IsFalse(text.startswith("f", 4));

			Assert::IsTrue(text.startswith("f", 5));
			Assert::IsFalse(text.startswith("fg", 5));
			Assert::IsFalse(text.startswith("Abcde", 5));
			Assert::IsFalse(text.startswith("g", 5));

			Assert::IsTrue(text.startswith("A", 0, 0));
			Assert::IsFalse(text.startswith("b", 0, 0));
			Assert::IsTrue(text.startswith("b", 1, 3));
			Assert::IsTrue(text.startswith("bc", 1, 3));
			Assert::IsTrue(text.startswith("bcd", 1, 3));
			Assert::IsFalse(text.startswith("bcde", 1, 3));

			Assert::IsTrue(text.startswith("", 5, 2));
			Assert::IsTrue(text.startswith("", 15, 16));

			Assert::IsTrue(text.startswith({ "ghi", "abca", "Abcd" }, 0, len - 2));
			Assert::IsFalse(text.startswith({ "def", "ghi" }, 0, len - 4));
			Assert::IsFalse(text.startswith({ "def", "ghi", "Abcd" }, 0, len - 4));


			pcs::CppWString wtext(L"Abcdef");

			Assert::IsTrue(wtext.startswith(L"A"));
			Assert::IsTrue(wtext.startswith(L"Ab"));
			Assert::IsTrue(wtext.startswith(L"Abc"));
			Assert::IsTrue(wtext.startswith(L"Abcd"));
			Assert::IsTrue(wtext.startswith(L"Abcde"));
			Assert::IsTrue(wtext.startswith(L"Abcdef"));
			Assert::IsFalse(wtext.startswith(L"Abcdefg"));
			Assert::IsFalse(wtext.startswith(L"a"));
			Assert::IsFalse(wtext.startswith(L"def"));

			Assert::IsTrue(wtext.startswith(L"b", 1));
			Assert::IsTrue(wtext.startswith(L"bc", 1));
			Assert::IsTrue(wtext.startswith(L"bcd", 1));
			Assert::IsFalse(wtext.startswith(L"bcdefg", 1));
			Assert::IsFalse(wtext.startswith(L"A", 1));
			Assert::IsFalse(wtext.startswith(L"def", 1));

			Assert::IsTrue(wtext.startswith(L"c", 2));
			Assert::IsTrue(wtext.startswith(L"cd", 2));
			Assert::IsTrue(wtext.startswith(L"cde", 2));
			Assert::IsFalse(wtext.startswith(L"cdefg", 2));
			Assert::IsFalse(wtext.startswith(L"Ab", 2));
			Assert::IsFalse(wtext.startswith(L"def", 2));

			Assert::IsTrue(wtext.startswith(L"d", 3));
			Assert::IsTrue(wtext.startswith(L"de", 3));
			Assert::IsTrue(wtext.startswith(L"def", 3));
			Assert::IsFalse(wtext.startswith(L"defg", 3));
			Assert::IsFalse(wtext.startswith(L"Abc", 3));
			Assert::IsFalse(wtext.startswith(L"ef", 3));

			Assert::IsTrue(wtext.startswith(L"e", 4));
			Assert::IsTrue(wtext.startswith(L"ef", 4));
			Assert::IsFalse(wtext.startswith(L"efg", 4));
			Assert::IsFalse(wtext.startswith(L"Abcd", 4));
			Assert::IsFalse(wtext.startswith(L"f", 4));

			Assert::IsTrue(wtext.startswith(L"f", 5));
			Assert::IsFalse(wtext.startswith(L"fg", 5));
			Assert::IsFalse(wtext.startswith(L"Abcde", 5));
			Assert::IsFalse(wtext.startswith(L"g", 5));

			Assert::IsTrue(wtext.startswith(L"A", 0, 0));
			Assert::IsFalse(wtext.startswith(L"b", 0, 0));
			Assert::IsTrue(wtext.startswith(L"b", 1, 3));
			Assert::IsTrue(wtext.startswith(L"bc", 1, 3));
			Assert::IsTrue(wtext.startswith(L"bcd", 1, 3));
			Assert::IsFalse(wtext.startswith(L"bcde", 1, 3));

			Assert::IsTrue(wtext.startswith(L"", 5, 2));
			Assert::IsTrue(wtext.startswith(L"", 15, 16));

			Assert::IsTrue(wtext.startswith({  L"ghi", L"abca", L"Abcd" }, 0, len - 2));
			Assert::IsFalse(wtext.startswith({ L"def", L"ghi" }, 0, len - 4));
			Assert::IsFalse(wtext.startswith({ L"def", L"ghi", L"Abcd" }, 0, len - 4));
		}

		TEST_METHOD(startswith_n)
		{
			pcs::CppString text("Abcdef");
			const size_t len{ text.size() };

			Assert::IsTrue(text.startswith_n("A", 2));
			Assert::IsTrue(text.startswith_n("Ab", 2));
			Assert::IsTrue(text.startswith_n("Abc", 3));
			Assert::IsTrue(text.startswith_n("Abcd", 5));
			Assert::IsTrue(text.startswith_n("Abcde", 5));
			Assert::IsTrue(text.startswith_n("Abcdef", 7));
			Assert::IsFalse(text.startswith_n("Abcdefg", 11));
			Assert::IsFalse(text.startswith_n("a", 2));
			Assert::IsFalse(text.startswith_n("def", len));

			Assert::IsTrue(text.startswith_n("b", 1, 1));
			Assert::IsTrue(text.startswith_n("bc", 1, 3));
			Assert::IsTrue(text.startswith_n("bcd", 1, 3));
			Assert::IsFalse(text.startswith_n("bcdefg", 1, 5));
			Assert::IsFalse(text.startswith_n("A", 1, 8));
			Assert::IsFalse(text.startswith_n("def", 1, 2));

			Assert::IsTrue(text.startswith_n("c", 2, 1));
			Assert::IsTrue(text.startswith_n("cd", 2, 2));
			Assert::IsTrue(text.startswith_n("cde", 2, 4));
			Assert::IsFalse(text.startswith_n("cdefg", 2, 6));
			Assert::IsFalse(text.startswith_n("Ab", 2, 2));
			Assert::IsFalse(text.startswith_n("def", 2, 5));

			Assert::IsTrue(text.startswith_n("d", 3, 2));
			Assert::IsTrue(text.startswith_n("de", 3, 2));
			Assert::IsTrue(text.startswith_n("def", 3, 4));
			Assert::IsFalse(text.startswith_n("defg", 3, 5));
			Assert::IsFalse(text.startswith_n("Abc", 3, 1));
			Assert::IsFalse(text.startswith_n("ef", 3, 2));

			Assert::IsTrue(text.startswith_n("e", 4, 1));
			Assert::IsTrue(text.startswith_n("ef", 4, 3));
			Assert::IsFalse(text.startswith_n("efg", 4, 5));
			Assert::IsFalse(text.startswith_n("Abcd", 4, 7));
			Assert::IsFalse(text.startswith_n("f", 4, 9));

			Assert::IsTrue(text.startswith_n("f", 5, 2));
			Assert::IsFalse(text.startswith_n("fg", 5, 1));
			Assert::IsFalse(text.startswith_n("Abcde", 5, 8));
			Assert::IsFalse(text.startswith_n("g", 5, 11));

			Assert::IsTrue(text.startswith_n("A", 0, 1));
			Assert::IsFalse(text.startswith_n("b", 0, 2));
			Assert::IsTrue(text.startswith_n("b", 1, 3));
			Assert::IsTrue(text.startswith_n("bc", 1, 3));
			Assert::IsTrue(text.startswith_n("bcd", 1, 3));
			Assert::IsFalse(text.startswith_n("bcde", 1, 3));

			Assert::IsTrue(text.startswith_n("", 5, 2));
			Assert::IsTrue(text.startswith_n("", 15, 16));

			Assert::IsTrue(text.startswith_n({ "ghi", "abca", "Abcd" }, 0, len - 2));
			Assert::IsFalse(text.startswith_n({ "def", "ghi" }, 0, len - 4));
			Assert::IsFalse(text.startswith_n({ "def", "ghi", "Abcd" }, 0, len - 4));


			pcs::CppWString wtext(L"Abcdef");
			const size_t wlen{ wtext.size() };

			Assert::IsTrue(wtext.startswith_n(L"A", 2));
			Assert::IsTrue(wtext.startswith_n(L"Ab", 2));
			Assert::IsTrue(wtext.startswith_n(L"Abc", 3));
			Assert::IsTrue(wtext.startswith_n(L"Abcd", 5));
			Assert::IsTrue(wtext.startswith_n(L"Abcde", 5));
			Assert::IsTrue(wtext.startswith_n(L"Abcdef", 7));
			Assert::IsFalse(wtext.startswith_n(L"Abcdefg", 11));
			Assert::IsFalse(wtext.startswith_n(L"a", 2));
			Assert::IsFalse(wtext.startswith_n(L"def", wlen));

			Assert::IsTrue(wtext.startswith_n(L"b", 1, 1));
			Assert::IsTrue(wtext.startswith_n(L"bc", 1, 3));
			Assert::IsTrue(wtext.startswith_n(L"bcd", 1, 3));
			Assert::IsFalse(wtext.startswith_n(L"bcdefg", 1, 5));
			Assert::IsFalse(wtext.startswith_n(L"A", 1, 8));
			Assert::IsFalse(wtext.startswith_n(L"def", 1, 2));

			Assert::IsTrue(wtext.startswith_n(L"c", 2, 1));
			Assert::IsTrue(wtext.startswith_n(L"cd", 2, 2));
			Assert::IsTrue(wtext.startswith_n(L"cde", 2, 4));
			Assert::IsFalse(wtext.startswith_n(L"cdefg", 2, 6));
			Assert::IsFalse(wtext.startswith_n(L"Ab", 2, 2));
			Assert::IsFalse(wtext.startswith_n(L"def", 2, 5));

			Assert::IsTrue(wtext.startswith_n(L"d", 3, 2));
			Assert::IsTrue(wtext.startswith_n(L"de", 3, 2));
			Assert::IsTrue(wtext.startswith_n(L"def", 3, 4));
			Assert::IsFalse(wtext.startswith_n(L"defg", 3, 5));
			Assert::IsFalse(wtext.startswith_n(L"Abc", 3, 1));
			Assert::IsFalse(wtext.startswith_n(L"ef", 3, 2));

			Assert::IsTrue(wtext.startswith_n(L"e", 4, 1));
			Assert::IsTrue(wtext.startswith_n(L"ef", 4, 3));
			Assert::IsFalse(wtext.startswith_n(L"efg", 4, 5));
			Assert::IsFalse(wtext.startswith_n(L"Abcd", 4, 7));
			Assert::IsFalse(wtext.startswith_n(L"f", 4, 9));

			Assert::IsTrue(wtext.startswith_n(L"f", 5, 2));
			Assert::IsFalse(wtext.startswith_n(L"fg", 5, 1));
			Assert::IsFalse(wtext.startswith_n(L"Abcde", 5, 8));
			Assert::IsFalse(wtext.startswith_n(L"g", 5, 11));

			Assert::IsTrue(wtext.startswith_n(L"A", 0, 1));
			Assert::IsFalse(wtext.startswith_n(L"b", 0, 2));
			Assert::IsTrue(wtext.startswith_n(L"b", 1, 3));
			Assert::IsTrue(wtext.startswith_n(L"bc", 1, 3));
			Assert::IsTrue(wtext.startswith_n(L"bcd", 1, 3));
			Assert::IsFalse(wtext.startswith_n(L"bcde", 1, 3));

			Assert::IsTrue(wtext.startswith_n(L"", 5, 2));
			Assert::IsTrue(wtext.startswith_n(L"", 15, 16));

			Assert::IsTrue(wtext.startswith_n({ L"ghi", L"abca", L"Abcd" }, 0, wlen - 2));
			Assert::IsFalse(wtext.startswith_n({ L"def", L"ghi" }, 0, wlen - 4));
			Assert::IsFalse(wtext.startswith_n({ L"def", L"ghi", L"Abcd" }, 0, wlen - 4));
		}

		TEST_METHOD(strip)
		{
			pcs::CppString text("abcdefedcbaea");

			Assert::AreEqual("bcdefedcbae", text.strip("a").c_str());
			Assert::AreEqual("cdefedcbae", text.strip("ba").c_str());
			Assert::AreEqual("defedcbae", text.strip("acb").c_str());
			Assert::AreEqual("efedcbae", text.strip("dacb").c_str());
			Assert::AreEqual("f", text.strip("abcde").c_str());
			Assert::AreEqual("bcdefedcb", text.strip("ea").c_str());
			Assert::AreEqual("cdefedc", text.strip("eba").c_str());
			Assert::AreEqual("abcdefedcbaea", text.strip("ghijZ").c_str());
			Assert::AreEqual("abcdefedcbaea", text.strip("ABc").c_str());

			pcs::CppWString wtext(L"abcdefedcbaea");

			Assert::AreEqual(L"bcdefedcbae", wtext.strip(L"a").c_str());
			Assert::AreEqual(L"cdefedcbae", wtext.strip(L"ba").c_str());
			Assert::AreEqual(L"defedcbae", wtext.strip(L"acb").c_str());
			Assert::AreEqual(L"efedcbae", wtext.strip(L"dacb").c_str());
			Assert::AreEqual(L"f", wtext.strip(L"abcde").c_str());
			Assert::AreEqual(L"bcdefedcb", wtext.strip(L"ea").c_str());
			Assert::AreEqual(L"cdefedc", wtext.strip(L"eba").c_str());
			Assert::AreEqual(L"abcdefedcbaea", wtext.strip(L"ghijZ").c_str());
			Assert::AreEqual(L"abcdefedcbaea", wtext.strip(L"ABc").c_str());
		}

		TEST_METHOD(substr)
		{
			pcs::CppString text("AbcDefGhi");

			Assert::AreEqual("AbcDefGhi", text.substr(0, 9).c_str());
			Assert::AreEqual("bcDefGhi", text.substr(1, 8).c_str());
			Assert::AreEqual("cDefGhi", text.substr(2, 7).c_str());
			Assert::AreEqual("DefGhi", text.substr(3, 6).c_str());
			Assert::AreEqual("efGhi", text.substr(4, 5).c_str());
			Assert::AreEqual("fGhi", text.substr(5, 4).c_str());
			Assert::AreEqual("Ghi", text.substr(6, 3).c_str());
			Assert::AreEqual("hi", text.substr(7, 2).c_str());
			Assert::AreEqual("i", text.substr(8, 1).c_str());
			Assert::AreEqual("", text.substr(9, 0).c_str());

			Assert::AreEqual("AbcDefGhi", text.substr(0).c_str());
			Assert::AreEqual("bcDefGhi", text.substr(1).c_str());
			Assert::AreEqual("cDefGhi", text.substr(2).c_str());
			Assert::AreEqual("DefGhi", text.substr(3).c_str());
			Assert::AreEqual("efGhi", text.substr(4).c_str());
			Assert::AreEqual("fGhi", text.substr(5).c_str());
			Assert::AreEqual("Ghi", text.substr(6).c_str());
			Assert::AreEqual("hi", text.substr(7).c_str());
			Assert::AreEqual("i", text.substr(8).c_str());
			Assert::AreEqual("", text.substr(9).c_str());

			Assert::AreEqual("AbcDefGh", text.substr(0, 8).c_str());
			Assert::AreEqual("bcDefGh", text.substr(1, 7).c_str());
			Assert::AreEqual("cDefG", text.substr(2, 5).c_str());
			Assert::AreEqual("DefGh", text.substr(3, 5).c_str());
			Assert::AreEqual("efGh", text.substr(4, 4).c_str());
			Assert::AreEqual("fG", text.substr(5, 2).c_str());
			Assert::AreEqual("G", text.substr(6, 1).c_str());
			Assert::AreEqual("h", text.substr(7, 1).c_str());
			Assert::AreEqual("i", text.substr(8, 3).c_str());
			Assert::AreEqual("", text.substr(9, 0).c_str());

			Assert::AreEqual("", text.substr(10, 15).c_str());
			Assert::AreEqual("", text.substr(21).c_str());

			pcs::CppWString wtext(L"AbcDefGhi");

			Assert::AreEqual(L"AbcDefGhi", wtext.substr(0, 9).c_str());
			Assert::AreEqual(L"bcDefGhi", wtext.substr(1, 8).c_str());
			Assert::AreEqual(L"cDefGhi", wtext.substr(2, 7).c_str());
			Assert::AreEqual(L"DefGhi", wtext.substr(3, 6).c_str());
			Assert::AreEqual(L"efGhi", wtext.substr(4, 5).c_str());
			Assert::AreEqual(L"fGhi", wtext.substr(5, 4).c_str());
			Assert::AreEqual(L"Ghi", wtext.substr(6, 3).c_str());
			Assert::AreEqual(L"hi", wtext.substr(7, 2).c_str());
			Assert::AreEqual(L"i", wtext.substr(8, 1).c_str());
			Assert::AreEqual(L"", wtext.substr(9, 0).c_str());

			Assert::AreEqual(L"AbcDefGhi", wtext.substr(0).c_str());
			Assert::AreEqual(L"bcDefGhi", wtext.substr(1).c_str());
			Assert::AreEqual(L"cDefGhi", wtext.substr(2).c_str());
			Assert::AreEqual(L"DefGhi", wtext.substr(3).c_str());
			Assert::AreEqual(L"efGhi", wtext.substr(4).c_str());
			Assert::AreEqual(L"fGhi", wtext.substr(5).c_str());
			Assert::AreEqual(L"Ghi", wtext.substr(6).c_str());
			Assert::AreEqual(L"hi", wtext.substr(7).c_str());
			Assert::AreEqual(L"i", wtext.substr(8).c_str());
			Assert::AreEqual(L"", wtext.substr(9).c_str());

			Assert::AreEqual(L"AbcDefGh", wtext.substr(0, 8).c_str());
			Assert::AreEqual(L"bcDefGh", wtext.substr(1, 7).c_str());
			Assert::AreEqual(L"cDefG", wtext.substr(2, 5).c_str());
			Assert::AreEqual(L"DefGh", wtext.substr(3, 5).c_str());
			Assert::AreEqual(L"efGh", wtext.substr(4, 4).c_str());
			Assert::AreEqual(L"fG", wtext.substr(5, 2).c_str());
			Assert::AreEqual(L"G", wtext.substr(6, 1).c_str());
			Assert::AreEqual(L"h", wtext.substr(7, 1).c_str());
			Assert::AreEqual(L"i", wtext.substr(8, 3).c_str());
			Assert::AreEqual(L"", wtext.substr(9, 0).c_str());

			Assert::AreEqual(L"", wtext.substr(10, 15).c_str());
			Assert::AreEqual(L"", wtext.substr(21).c_str());
		}

		TEST_METHOD(swapcase)
		{
			pcs::CppString s(255, '\0');
			for (int i : std::views::iota(0, 256))
				s[i] = pcs::CppString::value_type(i);
			pcs::CppString res{ s.swapcase() };
			for (auto const [s, r] : std::views::zip(s, res)) {
				if (std::islower(s))
					Assert::IsTrue(std::isupper(r));
				else if (std::isupper(s))
					Assert::IsTrue(std::islower(r));
				else
					Assert::AreEqual(s, r);
			}

			pcs::CppWString ws(0xffff, '\0');
			for (int i : std::views::iota(0, 0x1'0000))
				ws[i] = pcs::CppWString::value_type(i);
			pcs::CppWString wres{ ws.swapcase() };
			for (auto const [ws, wr] : std::views::zip(ws, wres)) {
				if (std::islower(ws))
					Assert::IsTrue(std::isupper(wr));
				else if (std::isupper(ws))
					Assert::IsTrue(std::islower(wr));
				else
					Assert::AreEqual(ws, wr);
			}
		}

		TEST_METHOD(title)
		{
			pcs::CppString text("to bE  TiTlEd - cheCKing,errors, in Case oF aNy fOUNd");
			pcs::CppString expected("To Be  Titled - Checking,errors, In Case Of Any Found");
			pcs::CppString res{ text.title() };
			Assert::AreEqual(expected.c_str(), res.c_str());

			pcs::CppWString wtext(L"to bE  TiTlEd - cheCKing,errors, in Case oF aNy fOUNd\u2026\x86");
			pcs::CppWString wexpected(L"To Be  Titled - Checking,errors, In Case Of Any Found\u2026\x86");
			pcs::CppWString wres{ wtext.title() };
			Assert::AreEqual(wexpected.c_str(), wres.c_str());

		}

		TEST_METHOD(translate)
		{
			pcs::CppString::TransTable trans_table("oizeaslbgOIZEASLG", "012345789012345789");
			pcs::CppString text("This is a big 'Oiseau' that can be seen in 'Le Zoo'");
			pcs::CppString expected("Th15 15 4 819 '01534u' th4t c4n 83 533n 1n '73 200'");
			Assert::AreEqual(expected.c_str(), text.translate(trans_table).c_str());

			pcs::CppWString::TransTable wtrans_table(L"oizeaslbgOIZEASLG", L"012345789012345789");
			pcs::CppWString wtext(L"This is a big 'Oiseau' that can be seen in 'Le Zoo'");
			pcs::CppWString wexpected(L"Th15 15 4 819 '01534u' th4t c4n 83 533n 1n '73 200'");
			Assert::AreEqual(wexpected.c_str(), wtext.translate(wtrans_table).c_str());
		}

		TEST_METHOD(upper)
		{
			for (int c = 0; c <= 255; ++c) {
				const char ch{ char(c) };
				constexpr int N{ 5 };
				pcs::CppString s(N, ch);
				s.upper();
				for (int i = 0; i < N; ++i)
					Assert::AreEqual(pcs::to_upper(ch), s[i]);
				Assert::AreEqual(char(std::toupper(ch)), pcs::CppString::upper(ch));
			}

			for (int c = 0; c <= 0xffff; ++c) {
				const wchar_t wch{ wchar_t(c) };
				constexpr int N{ 5 };
				pcs::CppWString ws(N, wch);
				ws.upper();
				for (int i = 0; i < N; ++i)
					Assert::AreEqual(pcs::to_upper(wch), ws[i]);
				Assert::AreEqual(wchar_t(std::toupper(wch)), pcs::CppWString::upper(wch));
			}

			pcs::CppString s(255, '\0');
			for (int i : std::views::iota(0, 256))
				s[i] = pcs::CppString::value_type(i);
			pcs::CppString res{ s.upper() };
			for (auto const [cs, cr] : std::views::zip(s, res)) {
				if (std::islower(cs))
					Assert::IsTrue(std::isupper(cr));
				else if (std::isupper(cs))
					Assert::IsTrue(std::isupper(cr));
				else
					Assert::AreEqual(cs, cr);
			}

			pcs::CppWString ws(0xffff, '\0');
			for (int i : std::views::iota(0, 0x1'0000))
				ws[i] = pcs::CppWString::value_type(i);
			pcs::CppWString wres{ ws.upper() };
			for (auto const [wcs, wcr] : std::views::zip(ws, wres)) {
				if (std::islower(wcs))
					Assert::IsTrue(std::isupper(wcr));
				else if (std::isupper(wcs))
					Assert::IsTrue(std::isupper(wcr));
				else
					Assert::AreEqual(wcs, wcr);
			}

		}

		TEST_METHOD(zfill)
		{
			pcs::CppString s("1.23");
			Assert::AreEqual("1.23", s.zfill(0).c_str());
			Assert::AreEqual("1.23", s.zfill(1).c_str());
			Assert::AreEqual("1.23", s.zfill(2).c_str());
			Assert::AreEqual("1.23", s.zfill(3).c_str());
			Assert::AreEqual("1.23", s.zfill(4).c_str());
			Assert::AreEqual("01.23", s.zfill(5).c_str());
			Assert::AreEqual("001.23", s.zfill(6).c_str());

			s = '+' + s;
			Assert::AreEqual("+1.23", s.zfill(0).c_str());
			Assert::AreEqual("+1.23", s.zfill(1).c_str());
			Assert::AreEqual("+1.23", s.zfill(2).c_str());
			Assert::AreEqual("+1.23", s.zfill(3).c_str());
			Assert::AreEqual("+1.23", s.zfill(4).c_str());
			Assert::AreEqual("+1.23", s.zfill(5).c_str());
			Assert::AreEqual("+01.23", s.zfill(6).c_str());
			Assert::AreEqual("+001.23", s.zfill(7).c_str());

			s[0] = '-';
			Assert::AreEqual("-1.23", s.zfill(0).c_str());
			Assert::AreEqual("-1.23", s.zfill(1).c_str());
			Assert::AreEqual("-1.23", s.zfill(2).c_str());
			Assert::AreEqual("-1.23", s.zfill(3).c_str());
			Assert::AreEqual("-1.23", s.zfill(4).c_str());
			Assert::AreEqual("-1.23", s.zfill(5).c_str());
			Assert::AreEqual("-01.23", s.zfill(6).c_str());
			Assert::AreEqual("-001.23", s.zfill(7).c_str());

			s[0] = '*';
			Assert::AreEqual("*1.23", s.zfill(0).c_str());
			Assert::AreEqual("*1.23", s.zfill(1).c_str());
			Assert::AreEqual("*1.23", s.zfill(2).c_str());
			Assert::AreEqual("*1.23", s.zfill(3).c_str());
			Assert::AreEqual("*1.23", s.zfill(4).c_str());
			Assert::AreEqual("*1.23", s.zfill(5).c_str());
			Assert::AreEqual("0*1.23", s.zfill(6).c_str());
			Assert::AreEqual("00*1.23", s.zfill(7).c_str());


			pcs::CppWString ws(L"1.23");
			Assert::AreEqual(L"1.23", ws.zfill(0).c_str());
			Assert::AreEqual(L"1.23", ws.zfill(1).c_str());
			Assert::AreEqual(L"1.23", ws.zfill(2).c_str());
			Assert::AreEqual(L"1.23", ws.zfill(3).c_str());
			Assert::AreEqual(L"1.23", ws.zfill(4).c_str());
			Assert::AreEqual(L"01.23", ws.zfill(5).c_str());
			Assert::AreEqual(L"001.23", ws.zfill(6).c_str());

			ws = L'+' + ws;
			Assert::AreEqual(L"+1.23", ws.zfill(0).c_str());
			Assert::AreEqual(L"+1.23", ws.zfill(1).c_str());
			Assert::AreEqual(L"+1.23", ws.zfill(2).c_str());
			Assert::AreEqual(L"+1.23", ws.zfill(3).c_str());
			Assert::AreEqual(L"+1.23", ws.zfill(4).c_str());
			Assert::AreEqual(L"+1.23", ws.zfill(5).c_str());
			Assert::AreEqual(L"+01.23", ws.zfill(6).c_str());
			Assert::AreEqual(L"+001.23", ws.zfill(7).c_str());

			ws[0] = L'-';
			Assert::AreEqual(L"-1.23", ws.zfill(0).c_str());
			Assert::AreEqual(L"-1.23", ws.zfill(1).c_str());
			Assert::AreEqual(L"-1.23", ws.zfill(2).c_str());
			Assert::AreEqual(L"-1.23", ws.zfill(3).c_str());
			Assert::AreEqual(L"-1.23", ws.zfill(4).c_str());
			Assert::AreEqual(L"-1.23", ws.zfill(5).c_str());
			Assert::AreEqual(L"-01.23", ws.zfill(6).c_str());
			Assert::AreEqual(L"-001.23", ws.zfill(7).c_str());

			ws[0] = L'*';
			Assert::AreEqual(L"*1.23", ws.zfill(0).c_str());
			Assert::AreEqual(L"*1.23", ws.zfill(1).c_str());
			Assert::AreEqual(L"*1.23", ws.zfill(2).c_str());
			Assert::AreEqual(L"*1.23", ws.zfill(3).c_str());
			Assert::AreEqual(L"*1.23", ws.zfill(4).c_str());
			Assert::AreEqual(L"*1.23", ws.zfill(5).c_str());
			Assert::AreEqual(L"0*1.23", ws.zfill(6).c_str());
			Assert::AreEqual(L"00*1.23", ws.zfill(7).c_str());
		}

	};
}
