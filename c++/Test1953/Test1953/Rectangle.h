#pragma once
#include "Shape.h"
class CRectangle :
	public CShape
{
private:
	CPoint m_Start;
	CPoint m_End;
public:
	CRectangle(int DrawStyle, int DrawWidth, COLORREF DrawColor, CPoint Start, CPoint End);
	virtual ~CRectangle(void);
	virtual void Draw(CDC *pDC);
};

