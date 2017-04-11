#include "stdafx.h"
#include "Patient.h"

Patient::Patient(long id, std::string nom, std::string prenom) {

}
void Patient::setGenome(std::string g) {
	genome.insert(g);
}
std::set<std::string> Patient::getGenome() {
	return genome;
}
std::vector<Analyse> Patient::rechercherAnalyses(long date, Maladie maladie) {
	return analyses;//to change ?
}
void Patient::ajouterAnalyse(Analyse analyse) {

}

Patient::~Patient()
{
}
