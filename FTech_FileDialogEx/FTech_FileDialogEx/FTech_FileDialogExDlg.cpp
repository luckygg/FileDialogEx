
// FTech_FileDialogExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_FileDialogEx.h"
#include "FTech_FileDialogExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_FileDialogExDlg dialog




CFTech_FileDialogExDlg::CFTech_FileDialogExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_FileDialogExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTech_FileDialogExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFTech_FileDialogExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SAVE, &CFTech_FileDialogExDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CFTech_FileDialogExDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_SETPATH, &CFTech_FileDialogExDlg::OnBnClickedBtnSetpath)
	ON_BN_CLICKED(IDC_BTN_LOAD2, &CFTech_FileDialogExDlg::OnBnClickedBtnLoad2)
END_MESSAGE_MAP()


// CFTech_FileDialogExDlg message handlers

BOOL CFTech_FileDialogExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_FileDialogExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTech_FileDialogExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFTech_FileDialogExDlg::OnBnClickedBtnSave()
{
	CString path=_T("");
	CFileDialogEx::SetFileExtension(_T("bmp"));
	CFileDialogEx::GetPathSaveFileDlg(path);
}

void CFTech_FileDialogExDlg::OnBnClickedBtnLoad()
{
	CString path=_T("");
	CFileDialogEx::GetPathOpenFileDlg(path);
}


void CFTech_FileDialogExDlg::OnBnClickedBtnSetpath()
{
	CString path=_T("");
	CFileDialogEx::GetPathSelectFolder(path);
}


void CFTech_FileDialogExDlg::OnBnClickedBtnLoad2()
{
	CStringArray arrPath;
	CFileDialogEx::GetPathOpenFileDlg(arrPath);

	int cnt=0;
	cnt = arrPath.GetCount();
	
	for (int i=0; i<cnt; i++)
	{
		OutputDebugString(arrPath.GetAt(i) + _T("\n"));
	}
}
