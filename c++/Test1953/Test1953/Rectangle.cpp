#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(int DrawStyle, int DrawWidth, COLORREF DrawColor, CPoint Start, CPoint End)
:CShape(DrawStyle, DrawWidth, DrawColor)
{
	m_Start = Start;
	m_End = End;
}

CRectangle::~CRectangle(void)
{
}

void CRectangle::Draw(CDC *pDC)
{
	CPen CurrentPen(m_DrawStyle, m_DrawWidth, m_DrawColor); //按当前用户设置的绘图参数，创建新画笔
	CPen* pOldPen = pDC->SelectObject(&CurrentPen);

	pDC->Rectangle(CRect(m_Start, m_End));
	pDC->SelectObject(pOldPen);
}
