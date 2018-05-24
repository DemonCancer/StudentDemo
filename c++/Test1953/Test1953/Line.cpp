#include "stdafx.h"
#include "Line.h"


CLine::CLine(int DrawStyle, int DrawWidth, COLORREF DrawColor, CPoint Start, CPoint End)
:CShape(DrawStyle, DrawWidth, DrawColor)
{
	m_Start = Start;
	m_End = End;
}

CLine::~CLine(void)
{
}

void CLine::Draw(CDC *pDC)
{
	CPen CurrentPen(m_DrawStyle, m_DrawWidth, m_DrawColor); //����ǰ�û����õĻ�ͼ�����������»���
	CPen* pOldPen = pDC->SelectObject(&CurrentPen);

	pDC->MoveTo(m_Start);
	pDC->LineTo(m_End);

	pDC->SelectObject(pOldPen);
}
