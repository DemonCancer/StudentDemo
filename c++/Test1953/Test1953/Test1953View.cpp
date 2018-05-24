
// Test1953View.cpp : CTest1953View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test1953.h"
///////
#include "Line.h"
#include "Rectangle.h"
#include "Ellipes.h"
#include "Test1953Doc.h"
///////
#endif

#include "Test1953Doc.h"
#include "Test1953View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest1953View

IMPLEMENT_DYNCREATE(CTest1953View, CView)

BEGIN_MESSAGE_MAP(CTest1953View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Line, &CTest1953View::OnLine)
	ON_COMMAND(ID_Rectangle, &CTest1953View::OnRectangle)
	ON_COMMAND(ID_Ellipes, &CTest1953View::OnEllipes)
	ON_COMMAND(ID_Solid, &CTest1953View::OnSolid)
	ON_COMMAND(ID_Dash, &CTest1953View::OnDash)
	ON_COMMAND(ID_Dot, &CTest1953View::OnDot)
	ON_COMMAND(ID_1Pixel, &CTest1953View::On1pixel)
	ON_COMMAND(ID_2Pixel, &CTest1953View::On2pixel)
	ON_COMMAND(ID_3Pixel, &CTest1953View::On3pixel)
	ON_COMMAND(ID_Black, &CTest1953View::OnBlack)
	ON_COMMAND(ID_Red, &CTest1953View::OnRed)
	ON_COMMAND(ID_Green, &CTest1953View::OnGreen)
	ON_COMMAND(ID_Blue, &CTest1953View::OnBlue)
	ON_UPDATE_COMMAND_UI(ID_Line, &CTest1953View::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_Rectangle, &CTest1953View::OnUpdateRectangle)
	ON_UPDATE_COMMAND_UI(ID_Ellipes, &CTest1953View::OnUpdateEllipes)
	ON_UPDATE_COMMAND_UI(ID_Solid, &CTest1953View::OnUpdateSolid)
	ON_UPDATE_COMMAND_UI(ID_Dash, &CTest1953View::OnUpdateDash)
	ON_UPDATE_COMMAND_UI(ID_Dot, &CTest1953View::OnUpdateDot)
	ON_UPDATE_COMMAND_UI(ID_1Pixel, &CTest1953View::OnUpdate1pixel)
	ON_UPDATE_COMMAND_UI(ID_2Pixel, &CTest1953View::OnUpdate2pixel)
	ON_UPDATE_COMMAND_UI(ID_3Pixel, &CTest1953View::OnUpdate3pixel)
	ON_UPDATE_COMMAND_UI(ID_Black, &CTest1953View::OnUpdateBlack)
	ON_UPDATE_COMMAND_UI(ID_Red, &CTest1953View::OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_Green, &CTest1953View::OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_Blue, &CTest1953View::OnUpdateBlue)
	ON_COMMAND(ID_Curve, &CTest1953View::OnCurve)
	ON_UPDATE_COMMAND_UI(ID_Curve, &CTest1953View::OnUpdateCurve)
END_MESSAGE_MAP()

// CTest1953View 构造/析构

CTest1953View::CTest1953View()
{
	// TODO:  在此处添加构造代码
	m_MouseDown = false;
	m_Shape = Line;
	m_DrawStyle = PS_SOLID;
	m_DrawWidth = 1;
	m_DrawColor = RGB(0, 0, 0);

}

CTest1953View::~CTest1953View()
{
}

BOOL CTest1953View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTest1953View 绘制

void CTest1953View::OnDraw(CDC* pDC)
{
	CTest1953Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码

	// TODO: 在此处为本机数据添加绘制代码
	CShape *p;
	POSITION pos = pDoc->m_List.GetHeadPosition();

	for (int i = 0; i<pDoc->m_List.GetCount(); i++)
	{
		p = (CShape*)pDoc->m_List.GetNext(pos);
		p->Draw(pDC);
	}
}


// CTest1953View 打印

BOOL CTest1953View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTest1953View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CTest1953View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

//////
void CTest1953View::EraseAndRedraw(CPoint& NewPoint)
{
	CClientDC dc(this);


	
	

	CPen WhitePen(PS_SOLID, m_DrawWidth, RGB(255, 255, 255)); //不论绘制时使用什么线形，擦除时总是采用实线擦除
	CPen* pOldPen = dc.SelectObject(&WhitePen);

	DrawShape(dc);  //擦除上次绘制的图形

	CPen CurrentPen(m_DrawStyle, m_DrawWidth, m_DrawColor); //按当前用户设置的绘图参数，创建新画笔
	dc.SelectObject(&CurrentPen);

	m_End = NewPoint;
	DrawShape(dc);  //按当前用户设置的绘图参数，重新绘制图形

	dc.SelectObject(pOldPen);
}

