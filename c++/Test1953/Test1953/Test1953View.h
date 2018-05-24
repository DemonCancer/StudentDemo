
// Test1953View.h : CTest1953View ��Ľӿ�
//

#pragma once


class CTest1953View : public CView
{
protected: // �������л�����
	CTest1953View();
	DECLARE_DYNCREATE(CTest1953View)

// ����
public:
	CTest1953Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTest1953View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
private:
	enum Shape { Line, Curve, Recangle, Ellipse } m_Shape; //����ö�٣����ڼ�¼ͼ�����͡�

	bool m_MouseDown;
	CPoint m_OldPoint;

	int m_DrawStyle;                            //��¼����
	int m_DrawWidth;                            //��¼�߿�
	COLORREF m_DrawColor;                       //��¼����ɫ

	CPoint m_Start;                             //��¼ͼ���������
	CPoint m_End;                               //��¼ͼ���յ�����

	void EraseAndRedraw(CPoint& NewPoint);      //�������ػ���ǰͼ��
	void DrawShape(CDC& dc);                    //���ƻ����һ��ͼ�Σ��ɡ�EraseAndRedraw�������ڲ�����

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipes();
	afx_msg void OnSolid();
	afx_msg void OnDash();
	afx_msg void OnDot();
	afx_msg void On1pixel();
	afx_msg void On2pixel();
	afx_msg void On3pixel();
	afx_msg void OnBlack();
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEllipes(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDash(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDot(CCmdUI *pCmdUI);
	afx_msg void OnUpdate1pixel(CCmdUI *pCmdUI);
	afx_msg void OnUpdate2pixel(CCmdUI *pCmdUI);
	afx_msg void OnUpdate3pixel(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBlue(CCmdUI *pCmdUI);
	afx_msg void OnCurve();
	afx_msg void OnUpdateCurve(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // Test1953View.cpp �еĵ��԰汾
inline CTest1953Doc* CTest1953View::GetDocument() const
   { return reinterpret_cast<CTest1953Doc*>(m_pDocument); }
#endif

