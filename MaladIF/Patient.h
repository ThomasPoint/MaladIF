#pragma once
#include <string>
#include <set>
#include <vector>
#include "Analyse.h"
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
	std::set<std::string> getGenome() const;
	std::string getNom() const;
	std::string getPrenom() const;
	long getId() const;
	std::vector<Analyse> rechercherAnalyses(long date, std::string maladie) const;
	//-1 si date indéfini, "" si maladie non définie. La recherche prend en compte toutes les maladies commençant par maladie.
	void ajouterAnalyse(Analyse analyse);
	bool estEgal(Patient a) const;
	~Patient();
};

