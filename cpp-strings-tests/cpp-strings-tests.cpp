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
}
