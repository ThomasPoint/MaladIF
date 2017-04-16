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
			a1.setDiagnostic(Diagnostic::POSITIF); 
			// on ne peut pas modifier le diagnostic après l'avoir ajouter l'analyse au patient
			// --> copie des valeurs l'objet lors de l'ajout à la liste 
			// --> utiliser une liste de pointeur au lieu d'une liste d'objet ?
			//Ou alors pas besoin, une Analyse est stocké dans Patient que quand son Diagnostic est fait ?
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
			
			v = patient.rechercherAnalyses(a1.getDate(), "");
			Assert::IsTrue(v.size() == 1 && a1.estEgal(v.at(0)),L"Test avec la date");
		}
		
	};
}