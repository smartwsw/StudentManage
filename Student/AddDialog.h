#pragma once


// AddDialog �Ի���

class AddDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AddDialog)

public:
	AddDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString Sex;
	CString Name;
	CString Id;
	CString BirthDate;
	CString HomeAddress;
	CString Address;
};
