
// MaladIF.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMaladIFApp :
// Consultez MaladIF.cpp pour l'implémentation de cette classe
//

class CMaladIFApp : public CWinApp
{
public:
	CMaladIFApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CMaladIFApp theApp;