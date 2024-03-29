﻿#pragma once


// GameSetting 대화 상자
#include "Playing.h"

class GameSetting : public CDialog
{
	DECLARE_DYNAMIC(GameSetting)

public:
	GameSetting(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~GameSetting();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();

	bool OK = false;

	int m_level; //난이도 그룹
	int m_color; //색깔 그룹

	Playing GameDialog;
	GameSetting* thisDialog;
};
