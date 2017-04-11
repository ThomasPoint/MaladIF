
// MaladIFServer.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMaladIFServerApp :
// Consultez MaladIFServer.cpp pour l'implémentation de cette classe
//

class CMaladIFServerApp : public CWinApp
{
public:
	CMaladIFServerApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CMaladIFServerApp theApp;