// examDialogFirst.cpp: файл реализации
//

#include "stdafx.h"
#include "MFC_Exam.h"
#include "ExamDialogFirst.h"
#include "ExamDialogSecond.h"
#include "ExamDialogThird.h"
#include "afxdialogex.h"


// диалоговое окно examDialogFirst

IMPLEMENT_DYNAMIC(ExamDialogFirst, CDialogEx)

ExamDialogFirst::ExamDialogFirst(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXAM_FIRST, pParent)
{

}

ExamDialogFirst::~ExamDialogFirst()
{
}

void ExamDialogFirst::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ExamDialogFirst, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ExamDialogFirst::OnBnClickedButton1)
	ON_COMMAND(ID_MODES_FIRSTMODE, &ExamDialogFirst::OnModesFirstmode)
	ON_COMMAND(ID_MODES_THIRDMODE, &ExamDialogFirst::OnModesThirdmode)
END_MESSAGE_MAP()


// обработчики сообщений examDialogFirst


void ExamDialogFirst::OnBnClickedButton1()
{
	HINSTANCE hModule = ::LoadLibraryA("TrackingDLL.dll");

	if (hModule) {
		typedef void(__stdcall FUNC)(char*);
		FUNC *startTracking, *stopTracking;

		startTracking = (FUNC*)::GetProcAddress((HMODULE)hModule, (LPCSTR)MAKEINTRESOURCE(1));
		stopTracking = (FUNC*)::GetProcAddress((HMODULE)hModule, (LPCSTR)MAKEINTRESOURCE(2));

		if (startTracking && stopTracking) {
			(*startTracking)("text.txt");
		}
		else {
			MessageBox(_T("Error: cannot get functions from dll"));
		}
		::FreeLibrary(hModule);
	}
}


void ExamDialogFirst::OnModesFirstmode()
{
	auto options = new ExamDialogSecond(this);
	options->DoModal();
}


void ExamDialogFirst::OnModesThirdmode()
{
	auto records = new ExamDialogThird(this);
	records->DoModal();
}
