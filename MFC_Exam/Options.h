#include "stdafx.h"

class Options {
public:
	static TCHAR pathStatFile[MAX_PATH];
	static bool keyStat;

	static TCHAR pathAppFile[MAX_PATH];
	static bool appStat;
};

TCHAR Options::pathStatFile[MAX_PATH];
bool Options::keyStat = false;

TCHAR Options::pathAppFile[MAX_PATH];
bool Options::appStat = false;
