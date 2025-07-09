#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "cppstrings.h"
using namespace pcs;


namespace cppstringstests
{

	//=====   PART 1   ============================================
	TEST_CLASS(cppstringstests_PART_1)
	{
	public:

		TEST_METHOD(_cs)
		{
			using namespace pcs;
			auto abcd = "abcD"cs;
			auto wabcd = L"abcD"cs;
			Assert::AreEqual(abcd.c_str(), CppString(abcd).c_str());
			Assert::AreEqual(wabcd.c_str(), CppWString(wabcd).c_str());
		}

		TEST_METHOD(_csv)
		{
			using namespace pcs;
			auto abcd = "abcD"csv;
			auto wabcd = L"abcD"csv;
			Assert::AreEqual(abcd.c_str(), CppString(abcd).c_str());
			Assert::AreEqual(wabcd.c_str(), CppWString(wabcd).c_str());
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
			std::map<char, pcs::CppString> table{ {'a', "b"cs}, {'b', "a"cs} };
			Assert::AreEqual("b"cs.c_str(), table['a'].c_str());
			Assert::AreEqual("a"cs.c_str(), table['b'].c_str());

			std::map<wchar_t, pcs::CppWString> wtable{ {L'a', L"b"cs}, {L'b', L"a"cs} };
			Assert::AreEqual(L"b"cs.c_str(), wtable['a'].c_str());
			Assert::AreEqual(L"a"cs.c_str(), wtable['b'].c_str());
		}

		TEST_METHOD(constructor_02)
		{
			CppString keys("abcdE");
			CppString values("ABCDe");
			pcs::CppString::TransTable t(keys, values);
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString('D').c_str(), t['d'].c_str());
			Assert::AreEqual(CppString('e').c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wt(CppWString(L"abcdE"), CppWString(L"ABCDe"));
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString(L'D').c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString(L'e').c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(constructor_03)
		{
			pcs::CppString::TransTable t(CppString("abc"), CppString("ABC"), CppString("dE"));
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wt(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(constructor_04)
		{
			pcs::CppString::TransTable t(CppString("abc"), { CppString("AA"), CppString("BBB"), CppString("C") });
			Assert::AreEqual(CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString('z').c_str(), t['z'].c_str());

			pcs::CppWString::TransTable wt(CppWString(L"abc"), { CppWString(L"AA"), CppWString(L"BBB"), CppWString(L"C") });
			Assert::AreEqual(CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L"C").c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString(L'9').c_str(), wt[L'9'].c_str());
		}

		TEST_METHOD(constructor_05)
		{
			pcs::CppString::TransTable t(CppString("abc"), { CppString("AA"), CppString("BBB"), CppString("C") }, "dE"cs);
			Assert::AreEqual(CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('z').c_str(), t['z'].c_str());

			pcs::CppWString::TransTable wt(CppWString(L"abc"), { CppWString(L"AA"), CppWString(L"BBB"), CppWString(L"C") }, L"dE"cs);
			Assert::AreEqual(CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L"C").c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'e').c_str(), wt[L'e'].c_str());
		}

		TEST_METHOD(constructor_06)
		{
			pcs::CppString::TransTable t("abC", "ABc");
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('c').c_str(), t['C'].c_str());
			Assert::AreEqual(CppString('c').c_str(), t['c'].c_str());

			pcs::CppWString::TransTable wt(L"abC", L"ABc");
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'c').c_str(), wt[L'C'].c_str());
			Assert::AreEqual(CppWString(L'c').c_str(), wt[L'c'].c_str());
		}

		TEST_METHOD(constructor_07)
		{
			pcs::CppString::TransTable t("abc", "ABC", "dE");
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('e').c_str(), t['e'].c_str());

			pcs::CppWString::TransTable wt(L"abc", L"ABC", L"dE");
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'A'].c_str());
		}

		TEST_METHOD(constructor_08)
		{
			std::string keys("abC");
			std::vector<std::string> values{ "AA", "BBB", "c" };
			pcs::CppString::TransTable t(keys.begin(), keys.end(), values.begin(), values.end());
			Assert::AreEqual(CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('c').c_str(), t['C'].c_str());
			Assert::AreEqual(CppString('c').c_str(), t['c'].c_str());

			std::wstring wkeys(L"abC");
			std::vector<std::wstring> wvalues{ L"AA", L"BBB", L"c" };
			pcs::CppWString::TransTable wt(wkeys.begin(), wkeys.end(), wvalues.begin(), wvalues.end());
			Assert::AreEqual(CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'c').c_str(), wt[L'C'].c_str());
			Assert::AreEqual(CppWString(L'c').c_str(), wt[L'c'].c_str());
		}

		TEST_METHOD(constructor_09)
		{
			std::string keys("abC");
			std::vector<std::string> values{ "AA", "BBB", "c" };
			std::string not_translated("dE");
			pcs::CppString::TransTable t(keys.begin(), keys.end(), values.begin(), values.end(), not_translated.cbegin(), not_translated.cend());
			Assert::AreEqual(CppString("AA").c_str(), t['a'].c_str());
			Assert::AreEqual(CppString("BBB").c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('c').c_str(), t['C'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('c').c_str(), t['c'].c_str());

			std::wstring wkeys(L"abC");
			std::vector<std::wstring> wvalues{ L"AA", L"BBB", L"c" };
			std::wstring wnot_translated(L"dE");
			pcs::CppWString::TransTable wt(wkeys.begin(), wkeys.end(), wvalues.begin(), wvalues.end(), wnot_translated.cbegin(), wnot_translated.cend());
			Assert::AreEqual(CppWString(L"AA").c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L"BBB").c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'c').c_str(), wt[L'C'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'c').c_str(), wt[L'c'].c_str());
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
			pcs::CppString::TransTable ct(CppString("abc"), CppString("ABC"), CppString("dE"));
			pcs::CppString::TransTable t(ct);
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wct(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			pcs::CppWString::TransTable wt(wct);
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(constructor_move)
		{
			pcs::CppString::TransTable mt(CppString("abc"), CppString("ABC"), CppString("dE"));
			pcs::CppString::TransTable t(std::move(mt));
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wmt(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			pcs::CppWString::TransTable wt(std::move(wmt));
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(assign_copy)
		{
			pcs::CppString::TransTable ct(CppString("abc"), CppString("ABC"), CppString("dE"));
			pcs::CppString::TransTable t = ct;
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wct(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			pcs::CppWString::TransTable wt = wct;
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(assign_move)
		{
			pcs::CppString::TransTable mt(CppString("abc"), CppString("ABC"), CppString("dE"));
			pcs::CppString::TransTable t = std::move(mt);
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wmt(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			pcs::CppWString::TransTable wt = std::move(wmt);
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(assign_map)
		{
			pcs::CppString::TransTable ct(CppString("abc"), CppString("ABC"), CppString("dE"));
			pcs::CppString::TransTable t = ct.get_table();
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString('f').c_str(), t['f'].c_str());

			pcs::CppWString::TransTable wct(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			pcs::CppWString::TransTable wt = wct.get_table();
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'f').c_str(), wt[L'f'].c_str());
		}

		TEST_METHOD(indexing)
		{
			pcs::CppString::TransTable t(CppString("abc"), CppString("ABC"), CppString("dE"));
			Assert::AreEqual(CppString('A').c_str(), t['a'].c_str());
			Assert::AreEqual(CppString('B').c_str(), t['b'].c_str());
			Assert::AreEqual(CppString('C').c_str(), t['c'].c_str());
			Assert::AreEqual(CppString().c_str(), t['d'].c_str());
			Assert::AreEqual(CppString().c_str(), t['E'].c_str());
			Assert::AreEqual(CppString(',').c_str(), t[','].c_str());

			pcs::CppWString::TransTable wt(CppWString(L"abc"), CppWString(L"ABC"), CppWString(L"dE"));
			Assert::AreEqual(CppWString(L'A').c_str(), wt[L'a'].c_str());
			Assert::AreEqual(CppWString(L'B').c_str(), wt[L'b'].c_str());
			Assert::AreEqual(CppWString(L'C').c_str(), wt[L'c'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'd'].c_str());
			Assert::AreEqual(CppWString().c_str(), wt[L'E'].c_str());
			Assert::AreEqual(CppWString(L'\n').c_str(), wt[L'\n'].c_str());
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
		}

		TEST_METHOD(constructor_10)
		{
			pcs::CppString s("abcDEfgh", 5);
			Assert::AreEqual(std::size_t(5), s.size());
			Assert::AreEqual(pcs::CppString("abcDE").c_str(), s.c_str());

			pcs::CppWString ws(L"ABCdefGH", 7);
			Assert::AreEqual(std::size_t(7), ws.size());
			Assert::AreEqual(pcs::CppWString(L"ABCdefG").c_str(), ws.c_str());
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

				CppString s(ch);
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

				CppString s(ch);
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

				CppWString ws(wch);
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

			CppString s(ch);
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

				CppString s(ch);
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

				CppString s(ch);
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

				CppWString ws(wch);
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

			CppString s(ch);
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
			Assert::AreEqual(" abc", s.rjust(4).c_str());
			Assert::AreEqual("  abc", s.rjust(5).c_str());
			Assert::AreEqual("abc", s.rjust(1).c_str());
			Assert::AreEqual("abc", s.rjust(2).c_str());
			Assert::AreEqual("abc", s.rjust(3).c_str());
			Assert::AreEqual(".abc", s.rjust(4, '.').c_str());
			Assert::AreEqual("..abc", s.rjust(5, '.').c_str());

			pcs::CppWString ws(L"abc");
			Assert::AreEqual(L"abc", ws.rjust(1).c_str());
			Assert::AreEqual(L"abc", ws.rjust(2).c_str());
			Assert::AreEqual(L"abc", ws.rjust(3).c_str());
			Assert::AreEqual(L" abc", ws.rjust(4).c_str());
			Assert::AreEqual(L"  abc", ws.rjust(5).c_str());
			Assert::AreEqual(L"abc", ws.rjust(1).c_str());
			Assert::AreEqual(L"abc", ws.rjust(2).c_str());
			Assert::AreEqual(L"abc", ws.rjust(3).c_str());
			Assert::AreEqual(L".abc", ws.rjust(4, '.').c_str());
			Assert::AreEqual(L"..abc", ws.rjust(5, '.').c_str());
		}

		TEST_METHOD(rpartition)
		{
			pcs::CppString s("abcd#123efg#123hij");
			std::vector<CppString> res{ s.rpartition("#123") };
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

			res = ""cs.rpartition("A");
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());

			pcs::CppWString ws(L"abcd#123efg#123hij");
			std::vector<CppWString> wres{ ws.rpartition(L"#123") };
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

			wres = L""cs.rpartition(L"A");
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
		}

		TEST_METHOD(rsplit)
		{
			pcs::CppString s(" abcd efg   hij klmn  ");
			std::vector<CppString> res{ s.rsplit() };
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

			s = pcs::CppString(5, ' ');  //"     "cs;
			res = s.rsplit();
			Assert::AreEqual(pcs::CppString::size_type(6), res.size());
			Assert::AreEqual("", res[0].c_str());
			Assert::AreEqual("", res[1].c_str());
			Assert::AreEqual("", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("", res[4].c_str());
			Assert::AreEqual("", res[5].c_str());


			s = " abcd#123efg#123hij #123#123klmn  "cs;
			res = s.rsplit("#123");
			Assert::AreEqual(pcs::CppString::size_type(5), res.size());
			Assert::AreEqual(" abcd", res[0].c_str());
			Assert::AreEqual("efg", res[1].c_str());
			Assert::AreEqual("hij ", res[2].c_str());
			Assert::AreEqual("", res[3].c_str());
			Assert::AreEqual("klmn  ", res[4].c_str());

			s = "#123#123abcd#123123efg#123hij #123#123klmn  #123#123"cs;
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
			std::vector<CppWString> wres{ ws.rsplit() };
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

			ws = pcs::CppWString(5, ' ');  //L"     "cs;
			wres = ws.rsplit();
			Assert::AreEqual(pcs::CppWString::size_type(6), wres.size());
			Assert::AreEqual(L"", wres[0].c_str());
			Assert::AreEqual(L"", wres[1].c_str());
			Assert::AreEqual(L"", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"", wres[4].c_str());
			Assert::AreEqual(L"", wres[5].c_str());

			ws = L" abcd#123efg#123hij #123#123klmn  "cs;
			wres = ws.rsplit(L"#123");
			Assert::AreEqual(pcs::CppWString::size_type(5), wres.size());
			Assert::AreEqual(L" abcd", wres[0].c_str());
			Assert::AreEqual(L"efg", wres[1].c_str());
			Assert::AreEqual(L"hij ", wres[2].c_str());
			Assert::AreEqual(L"", wres[3].c_str());
			Assert::AreEqual(L"klmn  ", wres[4].c_str());

			ws = L"#123#123abcd#123123efg#123hij #123#123klmn  #123#123"cs;
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

			s = " abcd efg  hij"cs;
			sres = s.rstrip();
			Assert::AreEqual(" abcd efg  hij", sres.c_str());

			s = ""cs;
			sres = s.rstrip();
			Assert::AreEqual("", sres.c_str());

			s = "     "cs;
			sres = s.rstrip();
			Assert::AreEqual("", sres.c_str());

			s = "#124abcd#124efg#124#124#124"cs;
			sres = s.rstrip("#124");
			Assert::AreEqual("#124abcd#124efg", sres.c_str());

			s = "#124abcd#124efg#124#124hij"cs;
			sres = s.rstrip("#124");
			Assert::AreEqual("#124abcd#124efg#124#124hij", sres.c_str());

			s = "#124#124#124#124#124";
			sres = s.rstrip("#124");
			Assert::AreEqual("", sres.c_str());

			pcs::CppWString ws(L" abcd efg   ");
			pcs::CppWString wsres{ ws.rstrip() };
			Assert::AreEqual(L" abcd efg", wsres.c_str());

			ws = L" abcd efg  hij"cs;
			wsres = ws.rstrip();
			Assert::AreEqual(L" abcd efg  hij", wsres.c_str());

			ws = L""cs;
			wsres = ws.rstrip();
			Assert::AreEqual(L"", wsres.c_str());

			ws = L"     "cs;
			wsres = ws.rstrip();
			Assert::AreEqual(L"", wsres.c_str());

			ws = L"#124abcd#124efg#124#124#124"cs;
			wsres = ws.rstrip(L"#124");
			Assert::AreEqual(L"#124abcd#124efg", wsres.c_str());

			ws = L"#124abcd#124efg#124#124hij"cs;
			wsres = ws.rstrip(L"#124");
			Assert::AreEqual(L"#124abcd#124efg#124#124hij", wsres.c_str());

			ws = L"#124#124#124#124#124";
			wsres = ws.rstrip(L"#124");
			Assert::AreEqual(L"", wsres.c_str());
		}

	};
}