void CTest1953View::DrawShape(CDC& dc)
{
	switch (m_Shape)
	{
	case Line:
		dc.MoveTo(m_Start);
		dc.LineTo(m_End);
		break;
	case Curve:
		dc.MoveTo(m_OldPoint);
		dc.LineTo(m_End);
		m_OldPoint = m_End;
		break;
	case Recangle:
		dc.Rectangle(CRect(m_Start, m_End));
		break;

	case Ellipse:
		dc.Ellipse(CRect(m_Start, m_End));
		break;
	}
}
///////

// CTest1953View 诊断

#ifdef _DEBUG
void CTest1953View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1953View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1953Doc* CTest1953View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1953Doc)));
	return (CTest1953Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest1953View 消息处理程序


void CTest1953View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_Start = point;
	m_End = point;

	m_MouseDown = true;
	m_OldPoint = point;
	
	CView::OnLButtonDown(nFlags, point);
}


void CTest1953View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	m_MouseDown = false;

	CShape *p;
	switch (m_Shape)
	{
	case Line:
		p = new CLine(m_DrawStyle, m_DrawWidth, m_DrawColor, m_Start, m_End);
		break;

	case Recangle:
		p = new CRectangle(m_DrawStyle, m_DrawWidth, m_DrawColor, m_Start, m_End);
		break;

	case Ellipse:
		p = new CEllipes(m_DrawStyle, m_DrawWidth, m_DrawColor, m_Start, m_End);
		break;
	}

	CTest1953Doc *pDoc = GetDocument();
	pDoc->m_List.AddTail(p);

	CView::OnLButtonUp(nFlags, point);
}


void CTest1953View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if(m_MouseDown)
	{
		EraseAndRedraw(point);
		
	}
	if (nFlags & MK_LBUTTON)
	{
		EraseAndRedraw(point);
	}
	CView::OnMouseMove(nFlags, point);
}


void CTest1953View::OnLine()
{
	// TODO:  在此添加命令处理程序代码
	m_Shape = Line;
}


void CTest1953View::OnRectangle()
{
	// TODO:  在此添加命令处理程序代码
	m_Shape = Recangle;
}


void CTest1953View::OnEllipes()
{
	// TODO:  在此添加命令处理程序代码
	m_Shape = Ellipse;
}


void CTest1953View::OnSolid()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawStyle = PS_SOLID;
}


void CTest1953View::OnDash()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawStyle = PS_DASH;
	
}


void CTest1953View::OnDot()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawStyle = PS_DOT;
}


void CTest1953View::On1pixel()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawWidth = 1;
}


void CTest1953View::On2pixel()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawWidth = 2;
}


void CTest1953View::On3pixel()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawWidth = 3;
}


void CTest1953View::OnBlack()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawColor = RGB(0, 0, 0);
}


void CTest1953View::OnRed()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawColor = RGB(255, 0, 0);
}


void CTest1953View::OnGreen()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawColor = RGB(0, 255, 0);
}


void CTest1953View::OnBlue()
{
	// TODO:  在此添加命令处理程序代码
	m_DrawColor = RGB(0, 0, 255);
}


void CTest1953View::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Shape == Line ? 1 : 0);
}


void CTest1953View::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Shape == Recangle ? 1 : 0);
}


void CTest1953View::OnUpdateEllipes(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_Shape == Ellipse ? 1 : 0);
}


void CTest1953View::OnUpdateSolid(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawStyle == PS_SOLID ? 1 : 0);
}


void CTest1953View::OnUpdateDash(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawStyle == PS_DASH ? 1 : 0);
}


void CTest1953View::OnUpdateDot(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawStyle == PS_DOT ? 1 : 0);
}


void CTest1953View::OnUpdate1pixel(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawWidth == 1 ? 1 : 0);
}


void CTest1953View::OnUpdate2pixel(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawWidth == 2 ? 1 : 0);
}


void CTest1953View::OnUpdate3pixel(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawWidth == 3 ? 1 : 0);
}


void CTest1953View::OnUpdateBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawColor == RGB(0, 0, 0) ? 1 : 0);
}


void CTest1953View::OnUpdateRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawColor == RGB(255, 0, 0) ? 1 : 0);
}


void CTest1953View::OnUpdateGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawColor == RGB(0, 255, 0) ? 1 : 0);
}


void CTest1953View::OnUpdateBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_DrawColor == RGB(0, 0, 255) ? 1 : 0);
}


void CTest1953View::OnCurve()
{
	m_Shape = Curve;
	// TODO:  在此添加命令处理程序代码
}


void CTest1953View::OnUpdateCurve(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Shape == Curve ? 1 : 0);
}
