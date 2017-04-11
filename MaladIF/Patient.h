#pragma once
#include <string>
#include <set>
#include <vector>
#include "Analyse.h"
#include "Maladie.h"
class Patient
{
private:
	long id;
	std::string nom;
	std::string prenom;
	std::vector<Analyse> analyses;
	std::set<std::string> genome;
public:
	Patient(long id, std::string nom, std::string prenom);
	void setGenome(std::string g);
	std::set<std::string> getGenome();
	std::vector<Analyse> rechercherAnalyses(long date, Maladie maladie);
	void ajouterAnalyse(Analyse analyse);
	~Patient();
};

