#include "stdafx.h"
#include "DBMedecin.h"


DBMedecin::DBMedecin()
{
}


DBMedecin::~DBMedecin()
{
}

std::vector<Patient> DBMedecin::rechercherPatient(long id, std::string nom, std::string prenom) const
{
	std::vector<Patient> result;
	for (Patient p : patients) {
		//si date est défini et que c'est pas celle qu'on veut passe à la prochaine Analyse
		//de même pour maladie
		if ((id != -1 && p.getId() != id)
			|| ((!nom.empty()) && (!(p.getNom().find(nom) != std::string::npos))) // si maladie est contenu
			|| ((!prenom.empty()) && (!(p.getPrenom().find(prenom) != std::string::npos))))																			//((!maladie.empty()) && a.getMaladie().compare(maladie)!=0))					// si maladie est egale
			continue;
		else
			result.push_back(p);
	}
	return result;
}

void DBMedecin::majListeMaladiesServeurs()
{
	//todo
}

Diagnostic DBMedecin::analyserPatient(Patient patient, std::string maladie)
{
	//todo
	return Diagnostic::ERREUR_CONNEXION;
}

std::vector<std::string> DBMedecin::getMaladies() const
{
	//todo
	return std::vector<std::string>();
}

void DBMedecin::creerPatient(Patient p)
{
	patients.push_back(p);
}
