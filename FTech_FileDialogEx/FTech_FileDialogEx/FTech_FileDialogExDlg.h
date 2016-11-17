
// FTech_FileDialogExDlg.h : header file
//

#pragma once
#include "FileDialogEx.h"

// CFTech_FileDialogExDlg dialog
class CFTech_FileDialogExDlg : public CDialogEx
{
// Construction
public:
	CFTech_FileDialogExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTECH_FILEDIALOGEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnBnClickedBtnSetpath();
	afx_msg void OnBnClickedBtnLoad2();
};
