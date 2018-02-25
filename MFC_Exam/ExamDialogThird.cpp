// ExamDialogThird.cpp: файл реализации
//

#include "stdafx.h"
#include "MFC_Exam.h"
#include "ExamDialogThird.h"
#include "afxdialogex.h"
#include "Options.h"

#include <fstream>
#include <streambuf>

using namespace std;

// диалоговое окно ExamDialogThird

IMPLEMENT_DYNAMIC(ExamDialogThird, CDialogEx)

ExamDialogThird::ExamDialogThird(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXAM_THIRD, pParent)
    , keysList(_T(""))
{
    ::SetTimer(AfxGetMainWnd()->m_hWnd, 99, 1000, (TIMERPROC) NULL);
}

ExamDialogThird::~ExamDialogThird()
{
    ::KillTimer(AfxGetMainWnd()->m_hWnd, 99);
}

void ExamDialogThird::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_LBString(pDX, IDC_LIST1, keysList);
}


BEGIN_MESSAGE_MAP(ExamDialogThird, CDialogEx)
    ON_WM_TIMER()
END_MESSAGE_MAP()


// обработчики сообщений ExamDialogThird


void ExamDialogThird::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == 99) {
        UpdateData();

        ifstream ifs(L"text.txt"); // C:\\Users\\dmlar\\Desktop
        string content;
        content.assign((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));

        keysList = content.c_str();

        UpdateData(FALSE);
    }

    CDialogEx::OnTimer(nIDEvent);
}
