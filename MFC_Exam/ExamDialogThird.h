#pragma once

// ���������� ���� ExamDialogThird

class ExamDialogThird : public CDialogEx
{
	DECLARE_DYNAMIC(ExamDialogThird)

public:
	ExamDialogThird(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~ExamDialogThird();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAM_THIRD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
    CString keysList;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
