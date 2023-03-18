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

	};
}
