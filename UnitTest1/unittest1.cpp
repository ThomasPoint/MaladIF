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
		
		TEST_METHOD(U1001)
		{
			Patient patient(1,"Gonnet","Tim");
			patient.setGenome("A,C,D"); // marche que pour un ordre alphabétique à cause de la perte d'ordre du set
			std::string gen;
			for (const std::string &piece : patient.getGenome()) gen += piece+",";
			gen.erase(gen.size() - 1);
			std::string test = "A,C,D";
			Assert::IsTrue(gen.compare(test)==0);
		}

	};
}