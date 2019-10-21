
// PenSDIView.h: CPenSDIView 클래스의 인터페이스
//

#pragma once


class CPenSDIView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPenSDIView() noexcept;
	DECLARE_DYNCREATE(CPenSDIView)

// 특성입니다.
public:
	CPenSDIDoc* GetDocument() const;

// 작업입니다.
public:
	CPoint pnt;
	COLORREF col;
	int size = 1;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPenSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize1();
	afx_msg void OnSize8();
	afx_msg void OnSize16();
	afx_msg void OnPenColor();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

#ifndef _DEBUG  // PenSDIView.cpp의 디버그 버전
inline CPenSDIDoc* CPenSDIView::GetDocument() const
   { return reinterpret_cast<CPenSDIDoc*>(m_pDocument); }
#endif

