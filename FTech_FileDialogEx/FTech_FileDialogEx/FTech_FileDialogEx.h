
// FTech_FileDialogEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTech_FileDialogExApp:
// See FTech_FileDialogEx.cpp for the implementation of this class
//

class CFTech_FileDialogExApp : public CWinApp
{
public:
	CFTech_FileDialogExApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFTech_FileDialogExApp theApp;