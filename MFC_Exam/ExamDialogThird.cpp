// ExamDialogThird.cpp: файл реализации
//

#include "stdafx.h"
#include "MFC_Exam.h"
#include "ExamDialogThird.h"
#include "afxdialogex.h"


// диалоговое окно ExamDialogThird

IMPLEMENT_DYNAMIC(ExamDialogThird, CDialogEx)

ExamDialogThird::ExamDialogThird(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXAM_THIRD, pParent)
{

}

ExamDialogThird::~ExamDialogThird()
{
}

void ExamDialogThird::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ExamDialogThird, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений ExamDialogThird
