
#include "stdafx.h"
#include "Victorina.h"
#include"Resource.h"
#include "mmSystem.h"

#define MAX_LOADSTRING 100
//////////////////////////////

//////////////////////////////
// Глобальные переменные:
HINSTANCE hInst;   
HINSTANCE hInstance;// текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна


PAINTSTRUCT ps;
HDC hdc;
TEXTMETRIC tm;
HWND hwndButtonChose;
static HWND hwndButton[10];
HWND hwndButtonVictorina[50];
HWND hwndButton_Victorina_Guestion[50];
HWND hwndButtonVictorinaPodskazki[10];
HWND hWnd;




int ReloadGame = 0;
int CountWin = 0;
int count =0;
int counterGame = 0;
int counter = 0;
int counterGameGG = 0;
int r[5], g[5], b[5];
static int cxChar, cyChar;
int rt;//переменная для подсчета квадратов
HBRUSH R, G, B;//кисточки для работы с прямоугольниками 

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
////////////////////////////////////////////////////////////////
INT_PTR CALLBACK   FistGuestion(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbTwo(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbTree(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbFour(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbFive(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbSix(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbSeven(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbEight(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbNine(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK   NumbTen(HWND, UINT, WPARAM, LPARAM);

//////////////////////////////////////////////////////////////
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_VICTORINA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VICTORINA));

    MSG msg;

    // Цикл основного сообщения:
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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)CreateSolidBrush(RGB(20, 20, 120));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_VICTORINA);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));
    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED| WS_SYSMENU,
	   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
    case WM_COMMAND:
        {
case WM_KEYDOWN:
#define HOTKEY1 2016

		//определение комбинаций клавиш
		RegisterHotKey(hWnd, HOTKEY1, MOD_CONTROL, VK_F1);
		
		//цикл обработки сообщений горячих клавиш
		//Enter_The_Game
	case WM_HOTKEY:{
		if (HOTKEY1 == (int)wParam) {
			PlaySound(NULL, NULL, SND_SYSTEM);
			
			InvalidateRect(hWnd, NULL, TRUE);
			for (int i = 0; i < 10; i++) {
				DestroyWindow(hwndButton_Victorina_Guestion[i]);
			}
			if (MessageBox(hWnd, "Начать игру ?\n\nСо всеми вопросами смотрите в пункт меню Instruction ", "Hello", MB_YESNO) == IDYES) {
		
				hwndButtonVictorina[0] = CreateWindow("BUTTON", "PRES_TO_START_FIRST_GAME",
					WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
					10,         // starting x position 
					10,         // starting y position 
					400,        // button width 
					50,        // button height 
					hWnd,       // parent window 
					(HMENU)11,       // No menu 
					hInstance,
					//(HINSTANCE)GetWindowLong(hWnd, NULL),
					NULL);

//////////////end button control
}
//Esit_from_game
else {

	for (int i = 0; i < 10; i++) {
		DestroyWindow(hwndButton_Victorina_Guestion[i]);
	}
				if (MessageBox(hWnd, "Exit?", "Are_you_want_this", MB_YESNO) == IDYES) {
					DestroyWindow(hWnd);
				}
			}				
}//end hotkey


////////////////////////////////////////////////////////////////////???????????????????????????????????
}//end of hotkey process

int wmId = LOWORD(wParam);// Разобрать выбор в меню:
switch (wmId) {

//start Game
case 11: {
	
PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\mainsound.wav"), NULL, SND_LOOP | SND_ASYNC);

////////////////////////////////////////////////
	static int cxChar, cyChar;
	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
/////////////////////////////////////////////////
	for (int up = 0; up < 5; up++) {
		
		R = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hdc, R);
//////////////////////////вверхний край
		r[up] = Rectangle(hdc,
			(cxChar+750)+(50*up), cyChar *(5),
			(102*cxChar)+50*up, (5) * cyChar/2);
///////////////////////////НИЖНИЙ КРАЙ 
		r[up] = Rectangle(hdc,
			(cxChar + 750) + (50 * up), cyChar *(5)+144,
			(102 * cxChar) + 50 * up, ((5) * cyChar / 2)+144);
	}
/////////////////////////////////////////
	
	for (rt = 0; rt < 4; rt++) {
		//////////////////////////////////////////////
		R = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hdc, R);
		r[rt] = Rectangle(hdc,
			cxChar + 700, cyChar *(5 + (3 * rt)),
			95 * cxChar, (5 + 6 * rt) * cyChar / 2);
		////////////////////////////////////////////
		r[rt] = Rectangle(hdc,
			cxChar + 1000, cyChar *(5 + (3 * rt)),
			137 * cxChar + 4, (5 + 6 * rt) * cyChar / 2);
	}

	ReleaseDC(hWnd, hdc);
	
//////////////////////////////////////////////
	hwndButton_Victorina_Guestion[0] = CreateWindow("BUTTON", "Fist_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			450,         // starting x position 
			41,         // starting y position 
			200,        // button width 
			30,        // button height 
			hWnd,       // parent window 
			(HMENU)0,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);	
///////////////////////////////////////////////////////
	DestroyWindow(hwndButtonVictorina[0]);//button start1
	
	break;
///////////////////////////////////
		case  ID_INSTRUCTION://пункт instruction 
		{
			MessageBox(hWnd, "Интрукция \n\n Для начала игры нажмите комбинацию Ctr+F1 \n\n "
				"Для вывода информации о создателе программы нажмите на кнопку About в панеле меню\n\n "
				"Для выхода из программы нажимите Exit \n"
			   ,"Инструкция", MB_OK);
			break;
		}
///////////////////////////////////////////////////////////////////////////////
		case ID_ABOUT: {
			MessageBox(hWnd, "Victorina ver 1.0  \n\n "
				"Developer : Predator \n\n "
				"HAVE FAN !!!!!!!!!\n\n"
				, "About", MB_OK);
			break;

		}
 ///////////////////////////////////////////////////////////////////
case IDM_EXIT: {

	DestroyWindow(hWnd);
	break;
}
///////////////////////////////////////////////////////
}//end//start
///////////////////////////////////////////

}//end of switch for chose players

int wmIdd = LOWORD(wParam);//обработчик сообщений от диалогового окна номер 2 
switch (wmIdd) {
	//первый вопрос

case 0: {
	
	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
////////////////////////////////////////////////////////
	
		hwndButtonVictorinaPodskazki[0] = CreateWindow("BUTTON", "Подсказка",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			671,         // starting x position 
			250,         // starting y position 
			100,        // button width 
			50,        // button height 
			hWnd,       // parent window 
			(HMENU)20,
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd, NULL),
			NULL);
	
///////////////////////////////////////////////////////
		
		//////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 750, cyChar *(5) + 48,
		102 * cxChar, ((5) * cyChar / 2) + 48);
      DestroyWindow(hwndButton_Victorina_Guestion[0]);
	
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[0]);
	}
	////////////////////////////////////////

	///////////////////////////////////////
	if (counterGameGG == 0) {
	 
	
		hwndButton_Victorina_Guestion[1] = CreateWindow("BUTTON", "Second_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			450,         // starting x position 
			80,         // starting y position 
			200,        // button width 
			30,        // button height 
			hWnd,       // parent window 
			(HMENU)1,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	/////////////////////////////////////////
	
	DialogBox(hInst, MAKEINTRESOURCE(IDD_FistGuestion), hwndButtonChose, FistGuestion);
	//////////////////////////////////////////////////
	DestroyWindow(hwndButtonVictorinaPodskazki[0]);
	
break;


case 20: {

	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nNope\nГермания", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[0]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[0]);
	}
	break;

}

}
////////////////////////////////////////////
//Second вопрос
case 1: {

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
/////////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[1] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)21,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);

////////////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 800, cyChar *(5) + 48,
		109 * cxChar, ((5) * cyChar / 2) + 48);
	///////////////////////////////////////////
	DestroyWindow(hwndButton_Victorina_Guestion[1]);
