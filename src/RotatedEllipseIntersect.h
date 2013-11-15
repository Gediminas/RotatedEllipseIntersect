// RotatedEllipseIntersect.h : main header file for the ROTATEDELLIPSEINTERSECT application
//

#if !defined(AFX_ROTATEDELLIPSEINTERSECT_H__A5A84D2D_53E4_471F_B489_B592E9C9AF59__INCLUDED_)
#define AFX_ROTATEDELLIPSEINTERSECT_H__A5A84D2D_53E4_471F_B489_B592E9C9AF59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRotatedEllipseIntersectApp:
// See RotatedEllipseIntersect.cpp for the implementation of this class
//

class CRotatedEllipseIntersectApp : public CWinApp
{
public:
	CRotatedEllipseIntersectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotatedEllipseIntersectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRotatedEllipseIntersectApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEDELLIPSEINTERSECT_H__A5A84D2D_53E4_471F_B489_B592E9C9AF59__INCLUDED_)
