
// caoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxbutton.h"


// CcaoDlg �Ի���
class CcaoDlg : public CDialogEx
{
// ����
public:
	CcaoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CDC m_dc;
	CBitmap m_bmp;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCButton m_xuzhou;
	CMFCButton m_lyg;
	CMFCButton m_suqian;
	CMFCButton m_huaian;
	CMFCButton m_yangzhou;
	CMFCButton m_taizhou;
	CMFCButton m_yancheng;
	CMFCButton m_nantong;
	CMFCButton m_suzhou;
	CMFCButton m_wuxi;
	CMFCButton m_zhanjiang;
	CMFCButton m_nanjing;
	CMFCButton m_changzhou;
	void changecolor();
	afx_msg void OnBnClickedSuzhou();
	CMFCButton m_taihu;
};
