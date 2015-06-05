// AddDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Student.h"
#include "AddDialog.h"
#include "afxdialogex.h"


// AddDialog 对话框

IMPLEMENT_DYNAMIC(AddDialog, CDialogEx)

AddDialog::AddDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddDialog::IDD, pParent)
	, Sex(_T(""))
	, Name(_T(""))
	, Id(_T(""))
	, BirthDate(_T(""))
	, HomeAddress(_T(""))
	, Address(_T(""))
{

}

AddDialog::~AddDialog()
{
}

void AddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, Sex);
	DDX_Text(pDX, IDC_EDIT1, Name);
	DDX_Text(pDX, IDC_EDIT2, Id);
	DDX_Text(pDX, IDC_EDIT3, BirthDate);
	DDX_Text(pDX, IDC_EDIT4, HomeAddress);
	DDX_Text(pDX, IDC_EDIT5, Address);
}


BEGIN_MESSAGE_MAP(AddDialog, CDialogEx)
END_MESSAGE_MAP()


// AddDialog 消息处理程序
