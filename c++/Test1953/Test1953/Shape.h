#pragma once
class CShape
{
//public:
//	CShape();
//	~CShape();
protected:					//便于子类直接访问，不要设置为private
	int m_DrawStyle;          	//记录线型
	int m_DrawWidth;        	//记录线宽
	COLORREF m_DrawColor;    	//记录线颜色
public:
	CShape(int DrawStyle, int DrawWidth, COLORREF DrawColor);
	virtual ~CShape(void);		//注意：要声明为虚析构函数
	virtual void Draw(CDC *pDC) = 0;
};

