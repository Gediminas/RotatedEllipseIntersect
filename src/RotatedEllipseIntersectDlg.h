// RotatedEllipseIntersectDlg.h : header file
//

#if !defined(AFX_ROTATEDELLIPSEINTERSECTDLG_H__390290A8_C953_426E_AE72_8808C82E9355__INCLUDED_)
#define AFX_ROTATEDELLIPSEINTERSECTDLG_H__390290A8_C953_426E_AE72_8808C82E9355__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Intersect.h"

/////////////////////////////////////////////////////////////////////////////
// CRotatedEllipseIntersectDlg dialog

class CRotatedEllipseIntersectDlg : public CDialog
{
// Construction
public:
	CRotatedEllipseIntersectDlg(CWnd* pParent = NULL);	// standard constructor

	//{{AFX_DATA(CRotatedEllipseIntersectDlg)
	enum { IDD = IDD_ROTATEDELLIPSEINTERSECT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotatedEllipseIntersectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRotatedEllipseIntersectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRecalc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	SEllipse2D ellipse;
	SLine2D    line;
	SPoint2D   pt1;
	SPoint2D   pt2;
	bool       bTouches;
	bool       bIntersects;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEDELLIPSEINTERSECTDLG_H__390290A8_C953_426E_AE72_8808C82E9355__INCLUDED_)
