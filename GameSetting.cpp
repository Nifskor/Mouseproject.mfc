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

//보고서 (Radio Button) ~ 80줄
void GameSetting::OnBnClickedButton1() //확인 버튼
{
	UpdateData(true);
	OK = true;
	switch (m_level) { //난이도 그룹
	case 0: //쉬움 선택 시
		GameDialog.easy = true;
		GameDialog.mid = false;
		GameDialog.hard = false;
		break;
	case 1: //보통 선택 시
		GameDialog.easy = false;
		GameDialog.mid = true;
		GameDialog.hard = false;
		break;
	case 2: //어려움 선택시
		GameDialog.easy = false;
		GameDialog.mid = false;
		GameDialog.hard = true;
		break;
	}
	switch (m_color) { //색깔 그룹
	case 0: //빨강 선택 시
		GameDialog.red = true;
		GameDialog.green = false;
		GameDialog.blue = false;
		break;
	case 1: //초록 선택 시
		GameDialog.red = false;
		GameDialog.green = true;
		GameDialog.blue = false;
		break;
	case 2: //노랑 선택시
		GameDialog.red = false;
		GameDialog.green = false;
		GameDialog.blue = true;
		break;
	}
	OnOK(); //창 닫기
	GameDialog.DoModal(); //게임 실행 창
	UpdateData(false);
}

void GameSetting::OnBnClickedButton2() //취소 버튼
{
	OK = false;
	OnOK();
}
