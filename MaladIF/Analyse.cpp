#include "stdafx.h"
#include "Analyse.h"

//dans .h ?
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

bool Analyse::estEgal(Analyse a) const
{
	if (maladie.compare(a.maladie) == 0
		&& dateFin == a.dateFin
		&& resultat == a.resultat
		&& dateDebut == a.dateDebut
		&& erreur == a.erreur)
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
