#pragma once


// ���������� ���� examDialogFirst

class ExamDialogFirst : public CDialogEx
{
	DECLARE_DYNAMIC(ExamDialogFirst)

public:
	ExamDialogFirst(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~ExamDialogFirst();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAM_FIRST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnModesFirstmode();
	afx_msg void OnModesThirdmode();
};
