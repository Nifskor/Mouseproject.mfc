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
	, m_score(0)
{

}

Playing::~Playing()
{
}

void Playing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	SetTimer(0, 1000, NULL); //원 생성 타이머
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);
	m_score = score;
}


BEGIN_MESSAGE_MAP(Playing, CDialog)
	ON_WM_TIMER()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EXIT, &Playing::OnExit)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// Playing 메시지 처리기


void Playing::OnTimer(UINT_PTR nIDEvent) //timer 메시지
{
	UpdateData(true);
	CDialog::OnTimer(nIDEvent);

	switch (nIDEvent){
	case 0:
		srand((unsigned int)time(NULL)); //랜덤 값 함수
		x1 = ((rand() % 10) * 130); //랜덤 값 지정
		y1 = ((rand() % 10) * 100);

		CClientDC dc(this);
		dc.Ellipse(x1 , y1, x1+50, y1+50); //랜덤 원 출력
		if (attack) { //명중 시 score ++
			score++;
			attack = false;
		}
		else{ //대기시간
			Sleep(1000);
			Invalidate(TRUE);
		}
		break;
	}
	UpdateData(false);
}


void Playing::OnContextMenu(CWnd* /*pWnd*/, CPoint point) //우클릭 메뉴 메시지
{
	CMenu menu;
	menu.LoadMenuW(IDR_MENU_PLAYING);
	//menu.CreatePopupMenu();
	CMenu* pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, AfxGetMainWnd());
}


void Playing::OnExit() //나가기 메뉴 / TODO
{   if (AfxMessageBox(_T("정말 종료하시겠습니까?"), MB_YESNO) == IDYES) { OnOK(); }   }



void Playing::OnMouseMove(UINT nFlags, CPoint point) //마우스 커서 움직임 메시지
{
	m_point = point;
	if ((m_point.x > x1) && (m_point.x < x1+50) && (m_point.y > y1) && (m_point.y < y1 + 50)) { //마우스와 원의 좌표가 일치하면
		attack = true; //score를 올리기 위해 사용
		Invalidate(TRUE);
		SetTimer(0, 300, NULL);
	}
	CDialog::OnMouseMove(nFlags, point);
}
