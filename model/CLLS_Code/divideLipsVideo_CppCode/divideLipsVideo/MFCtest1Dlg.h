
// MFCtest1Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCtest1Dlg �Ի���
class CMFCtest1Dlg : public CDialogEx
{
// ����
public:
	CMFCtest1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCTEST1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenVideoButton2();
	//afx_msg void OnDropdownOpenVideoButton2(NMHDR *pNMHDR, LRESULT *pResult);
};
