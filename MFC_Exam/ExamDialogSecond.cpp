// ExamDialogSecond.cpp: файл реализации
//

#include "stdafx.h"
#include "MFC_Exam.h"
#include "ExamDialogSecond.h"
#include "afxdialogex.h"
#include "Options.h"


// диалоговое окно ExamDialogSecond

IMPLEMENT_DYNAMIC(ExamDialogSecond, CDialogEx)

ExamDialogSecond::ExamDialogSecond(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXAM_SECOND, pParent)
	, keysPath(_T(""))
	, appsPath(_T(""))
	, keysCheck(FALSE)
	, appsCheck(FALSE)
{

}

ExamDialogSecond::~ExamDialogSecond()
{
}

void ExamDialogSecond::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, keysPath);
	DDX_Text(pDX, IDC_EDIT2, appsPath);
	DDX_Check(pDX, IDC_CHECK1, keysCheck);
	DDX_Check(pDX, IDC_CHECK2, appsCheck);
}


BEGIN_MESSAGE_MAP(ExamDialogSecond, CDialogEx)
	ON_BN_CLICKED(IDOK, &ExamDialogSecond::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ExamDialogSecond::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &ExamDialogSecond::OnBnClickedButton2)
END_MESSAGE_MAP()


// обработчики сообщений ExamDialogSecond


void ExamDialogSecond::OnBnClickedOk()
{
	UpdateData();

	Options::keyStat = keysCheck;
	Options::appStat = appsCheck;

	wcscpy_s(Options::pathAppFile, MAX_PATH, appsPath.GetBuffer());
	wcscpy_s(Options::pathStatFile, MAX_PATH, keysPath.GetBuffer());

	CDialogEx::OnOK();
}


void ExamDialogSecond::OnBnClickedCancel()
{

	CDialogEx::OnCancel();
}


void ExamDialogSecond::OnBnClickedButton2()
{

}

