#pragma once


// AddDialog 对话框

class AddDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AddDialog)

public:
	AddDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Sex;
	CString Name;
	CString Id;
	CString BirthDate;
	CString HomeAddress;
	CString Address;
};
