#include "stdafx.h"
#include "Patient.h"

//dans .h ?
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
std::set<std::string> Patient::getGenome() const {
	return genome;
}
std::string Patient::getNom() const
{
	return nom;
}
std::string Patient::getPrenom() const
{
	return prenom;
}
long Patient::getId() const
{
	return id;
}
std::vector<Analyse> Patient::rechercherAnalyses(long date, std::string maladie) const {
	std::vector<Analyse> result;
	for (Analyse a : analyses){
		//si date est défini et que c'est pas celle qu'on veut passe à la prochaine Analyse
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
bool Patient::estEgal(Patient a) const //prend en compte que nom, prenom, id
{
	if (nom.compare(a.nom) == 0
		&& prenom.compare(a.prenom) == 0
		&& id == a.id)
		return true;
	else
		return false;
}

Patient::~Patient()
{
}
