
// StudentDoc.h : CStudentDoc 类的接口
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
protected: // 仅从序列化创建
	CStudentDoc();
	DECLARE_DYNCREATE(CStudentDoc)

// 特性
public:
	Student stu[100];
	int StuNum;
	int Current;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CStudentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void StuAdd();
	afx_msg void StuEdit();
	afx_msg void StuDel();
	afx_msg void SortAsName();
	afx_msg void SortAsId();
};

