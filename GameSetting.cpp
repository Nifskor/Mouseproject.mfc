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
{

}

GameSetting::~GameSetting()
{
}

void GameSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameSetting, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &GameSetting::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &GameSetting::OnBnClickedButton1)
END_MESSAGE_MAP()

void GameSetting::OnBnClickedButton1() //확인 버튼
{
	OK = true;
	OnOK();
}

void GameSetting::OnBnClickedButton2() //취소 버튼
{
	OK = false;
	OnOK();
}

