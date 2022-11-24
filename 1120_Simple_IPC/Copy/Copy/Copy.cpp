// Copy.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Copy.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_COPY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_COPY));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_COPY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_COPY);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

//색상 구분
int g_color;

//도형 구분
int g_kind;

//선 종류
int g_linekind;

//선 굵기
int g_linesize;

//좌표 전역 변수
int g_x, g_y;
int g_x2, g_y2;

bool g_p;


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_USER+0:
    {
        g_color = 1;     
    }
     break;
    case WM_USER + 1:
    {
        g_color = 2;
    }
    break;
    case WM_USER + 2:
    {
        g_color = 3;

    }
    break;
    case WM_USER + 3:
    {
        g_kind = 1;
    }
    break;
    case WM_USER + 4:
    {
        g_kind = 2;
    }
    break;
    case WM_USER + 5:
    {
        g_kind = 3;
    }
    break;
    case WM_USER + 6:
    {
        g_kind = 4;
    }
    break;
    case WM_USER + 7:
    {
        g_linesize = 1;
    }
    break;
    case WM_USER + 8:
    {
        g_linesize = 2;
    }
    break;
    case WM_USER + 9:
    {
        g_linesize = 3;
    }
    break;
    case WM_USER + 10:
    {
        g_linesize = 4;
    }
    break;
    case WM_USER + 11:
    {
        g_linesize = 5;
    }
    break;
    case WM_USER + 12:
    {
        g_linekind = 1;
    }
    break;
    case WM_USER + 13:
    {
        g_linekind = 2;      
    }
    break;
    case WM_LBUTTONDOWN:
    {       
            g_p = true;
            g_x = LOWORD(lParam);
            g_y = HIWORD(lParam);
      
    }
    break;
    case WM_LBUTTONUP:
    {

        int x, y;
        int source = 0;
        int color = 0;
        int linesize = 0;

        g_p = false;

        HDC hdc;
        HPEN os_pen, my_pen;
        HBRUSH os_b, my_b;


        x = LOWORD(lParam);
        y = HIWORD(lParam);

        hdc = GetDC(hWnd);

       
  
        // 선 종류 고르기
        switch (g_linekind)
        {  
        case 0:
            break;
        case 1:
            source = PS_COSMETIC;
            break;
        case 2:
            source = PS_DASH;
            break;
        default:
            break;
        }
      
        // 색상 고르기
        switch (g_color)
        {
        case 1:
            color = RGB(255, 0, 0);
            break;
        case 2:
            color = RGB(0, 0, 0);
            break;
        case 3:
            color = RGB(0, 0, 255);
            break;
        default:
            break;
        }
        
        //선 사이즈 고르기
        switch (g_linesize)
        {
        case 1:
            linesize = 1;
            break;
        case 2:
            linesize = 2;
            break;
        case 3:
            linesize = 5;
            break;
        case 4:
            linesize = 10;
            break;
        case 5:
            linesize = 15;
            break;
        default:
            break;
        }
     
        my_b = CreateSolidBrush(color);


        os_b = (HBRUSH)SelectObject(hdc, my_b);
        //1.생성

        my_pen = CreatePen(source, linesize, color);

        //2. 교체 : os의 현재 객체 반환

        os_pen = (HPEN)SelectObject(hdc, my_pen);
        
       
        // 3. 사용
        switch (g_kind)
        { 
        case 0:
        {
            MoveToEx(hdc, g_x, g_y, NULL);
            LineTo(hdc, x, y);
        }
        case 1:
        {
            MoveToEx(hdc, g_x, g_y, NULL);
            LineTo(hdc, x, y);
        }
        break;
        case 2:
        {
            Rectangle(hdc, g_x, g_y, x, y);
        }
        break;
        case 3:
        {
            Ellipse(hdc, g_x, g_y, x, y);
        }
        break;
        }

        // 4. 교체 : 원래 객체로 복원

        SelectObject(hdc, os_pen);
        SelectObject(hdc, os_b);
        //5. 삭제

        DeleteObject(my_pen);
        DeleteObject(my_b);
        ReleaseDC(hWnd, hdc);
        
    }
    break;
     case WM_MOUSEMOVE:
         {

             HPEN os_pen, my_pen;
             HBRUSH os_b, my_b;
             HDC hdc;            
             int source = 0;
             int color = 0;
             int linesize = 0;

             hdc = GetDC(hWnd);

             // 선 종류 고르기 하지만 자유곡선이라 큰 차이가 없음
             switch (g_linekind)
             {       
             case 0:
                 break;
             case 1:
                 source = PS_COSMETIC;
                 break;
             case 2:
                 source = PS_DASH;
                 break;
             default:
                 break;
             }
             // 색상 고르기
             switch (g_color)
             {
                 case 1:
                 color = RGB(255, 0, 0);
                 break;
             case 2:
                 color = RGB(0, 0, 0);
                 break;
             case 3:
                 color = RGB(0, 0, 255);
                 break;
             default:
                 break;
             }

             //선 사이즈 고르기
             switch (g_linesize)
             {            
             case 1:
                 linesize = 1;
                 break;
             case 2:
                 linesize = 2;
                 break;
             case 3:
                 linesize = 5;
                 break;
             case 4:
                 linesize = 10;
                 break;
             case 5:
                 linesize = 15;
                 break;
             default:
                 break;
             }


             my_b = CreateSolidBrush(color);
             os_b = (HBRUSH)SelectObject(hdc, my_b);
             //1.생성

             my_pen = CreatePen(source, linesize, color);

             //2. 교체 : os의 현재 객체 반환

             os_pen = (HPEN)SelectObject(hdc, my_pen);

             if (g_kind == 4)
             {
                 if (false == g_p)
                     break;

                 g_x2 = LOWORD(lParam);
                 g_y2 = HIWORD(lParam);

                 MoveToEx(hdc, g_x, g_y, NULL);
                 g_x = g_x2;
                 g_y = g_y2;
                 LineTo(hdc, g_x, g_y);


             };
             SelectObject(hdc, os_pen);
             SelectObject(hdc, os_b);


             DeleteObject(my_pen);
             DeleteObject(my_b);
             ReleaseDC(hWnd, hdc);
         }
         break;


    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
