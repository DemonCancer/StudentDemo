
// Test1953.h : Test1953 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTest1953App:
// �йش����ʵ�֣������ Test1953.cpp
//

class CTest1953App : public CWinAppEx
{
public:
	CTest1953App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTest1953App theApp;
