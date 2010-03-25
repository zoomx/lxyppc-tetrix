// TetrixPreDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Stream.h"
#include "MyEdit.h"

#define     WM_PLAYACTION       WM_USER+100

// CTetrixPreDlg 对话框
class CTetrixPreDlg : public CDialog
{
// 构造
public:
	CTetrixPreDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TETRIXPRE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedTest();
    CStatic m_pic;
    afx_msg void OnBnClickedLoad();
    afx_msg void OnBnClickedSave();
    CImage  m_image;
    afx_msg void OnTimer(UINT nIDEvent);
    int     m_keyCode;
    CStatic m_picDbg;
protected:
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    CMyEdit m_edit;
    CDC*     m_pMemDC;
};

void    GenerateJpeg(const char* fileName);


