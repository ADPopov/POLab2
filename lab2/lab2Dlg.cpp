
// lab2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "lab2.h"
#include "lab2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно Clab2Dlg



Clab2Dlg::Clab2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB2_DIALOG, pParent)
	, first_editCtrl(_T("Первое поле"))
	, second_editCtrl(_T(""))
	, EditCtrl_SlideValue(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, left_btn);
	DDX_Control(pDX, IDC_BUTTON2, right_btn);
	DDX_Text(pDX, IDC_EDIT1, first_editCtrl);
	DDX_Text(pDX, IDC_EDIT2, second_editCtrl);
	DDX_Control(pDX, IDC_BUTTON3, btn_move);
	DDX_Control(pDX, IDC_BUTTON4, btn_remove);
	DDX_Control(pDX, IDC_SLIDER1, slideCtrl);

	DDX_Text(pDX, IDC_EDIT3, EditCtrl_SlideValue);
	DDX_Control(pDX, IDC_BUTTON5, btn_moveButton);
	DDX_Control(pDX, IDC_BUTTON6, btn_random);
}

BEGIN_MESSAGE_MAP(Clab2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Clab2Dlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON2, &Clab2Dlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON3, &Clab2Dlg::OnBnClickedButtonMove)
	ON_BN_CLICKED(IDC_BUTTON4, &Clab2Dlg::OnBnClickedButtonRemove)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Clab2Dlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_BUTTON5, &Clab2Dlg::OnBnClickedButtonMoveBtn)
END_MESSAGE_MAP()


// Обработчики сообщений Clab2Dlg

BOOL Clab2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	right_btn.EnableWindow(0);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Clab2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Clab2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clab2Dlg::OnBnClickedButtonLeft()
{
	left_btn.EnableWindow(0);
	right_btn.EnableWindow(1);
}


void Clab2Dlg::OnBnClickedButtonRight()
{
	left_btn.EnableWindow(1);
	right_btn.EnableWindow(0);
}

void Clab2Dlg::OnBnClickedButtonMove()
{
	UpdateData(true); //метод для считывания данных из контролов окна
	CString str = first_editCtrl;

	first_editCtrl = "";
	second_editCtrl = str;
	UpdateData(0);
}


void Clab2Dlg::OnBnClickedButtonRemove()
{
	UpdateData(true); //метод для считывания данных из контролов окна
	CString str = second_editCtrl;

	second_editCtrl = "";
	first_editCtrl = str;
	UpdateData(0);
}



void Clab2Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	EditCtrl_SlideValue = slideCtrl.GetPos();
	UpdateData(0);

	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void Clab2Dlg::OnBnClickedButtonMoveBtn()
{
	btn_random.MoveWindow(rand() % 200, rand() % 200, 70, 60, 1);
}

