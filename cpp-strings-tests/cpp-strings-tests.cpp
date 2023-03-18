#include "pch.h"
#include "CppUnitTest.h"

#include "cppstrings.h"

#include <format>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cppstringstests
{
	TEST_CLASS(cppstringstests)
	{
	public:
		
		TEST_METHOD(is_alpha)
		{
			for (int ch = 0; ch <= 255; ++ch)
				Assert::AreEqual((const bool)std::isalpha(ch), pcs::is_alpha(char(ch)));
			for (wchar_t ch=0; ch < L'\uffff'; ++ch)
				Assert::AreEqual((const bool)std::iswalpha(ch), pcs::is_alpha(ch));
		}
	};
}
