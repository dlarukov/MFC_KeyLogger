#pragma once

// ���������� ���� ExamDialogSecond

class ExamDialogSecond : public CDialogEx
{
	DECLARE_DYNAMIC(ExamDialogSecond)

public:
	ExamDialogSecond(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~ExamDialogSecond();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAM_SECOND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString keysPath;
	CString appsPath;
	afx_msg void OnBnClickedButton2();
	BOOL keysCheck;
	BOOL appsCheck;
    afx_msg void OnBnClickedButton3();
};
