
// lab2Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно Clab2Dlg
class Clab2Dlg : public CDialogEx
{
// Создание
public:
	Clab2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton left_btn;
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	CButton right_btn;
	CButton btn_move;
	CString first_editCtrl;
	CString second_editCtrl;
	afx_msg void OnBnClickedButtonMove();
	CButton btn_remove;
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl slideCtrl;
	INT EditCtrl_SlideValue;
	CButton btn_moveButton;
	CButton btn_random;
	afx_msg void OnBnClickedButtonMoveBtn();
};
