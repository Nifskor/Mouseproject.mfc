#pragma once
#include "Result.h"

// Playing 대화 상자

class Playing : public CDialog
{
	DECLARE_DYNAMIC(Playing)

public:
	Playing(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Playing();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAYING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int x1 = 0; //원 출력 좌표
	int y1 = 0;
	int Create_time; //원 생성 시간
	int score = 0; //스코어

	bool attack = false;

	CPoint m_point; //마우스 좌표 (우클릭 메뉴에 사용)
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnExit();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_score; //스코어 Edit Control
	int m_time; //시간 Edit Control

	//GameSetting에서 불러올 변수들
	bool easy;
	bool mid;
	bool hard;
	bool red;
	bool green;
	bool blue;

	CBrush brush; //색깔 원 brush
	CBrush* oldBrush; //색깔 원 oldBrush

	Result ResultDialog; //결과 창
};
