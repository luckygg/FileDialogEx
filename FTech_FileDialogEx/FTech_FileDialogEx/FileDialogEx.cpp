#include "StdAfx.h"
#include "FileDialogEx.h"


CString CFileDialogEx::m_strFileFilter = _T("All Files (*.*)|*.*||");
CFileDialogEx::CFileDialogEx(void)
{
}


CFileDialogEx::~CFileDialogEx(void)
{
}


bool CFileDialogEx::GetPathOpenFileDlg(CString &strValue, CString strInitDir)
{
	CString	strFilter = _T("All Files (*.*)|*.*||");

	CFileDialog FileDlg(TRUE, NULL, NULL, 0, m_strFileFilter);

	if (strInitDir.IsEmpty() == false)
		FileDlg.m_ofn.lpstrInitialDir = strInitDir;

	if( FileDlg.DoModal() != IDOK ) return false;

	strValue = FileDlg.GetPathName();

	return true;
}

bool CFileDialogEx::GetPathOpenFileDlg(CStringArray &arrValue, CString strInitDir)
{
	CString	strFilter = _T("All Files (*.*)|*.*||");
	CString strFileList;

	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, m_strFileFilter);

	const int c_cMaxFiles = 400;
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1;
	FileDlg.GetOFN().lpstrFile = strFileList.GetBuffer(c_cbBuffSize);
	FileDlg.GetOFN().nMaxFile = c_cbBuffSize;

	if (strInitDir.IsEmpty() == false)
		FileDlg.m_ofn.lpstrInitialDir = strInitDir;

	if( FileDlg.DoModal() != IDOK) return false;
	
	arrValue.RemoveAll();

	for(POSITION pos=FileDlg.GetStartPosition(); pos != NULL;)
	{
		CString File = FileDlg.GetNextPathName(pos);
		arrValue.Add(File);
	}

	return true;
}

bool CFileDialogEx::GetPathSaveFileDlg(CString &strValue, CString strInitDir)
{
	CString	strFilter = _T("All Files (*.*)|*.*||");

	CFileDialog FileDlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, m_strFileFilter);

	if (strInitDir.IsEmpty() == false)
		FileDlg.m_ofn.lpstrInitialDir = strInitDir;

	if( FileDlg.DoModal() != IDOK ) return false;
	
	strValue = FileDlg.GetPathName();

	return true;
}

bool CFileDialogEx::GetPathSelectFolder(CString &strValue, CString strInitDir)
{
	CFolderPickerDialog PickerDlg(NULL,OFN_FILEMUSTEXIST);

	if (strInitDir.IsEmpty() == false)
		PickerDlg.m_ofn.lpstrInitialDir = strInitDir;

	if(PickerDlg.DoModal() != IDOK) return false;
	
	strValue = PickerDlg.GetFolderPath();

	return true;
}

void CFileDialogEx::SetFileExtension(CString strExtension)
{
	m_strFileFilter.Format(_T("%s Files (*.%s)|*.%s||"),strExtension,strExtension,strExtension);
}