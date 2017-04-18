#include "stdafx.h"
#include "CppUnitTest.h"

#include "DBMedecin.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(U1101)
		{
			Patient p1(1, "Gonnet", "Tim");
			Patient p2(2, "Fontaine", "Romain");
			DBMedecin dbMedecin;
			dbMedecin.creerPatient(p1);
			dbMedecin.creerPatient(p2);
			std::vector<Patient> v;

			v = dbMedecin.rechercherPatient(-1, "Gonnet","Tim");
			Assert::IsTrue(v.size() == 1 && p1.estEgal(v.at(0)), L"Test avec Tim");

			v = dbMedecin.rechercherPatient(-1, "", "");
			Assert::IsTrue(v.size() == 2 && p1.estEgal(v.at(0)), L"Test avec aucun argument");

			v = dbMedecin.rechercherPatient(1, "", "");
			Assert::IsTrue(v.size() == 1 && p1.estEgal(v.at(0)), L"Test 2 avec Tim");

			v = dbMedecin.rechercherPatient(1, "Gonnet", "Tim");
			Assert::IsTrue(v.size() == 1 && p1.estEgal(v.at(0)), L"Test 3 avec Tim");

			v = dbMedecin.rechercherPatient(-1, "G", "T");
			Assert::IsTrue(v.size() == 1 && p1.estEgal(v.at(0)), L"Test 4 avec Tim");
		}


	};
}