///////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[2]);
	}
	//////////////////////////////////////////////
	if (counterGameGG <= 1) {
		
		hwndButton_Victorina_Guestion[2] = CreateWindow("BUTTON", "Thrid_Guestion",
				WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
				450,         // starting x position 
				120,         // starting y position 
				200,        // button width 
				30,        // button height 
				hWnd,       // parent window 
				(HMENU)2,       // No menu 
				hInstance,
			//	(HINSTANCE)GetWindowLong(hWnd,NULL),
				NULL);
		
	}
	/////////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_StcondGuestion), hwndButtonChose, NumbTwo);
	DestroyWindow(hwndButtonVictorinaPodskazki[1]);

	break;

case 21: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nNope\nКулхард", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[1]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[1]);
	}

	
	break;
}
}
//////////////////////////////////
//Thrid Guestion
case 2: {

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
	////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[2] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)22,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 850, cyChar *(5) + 48,
		116 * cxChar+1, ((5) * cyChar / 2) + 48);
	DestroyWindow(hwndButton_Victorina_Guestion[2]);
	//////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[2]);
	}
	///////////////////////////////////////////////////
	if (counterGameGG <= 2) {

		hwndButton_Victorina_Guestion[3] = CreateWindow("BUTTON", "Fourth_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			450,         // starting x position 
			160,         // starting y position 
			200,        // button width 
			30,        // button height 
			hWnd,       // parent window 
			(HMENU)3,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);

	}
	//////////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Third), hwndButtonChose, NumbTree);
	DestroyWindow(hwndButtonVictorinaPodskazki[2]);
	break;
	//////////////////////////
