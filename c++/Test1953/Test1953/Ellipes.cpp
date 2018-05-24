#include "stdafx.h"
#include "Ellipes.h"


CEllipes::CEllipes(int DrawStyle, int DrawWidth, COLORREF DrawColor, CPoint Start, CPoint End)
:CShape(DrawStyle, DrawWidth, DrawColor)
{
	m_Start = Start;
	m_End = End;
}

CEllipes::~CEllipes(void)
{
}

void CEllipes::Draw(CDC *pDC)
{
	CPen CurrentPen(m_DrawStyle, m_DrawWidth, m_DrawColor); //����ǰ�û����õĻ�ͼ�����������»���
	CPen* pOldPen = pDC->SelectObject(&CurrentPen);

	pDC->Ellipse(CRect(m_Start, m_End));
	pDC->SelectObject(pOldPen);
}
