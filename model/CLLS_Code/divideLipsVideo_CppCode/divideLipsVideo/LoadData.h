#pragma once


// LoadData �Ի���

class LoadData : public CDialogEx
{
	DECLARE_DYNAMIC(LoadData)

public:
	LoadData(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LoadData();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedVideoButton1();
	afx_msg void OnBnClickedJsonButton2();
	afx_msg void OnBnClickedProcessButton4();
	afx_msg void OnBnClickedProcessButton5();
	afx_msg void OnBnClickedMenu1Button1();
	afx_msg void OnBnClickedExit1Button2();
};
