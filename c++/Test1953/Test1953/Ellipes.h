#pragma once
#include "Shape.h"
class CEllipes :
	public CShape
{
private:
	CPoint m_Start;
	CPoint m_End;
public:
	CEllipes(int DrawStyle, int DrawWidth, COLORREF DrawColor, CPoint Start, CPoint End);
	virtual ~CEllipes(void);
	virtual void Draw(CDC *pDC);
};

