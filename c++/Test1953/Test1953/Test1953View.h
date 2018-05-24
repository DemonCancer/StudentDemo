
// Test1953View.h : CTest1953View 类的接口
//

#pragma once


class CTest1953View : public CView
{
protected: // 仅从序列化创建
	CTest1953View();
	DECLARE_DYNCREATE(CTest1953View)

// 特性
public:
	CTest1953Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTest1953View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
private:
	enum Shape { Line, Curve, Recangle, Ellipse } m_Shape; //类内枚举，用于记录图形类型、

	bool m_MouseDown;
	CPoint m_OldPoint;

	int m_DrawStyle;                            //记录线型
	int m_DrawWidth;                            //记录线宽
	COLORREF m_DrawColor;                       //记录线颜色

	CPoint m_Start;                             //记录图形起点坐标
	CPoint m_End;                               //记录图形终点坐标

	void EraseAndRedraw(CPoint& NewPoint);      //擦除并重画当前图形
	void DrawShape(CDC& dc);                    //绘制或擦除一个图形，由“EraseAndRedraw（）”内部调用

// 生成的消息映射函数
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

#ifndef _DEBUG  // Test1953View.cpp 中的调试版本
inline CTest1953Doc* CTest1953View::GetDocument() const
   { return reinterpret_cast<CTest1953Doc*>(m_pDocument); }
#endif

