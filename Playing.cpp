﻿// Playing.cpp: 구현 파일
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

BOOL Playing::OnInitDialog() {
	CDialog::OnInitDialog();

	//원 색깔 지정
	if (red) {
		brush.CreateSolidBrush(RGB(255, 0, 0));
	}
	else if (green) {
		brush.CreateSolidBrush(RGB(0, 255, 0));
	}
	else if (blue) {
		brush.CreateSolidBrush(RGB(0, 0, 255));
	}

	if (easy)
		Create_time = 1000; //1초
	else if (mid)
		Create_time = 500; //0.5초
	else if (hard)
		Create_time = 300; //0.3초

	SetTimer(1, 1000, NULL); //게임 시간 타이머

	return TRUE;
}

Playing::Playing(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PLAYING_DIALOG, pParent)
	, m_score(0)
	, m_time(4) //31초로 초기화 / TODO 시간 31초로
{

}

Playing::~Playing()
{
}


void Playing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_score);

	m_score = score;
	SetTimer(0, Create_time, NULL); //원 생성 타이머
	DDX_Text(pDX, IDC_EDIT_TIME, m_time);
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
	switch (nIDEvent) {
		case 0: { //원 처리
			srand((unsigned int)time(NULL)); //랜덤 값 함수
			x1 = ((rand() % 10) * 130); //랜덤 값 지정
			y1 = ((rand() % 10) * 100);

			CClientDC dc(this);
			dc.SelectObject(&brush);
			dc.Ellipse(x1, y1, x1 + 50, y1 + 50); //랜덤 원 출력

			if (attack) { //명중 시 score ++
				score++;
				attack = false;
			}
			else { //대기시간
				Sleep(Create_time);
				Invalidate(TRUE);
			}
			break;
		} //case 0 끝
		case 1: {
			m_time--;
			if (m_time == 0) { //0초가 된다면
				KillTimer(0);
				KillTimer(1);
				OnOK();
			}
			break;
		} //case 1 끝
	}
	UpdateData(false);
}


void Playing::OnContextMenu(CWnd* /*pWnd*/, CPoint point) //우클릭 메뉴 메시지
{
	CMenu menu;
	menu.LoadMenu(IDR_MENU_PLAYING);
	CMenu* mnuPopupMenu = menu.GetSubMenu(0);
	ASSERT(mnuPopupMenu);
	mnuPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void Playing::OnExit() //나가기 메뉴 / TODO
{
	if (AfxMessageBox(_T("정말 종료하시겠습니까?"), MB_YESNO) == IDYES) { exit(0); }
}



void Playing::OnMouseMove(UINT nFlags, CPoint point) //마우스 커서 움직임 메시지
{
	m_point = point;
	if ((m_point.x > x1) && (m_point.x < x1 + 50) && (m_point.y > y1) && (m_point.y < y1 + 50)) { //마우스와 원의 좌표가 일치하면
		attack = true; //score를 올리기 위해 사용
		Invalidate(TRUE);
		KillTimer(0);
		SetTimer(0, Create_time, NULL);
	}

	CDialog::OnMouseMove(nFlags, point);
}
