#pragma once


// ResultShow �Ի���

class ResultShow : public CDialogEx
{
	DECLARE_DYNAMIC(ResultShow)

public:
	ResultShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ResultShow();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMenuButton1();
	afx_msg void OnBnClickedExitButton2();
};
