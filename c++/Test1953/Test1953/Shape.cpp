#include "stdafx.h"
#include "Shape.h"


CShape::CShape(int DrawStyle, int DrawWidth, COLORREF DrawColor)
{
	m_DrawStyle = DrawStyle;
	m_DrawWidth = DrawWidth;
	m_DrawColor = DrawColor;
}

CShape::~CShape(void)
{
}
