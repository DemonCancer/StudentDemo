#pragma once
class CShape
{
//public:
//	CShape();
//	~CShape();
protected:					//��������ֱ�ӷ��ʣ���Ҫ����Ϊprivate
	int m_DrawStyle;          	//��¼����
	int m_DrawWidth;        	//��¼�߿�
	COLORREF m_DrawColor;    	//��¼����ɫ
public:
	CShape(int DrawStyle, int DrawWidth, COLORREF DrawColor);
	virtual ~CShape(void);		//ע�⣺Ҫ����Ϊ����������
	virtual void Draw(CDC *pDC) = 0;
};

