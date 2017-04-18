#pragma once

#include <vector>
#include <map>
#include <string>

#include "Patient.h"
class DBMedecin
{
public:
	DBMedecin();
	~DBMedecin();
	std::vector<Patient> rechercherPatient(long id,  std::string nom, std::string prenom) const;
	void majListeMaladiesServeurs();
	Diagnostic analyserPatient( Patient patient ,std::string maladie);
	std::vector<std::string> getMaladies() const;
	void creerPatient( Patient p );
	//void ajouterServeur(ServeurDistant s);
	//void ajouterServeurDistant( ServeurDistant sd  ); //en double ?
	//void supprimerServeurDistant( ServeurDistantsd sd);
private:
	std::vector<Patient> patients;
	//std::vector<ServeurDistant> serveurs;
	//std::multimap<std::string, ServeurDistant> maladiesServeurs;
};

