//----------------------------------------------------------
// FileDialogEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-09-05 15:00
// Modified by William Kim
//----------------------------------------------------------
#pragma once

class CFileDialogEx
{
public:
	CFileDialogEx(void);
	~CFileDialogEx(void);

	static bool GetPathOpenFileDlg(CString &strValue, CString strInitDir=_T(""));
	static bool GetPathOpenFileDlg(CStringArray &arrValue, CString strInitDir=_T(""));
	static bool GetPathSaveFileDlg(CString &strValue, CString strInitDir=_T(""));
	static bool GetPathSelectFolder(CString &strValue, CString strInitDir=_T(""));
	static void SetFileExtension(CString strExtension);
private :
	static CString m_strFileFilter;
};

