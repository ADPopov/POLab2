
// lab2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Clab2App:
// Сведения о реализации этого класса: lab2.cpp
//

class Clab2App : public CWinApp
{
public:
	Clab2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonMove();
	afx_msg void OnBnClickedButtonMoveBtn();
};

extern Clab2App theApp;
