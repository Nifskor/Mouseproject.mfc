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
END_MESSAGE_MAP()


// GameSetting 메시지 처리기


void GameSetting::OnBnClickedButton2() //취소 버튼
{
	OnOK();
}
