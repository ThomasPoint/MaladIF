#pragma once
#include <string>
#include "Diagnostic.h"
class Analyse
{
public:
	Analyse(std::string maladie);
	~Analyse();
	long getDate() const;
	std::string getMaladie() const;
	void setDiagnostic(Diagnostic d);
	bool getResultat() const;
	bool estEgal(Analyse a) const;
private:
	std::string maladie;
	long dateDebut;
	long dateFin;
	bool resultat;
	bool erreur;
};