case 22: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nNope\nТрое", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[2]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[2]);
	}
	break;
}

}
/////////////////////////////////////////
//Forth Guestion
case 3: {

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
	//////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[3] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)23,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 900, cyChar *(5) + 48,
		123 * cxChar + 2, ((5) * cyChar / 2) + 48);
	DestroyWindow(hwndButton_Victorina_Guestion[3]);
	///////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[3]);
	}
	/////////////////////////////////////
	if (counterGameGG <= 3) {

		hwndButton_Victorina_Guestion[4] = CreateWindow("BUTTON", "Fifth_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			450,         // starting x position 
			200,         // starting y position 
			200,        // button width 
			30,        // button height 
			hWnd,       // parent window 
			(HMENU)4,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Four), hwndButtonChose, NumbFour);
	DestroyWindow(hwndButtonVictorinaPodskazki[3]);
	break;
case 23: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nNope\n300", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[3]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[3]);
	}
	break;
}

}
/////////////////////////////////////////		
//five Guestion
case 4:{

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
/////////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[4] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)24,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	//////////
	/////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 950, cyChar *(5) + 48,
		130 * cxChar + 3, ((5) * cyChar / 2) + 48);
	DestroyWindow(hwndButton_Victorina_Guestion[4]);
	///////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[4]);
	}
	////////////////////////////////////
	if (counterGameGG <= 4) {

		hwndButton_Victorina_Guestion[5] = CreateWindow("BUTTON", "Sixth_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			1025,         // starting x position 
			42,         // starting y position 
			200,        // button width 
			29,        // button height 
			hWnd,       // parent window 
			(HMENU)5,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	/////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Five), hwndButtonChose, NumbFive);
	DestroyWindow(hwndButtonVictorinaPodskazki[4]);
	break;

case 24: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?" , "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nКоперник\nКеплер", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[4]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[4]);
	}
	break;
}


}
/////////////////////////
//Six Guestion 
case 5: {
	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
////////////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[5] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)25,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	///////////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 750, cyChar *(5) + 96,
		102 * cxChar , ((5) * cyChar / 2) + 96);
	DestroyWindow(hwndButton_Victorina_Guestion[5]);
	////////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[5]);
	}
	//////////////////////////////////////////
	if (counterGameGG <= 5) {

		hwndButton_Victorina_Guestion[6] = CreateWindow("BUTTON", "Seventh_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			1025,         // starting x position 
			80,         // starting y position 
			200,        // button width 
			29,        // button height 
			hWnd,       // parent window 
			(HMENU)6,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	/////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Six), hwndButtonChose, NumbSix);
	DestroyWindow(hwndButtonVictorinaPodskazki[5]);
	break;

case 25: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nКреп-Лизет\nКреп-Мюзет", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[5]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[5]);
	}
	break;
}

}
//////////////////////
//Seven Guestion
case 6: {

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
///////////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[6] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)26,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	//////////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 800, cyChar *(5) + 96,
		109 * cxChar, ((5) * cyChar / 2) + 96);
	DestroyWindow(hwndButton_Victorina_Guestion[6]);
	/////////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[6]);
	}
	///////////////////////////////////////
	if (counterGameGG <= 6) {

		hwndButton_Victorina_Guestion[7] = CreateWindow("BUTTON", "Eighth_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			1025,         // starting x position 
			120,         // starting y position 
			200,        // button width 
			29,        // button height 
			hWnd,       // parent window 
			(HMENU)7,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	/////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Seven), hwndButtonChose, NumbSeven);
	DestroyWindow(hwndButtonVictorinaPodskazki[6]);
	break;
case 26: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter ++ ;
		MessageBox(hWnd, "Uncorrect:\nNope\n2", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[6]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[6]);
	}
	break;
}
}
/////////////////////////////////
//Eight Guestion 
case 7: {
	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
/////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[7] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)27,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	/////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 850, cyChar *(5) + 96,
		116 * cxChar+1, ((5) * cyChar / 2) + 96);
	DestroyWindow(hwndButton_Victorina_Guestion[7]);
	//////////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[8]);
	}
	//////////////////////////////////////////
	if (counterGameGG <= 7) {

		hwndButton_Victorina_Guestion[8] = CreateWindow("BUTTON", "Ninth_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			1025,         // starting x position 
			160,         // starting y position 
			200,        // button width 
			29,        // button height 
			hWnd,       // parent window 
			(HMENU)8,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	/////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Eight), hwndButtonChose, NumbEight);
	DestroyWindow(hwndButtonVictorinaPodskazki[7]);
	break;
case 27: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nNope\nТумак", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[7]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[7]);
	}
	break;
}
}
/////////////////////////////////
//Nine Guestion
case 8: {

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
/////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[8] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)28,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	//////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 900, cyChar *(5) + 96,
		123 * cxChar + 2, ((5) * cyChar / 2) + 96);
	DestroyWindow(hwndButton_Victorina_Guestion[8]);
	/////////////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[8]);
	}
	/////////////////////////////////////////////
	if (counterGameGG <= 8) {

		hwndButton_Victorina_Guestion[9] = CreateWindow("BUTTON", "Tenth_Guestion",
			WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
			1025,         // starting x position 
			200,         // starting y position 
			200,        // button width 
			29,        // button height 
			hWnd,       // parent window 
			(HMENU)9,       // No menu 
			hInstance,
			//(HINSTANCE)GetWindowLong(hWnd,NULL),
			NULL);
	}
	/////////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Nine), hwndButtonChose, NumbNine);
	DestroyWindow(hwndButtonVictorinaPodskazki[8]);
	break;
