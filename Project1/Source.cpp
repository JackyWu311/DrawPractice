// Name: 吳明壎
// Date: March 2, 2017
// Last Update: March 2, 2017
// Problem statement: 畫三角形

#include<iostream>
#include<string>
using namespace std;

//封裝繪圖板，最大100*100
struct Panel {
	int Width;
	int Height;
	char Canvas[100][100];
};

//初始化繪圖板(全部設為0)
void initial(char Canvas[100][100]) {
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			Canvas[i][j] = 0;
		}
	}
}

//列印繪圖板( 1 印出 X ， 0 印出 * )
void print(char Canvas[100][100], int x, int y) {
	for (int i = 0; i<y; i++) {
		for (int j = 0; j<x; j++) {
			if (Canvas[j][i] == 1) {
				cout << "X";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

//畫正方形
void DrawSquare(Panel &panel, int x, int y, int width) {
	if (x+width > panel.Width || y+width > panel.Height) {
		cout << "Out of range." << endl;
	}
	else {
		for (int i = y; i < y + width; i++) {
			for (int j = x; j < x + width; j++) {
				panel.Canvas[j][i] = 1;
			}
		}
		print(panel.Canvas, panel.Height, panel.Width);
	}
}

//畫三角形
void DrawTriangle(Panel &panel, int x, int y, int width, string Direction) {
	//RD
	if (Direction == "RD") {
		if (x + width > panel.Width || y + width > panel.Height) {
			cout << "Out of range." << endl;
		}
		else {
			int widthx = width;
			for (int i = y; i <= y + width - 1; i++) {
				for (int j = x; j <= x + widthx - 1; j++) {
					panel.Canvas[j][i] = 1;
				}
				widthx--;
			}
			print(panel.Canvas, panel.Height, panel.Width);
		}
	}
	//RU
	else if (Direction == "RU") {
		if (x + width > panel.Width || y - width < 0) {
			cout << "Out of range." << endl;
		}
		else {
			int count = 1;
			for (int i = y - width + 1; i <= y; i++) {
				for (int j = x; j <= count + x-1; j++) {
					panel.Canvas[j][i] = 1;
				}
				count++;
			}
			print(panel.Canvas, panel.Height, panel.Width);
		}
	}
	//LD
	else if (Direction=="LD") {
		if (x - width<0 || y + width>panel.Height) {
			cout << "Out of range." << endl;
		}
		else {
			int count = width;
			for (int i = y; i <= y + width - 1; i++) {
				for (int j = x - count + 1; j <= x; j++) {
					panel.Canvas[j][i] = 1;
				}
				count--;
			}
			print(panel.Canvas, panel.Height, panel.Width);
		}
	}
	//LU
	else if (Direction=="LU") {
		if (x - width < 0 || y - width < 0) {
			cout << "Out of range." << endl;
		}
		else {
			int count = 0;
			for (int i = y - width + 1; i <= y; i++) {
				for (int j = x - count; j <= x; j++) {
					panel.Canvas[j][i] = 1;
				}
				count++;
			}
		}
		print(panel.Canvas, panel.Height, panel.Width);
	}
	else
	{
		cout << "請輸入正確格式!!" << endl;
	}
}

//畫直線
void DrawLine(Panel &panel, int x1, int y1, int x2, int y2) { 
	if (x1 > panel.Width || y1 > panel.Height || x2 > panel.Width || y2 > panel.Height) {
		cout << "Out of range." << endl;
	}
	else {
		if (x1 == x2) {			//X座標相等，再判斷Y座標的大小
			if (y1 >= y2) {		
				for (int i = y2; i <= y1; i++) {
					panel.Canvas[x1][i] = 1;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
			else {
				for (int i = y1; i <= y2; i++) {
					panel.Canvas[x1][i] = 1;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
		}
		else if (x1>x2) {		//X座標不相等，X1>X2，再判斷Y座標的大小
			if(y1 > y2) {
				for (int i = x2; i <= x1; i++) {
					panel.Canvas[i][y2] = 1;
					y2++;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
			else if (y1 = y2) {
				for (int i = x2; i <= x1; i++) {
					panel.Canvas[i][y1] = 1;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
			else {
				for (int i = y2; i >=y1 ; i--) {
					panel.Canvas[x2][i] = 1;
					x2++;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
		}
		else {			//X座標不相等，X1<X2，再判斷Y座標的大小
			if (y1 > y2) {
				for (int i = x1; i <= x2; i++) {
					panel.Canvas[i][y1] = 1;
					y1--;
				}
				print(panel.Canvas, panel.Height, panel.Width);

			}
			else if (y1 == y2) {
				for (int i = x1; i <= x2; i++) {
					panel.Canvas[i][y1] = 1;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
			else{
				for (int i = x1; i <= x2; i++) {
					panel.Canvas[i][y1] = 1;
					y1++;
				}
				print(panel.Canvas, panel.Height, panel.Width);
			}
		}
	}
}

void main() {
	Panel panel;
	initial(panel.Canvas);
	string TYPE,Direction;
	cin >> panel.Height >> panel.Width >> TYPE;
	while (TYPE != "EXIT")
	{
		char Type = TYPE[0];
		switch (Type)
		{
		case 'S':		//S為實心正方形
			int width, x, y;
			cin >> width >> x >> y;
			DrawSquare(panel, x, y, width);
			break;
		case 'T':
			int widthT, xT, yT;
			cin >> widthT >> xT >> yT >> Direction;
			DrawTriangle(panel,xT,yT,widthT,Direction);
			break;
		case 'L':		//L為直線或45度斜線
			int  x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			DrawLine(panel, x1, y1, x2, y2);
			break;
		}
		cin >> TYPE;
	}
	system("pause");
}