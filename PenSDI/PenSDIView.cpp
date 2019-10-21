
// PenSDIView.cpp: CPenSDIView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "PenSDI.h"
#endif

#include "PenSDIDoc.h"
#include "PenSDIView.h"
#include "CLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenSDIView

IMPLEMENT_DYNCREATE(CPenSDIView, CView)

BEGIN_MESSAGE_MAP(CPenSDIView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SIZE_1, &CPenSDIView::OnSize1)
	ON_COMMAND(ID_SIZE_8, &CPenSDIView::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CPenSDIView::OnSize16)
	ON_COMMAND(ID_PEN_COLOR, &CPenSDIView::OnPenColor)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// CPenSDIView 생성/소멸

CPenSDIView::CPenSDIView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenSDIView::~CPenSDIView()
{
}

BOOL CPenSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPenSDIView 그리기

void CPenSDIView::OnDraw(CDC* pDC)
{
	CPenSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int n = GetDocument()->m_oa.GetSize();
	for (int i = 0; i < n; i++) {
		CLine* p;
		p = (CLine*)pDoc->m_oa[i];
		p->draw(pDC);
	}
}


// CPenSDIView 인쇄

BOOL CPenSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenSDIView 진단

#ifdef _DEBUG
void CPenSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CPenSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenSDIDoc* CPenSDIView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenSDIDoc)));
	return (CPenSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenSDIView 메시지 처리기

void CPenSDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) {
		CClientDC dc(this);
		CPen pen(PS_SOLID, size, col);
		dc.SelectObject(&pen);
		dc.MoveTo(pnt);
		dc.LineTo(point);
	}
	pnt = point;
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
}


void CPenSDIView::OnSize1()
{
	size = 1;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenSDIView::OnSize8()
{
	size = 8;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenSDIView::OnSize16()
{
	size = 16;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenSDIView::OnPenColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		col = dlg.GetColor();
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CPenSDIView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu m;
	m.LoadMenu(IDR_MENU1);
	CMenu* p = m.GetSubMenu(0);
	p->TrackPopupMenu(NULL, point.x, point.y, this, NULL);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