case 28: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nЗащитник\nПолузащитник", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[8]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[8]);
	}
	break;
}
}
//////////////////////////
//Ten Guestion 
case 9: {

	hdc = GetDC(hWnd);
	GetTextMetrics(hdc, &tm);
	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight + tm.tmExternalLeading;
////////////////////////////////////////////////////
	hwndButtonVictorinaPodskazki[9] = CreateWindow("BUTTON", "Подсказка",
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP | BS_PUSHBUTTON,
		671,         // starting x position 
		250,         // starting y position 
		100,        // button width 
		50,        // button height 
		hWnd,       // parent window 
		(HMENU)29,
		hInstance,
		//(HINSTANCE)GetWindowLong(hWnd, NULL),
		NULL);
	//////////////////////////////////////////////////
	B = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, B);
	b[0] = Rectangle(hdc,
		cxChar + 950, cyChar *(5) + 96,
		130 * cxChar + 3, ((5) * cyChar / 2) + 96);
	DestroyWindow(hwndButton_Victorina_Guestion[9]);
	////////////////////////////////////////
	if (counter >= 1) {
		DestroyWindow(hwndButtonVictorinaPodskazki[9]);
	}
	/////////////////////////////////////////
	DialogBox(hInst, MAKEINTRESOURCE(IDD_Ten), hwndButtonChose, NumbTen);
	DestroyWindow(hwndButtonVictorinaPodskazki[9]);
	break;
	/////////////////////////////////////////////////////
