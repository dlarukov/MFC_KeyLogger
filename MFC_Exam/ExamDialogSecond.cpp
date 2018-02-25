#include "stdafx.h"
#include "MFC_Exam.h"
#include "ExamDialogSecond.h"
#include "afxdialogex.h"
#include "Options.h"

// диалоговое окно ExamDialogSecond

IMPLEMENT_DYNAMIC(ExamDialogSecond, CDialogEx)

ExamDialogSecond::ExamDialogSecond(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXAM_SECOND, pParent)
	, keysPath(Options::pathStatFile)
	, appsPath(Options::pathAppFile)
	, keysCheck(Options::keyStat)
	, appsCheck(Options::appStat)
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
    ON_BN_CLICKED(IDC_BUTTON3, &ExamDialogSecond::OnBnClickedButton3)
END_MESSAGE_MAP()


// обработчики сообщений ExamDialogSecond


void ExamDialogSecond::OnBnClickedOk()
{
	UpdateData();

	Options::keyStat = keysCheck;
	Options::appStat = appsCheck;

    //keysPath += _T("\\text.txt");

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
    UpdateData();
    BROWSEINFO bi = { 0 };
    bi.lpszTitle = _T("Select Folder");
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != 0)
    {
        // get the name of the folder
        TCHAR path[MAX_PATH];
        SHGetPathFromIDList(pidl, path);
        keysPath = path;

        // free memory used
        IMalloc * imalloc = 0;
        if (SUCCEEDED(SHGetMalloc(&imalloc)))
        {
            imalloc->Free(pidl);
            imalloc->Release();
        }
    }
    UpdateData(FALSE);
}


void ExamDialogSecond::OnBnClickedButton3()
{
    UpdateData();
    BROWSEINFO bi = { 0 };
    bi.lpszTitle = _T("Select Folder");
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != 0)
    {
        // get the name of the folder
        TCHAR path[MAX_PATH];
        SHGetPathFromIDList(pidl, path);
        appsPath = path;

        // free memory used
        IMalloc * imalloc = 0;
        if (SUCCEEDED(SHGetMalloc(&imalloc)))
        {
            imalloc->Free(pidl);
            imalloc->Release();
        }
    }
    UpdateData(FALSE);
}

