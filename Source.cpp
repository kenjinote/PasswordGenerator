﻿#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>
#include <commctrl.h>
#include <array>
#include <random>
#include "sha512.hh"
#include "resource.h"

#define CHECKBOX_STYLE (WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX)

const TCHAR szClassName[] = TEXT("PASSWORD GENERATOR");
const TCHAR szChar[] = TEXT("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");

enum
{
	ID_STATIC1 = 1000, ID_STATIC2, ID_STATIC3,
	ID_EDIT1, ID_EDIT2, ID_EDIT3,
	ID_CHECK_UPPER, ID_CHECK_LOWER,
	ID_CHECK_NUMBER, ID_CHECK1, ID_CHECK2,
	ID_CHECK3, ID_CHECK4, ID_CHECK5,
	ID_CHECK6, ID_CHECK7, ID_CHECK8,
	ID_CHECK9, ID_CHECK10, ID_CHECK11,
	ID_CHECK12, ID_CHECK13, ID_CHECK14,
	ID_CHECK15, ID_CHECK16, ID_CHECK17,
	ID_CHECK18, ID_CHECK19, ID_CHECK20,
	ID_CHECK21, ID_CHECK22, ID_CHECK23,
	ID_CHECK24, ID_CHECK25, ID_CHECK26,
	ID_CHECK27, ID_CHECK28, ID_CHECK29,
	ID_CHECK30, ID_CHECK31, ID_CHECK32,
	ID_CHECKALL
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		// 文字数
		CreateWindow(WC_STATIC, TEXT("文字数："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,
			10, 10, 128, 30, hWnd, (HMENU)ID_STATIC1,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindowEx(WS_EX_CLIENTEDGE, WC_EDIT,
			TEXT("16"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER,
			138, 10, 256, 30, hWnd, (HMENU)ID_EDIT1,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		// 記号
		CreateWindow(WC_STATIC, TEXT("使用文字："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,
			10, 50, 128, 30, hWnd, (HMENU)ID_STATIC2,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("大文字"), CHECKBOX_STYLE,
			138, 50, 90, 30, hWnd, (HMENU)ID_CHECK_UPPER,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("小文字"), CHECKBOX_STYLE,
			228, 50, 90, 30, hWnd, (HMENU)ID_CHECK_LOWER,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("数字"), CHECKBOX_STYLE,
			318, 50, 64, 30, hWnd, (HMENU)ID_CHECK_NUMBER,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("!"), CHECKBOX_STYLE,
			138, 90, 32, 30, hWnd, (HMENU)ID_CHECK1,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("\""), CHECKBOX_STYLE,
			170, 90, 32, 30, hWnd, (HMENU)ID_CHECK2,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("#"), CHECKBOX_STYLE,
			202, 90, 32, 30, hWnd, (HMENU)ID_CHECK3,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("$"), CHECKBOX_STYLE,
			234, 90, 32, 30, hWnd, (HMENU)ID_CHECK4,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("%"), CHECKBOX_STYLE,
			266, 90, 32, 30, hWnd, (HMENU)ID_CHECK5,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("&&"), CHECKBOX_STYLE,
			298, 90, 32, 30, hWnd, (HMENU)ID_CHECK6,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("'"), CHECKBOX_STYLE,
			330, 90, 32, 30, hWnd, (HMENU)ID_CHECK7,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("("), CHECKBOX_STYLE,
			362, 90, 32, 30, hWnd, (HMENU)ID_CHECK8,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT(")"), CHECKBOX_STYLE,
			138, 130, 32, 30, hWnd, (HMENU)ID_CHECK9,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("*"), CHECKBOX_STYLE,
			170, 130, 32, 30, hWnd, (HMENU)ID_CHECK10,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("+"), CHECKBOX_STYLE,
			202, 130, 32, 30, hWnd, (HMENU)ID_CHECK11,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT(","), CHECKBOX_STYLE,
			234, 130, 32, 30, hWnd, (HMENU)ID_CHECK12,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("-"), CHECKBOX_STYLE,
			266, 130, 32, 30, hWnd, (HMENU)ID_CHECK13,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("."), CHECKBOX_STYLE,
			298, 130, 32, 30, hWnd, (HMENU)ID_CHECK14,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("/"), CHECKBOX_STYLE,
			330, 130, 32, 30, hWnd, (HMENU)ID_CHECK15,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT(":"), CHECKBOX_STYLE,
			362, 130, 32, 30, hWnd, (HMENU)ID_CHECK16,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT(";"), CHECKBOX_STYLE,
			138, 170, 32, 30, hWnd, (HMENU)ID_CHECK17,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("<"), CHECKBOX_STYLE,
			170, 170, 32, 30, hWnd, (HMENU)ID_CHECK18,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("="), CHECKBOX_STYLE,
			202, 170, 32, 30, hWnd, (HMENU)ID_CHECK19,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT(">"), CHECKBOX_STYLE,
			234, 170, 32, 30, hWnd, (HMENU)ID_CHECK20,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("?"), CHECKBOX_STYLE,
			266, 170, 32, 30, hWnd, (HMENU)ID_CHECK21,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("@"), CHECKBOX_STYLE,
			298, 170, 32, 30, hWnd, (HMENU)ID_CHECK22,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("["), CHECKBOX_STYLE,
			330, 170, 32, 30, hWnd, (HMENU)ID_CHECK23,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("\\"), CHECKBOX_STYLE,
			362, 170, 32, 30, hWnd, (HMENU)ID_CHECK24,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("]"), CHECKBOX_STYLE,
			138, 210, 32, 30, hWnd, (HMENU)ID_CHECK25,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("^"), CHECKBOX_STYLE,
			170, 210, 32, 30, hWnd, (HMENU)ID_CHECK26,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("_"), CHECKBOX_STYLE,
			202, 210, 32, 30, hWnd, (HMENU)ID_CHECK27,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("`"), CHECKBOX_STYLE,
			234, 210, 32, 30, hWnd, (HMENU)ID_CHECK28,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("{"), CHECKBOX_STYLE,
			266, 210, 32, 30, hWnd, (HMENU)ID_CHECK29,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("|"), CHECKBOX_STYLE,
			298, 210, 32, 30, hWnd, (HMENU)ID_CHECK30,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("}"), CHECKBOX_STYLE,
			330, 210, 32, 30, hWnd, (HMENU)ID_CHECK31,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("~"), CHECKBOX_STYLE,
			362, 210, 32, 30, hWnd, (HMENU)ID_CHECK32,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindow(WC_BUTTON, TEXT("記号"),
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTO3STATE,
			10, 90, 64, 30, hWnd, (HMENU)ID_CHECKALL,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		{
			for (int nID = ID_CHECK_UPPER; nID <= ID_CHECKALL; ++nID)
				CheckDlgButton(hWnd, nID, 1);
		}
		// 生成個数
		CreateWindow(WC_STATIC, TEXT("生成個数："),
			WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,
			10, 250, 128, 30, hWnd, (HMENU)ID_STATIC3,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		CreateWindowEx(WS_EX_CLIENTEDGE, WC_EDIT, TEXT("1"),
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NUMBER,
			138, 250, 256, 30, hWnd, (HMENU)ID_EDIT2,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		// 生成ボタン
		CreateWindow(WC_BUTTON, TEXT("生成"),
			WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			10, 290, 128, 30, hWnd, (HMENU)IDOK,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		// 生成結果
		CreateWindowEx(WS_EX_CLIENTEDGE, WC_EDIT, 0,
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP |
			ES_READONLY | ES_MULTILINE | ES_AUTOHSCROLL,
			10, 330, 384, 256, hWnd, (HMENU)ID_EDIT3,
			((LPCREATESTRUCT)lParam)->hInstance, 0);
		SendDlgItemMessage(hWnd, ID_EDIT3, EM_LIMITTEXT, 0, 0);
		SendDlgItemMessage(hWnd, ID_EDIT3, WM_SETFONT,
			(WPARAM)(HFONT)GetStockObject(SYSTEM_FIXED_FONT), 0);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			SetDlgItemText(hWnd, ID_EDIT3, 0);
			BOOL bTranslated;
			const int nPassLen = GetDlgItemInt(hWnd, ID_EDIT1, &bTranslated, 0);
			if (bTranslated == FALSE || nPassLen <= 0)
			{
				SendDlgItemMessage(hWnd, ID_EDIT1, EM_SETSEL, 0, -1);
				SetFocus(GetDlgItem(hWnd, ID_EDIT1));
				break;
			}
			const int nPassCount = GetDlgItemInt(hWnd, ID_EDIT2, &bTranslated, 0);
			if (bTranslated == FALSE || nPassCount <= 0)
			{
				SendDlgItemMessage(hWnd, ID_EDIT2, EM_SETSEL, 0, -1);
				SetFocus(GetDlgItem(hWnd, ID_EDIT2));
				break;
			}
			TCHAR szSample[95] = { 0 };
			if (IsDlgButtonChecked(hWnd, ID_CHECK_UPPER) == 1)
			{
				lstrcat(szSample, TEXT("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
			}
			if (IsDlgButtonChecked(hWnd, ID_CHECK_LOWER) == 1)
			{
				lstrcat(szSample, TEXT("abcdefghijklmnopqrstuvwxyz"));
			}
			if (IsDlgButtonChecked(hWnd, ID_CHECK_NUMBER) == 1)
			{
				lstrcat(szSample, TEXT("0123456789"));
			}
			TCHAR szTemp[2] = { 0 };
			for (int nID = ID_CHECK1; nID <= ID_CHECK32; ++nID)
			{
				if (IsDlgButtonChecked(hWnd, nID) == 1)
				{
					szTemp[0] = szChar[nID - ID_CHECK1];
					lstrcat(szSample, szTemp);
				}
			}
			if (lstrlen(szSample) == 0)
			{
				MessageBox(
					hWnd,
					TEXT("パスワードを生成するには、")
					TEXT("[使用文字]チェックボックスを")
					TEXT("少なくとも一つは選択する必要があります。"),
					0,
					0);
				break;
			}
			LPTSTR lpszPassWord = (LPTSTR)GlobalAlloc(GMEM_FIXED,
				sizeof(TCHAR)*(nPassLen + 3));
			lpszPassWord[nPassLen] = TEXT('\r');
			lpszPassWord[nPassLen + 1] = TEXT('\n');
			lpszPassWord[nPassLen + 2] = TEXT('\0');
			// 初期シードを設定
			std::array<std::seed_seq::result_type, std::mt19937::state_size> seed_data;
			std::random_device rd;
			std::generate_n(seed_data.data(), seed_data.size(), std::ref(rd));
			std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
			std::mt19937 engine(seq);
			// 乱数生成
			const UINT charlen = lstrlen(szSample);
			for (int i = 0; i < nPassCount; ++i)
			{
				for (int j = 0; j < nPassLen; ++j)
				{
					UINT r = engine();
					auto str = sw::sha512::calculate(&r, sizeof(UINT));
					r = stoul(str.substr(0, 8), nullptr, 16) % charlen;
					lpszPassWord[j] = szSample[r];
				}
				SendDlgItemMessage(hWnd, ID_EDIT3, EM_REPLACESEL, 0, (LPARAM)lpszPassWord);
			}
			GlobalFree(lpszPassWord);
			SendDlgItemMessage(hWnd, ID_EDIT3, EM_SETSEL, 0, -1);
			SetFocus(GetDlgItem(hWnd, ID_EDIT3));
		}
		else if (LOWORD(wParam) == ID_CHECKALL)
		{
			if (BST_INDETERMINATE == SendDlgItemMessage(hWnd, ID_CHECKALL, BM_GETCHECK, 0, 0))
				SendDlgItemMessage(hWnd, ID_CHECKALL, BM_SETCHECK, BST_UNCHECKED, 0);
			const BOOL bCheck = IsDlgButtonChecked(hWnd, ID_CHECKALL);
			for (int nID = ID_CHECK1; nID <= ID_CHECK32; ++nID)
				CheckDlgButton(hWnd, nID, bCheck);
		}
		else if (ID_CHECK1 <= LOWORD(wParam) && LOWORD(wParam) <= ID_CHECK32)
		{
			BOOL bOnCount = FALSE, bOffCount = FALSE;
			for (int nID = ID_CHECK1; nID <= ID_CHECK32; ++nID)
			{
				if (IsDlgButtonChecked(hWnd, nID))
					bOnCount = TRUE;
				else
					bOffCount = TRUE;
			}
			if (bOnCount&&bOffCount)
				SendDlgItemMessage(hWnd, ID_CHECKALL, BM_SETCHECK, BST_INDETERMINATE, 0);
			else if (bOnCount && !bOffCount)
				SendDlgItemMessage(hWnd, ID_CHECKALL, BM_SETCHECK, BST_CHECKED, 0);
			else if (!bOnCount&&bOffCount)
				SendDlgItemMessage(hWnd, ID_CHECKALL, BM_SETCHECK, BST_UNCHECKED, 0);
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return(DefDlgProc(hWnd, msg, wParam, lParam));
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	const WNDCLASS wndclass = {
		0,
		WndProc,
		0,
		DLGWINDOWEXTRA,
		hInstance,
		LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)),
		LoadCursor(0, IDC_ARROW),
		0,
		0,
		szClassName
	};
	RegisterClass(&wndclass);
	RECT rect = { 0,0,404,596 };
	AdjustWindowRect(&rect, WS_CAPTION | WS_SYSMENU, 0);
	const HWND hWnd = CreateWindow(
		szClassName,
		TEXT("パスワード生成"),
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,
		0,
		rect.right - rect.left,
		rect.bottom - rect.top,
		0,
		0,
		hInstance,
		0
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!IsDialogMessage(hWnd, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}
