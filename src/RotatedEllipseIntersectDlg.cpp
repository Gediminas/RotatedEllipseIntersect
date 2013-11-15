// RotatedEllipseIntersectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RotatedEllipseIntersect.h"
#include "RotatedEllipseIntersectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotatedEllipseIntersectDlg dialog

CRotatedEllipseIntersectDlg::CRotatedEllipseIntersectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRotatedEllipseIntersectDlg::IDD, pParent)
{
	ellipse.dRadiusX   = 100;
	ellipse.dRadiusY   =  50;
	ellipse.ptCenter.x = 200;
	ellipse.ptCenter.y = 200;
	ellipse.dAngle     =  30;

	line.pt1.x =   0;
	line.pt1.y =  50;
	line.pt2.x = 300;
	line.pt2.y = 500;

	pt1.x = 0;
	pt1.y = 0;
	pt2.x = 0;
	pt2.y = 0;

	bTouches;
	bIntersects;


	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRotatedEllipseIntersectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_ERX, ellipse.dRadiusX);
	DDX_Text(pDX, IDC_ERY, ellipse.dRadiusY);
	DDX_Text(pDX, IDC_EAR, ellipse.dAngle);
	DDX_Text(pDX, IDC_ECX, ellipse.ptCenter.x);
	DDX_Text(pDX, IDC_ECY, ellipse.ptCenter.y);
	DDX_Text(pDX, IDC_L1X, line.pt1.x);
	DDX_Text(pDX, IDC_L1Y, line.pt1.y);
	DDX_Text(pDX, IDC_L2X, line.pt2.x);
	DDX_Text(pDX, IDC_L2Y, line.pt2.y);
	DDX_Text(pDX, IDC_R1X, pt1.x);
	DDX_Text(pDX, IDC_R1Y, pt1.y);
	DDX_Text(pDX, IDC_R2X, pt2.x);
	DDX_Text(pDX, IDC_R2Y, pt2.y);
	
	//{{AFX_DATA_MAP(CRotatedEllipseIntersectDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRotatedEllipseIntersectDlg, CDialog)
	//{{AFX_MSG_MAP(CRotatedEllipseIntersectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_RECALC, OnRecalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotatedEllipseIntersectDlg message handlers

BOOL CRotatedEllipseIntersectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	OnRecalc();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRotatedEllipseIntersectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRotatedEllipseIntersectDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();

		CClientDC dc(this); // device context for painting
		CGdiObject *pBrushOld = dc.SelectStockObject(NULL_BRUSH);

		for (int x = 0; x < 6; ++ x)
		{
			CPen pen(PS_DOT, 1, RGB(100, 100, 100));
			CPen *pPenOld = dc.SelectObject(&pen);
			dc.MoveTo(50+100*x, 50);
			dc.LineTo(50+100*x,550);
			dc.MoveTo( 50,  50+100*x);
			dc.LineTo(550,  50+100*x);
			dc.SelectObject(pPenOld);
		}

		DrawRotatedEllipse(&dc,	ellipse, 50, 50);

		dc.Ellipse(	50+(int)ellipse.ptCenter.x-2, 50+(int)ellipse.ptCenter.y-2,
					50+(int)ellipse.ptCenter.x+2, 50+(int)ellipse.ptCenter.y+2);

		dc.MoveTo(50+(int)line.pt1.x, 50+(int)line.pt1.y);
		dc.LineTo(50+(int)line.pt2.x, 50+(int)line.pt2.y);

		if (bIntersects || bTouches)
		{
			CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
			CPen *pPenOld = dc.SelectObject(&pen);
			dc.Ellipse(	50+(int)pt2.x-7, 50+(int)pt2.y-7,
						50+(int)pt2.x+7, 50+(int)pt2.y+7);

			dc.Ellipse(	50+(int)pt1.x-5, 50+(int)pt1.y-5,
						50+(int)pt1.x+5, 50+(int)pt1.y+5);
			dc.SelectObject(pPenOld);
		}

		dc.SelectObject(pBrushOld);
	}
}

HCURSOR CRotatedEllipseIntersectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRotatedEllipseIntersectDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnMouseMove(nFlags, point);
}

void CRotatedEllipseIntersectDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonUp(nFlags, point);
}

void CRotatedEllipseIntersectDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CRotatedEllipseIntersectDlg::OnRecalc() 
{
	UpdateData();
	
	bTouches = false;
	bIntersects = IntersectEllipseWithLine(ellipse, line, pt1, pt2, bTouches);

	if (!bIntersects)
	{
		pt1.x = pt1.y = pt2.x = pt2.y = 0;
	}

	UpdateData(FALSE);

	Invalidate();
}
