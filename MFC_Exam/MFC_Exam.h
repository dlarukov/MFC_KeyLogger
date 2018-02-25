
// MFC_Exam.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

// CMFC_ExamApp:
// See MFC_Exam.cpp for the implementation of this class
//

class CMFC_ExamApp : public CWinApp
{
public:
	CMFC_ExamApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_ExamApp theApp;