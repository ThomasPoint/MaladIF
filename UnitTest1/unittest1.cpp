#include "stdafx.h"
#include "CppUnitTest.h"
#include "Patient.h"
#include <string>
#include <set>
#include <iostream>
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
			gen.erase(gen.size() - 1); // on enleve la derniere virgule
			std::string test = "A,C,D";
			Assert::IsTrue(gen.compare(test)==0);
		}

		TEST_METHOD(U1002)
		{
			Patient patient(1, "Gonnet", "Tim");
			Analyse a1("maladie1");
			Analyse a2("maladie2");
			patient.ajouterAnalyse(a1);
			patient.ajouterAnalyse(a2);
			std::vector<Analyse> v;
			
			v=patient.rechercherAnalyses(-1, "maladie1");
			Assert::IsTrue(v.size() == 1 && a1.estEgal(v.at(0)), L"Test avec maladie1");

			v = patient.rechercherAnalyses(-1, "");
			Assert::IsTrue(v.size() == 2,L"Test sans paramètre");

			v = patient.rechercherAnalyses(-1, "maladie3");
			Assert::IsTrue(v.size() == 0,L"Test avec maladie3");

			a1.setDiagnostic(Diagnostic::POSITIF);
			v = patient.rechercherAnalyses(a1.getDate(), "");
			Logger::WriteMessage((std::to_string(v.size()).c_str()));
			Logger::WriteMessage((std::to_string(a1.getDate()).c_str()));
			Logger::WriteMessage((std::to_string(a2.getDate()).c_str()));
			Assert::IsTrue(v.size() == 1 && a1.estEgal(v.at(0)),L"Test avec la date");
		}

	};
}