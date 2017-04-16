#include "stdafx.h"
#include "Analyse.h"

#include <time.h>

Analyse::Analyse(std::string maladie)
{
	this->maladie = maladie;
	this->dateDebut =(long) time(NULL);
	this->dateFin = -1;
}

Analyse::~Analyse()
{
}

long Analyse::getDate() const
{
	return dateFin;
}

std::string Analyse::getMaladie() const
{
	return maladie;
}

bool Analyse::getResultat() const
{
	return resultat;
}

bool Analyse::estEgal(Analyse a) const//ne compare que la maladie et la date
{
	if (getMaladie().compare(a.getMaladie()) == 0
		&& getDate() == a.getDate()
		&& getResultat() == a.getResultat())
		return true;
	else
		return false;
}


void Analyse::setDiagnostic(Diagnostic d) {
	switch (d) {
	case Diagnostic::POSITIF:
		resultat = true;
		erreur = false;
		break;
	case Diagnostic::NEGATIF:
		resultat = false;
		erreur = false;
		break;
	case Diagnostic::ERREUR_CONNEXION:
		erreur = true;
		break;
	case Diagnostic::MALADIE_INCONNUE:
		erreur = true;
		break;
	default:
		break;
	}
	dateFin = (long)time(NULL);
}