case 29: {
	if (MessageBox(hWnd, "Хотите использовать подсказку ?Uncorrect:", "", MB_YESNO) == IDYES) {
		counter++;
		MessageBox(hWnd, "Uncorrect:\nNope\nПтица", "Answer", MB_OK);
		DestroyWindow(hwndButtonVictorinaPodskazki[9]);

	}
	else {
		DestroyWindow(hwndButtonVictorinaPodskazki[9]);
	}
	break;
}

}

break;
}//end of switch
 
////////////////////////////////////
break;
}//end of command

	case WM_PAINT:
        {
            
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
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

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK FistGuestion(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

    UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if (LOWORD(wParam) == Ansver1_for_Fist_Guestion) {
		
			MessageBox(hWnd, "Correct", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 48,
					102 * cxChar, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 48,
					102 * cxChar, ((5) * cyChar / 2) + 48);
		
			CountWin++;
			counterGameGG++;
				
	}
			
//////////////////////////////////////////////

			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver2_for_Fist_Guestion ||
			(LOWORD(wParam) == Ansver3_for_Fist_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Fist_Guestion) ){

           MessageBox(hWnd, "uncorect", "Answer", MB_OK);	
			if (

				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 48,
					102 * cxChar, ((5) * cyChar / 2) + 48))
			{
				R = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, R);
				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 48,
					102 * cxChar, ((5) * cyChar / 2) + 48);
				
				count++;
				counterGameGG++;
			}

/////////////////////////////////////////////////////////////////////	
				  if (count >= 3) {
					 
						  EndDialog(hDlg, LOWORD(wParam));
					  //////////////////////////////////////////////
					  for (int i = 0; i < 10; i++) {
						  DestroyWindow(hwndButton_Victorina_Guestion[i]);
					  }
					  ////////////////////////////////////
					  for (int p = 0; p < 10; p++) {
						  DestroyWindow(hwndButtonVictorinaPodskazki[p]);
					  }
					  //////////////////////////////////////////////////////
					  InvalidateRect(hWnd, NULL, TRUE);

					  PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
					  if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

						  PlaySound(NULL, NULL, SND_SYSTEM);
					  }
					  count = 0;
					  counterGameGG=0;
					
				  };
				  ////////////////////////
				 
///////////////////////////////////////////////////////////////////////		
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
	break;
///////////////////////////////////////////////////////////////////////
	
    
   }
    return (INT_PTR)FALSE;
}
///////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbTwo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////


		if ((LOWORD(wParam) == Ansver2_for_Second_Guestion)==TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 48,
					109 * cxChar, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 48,
					109 * cxChar, ((5) * cyChar / 2) + 48);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////
		
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Second_Guestion ||
			(LOWORD(wParam) == Ansver3_for_Second_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Second_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 48,
					109 * cxChar, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 48,
					109 * cxChar, ((5) * cyChar / 2) + 48);
				counterGameGG++;
				 count++;
			}
		
			
				
			///////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				////////////////////////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				/////////////////////////////////////////
				InvalidateRect(hWnd, NULL, TRUE);
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
				
			};
		
			/////////////////////////////////////////

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор

		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;
}
////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbTree(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == Ansver3_for_Thrid_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 48,
					116 * cxChar+1, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 48,
					116 * cxChar+1, ((5) * cyChar / 2) + 48);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////
			
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Thrid_Guestion ||
			(LOWORD(wParam) == Ansver2_for_Thrid_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Thrid_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 48,
					116 * cxChar+1, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 48,
					116 * cxChar+1, ((5) * cyChar / 2) + 48);
				 count++;
				 counterGameGG++;
			}
		
			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				//////////////////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				//////////////////////////////////////////////
				InvalidateRect(hWnd, NULL, TRUE);
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
			
			};
			//////////////////////////////////////////////////////
			///////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;
}
////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbFour(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == Ansver2_for_Fourth_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 48,
					123 * cxChar + 2, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 48,
					123 * cxChar+2, ((5) * cyChar / 2) + 48);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////
	
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Fourth_Guestion ||
			(LOWORD(wParam) == Ansver3_for_Fourth_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Fourth_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 48,
					123 * cxChar + 2, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 48,
					123 * cxChar + 2, ((5) * cyChar / 2) + 48);
				count++;
				counterGameGG++;
			}
		
			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				/////////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				/////////////////////////////////////
				InvalidateRect(hWnd, NULL, TRUE);

				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
			
			};
			////////////////////////////////////////////////////
			
			/////////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
