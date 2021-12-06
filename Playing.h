#pragma once

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

	bool attack = false;
	int score = 0; //스코어

	CPoint m_point; //마우스 좌표 (우클릭 메뉴에 사용)
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnExit();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_score;

	//GameSetting에서 불러올 변수들
	bool easy;
	bool mid;
	bool hard;
	bool red;
	bool green;
	bool blue;

	CBrush brush; //색깔 원 brush
	CBrush* oldBrush; //색깔 원 oldBrush
};
