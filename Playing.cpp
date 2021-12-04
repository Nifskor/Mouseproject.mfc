// Playing.cpp: 구현 파일
//원 생성 범위 : (50, 50, 100, 100) ~ (550, 550, 600, 600)

#include "pch.h"
#include "Mouseproject.h"
#include "Playing.h"
#include "afxdialogex.h"

//랜덤 함수 사용
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <windows.h> //sleep 함수



// Playing 대화 상자

IMPLEMENT_DYNAMIC(Playing, CDialog)

Playing::Playing(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PLAYING_DIALOG, pParent)
{

}

Playing::~Playing()
{
}

void Playing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	SetTimer(0, 10, NULL); //0.5초
}


BEGIN_MESSAGE_MAP(Playing, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Playing 메시지 처리기


void Playing::OnTimer(UINT_PTR nIDEvent) //timer 메시지
{
	CDialog::OnTimer(nIDEvent);
	int x1 = 0; //원 출력 좌표
	int y1 = 0;

	switch (nIDEvent){
	case 0:
		srand((unsigned int)time(NULL)); //랜덤 값 함수
		x1 = ((rand() % 10) * 60); //0~9
		y1 = ((rand() % 10) * 60);

		CClientDC dc(this);
		dc.Ellipse(x1 , y1, x1+50, y1+50); //랜덤 원 출력
		Sleep(100);
		Invalidate(TRUE); //원 지우기
		break;
	}
}