/////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbFive(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == Ansver3_for_Five_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 48,
					130 * cxChar + 3, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 48,
					130 * cxChar + 3, ((5) * cyChar / 2) + 48);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////
	
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Five_Guestion ||
			(LOWORD(wParam) == Ansver2_for_Five_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Five_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 48,
					130 * cxChar + 3, ((5) * cyChar / 2) + 48))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 48,
					130 * cxChar + 3, ((5) * cyChar / 2) + 48);
				count++;
				counterGameGG++;
			}
		
			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				////////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				/////////////////////////////////////
				InvalidateRect(hWnd, NULL, TRUE);

				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
			
			};
///////////////////////////////////////////////////
			
			//////////////////////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
////////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbSix(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == NOPE_for_Six_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 96,
					102 * cxChar, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 96,
					102 * cxChar , ((5) * cyChar / 2) + 96);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////

	
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Six_Guestion ||
			(LOWORD(wParam) == Ansver2_for_Six_Guestion) ||
			(LOWORD(wParam) == Ansver3_for_Six_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 96,
					102 * cxChar , ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 750, cyChar *(5) + 96,
					102 * cxChar , ((5) * cyChar / 2) + 96);
				count++;
				counterGameGG++;
			}

			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				////////////////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				///////////////////////////////////////////
				InvalidateRect(hWnd, NULL, TRUE);
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
			
			};
			/////////////////////////////////////////////////////
			
			//////////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
/////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbSeven(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == Ansver3_for_Seven_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 96,
					109 * cxChar, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 96,
					109 * cxChar, ((5) * cyChar / 2) + 96);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////

			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Seven_Guestion ||
			(LOWORD(wParam) == Ansver2_for_Seven_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Seven_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 96,
					109 * cxChar, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 800, cyChar *(5) + 96,
					109 * cxChar, ((5) * cyChar / 2) + 96);
				count++;
				counterGameGG++;
			}
	
			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				/////////////////////////////

				InvalidateRect(hWnd, NULL, TRUE);

				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
				
			};
			///////////////////////////////////////////
			
			///////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbEight(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == Ansver2_for_Eight_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 96,
					116 * cxChar+1, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 96,
					116 * cxChar+1, ((5) * cyChar / 2) + 96);
				counterGameGG++;
				CountWin++;
			}
			
			/////////////////////////////
		
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Eight_Guestion ||
			(LOWORD(wParam) == Ansver3_for_Eight_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Eight_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 96,
					116 * cxChar+1, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 850, cyChar *(5) + 96,
					116 * cxChar+1, ((5) * cyChar / 2) + 96);
				count++;
				counterGameGG++;
			}
			///////////////////////////////////////////////////////////////////
			
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				//////////////////
				InvalidateRect(hWnd, NULL, TRUE);

				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				count = 0;
				counterGameGG = 0;
			
			};
			//////////////////////////////////
			
			/////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbNine(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == NOPE_for_Nine_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 96,
					123 * cxChar + 2, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 96,
					123 * cxChar + 2, ((5) * cyChar / 2) + 96);
				counterGameGG++;
				CountWin++;
			}
			//////////////////////////////////////////////
		
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Nine_Guestion ||
			(LOWORD(wParam) == Ansver2_for_Nine_Guestion) ||
			(LOWORD(wParam) == Ansver3_for_Nine_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 96,
					123 * cxChar + 2, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 900, cyChar *(5) + 96,
					123 * cxChar + 2, ((5) * cyChar / 2) + 96);
				count++;
				counterGameGG++;
			}

			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				///////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				///////////////////////////////
				InvalidateRect(hWnd, NULL, TRUE);
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {

					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				
				count = 0;
				counterGameGG = 0;
				
			};
