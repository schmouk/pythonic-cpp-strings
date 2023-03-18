#include "pch.h"
#include "CppUnitTest.h"

#include "cppstrings.h"

#include <format>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cppstringstests
{
	//===   templated chars classes tests   ======================
	TEST_CLASS(cppstringstests_PART_1)
	{
	public:
		
		TEST_METHOD(is_alpha)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isalpha(ch), pcs::is_alpha(char(ch)));
			for (wchar_t ch=0; ch < L'\uffff'; ++ch)
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

	};
}
