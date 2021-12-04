
// MouseprojectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Mouseproject.h"
#include "MouseprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMouseprojectDlg 대화 상자



CMouseprojectDlg::CMouseprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MOUSEPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMouseprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMouseprojectDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_START, &CMouseprojectDlg::OnBnClickedButtonStart)
	ON_COMMAND(ID_MENU_GUIDE, &CMouseprojectDlg::OnMenuGuide)
	ON_COMMAND(ID_MENU_INFORMATION, &CMouseprojectDlg::OnMenuInformation)
	ON_COMMAND(ID_MENU_EXIT, &CMouseprojectDlg::OnMenuExit)
END_MESSAGE_MAP()


// CMouseprojectDlg 메시지 처리기

BOOL CMouseprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//제목 글꼴
	m_font.CreateFont(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("12롯데마트드림Bold"));
	GetDlgItem(IDC_STATIC_TITLE)->SetFont(&m_font);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMouseprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMouseprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMouseprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//게임 제목 색 변경
HBRUSH CMouseprojectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TITLE)
		pDC->SetTextColor(RGB(222, 172, 107));
	return hbr;
}


void CMouseprojectDlg::OnBnClickedButtonExit() //종료 버튼
{
	if (AfxMessageBox(_T("정말 종료하시겠습니까?"), MB_YESNO) == IDYES) {  OnOK();  }
}


void CMouseprojectDlg::OnBnClickedButtonStart() //시작 버튼
{
	Dialog.DoModal();
	if (Dialog.OK) {
		//Invalidate(TRUE);
		OnOK(); //화면 지우기가 안 되서 걍 새 창 띄우기로 했음
		GameDialog.DoModal(); //게임 실행 창
	}
}


void CMouseprojectDlg::OnMenuGuide() { //메뉴 - 게임 방법
	MessageBox(_T("[고양이가 된 쥐 - 게임 방법]\n\n[게임 규칙]\n제한시간 내에 화면에 나타나는 도형이\n사라지기 전에 마우스를 이용해 이동시키세요!\n\n1. 메인 화면에서 시작 버튼을 누릅니다.\n2. GameSetting 창에서 게임 설정을 정한 후 확인을 누르면 게임이 시작됩니다."));
}


void CMouseprojectDlg::OnMenuInformation() { //메뉴 - 프로그램 정보
	MessageBox(_T("[게임 제목]\n고양이가 된 쥐\n\n[팀 이름]\n물풍선 (MFC)\n\n[팀원]\n동의대학교 컴퓨터소프트웨어공학과\n김성민 20173142\n박상현 20183145\n최인수 20173236\n\n[프로젝트 기간]\n2021/11/10 ~ 2021/12/10"));
}


void CMouseprojectDlg::OnMenuExit() { //메뉴 - 종료
	if (AfxMessageBox(_T("정말 종료하시겠습니까?"), MB_YESNO) == IDYES) {  OnOK();  }
}