//////////////////////////////////////
			
			///////////////////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK NumbTen(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		////////////////////////////////////////////////////////////////////////
		if ((LOWORD(wParam) == Ansver2_for_Ten_Guestion) == TRUE) {

			MessageBox(hWnd, "Correct", "Answer", MB_OK);
			if (

				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 96,
					130 * cxChar + 3, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 96,
					130 * cxChar + 3, ((5) * cyChar / 2) + 96);
			
				CountWin++;
				counterGameGG++;
			}
			///////////////////////////////////////////
			if ( CountWin == 10) {
				EndDialog(hDlg, LOWORD(wParam));
			
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}

				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\perfectresult.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "PERFECT RESULT", "Win", MB_OK) == IDOK) {
				
					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				InvalidateRect(hWnd, NULL, TRUE);
				counterGameGG = 0;
		
			};
			////////////////////////////
			if (CountWin == 8) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\winresult.wav"), NULL, SND_LOOP | SND_ASYNC);
				if(MessageBox(hWnd, "YOU_WIN", "Win", MB_OK)==IDOK){
					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				InvalidateRect(hWnd, NULL, TRUE);
				counterGameGG = 0;
			};
			if (CountWin == 9) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\winresult.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU_WIN", "Win", MB_OK) == IDOK) {
					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				InvalidateRect(hWnd, NULL, TRUE);
				counterGameGG = 0;
			}
			//////////////////////////////////////////////
		
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}//правильный выбор
		if (LOWORD(wParam) == Ansver1_for_Ten_Guestion ||
			(LOWORD(wParam) == Ansver3_for_Ten_Guestion) ||
			(LOWORD(wParam) == NOPE_for_Ten_Guestion) == TRUE) {

			MessageBox(hWnd, "uncorect", "Answer", MB_OK);

			if (

				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 96,
					130 * cxChar + 3, ((5) * cyChar / 2) + 96))
			{
				G = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, G);
				b[0] = Rectangle(hdc,
					cxChar + 950, cyChar *(5) + 96,
					130 * cxChar + 3, ((5) * cyChar / 2) + 96);
				count++;
				counterGameGG++;
			}
			///////////////////////////////////////////////////////////////////
		
			if (CountWin == 8) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\winresult.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU_WIN", "Win", MB_OK) == IDOK) {
					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				InvalidateRect(hWnd, NULL, TRUE);
				counterGameGG = 0;
			};
			///////////////////////////////
			if (CountWin == 9) {
				EndDialog(hDlg, LOWORD(wParam));
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\winresult.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU_WIN", "Win", MB_OK) == IDOK) {
					PlaySound(NULL, NULL, SND_SYSTEM);
				}
				InvalidateRect(hWnd, NULL, TRUE);
				counterGameGG = 0;
			}
			/////////////////////////////////////////////////////////////////////	
			if (count >= 3) {

				EndDialog(hDlg, LOWORD(wParam));

				for (int i = 0; i < 10; i++) {
					DestroyWindow(hwndButton_Victorina_Guestion[i]);
				}
				///////////////////////////////
				for (int p = 0; p < 10; p++) {
					DestroyWindow(hwndButtonVictorinaPodskazki[p]);
				}
				InvalidateRect(hWnd, NULL, TRUE);

				PlaySound(TEXT("C:\\Users\\Пользователь\\Documents\\Visual Studio 2015\\Projects\\Victorina\\lose.wav"), NULL, SND_LOOP | SND_ASYNC);
				if (MessageBox(hWnd, "YOU LOSE", "Sory", MB_OK) == IDOK) {
				
					PlaySound(NULL, NULL, SND_SYSTEM);
		
				}
				count = 0;
				counterGameGG = 0;
			
			};
			///////////////////////////////////////////
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}//неправильный выбор
		break;
		///////////////////////////////////////////////////////////////////////


	}
	return (INT_PTR)FALSE;

}
/////////////////////////////////////////////////////////////////

