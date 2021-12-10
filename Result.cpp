// Result.cpp: 구현 파일
//

#include "pch.h"
#include "Mouseproject.h"
#include "Result.h"
#include "afxdialogex.h"


// Result 대화 상자

IMPLEMENT_DYNAMIC(Result, CDialog)

BOOL Result::OnInitDialog() {
	CDialog::OnInitDialog();
	//게임 종료! 글꼴
	m_font.CreateFont(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("HY견고딕"));
	GetDlgItem(IDC_STATIC_END)->SetFont(&m_font);

	return TRUE;
}

Result::Result(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RESULT_DIALOG, pParent)
	, m_score(0)
	, m_level(_T(""))
	, m_ranking(_T(""))
{

}

Result::~Result()
{
}

void Result::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);
	DDX_Text(pDX, IDC_EDIT_LEVEL, m_level);
	DDX_Text(pDX, IDC_EDIT_RANKING, m_ranking);
}


BEGIN_MESSAGE_MAP(Result, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &Result::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_RESTART, &Result::OnBnClickedButtonRestart)
END_MESSAGE_MAP()


// Result 메시지 처리기


void Result::OnBnClickedButtonExit() //종료 버튼
{
	if (AfxMessageBox(_T("정말 종료하시겠습니까?"), MB_YESNO) == IDYES) { OnOK(); }
}


void Result::OnBnClickedButtonRestart() //메인 화면 버튼
{
	OnOK();
}
