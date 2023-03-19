#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "cppstrings.h"
using namespace pcs;


namespace cppstringstests
{
	//===   templated chars classes tests   ======================
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
}
