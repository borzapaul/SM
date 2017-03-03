
// Proiect_SMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Proiect_SM.h"
#include "Proiect_SMDlg.h"
#include "afxdialogex.h"

#include <Psapi.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif




//Global variables
int max_numbers_of_lines = 0;
int number_lines_col1 = 0;
int number_lines_col2 = 0;
int number_lines_col3 = 0;

// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProiect_SMDlg dialog



CProiect_SMDlg::CProiect_SMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProiect_SMDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProiect_SMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Magenta1);
}

BEGIN_MESSAGE_MAP(CProiect_SMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProiect_SMDlg::Add_Item_Col1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProiect_SMDlg::Add_Item_Col2)
	ON_BN_CLICKED(IDC_BUTTON3, &CProiect_SMDlg::Add_Item_Col3)
END_MESSAGE_MAP()


// CProiect_SMDlg message handlers

BOOL CProiect_SMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	//Inserare coloane
	int InsertColumn(
		int nCol,
		const LVCOLUMN* pColumn
		);
	int InsertColumn(
		int nCol,
		LPCTSTR lpszColumnHeading,
		int nFormat = LVCFMT_CENTER,
		int nWidth = 1000,
		int nSubItem = -1
		);

	BOOL SetColumnWidth(
		int nCol,
		int cx
		);
	//inseram 3 coloana in List Control
	if (Magenta1.InsertColumn(1, TEXT("Proprietate")) < 0)
		printf("error");
	if(Magenta1.InsertColumn(2, TEXT("Valoarea")) < 0)
		printf("error");
	if(Magenta1.InsertColumn(3, TEXT("Unitatea de masura"))<0)
		printf("error");

	//setam dimensiunea coloanei la 150 pixeli
	if(Magenta1.SetColumnWidth(0, 200) != 0)
		printf("error");
	if(Magenta1.SetColumnWidth(1, 150) != 0)
		printf("error");
	if(Magenta1.SetColumnWidth(2, 150) != 0)
		printf("error");


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProiect_SMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProiect_SMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProiect_SMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProiect_SMDlg::Add_Item_Col1()
{
	int InsertItem(
		const LVITEM* pItem
		);
	int InsertItem(
		int nItem,
		LPCTSTR lpszItem
		);
	int InsertItem(
		int nItem,
		LPCTSTR lpszItem,
		int nImage
		);
	int InsertItem(
		UINT nMask,
		int nItem,
		LPCTSTR lpszItem,
		UINT nState,
		UINT nStateMask,
		int nImage,
		LPARAM lParam
		);
	BOOL SetItemText(
		int nItem,
		int nSubItem,
		LPCTSTR lpszText
		);
	//Algroritmul pentru a seta informatia sitemuluui pe prima coloana
	
	SYSTEM_INFO SysInfo;
 //variabila pentru a convertii SysInfo care ii de tipul SYSTEM_INFO
	CString PageSize, MinimVirtualMem,MaximVirtualMem;					  //intr-o variabila de tipul LPCTSTR

	Magenta1.DeleteAllItems();

	GetSystemInfo(&SysInfo); // Copy the hardware information to the SYSTEM_INFO structure. 
 
	PageSize.Format(_T("%u"), SysInfo.dwPageSize);

	// Display the contents of the SYSTEM_INFO structure. 

	if (Magenta1.InsertItem(0, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(0, 0, TEXT("Dim pag memorie")) == 0)
		printf("error");
	if (Magenta1.SetItemText(0, 1, PageSize) == 0)
		printf("error");
	if (Magenta1.SetItemText(0, 2, TEXT("KB")) == 0)
		printf("error");
	/////////////////////////////////////////////

	MinimVirtualMem.Format(_T("%u"), SysInfo.lpMinimumApplicationAddress);

	if (Magenta1.InsertItem(1, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(1, 0, TEXT("Adrs. minima de mem virt")) == 0)
		printf("error");
	if (Magenta1.SetItemText(1, 1, MinimVirtualMem) == 0)
		printf("error");
	if (Magenta1.SetItemText(1, 2, 0) == 0)
		printf("error");

	MaximVirtualMem.Format(_T("%u"), SysInfo.lpMaximumApplicationAddress);

	if (Magenta1.InsertItem(2, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(2, 0, TEXT("Adrs. maxima de mem virt")) == 0)
		printf("error");
	if (Magenta1.SetItemText(2, 1, MaximVirtualMem) == 0)
		printf("error");
	if (Magenta1.SetItemText(2, 2, 0) == 0)
		printf("error");


	MEMORYSTATUSEX totalMemPhysichal;
	CString totalAvlMem, memSOInfo, totalVirtual, availableVirt, memoryload;

	GlobalMemoryStatusEx(&totalMemPhysichal);

	totalAvlMem.Format(_T("%u"), totalMemPhysichal.ullAvailPhys);

	if (Magenta1.InsertItem(3, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(3, 0, TEXT("Total avl. mem")) == 0)
		printf("error");
	if (Magenta1.SetItemText(3, 1, totalAvlMem) == 0)
		printf("error");
	if (Magenta1.SetItemText(3, 2, TEXT("KB")) == 0)
		printf("error");

	_PERFORMANCE_INFORMATION memSO;

	GetPerformanceInfo(&memSO, sizeof(memSO));

	memSOInfo.Format(_T("%u"), memSO.KernelTotal);
	if (Magenta1.InsertItem(4, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(4, 0, TEXT("Total SO mem")) == 0)
		printf("error");
	if (Magenta1.SetItemText(4, 1, memSOInfo) == 0)
		printf("error");
	if (Magenta1.SetItemText(4, 2, TEXT("KB")) == 0)
		printf("error");



	totalVirtual.Format(_T("%u"), totalMemPhysichal.ullTotalVirtual);

	if (Magenta1.InsertItem(5, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(5, 0, TEXT("Total virtual mem")) == 0)
		printf("error");
	if (Magenta1.SetItemText(5, 1, totalVirtual) == 0)
		printf("error");
	if (Magenta1.SetItemText(5, 2, TEXT("KB")) == 0)
		printf("error");

	availableVirt.Format(_T("%u"), totalMemPhysichal.ullAvailVirtual);
	if (Magenta1.InsertItem(6, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(6, 0, TEXT("Available virtual mem")) == 0)
		printf("error");
	if (Magenta1.SetItemText(6, 1, availableVirt) == 0)
		printf("error");
	if (Magenta1.SetItemText(6, 2, TEXT("KB")) == 0)
		printf("error");

	memoryload.Format(_T("%d"), totalMemPhysichal.dwMemoryLoad);
	if (Magenta1.InsertItem(7, 0) < 0)
		printf("error");

	if (Magenta1.SetItemText(7, 0, TEXT("Memory load")) == 0)
		printf("error");
	if (Magenta1.SetItemText(7, 1, memoryload) == 0)
		printf("error");
	if (Magenta1.SetItemText(7, 2, 0) == 0)
		printf("error");


	/*if (number_lines_col1 < max_numbers_of_lines)  //daca in coloana nu avem mai multe linii de cat numarul maxim de linii  
	{                                              //at scriem doar textul in indexul cu valoarea stocata in number_lines_col1
		if (Magenta1.SetItemText(number_lines_col1, 0, t) == 0)
			printf("error");
		number_lines_col1++;
	}
	else{											//altfel inseram o linie si scriem textul dar si crestem numarul maxim de linii
		if (Magenta1.InsertItem(number_lines_col1, 0) < 0)
			printf("error");
		if (Magenta1.SetItemText(number_lines_col1, 0, t) == 0)
			printf("error");
		number_lines_col1++;
		max_numbers_of_lines++;
	}*/


}

void CProiect_SMDlg::Add_Item_Col2()
{
	int InsertItem(
		const LVITEM* pItem
		);
	int InsertItem(
		int nItem,
		LPCTSTR lpszItem
		);
	int InsertItem(
		int nItem,
		LPCTSTR lpszItem,
		int nImage
		);
	int InsertItem(
		UINT nMask,
		int nItem,
		LPCTSTR lpszItem,
		UINT nState,
		UINT nStateMask,
		int nImage,
		LPARAM lParam
		);

	BOOL SetItemText(
		int nItem,
		int nSubItem,
		LPCTSTR lpszText
		);



	if (number_lines_col2 < max_numbers_of_lines)    
	{
		if (Magenta1.SetItemText(number_lines_col2, 1, TEXT("ELEMENT 2")) == 0)
			printf("error");
		number_lines_col2++;
	}
	else{
		if (Magenta1.InsertItem(number_lines_col2, 0) < 0)
			printf("error");
		if (Magenta1.SetItemText(number_lines_col2, 1, TEXT("ELEMENT 2")) == 0)
			printf("error");
		number_lines_col2++;
		max_numbers_of_lines++;
	}
}


void CProiect_SMDlg::Add_Item_Col3()
{
	int InsertItem(
		const LVITEM* pItem
		);
	int InsertItem(
		int nItem,
		LPCTSTR lpszItem
		);
	int InsertItem(
		int nItem,
		LPCTSTR lpszItem,
		int nImage
		);
	int InsertItem(
		UINT nMask,
		int nItem,
		LPCTSTR lpszItem,
		UINT nState,
		UINT nStateMask,
		int nImage,
		LPARAM lParam
		);

	BOOL SetItemText(
		int nItem,
		int nSubItem,
		LPCTSTR lpszText
		);


	if (number_lines_col3 < max_numbers_of_lines)
	{
		if (Magenta1.SetItemText(number_lines_col3, 2, TEXT("ELEMENT 3")) == 0)
			printf("error");
		number_lines_col3++;
	}
	else{
		if (Magenta1.InsertItem(number_lines_col3, 0) < 0)
			printf("error");
		if (Magenta1.SetItemText(number_lines_col3, 2, TEXT("ELEMENT 3")) == 0)
			printf("error");
		number_lines_col3++;
		max_numbers_of_lines++;
	}
}
