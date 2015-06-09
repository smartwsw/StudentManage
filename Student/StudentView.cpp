
// StudentView.cpp : CStudentView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
//	ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CStudentView 构造/析构

CStudentView::CStudentView()
{
	hello = this;
	// TODO:  在此处添加构造代码

}

CStudentView::~CStudentView()
{
}

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CStudentView 绘制


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
	pDC->TextOutW(0, 0, (CString)"姓名");
	pDC->TextOutW(100, 0, (CString)"学号");
	pDC->TextOutW(200, 0, (CString)"性别");
	pDC->TextOutW(300, 0, (CString)"出生日期");
	pDC->TextOutW(400, 0, (CString)"住址");
	pDC->TextOutW(500, 0, (CString)"籍贯");
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
	// TODO:  在此处为本机数据添加绘制代码
}

void CStudentView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO:  计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CStudentView 打印

BOOL CStudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CStudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CStudentView 诊断

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CStudentDoc* CStudentView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentDoc)));
	return (CStudentDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentView 消息处理程序


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
	// TODO:  在此添加专用代码和/或调用基类
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

	// TODO:  在此添加消息处理程序代码和/或调用默认值

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
	// TODO:  在此处添加消息处理程序代码
}


void CStudentView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//
//	CScrollView::OnMButtonDblClk(nFlags, point);
//}


void CStudentView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->StuEdit();
	CScrollView::OnLButtonDblClk(nFlags, point);
}
