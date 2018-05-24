
// Test1953View.cpp : CTest1953View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CTest1953View ����/����

CTest1953View::CTest1953View()
{
	// TODO:  �ڴ˴���ӹ������
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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTest1953View ����

void CTest1953View::OnDraw(CDC* pDC)
{
	CTest1953Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CShape *p;
	POSITION pos = pDoc->m_List.GetHeadPosition();

	for (int i = 0; i<pDoc->m_List.GetCount(); i++)
	{
		p = (CShape*)pDoc->m_List.GetNext(pos);
		p->Draw(pDC);
	}
}


// CTest1953View ��ӡ

BOOL CTest1953View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTest1953View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTest1953View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

//////
void CTest1953View::EraseAndRedraw(CPoint& NewPoint)
{
	CClientDC dc(this);


	
	

	CPen WhitePen(PS_SOLID, m_DrawWidth, RGB(255, 255, 255)); //���ۻ���ʱʹ��ʲô���Σ�����ʱ���ǲ���ʵ�߲���
	CPen* pOldPen = dc.SelectObject(&WhitePen);

	DrawShape(dc);  //�����ϴλ��Ƶ�ͼ��

	CPen CurrentPen(m_DrawStyle, m_DrawWidth, m_DrawColor); //����ǰ�û����õĻ�ͼ�����������»���
	dc.SelectObject(&CurrentPen);

	m_End = NewPoint;
	DrawShape(dc);  //����ǰ�û����õĻ�ͼ���������»���ͼ��

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

// CTest1953View ���

#ifdef _DEBUG
void CTest1953View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1953View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1953Doc* CTest1953View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1953Doc)));
	return (CTest1953Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest1953View ��Ϣ�������


void CTest1953View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_Start = point;
	m_End = point;

	m_MouseDown = true;
	m_OldPoint = point;
	
	CView::OnLButtonDown(nFlags, point);
}


void CTest1953View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ���������������
	m_Shape = Line;
}


void CTest1953View::OnRectangle()
{
	// TODO:  �ڴ���������������
	m_Shape = Recangle;
}


void CTest1953View::OnEllipes()
{
	// TODO:  �ڴ���������������
	m_Shape = Ellipse;
}


void CTest1953View::OnSolid()
{
	// TODO:  �ڴ���������������
	m_DrawStyle = PS_SOLID;
}


void CTest1953View::OnDash()
{
	// TODO:  �ڴ���������������
	m_DrawStyle = PS_DASH;
	
}


void CTest1953View::OnDot()
{
	// TODO:  �ڴ���������������
	m_DrawStyle = PS_DOT;
}


void CTest1953View::On1pixel()
{
	// TODO:  �ڴ���������������
	m_DrawWidth = 1;
}


void CTest1953View::On2pixel()
{
	// TODO:  �ڴ���������������
	m_DrawWidth = 2;
}


void CTest1953View::On3pixel()
{
	// TODO:  �ڴ���������������
	m_DrawWidth = 3;
}


void CTest1953View::OnBlack()
{
	// TODO:  �ڴ���������������
	m_DrawColor = RGB(0, 0, 0);
}


void CTest1953View::OnRed()
{
	// TODO:  �ڴ���������������
	m_DrawColor = RGB(255, 0, 0);
}


void CTest1953View::OnGreen()
{
	// TODO:  �ڴ���������������
	m_DrawColor = RGB(0, 255, 0);
}


void CTest1953View::OnBlue()
{
	// TODO:  �ڴ���������������
	m_DrawColor = RGB(0, 0, 255);
}


void CTest1953View::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Shape == Line ? 1 : 0);
}


void CTest1953View::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
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
	// TODO:  �ڴ���������������
}


void CTest1953View::OnUpdateCurve(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Shape == Curve ? 1 : 0);
}
