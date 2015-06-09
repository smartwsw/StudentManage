
// StudentView.cpp : CStudentView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Student.h"
#endif

#include "StudentDoc.h"
#include "StudentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CStudentView *hello = NULL;
// CStudentView

IMPLEMENT_DYNCREATE(CStudentView, CScrollView)

BEGIN_MESSAGE_MAP(CStudentView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
//	ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CStudentView ����/����

CStudentView::CStudentView()
{
	hello = this;
	// TODO:  �ڴ˴���ӹ������

}

CStudentView::~CStudentView()
{
}

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CStudentView ����


void CStudentView::OnDraw(CDC* pDC)
{
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CSize sizeTotal, sizePage;
	sizeTotal.cx = 100;
	sizeTotal.cy = pDoc->StuNum * 20 + 20;
	RECT rect;
	GetClientRect(&rect);
	sizePage.cx = rect.right - rect.left - 8;
	sizePage.cy = rect.bottom - rect.top - 40;
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, CSize(8, 20));
	hello = this;
	pDC->TextOutW(0, 0, (CString)"����");
	pDC->TextOutW(100, 0, (CString)"ѧ��");
	pDC->TextOutW(200, 0, (CString)"�Ա�");
	pDC->TextOutW(300, 0, (CString)"��������");
	pDC->TextOutW(400, 0, (CString)"סַ");
	pDC->TextOutW(500, 0, (CString)"����");
	int i;
	for (i = 0; i < pDoc->StuNum; i++) {
		if (i == pDoc->Current) {
			COLORREF old_text_color = pDC->SetTextColor(RGB(255, 255, 255));
			COLORREF old_bk_color = pDC->SetBkColor(RGB(0, 0, 0));
		}
		pDC->TextOutW(0, (i + 1) * 20, pDoc->stu[i].Name);
		pDC->TextOutW(100, (i + 1) * 20, pDoc->stu[i].Id);
		pDC->TextOutW(200, (i + 1) * 20, pDoc->stu[i].Sex);
		pDC->TextOutW(300, (i + 1) * 20, pDoc->stu[i].BirthDate);
		pDC->TextOutW(400, (i + 1) * 20, pDoc->stu[i].Address);
		pDC->TextOutW(500, (i + 1) * 20, pDoc->stu[i].HomeAddress);
		COLORREF old_text_color = pDC->SetTextColor(RGB(0, 0, 0));
		COLORREF old_bk_color = pDC->SetBkColor(RGB(255, 255, 255));
	}
	if (!pDoc)
		return;
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CStudentView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO:  �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CStudentView ��ӡ

BOOL CStudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CStudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CStudentView ���

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CStudentDoc* CStudentView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentDoc)));
	return (CStudentDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentView ��Ϣ�������


void CStudentView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	CStudentDoc* pDoc = GetDocument();

	// TODO: calculate the total size of this view
	CSize sizeTotal, sizePage;
	sizeTotal.cx = 100;
	sizeTotal.cy = pDoc->StuNum * 20;
	RECT rect;
	GetClientRect(&rect);
	sizePage.cx = rect.right - rect.left - 8;
	sizePage.cy = rect.bottom - rect.top - 20;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, CSize(8, 20));

	Invalidate();
	// TODO:  �ڴ����ר�ô����/����û���
}


void CStudentView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CView::OnLButtonDown(nFlags, point);
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (point.y / 20 < pDoc->StuNum + 1 && point.y > 20) {
		pDoc->Current = (point.y / 20) - 1;
	}
	Invalidate();

	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CScrollView::OnLButtonDown(nFlags, point);
}


void CStudentView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);
	CStudentDoc* pDoc = GetDocument();

	// TODO: calculate the total size of this view
	CSize sizeTotal, sizePage;
	sizeTotal.cx = 100;
	sizeTotal.cy = (pDoc->StuNum + 1) * 20;
	sizePage.cx = cx ;
	sizePage.cy = cy ;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, CSize(8, 20));

	Invalidate();
	// TODO:  �ڴ˴������Ϣ����������
}


void CStudentView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	switch (nChar) {
	case VK_UP:
		if (pDoc->Current > 0)
			pDoc->Current--;
		break;
	case VK_DOWN:
		if (pDoc->Current < pDoc->StuNum-1)
			pDoc->Current++;
		break;
	default:
		break;
	}
	Invalidate();
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}




//void CStudentView::OnMButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CScrollView::OnMButtonDblClk(nFlags, point);
//}


void CStudentView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->StuEdit();
	CScrollView::OnLButtonDblClk(nFlags, point);
}
