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

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
