
// StudentDoc.cpp : CStudentDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Student.h"
#endif

#include "StudentDoc.h"
#include "StudentView.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CStudentDoc
extern CStudentView *hello;
IMPLEMENT_DYNCREATE(CStudentDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentDoc, CDocument)
	ON_COMMAND(ID_32771, &CStudentDoc::StuAdd)
	ON_COMMAND(ID_32772, &CStudentDoc::StuEdit)
	ON_COMMAND(ID_32773, &CStudentDoc::StuDel)
	ON_COMMAND(ID_32775, &CStudentDoc::SortAsName)
	ON_COMMAND(ID_32776, &CStudentDoc::SortAsId)
END_MESSAGE_MAP()


// CStudentDoc ����/����

CStudentDoc::CStudentDoc()
{
	StuNum = 0;
	Current = 0;
	// TODO:  �ڴ����һ���Թ������

}

CStudentDoc::~CStudentDoc()
{
}

BOOL CStudentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CStudentDoc ���л�

void CStudentDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int i;
		for (i = 0; i < StuNum; i++) {
			ar.WriteString(stu[i].Name);
			ar.WriteString(_T("\n"));
			ar.WriteString(stu[i].Id);
			ar.WriteString(_T("\n"));
			ar.WriteString(stu[i].Sex);
			ar.WriteString(_T("\n"));
			ar.WriteString(stu[i].BirthDate);
			ar.WriteString(_T("\n"));
			ar.WriteString(stu[i].Address);
			ar.WriteString(_T("\n"));
			ar.WriteString(stu[i].HomeAddress);
			ar.WriteString(_T("\n"));
		}
	}
	else
	{
		CString Name, Id, Sex, BirthDate, Address, HomeAddress;
		while (1){
			if (!ar.ReadString(Name))
				break;
			if (!ar.ReadString(Id))
				break;
			if (!ar.ReadString(Sex))
				break;
			if (!ar.ReadString(BirthDate))
				break;
			if (!ar.ReadString(Address))
				break;
			if (!ar.ReadString(HomeAddress))
				break;
			stu[StuNum].Name = Name;
			stu[StuNum].Id = Id;
			stu[StuNum].Sex = Sex;
			stu[StuNum].BirthDate = BirthDate;
			stu[StuNum].Address = Address;
			stu[StuNum].HomeAddress = HomeAddress;
			StuNum++;
			if (hello != NULL)
				hello->Invalidate();
			SetModifiedFlag();
		}
	
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CStudentDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CStudentDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CStudentDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStudentDoc ���

#ifdef _DEBUG
void CStudentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudentDoc ����


void CStudentDoc::StuAdd()
{
	AddDialog dlg;
	if (dlg.DoModal() == IDOK) {
		stu[StuNum].Name = dlg.Name;
		stu[StuNum].Id = dlg.Id;
		stu[StuNum].Sex = dlg.Sex;
		stu[StuNum].Address = dlg.Address;
		stu[StuNum].HomeAddress = dlg.HomeAddress;
		stu[StuNum].BirthDate = dlg.BirthDate;
		StuNum++;
		if (hello != NULL)
			hello->Invalidate();
		SetModifiedFlag();
	}
	// TODO:  �ڴ���������������
}


void CStudentDoc::StuEdit()
{
	AddDialog dlg;
	dlg.Name = stu[Current].Name;
	dlg.Address = stu[Current].Address;
	dlg.Sex = stu[Current].Sex;
	dlg.Id = stu[Current].Id;
	dlg.HomeAddress = stu[Current].HomeAddress;
	dlg.BirthDate = stu[Current].BirthDate;
	if (dlg.DoModal() == IDOK) {
		stu[Current].Name = dlg.Name;
		stu[Current].Id = dlg.Id;
		stu[Current].Sex = dlg.Sex;
		stu[Current].Address = dlg.Address;
		stu[Current].HomeAddress = dlg.HomeAddress;
		stu[Current].BirthDate = dlg.BirthDate;
		if (hello != NULL)
			hello->Invalidate();
		SetModifiedFlag();
	}
	// TODO:  �ڴ���������������
}


void CStudentDoc::StuDel()
{
	if (StuNum <= 0)
		return;
	int i;
	for (i = Current; i < StuNum - 1; i++) {
		stu[i] = stu[i + 1];
	}
	StuNum--;
	if (hello != NULL)
		hello->Invalidate();
	SetModifiedFlag();
	// TODO:  �ڴ���������������
}

int cmpStudentAsName(const void *x, const void *y)
{
	Student *pNodex = (Student*)x, *pNodey = (Student*)y;
	return lstrcmp(pNodex->Name,pNodey->Name);
}

int cmpStudentAsId(const void *x, const void *y)
{
	Student *pNodex = (Student*)x, *pNodey = (Student*)y;
	return (pNodex->Id > pNodey->Id);
}

void CStudentDoc::SortAsName()
{
	qsort(stu, StuNum, sizeof(stu[0]), cmpStudentAsName);
	if (hello != NULL)
		hello->Invalidate();
	SetModifiedFlag();
	// TODO:  �ڴ���������������
}


void CStudentDoc::SortAsId()
{
	qsort(stu, StuNum, sizeof(stu[0]), cmpStudentAsId);
	if (hello != NULL)
		hello->Invalidate();
	SetModifiedFlag();
	// TODO:  �ڴ���������������
}
