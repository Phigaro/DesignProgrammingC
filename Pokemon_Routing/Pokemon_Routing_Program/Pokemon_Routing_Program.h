
// Pokemon_Routing_Program.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPokemon_Routing_ProgramApp:
// �� Ŭ������ ������ ���ؼ��� Pokemon_Routing_Program.cpp�� �����Ͻʽÿ�.
//

class CPokemon_Routing_ProgramApp : public CWinApp
{
public:
	CPokemon_Routing_ProgramApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPokemon_Routing_ProgramApp theApp;