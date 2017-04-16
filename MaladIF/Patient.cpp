#include "stdafx.h"
#include "Patient.h"
#include <sstream>
#include <iostream>
Patient::Patient(long id, std::string nom, std::string prenom) {
	this->id = id;
	this->nom = nom;
	this->prenom = prenom;
}
void Patient::setGenome(std::string g) {
	std::stringstream ss(g);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, ',')) {
		genome.insert(item);
	}
}
std::set<std::string> Patient::getGenome() {
	return genome;
}
std::vector<Analyse> Patient::rechercherAnalyses(long date, std::string maladie) {
	std::vector<Analyse> result;
	for (Analyse a : analyses){
		//si date est défini et que c'est pas celle qu'on veut passe à la prochaine
		//de même pour maladie
		if ((date != -1 && a.getDate() != date) || 
			((!maladie.empty()) && (!(a.getMaladie().find(maladie) != std::string::npos)))) // si maladie est contenu
			//((!maladie.empty()) && a.getMaladie().compare(maladie)!=0))					// si maladie est egale
			continue;
		else
			result.push_back(a);
	}
	return result;
}
void Patient::ajouterAnalyse(Analyse analyse) {
	analyses.push_back(analyse);
}

Patient::~Patient()
{
}
