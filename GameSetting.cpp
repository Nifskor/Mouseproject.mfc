// GameSetting.cpp: 구현 파일
//

#include "pch.h"
#include "Mouseproject.h"
#include "GameSetting.h"
#include "afxdialogex.h"


// GameSetting 대화 상자

IMPLEMENT_DYNAMIC(GameSetting, CDialog)

GameSetting::GameSetting(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_level(0)
	, m_color(0)
{
}

GameSetting::~GameSetting()
{
}

void GameSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_EASY, m_level);
	DDX_Radio(pDX, IDC_RADIO_RED, m_color);
}


BEGIN_MESSAGE_MAP(GameSetting, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &GameSetting::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &GameSetting::OnBnClickedButton1)
END_MESSAGE_MAP()

void GameSetting::OnBnClickedButton1() //확인 버튼
{
	UpdateData(true);
	switch(m_level){ //난이도 그룹
		case 0: //쉬움 선택 시
			easy = true;
			break;
		case 1: //보통 선택 시
			mid = true;
			break;
		case 2: //어려움 선택시
			hard = true;
			break;
	}
	switch (m_color) { //색깔 그룹
	case 0: //빨강 선택 시
		red = true;
		break;
	case 1: //초록 선택 시
		green = true;
		break;
	case 2: //노랑 선택시
		yellow = true;
		break;
	}
		OK = true;
		OnOK(); //창 닫기
}

void GameSetting::OnBnClickedButton2() //취소 버튼
{
	OK = false;
	OnOK();
}

