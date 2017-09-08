
// caoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "cao.h"
#include "caoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcaoDlg 对话框



CcaoDlg::CcaoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_XUZHOU, m_xuzhou);
	DDX_Control(pDX, IDC_LYG, m_lyg);
	DDX_Control(pDX, IDC_SUQIAN, m_suqian);
	DDX_Control(pDX, IDC_HUAIAN, m_huaian);
	DDX_Control(pDX, IDC_YANGZHOU, m_yangzhou);
	DDX_Control(pDX, IDC_TAIZHOU, m_taizhou);
	DDX_Control(pDX, IDC_YANCHENG, m_yancheng);
	DDX_Control(pDX, IDC_NANTONG, m_nantong);
	DDX_Control(pDX, IDC_SUZHOU, m_suzhou);
	DDX_Control(pDX, IDC_WUXI, m_wuxi);
	DDX_Control(pDX, IDC_ZHANJIANG, m_zhanjiang);
	DDX_Control(pDX, IDC_NANJING, m_nanjing);
	DDX_Control(pDX, IDC_CHANGZHOU, m_changzhou);
	DDX_Control(pDX, IDC_TAIHU, m_taihu);
}

BEGIN_MESSAGE_MAP(CcaoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SUZHOU, &CcaoDlg::OnBnClickedSuzhou)
END_MESSAGE_MAP()


// CcaoDlg 消息处理程序

BOOL CcaoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	changecolor();
	CBitmap bmp;
	bmp.LoadBitmapW(MAKEINTRESOURCE(IDB_BITMAP1));
	//添加位图
	m_bmp.Attach(bmp);
	//创建兼容DC
	CDC* pDc = GetDC();
	m_dc.CreateCompatibleDC(pDc);
	//用完之后释放
	ReleaseDC(pDc);
	//把位图对象选入DC中
	m_dc.SelectObject(&m_bmp);
	//使窗口无效,这样OnPaint函数就会被触发,使之被画出来
	Invalidate(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcaoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcaoDlg::OnPaint()
{
	/*if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}*/
	CPaintDC dc(this);
	CRect rect = { 0 };
	GetClientRect(&rect);
	//缩放位图
	BITMAP bm;
	m_bmp.GetBitmap(&bm);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(),
		&m_dc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

	CDialogEx::OnPaint();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcaoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcaoDlg::changecolor()
{
	m_suzhou.m_bTransparent = FALSE;
	m_suzhou.m_bDontUseWinXPTheme = TRUE;
	m_suzhou.m_bDrawFocus = FALSE;
	m_suzhou.SetFaceColor(RGB(255, 201, 14), TRUE);

	m_nanjing.m_bDrawFocus = FALSE;
	m_nanjing.m_bTransparent = FALSE;
	m_nanjing.m_bDontUseWinXPTheme = TRUE;
	m_nanjing.SetFaceColor(RGB(255, 128, 0), TRUE);

	m_yangzhou.m_bDrawFocus = FALSE;
	m_yangzhou.m_bTransparent = FALSE;
	m_yangzhou.m_bDontUseWinXPTheme = TRUE;
	m_yangzhou.SetFaceColor(RGB(237, 28, 36), TRUE);


	m_zhanjiang.m_bDrawFocus = FALSE;
	m_zhanjiang.m_bTransparent = FALSE;
	m_zhanjiang.m_bDontUseWinXPTheme = TRUE;
	m_zhanjiang.SetFaceColor(RGB(146, 232, 40), TRUE);


	m_taizhou.m_bDrawFocus = FALSE;
	m_taizhou.m_bTransparent = FALSE;
	m_taizhou.m_bDontUseWinXPTheme = TRUE;
	m_taizhou.SetFaceColor(RGB(163, 73, 164), TRUE);

	m_lyg.m_bDrawFocus = FALSE;
	m_lyg.m_bTransparent = FALSE;
	m_lyg.m_bDontUseWinXPTheme = TRUE;
	m_lyg.SetFaceColor(RGB(181, 230, 29), TRUE);

	m_changzhou.m_bDrawFocus = FALSE;
	m_changzhou.m_bTransparent = FALSE;
	m_changzhou.m_bDontUseWinXPTheme = TRUE;
	m_changzhou.SetFaceColor(RGB(150, 30, 30), TRUE);


	m_wuxi.m_bDrawFocus = FALSE;
	m_wuxi.m_bTransparent = FALSE;
	m_wuxi.m_bDontUseWinXPTheme = TRUE;
	m_wuxi.SetFaceColor(RGB(100, 100, 100), TRUE);


	m_huaian.m_bDrawFocus = FALSE;
	m_huaian.m_bTransparent = FALSE;
	m_huaian.m_bDontUseWinXPTheme = TRUE;
	m_huaian.SetFaceColor(RGB(255,128,255), TRUE);


	m_suqian.m_bDrawFocus = FALSE;
	m_suqian.m_bTransparent = FALSE;
	m_suqian.m_bDontUseWinXPTheme = TRUE;
	m_suqian.SetFaceColor(RGB(34, 177, 76), TRUE);


	m_taihu.m_bDrawFocus = FALSE;
	m_taihu.m_bTransparent = FALSE;
	m_taihu.m_bDontUseWinXPTheme = TRUE;
	m_taihu.SetFaceColor(RGB(153, 217, 234), TRUE);

	m_nantong.m_bDrawFocus = FALSE;
	m_nantong.m_bTransparent = FALSE;
	m_nantong.m_bDontUseWinXPTheme = TRUE;
	m_nantong.SetFaceColor(RGB(255, 255, 0), TRUE);

	m_yancheng.m_bDrawFocus = FALSE;
	m_yancheng.m_bTransparent = FALSE;
	m_yancheng.m_bDontUseWinXPTheme = TRUE;
	m_yancheng.SetFaceColor(RGB(182, 122, 87), TRUE);

	m_xuzhou.m_bDrawFocus = FALSE;
	m_xuzhou.m_bTransparent = FALSE;
	m_xuzhou.m_bDontUseWinXPTheme = TRUE;
	m_xuzhou.SetFaceColor(RGB(0, 162, 232), TRUE);


	
}

void CcaoDlg::OnBnClickedSuzhou()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("   aaa"));
}
