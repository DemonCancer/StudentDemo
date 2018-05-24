#pragma once
#include "Shape.h"
class CLine :
	public CShape
{
private:
	CPoint m_Start;
	CPoint m_End;

public:
	CLine(int DrawStyle, int DrawWidth, COLORREF DrawColor, CPoint Start, CPoint End);
	virtual ~CLine(void);
	virtual void Draw(CDC *pDC);
};

