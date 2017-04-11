#include "stdafx.h"
#include "CppUnitTest.h"
#include "Patient.h"
#include <string>
#include <set>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Patient patient(1,"Gonnet","Tim");
			patient.setGenome("A");
			std::string gen = *patient.getGenome().begin();
			std::string test = "A";
			Assert::IsTrue(gen.compare(test)==0);
			//Assert::AreEqual(test,test, "Test 1 failed");
		}

	};
}