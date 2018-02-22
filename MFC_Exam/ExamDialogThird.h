#pragma once


// диалоговое окно ExamDialogThird

class ExamDialogThird : public CDialogEx
{
	DECLARE_DYNAMIC(ExamDialogThird)

public:
	ExamDialogThird(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~ExamDialogThird();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAM_THIRD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
