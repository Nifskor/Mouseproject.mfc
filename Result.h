#pragma once


// Result 대화 상자

class Result : public CDialog
{
	DECLARE_DYNAMIC(Result)

public:
	Result(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Result();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	CFont m_font; //폰트 설정
	int m_score; //스코어 Edit Control
	CString m_level; //레벨 Edit Control
	CString m_ranking; //랭킹 Edit Control
	afx_msg void OnBnClickedButtonExit(); //종료 버튼
	afx_msg void OnBnClickedButtonRestart(); //메인 화면 버튼
};
