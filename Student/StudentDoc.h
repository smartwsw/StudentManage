
// StudentDoc.h : CStudentDoc ��Ľӿ�
//

#include "AddDialog.h"
#include "Student.h"
#include <iostream>
using namespace std;
#pragma once

struct Student {
	CString Name;
	CString Address;
	CString Id;
	CString Sex;
	CString BirthDate;
	CString HomeAddress;
};

class CStudentDoc : public CDocument
{
protected: // �������л�����
	CStudentDoc();
	DECLARE_DYNCREATE(CStudentDoc)

// ����
public:
	Student stu[100];
	int StuNum;
	int Current;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CStudentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void StuAdd();
	afx_msg void StuEdit();
	afx_msg void StuDel();
	afx_msg void SortAsName();
	afx_msg void SortAsId();
};

