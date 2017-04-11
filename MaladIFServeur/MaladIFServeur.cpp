// MaladIFServeur.cpp : fichier projet principal.

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(args->Length);
	int port = 4242;
	switch (args->Length) {
	case 3:
		Int32::TryParse(args[2], port);
	case 1:
		Console::WriteLine(args[0]);
		Console::WriteLine(port);
		break;
	default:
		//erreur
		break;
	}

	Console::ReadKey();
    return 0;
}
