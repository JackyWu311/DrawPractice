// Name: �d����
// Date: March 2, 2017
// Last Update: March 2, 2017
// Problem statement: �e�T����

#include<iostream>
#include<string>
using namespace std;

//�ʸ�ø�ϪO�A�̤j100*100
struct Panel {
	int Width;
	int Height;
	char Canvas[100][100];
};

//��l��ø�ϪO(�����]��0)
void initial(char Canvas[100][100]) {
	for (int i = 0; i<100; i++) {
		for (int j = 0; j<100; j++) {
			Canvas[i][j] = 0;
		}
	}
}

//�C�Lø�ϪO( 1 �L�X X �A 0 �L�X * )
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

//�e�����
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

//�e�T����
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
		cout << "�п�J���T�榡!!" << endl;
	}
}

//�e���u
void DrawLine(Panel &panel, int x1, int y1, int x2, int y2) { 
	if (x1 > panel.Width || y1 > panel.Height || x2 > panel.Width || y2 > panel.Height) {
		cout << "Out of range." << endl;
	}
	else {
		if (x1 == x2) {			//X�y�Ь۵��A�A�P�_Y�y�Ъ��j�p
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
		else if (x1>x2) {		//X�y�Ф��۵��AX1>X2�A�A�P�_Y�y�Ъ��j�p
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
		else {			//X�y�Ф��۵��AX1<X2�A�A�P�_Y�y�Ъ��j�p
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
		case 'S':		//S����ߥ����
			int width, x, y;
			cin >> width >> x >> y;
			DrawSquare(panel, x, y, width);
			break;
		case 'T':
			int widthT, xT, yT;
			cin >> widthT >> xT >> yT >> Direction;
			DrawTriangle(panel,xT,yT,widthT,Direction);
			break;
		case 'L':		//L�����u��45�ױ׽u
			int  x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			DrawLine(panel, x1, y1, x2, y2);
			break;
		}
		cin >> TYPE;
	}
	system("pause");
}