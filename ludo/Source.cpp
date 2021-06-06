#include <cmath>
#include <iostream>
#include<fstream>
#include <string>
#include <time.h>
#include <conio.h>
#include "mygraphics.h"
#include "myconsole.h"
using namespace std;
int board[10][10];
COLORREF black = RGB(0, 0, 0);
COLORREF white = RGB(255, 255, 255);
COLORREF random = RGB(0, 0, 0);
COLORREF random1 = RGB(255, 255, 0);
COLORREF blue = RGB(255, 0, 0);
COLORREF green = RGB(0, 255, 0);
void menu();
int y3 = 0;
int y4 = 0;
int n[5][4];
int l[2][4];
bool qr=true;
int objects[2][5] =  {0} ;
void shield(int x,int y)
{
	x = x + 10;
	y = y + 10;
	myLine(x, y, x + 20, y-10, white);
	myLine(x + 20, y - 10, x + 40, y, white);
	myLine(x, y, x + 20, y + 20, white);
	myLine(x + 20, y + 20, x + 40, y,white);
}
void player1(COLORREF blue = RGB(255, 0, 0),int x = 65 * 11, int y = 65 * 10)
{
	x = x + 20,y=y+10;
	myEllipse(x, y, x + 15, y + 10, black, blue);
	myEllipse(x - 10, y + 10, x + 20, y + 35, black, blue);
	myEllipse(x + 20, y + 10, x + 30, y + 20, black, blue);
	myEllipse(x - 10, y + 12, x - 15, y + 18, black, blue);
	myEllipse(x + 10, y + 30, x + 25, y + 40, black, blue);
	myEllipse(x - 7, y + 30, x - 15, y + 40, black, blue);
}
void player2(COLORREF green= RGB(0,0,255),int x = 65*12,int y = 65*10)
{
	x = x + 20, y = y + 10;
	myEllipse(x, y, x + 15, y + 10, black, green);
	myEllipse(x - 10, y + 10, x + 20, y + 35, black, green);
	myEllipse(x + 20, y + 10, x + 30, y + 20, black, green);
	myEllipse(x - 10, y + 12, x - 15, y + 18, black, green);
	myEllipse(x + 10, y + 30, x + 25, y + 40, black, green);
	myEllipse(x - 7, y + 30, x - 15, y + 40, black, green);
}
void dice()
{
	myRect(700, 200, 790, 290, random, random1);
}
void gladder(int x, int y, int x1, int y1)
{
	x = x + 10;
	y1 = y1 + 20;
	for (int i = x,j=y; i < x1&&j<y1;i++,j++)
		mySetPixel(i,j,black);
	for (int r = y,g=x; r < y1&&g<x1; r +=10,g+=10)
		myLine(g, r, g + 20, r-10, black);
	for (int i = x+30, j = y; i < x1+30&&j < y1; i++, j++)
		mySetPixel(i, j, black);
}
void ladder(int a[][4], int row, int col = 4)
{
	for (int i = 0; i < row; i++)
	{
		gladder(a[i][0], a[i][1]+10, a[i][2], a[i][3]);
	}
}
void sword(int x1, int y1)
{
	myLine(x1, y1, x1 + 5, y1 + 10, random1);
	for (int q = 0; q < 10; q++)
		myLine(x1 + 5, y1 + 5 + q, x1 + 5, y1 + 5, RGB(255, 0, 255));
	myLine(x1, y1 + 10, x1 + 20, y1 + 10, random1);
	for (int t = 0; t < 10; t++)
		myLine(x1 + 5 + t, y1 + 10, x1 + 40, y1 + 40, white);
}
void numbers(int number, int x, int y, int ht)
{
	switch (number)
	{
	case 0:
		myEllipse(x, y, x + ht, y + ht, random, random);
		break;

	case 1:
		myLine(x, y, x, y + ht, random);
		break;

	case 2:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + ht, y + ht / 2, random);
		myLine(x + ht, y + ht / 2, x, y + ht / 2, random);
		myLine(x, y + ht / 2, x, y + ht / 2 + 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		break;

	case 3:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + ht, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x + ht, y + 4 * ht / 5 + 2, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		break;

	case 4:
		myLine(x, y, x, y + 3 * ht / 5, random);
		myLine(x, y + 3 * ht / 5, x + ht, y + 3 * ht / 5, random);
		myLine(x + 2 * ht / 5, y + ht / 4, x + 2 * ht / 5, y + 4 * ht / 5 + 3, random);
		break;

	case 5:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x + ht, y + 4 * ht / 5, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		break;

	case 6:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht + ht / 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		myLine(x + ht, y + ht + ht / 5, x + ht, y + ht / 2, random);
		myLine(x + ht, y + ht / 2, x, y + ht / 2, random);
		break;

	case 7:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + 4 * ht / 5, y + ht, random);
		break;

	case 8:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht + ht / 4, random);
		myLine(x + ht, y, x + ht, y + ht + ht / 4, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		myLine(x, y + 3 * ht / 5, x + ht, y + 3 + ht / 4, random);
		break;

	case 9:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht / 2, random);
		myLine(x + ht, y, x + ht, y + ht + ht / 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		myLine(x, y + ht / 2, x + ht, y + 3 + ht / 5, random);
		break;
	}
}
int DiceNo()
{
	srand((unsigned)time(NULL));
	int no;
	no = rand() % 6 + 1;
	int x = 730, y = 230;
	numbers(no, x, y,30);
	return no;
}
void counting()
{
	for (int i = 9,k=0; i >= 0; i--,k++)
		for (int j = 9,l=0; j>=0; j--,l++)
		{
			int x1 = 30 + l * 65, y1 = 30 + k * 65;
			numbers(i, x1 + 30, y1 + 10, 10);
			numbers(j, x1 + 45, y1 + 10, 10);
		}
}
void snake(int x, int y)
{
	myEllipse(x, y, 40 + x, y + 40, black, white); //face
	myEllipse(x + 12, y + 12, x + 16, y + 16, black, black); //eye
	myEllipse(x + 20, y + 12, x + 24, y + 16, black, black); //eye
	myLine(x + 10, y + 28, x + 30, y + 35, black); //lips
}
void gsnake(int s[][4], int row, int col,int y)
{
	for (int i = 0; i < y; i++)
		{
			snake(s[i][0], s[i][1]);
			myLine(s[i][0] + 20, s[i][1] + 40, s[i][2] + 10, s[i][3] + 20, white);
			myLine(s[i][0] + 23, s[i][1] + 40, s[i][2] + 10, s[i][3] + 20, black);
			myLine(s[i][0] + 25, s[i][1] + 40, s[i][2] + 10, s[i][3] + 20, black);
			myLine(s[i][0] + 27, s[i][1] + 40, s[i][2] + 10, s[i][3] + 20, white);
		}
}
void gcoin(int x,int y)
{
	myEllipse(x+ 4, y + 12, x+30, y+40, RGB(0, 255, 255), RGB(255, 255, 0));
	myEllipse(x + 4, y + 5,x+30, y+33, RGB(0, 255, 255), RGB(255, 255, 0));
}
void scoin(int x, int y)
{
	myEllipse(x + 4, y + 12, x + 30, y + 40, RGB(0, 25, 255), RGB(240, 240, 240));
	myEllipse(x + 4, y + 5, x + 30, y + 33, RGB(0, 25, 255), RGB(240, 240, 240));
}
void diamond(int x, int y)
{
	for (int i = 0; i < 40; i++)
		for (int j = 10; j < 20; j++)
			myLine(x + i / 5, y + j / 2, x + i / 2 + 10, y + j + 10, RGB(255, 255, 255));
}
void draw(int board[][10], bool& qr)
{
	COLORREF g = RGB(0, 255, 0), p = RGB(255, 0, 255), s = RGB(120, 255, 255), b = RGB(100, 100, 255), r = RGB(255, 0, 0), o = RGB(255, 165, 0), y = RGB(255, 255, 0), w = RGB(255, 255, 255);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			int x1 = 30 + j * 65, y1 = 30 + i * 65;
			int x2 = 100 + j * 65, y2 = 100 + i * 65;
			switch (board[i][j])
			{
			case 0:
				myRect(x1, y1, x2, y2, w, g);
				sword(x1 + 5, y1 + 5);
				break;
			case 1:
				myRect(x1, y1, x2, y2, w, p);
				gcoin(x1, y1);
				break;
			case 2:
				myRect(x1, y1, x2, y2, w, s);
				scoin(x1, y1);
			case 3:
				myRect(x1, y1, x2, y2, w, b);
				if (x1 > 60)
				{
					for (int k = 4; k < 48; k += 6)
						myLine(x1 + k, y1 + 1, x1 + k, y1 + 58, RGB(150, 150, 150));
				}
				break;
			case 4:
				myRect(x1, y1, x2, y2, w, r);
				diamond(x1 + 10, y1 + 20);
				break;
			case 5:
				myRect(x1, y1, x2, y2, w, o);
				if (qr)
				{
					if (!(y4 == 2) && y1 > 180 && x1 > 120 && x1 < 460)
					{
						bool c = 1;
						int p1 = 0;
						l[y4][p1] = x1;
						p1++;
						l[y4][p1] = y1;
						p1++;
						l[y4][p1] = x1 + ((rand() % 3) + 1) * 65;
						for (int i = 0; i < 5; i++)
							if (l[y4][p1] == n[i][p1])
								c = 0;
						if (c)
							p1++;
						else
						{
							l[y4][p1] = x1 + ((rand() % 3) + 1) * 65;
							p1++;
							for (int i = 0; i < 5; i++)
								if (l[y4][p1] == n[i][p1])
									c = 0;
							if (c)
								p1++;
							else
							{
								l[y4][p1] = x1 + ((rand() % 3) + 1) * 65;
								p1++;
							}
						}
						l[y4][p1] = y1 + ((rand() % 2) + 1) * 65;
						y4++;
					}
				}
				break;
			case 6:
				myRect(x1, y1, x2, y2, w, y);
				if (qr)
				{
					if (!(y3 == 5) && x1>120 && x1 < 420 && y1 < 420)
					{
						int p1 = 0;
						n[y3][p1] = x1;
						p1++;
						n[y3][p1] = y1;
						p1++;
						n[y3][p1] = x1 + ((rand() % 2) + 1) * 65 + 30;
						{int c = 0;
						for (int i = 0; i < 5; i++)
							if (n[y3][p1] == l[i][p1])
								c = 0;
						if (c)
							p1++;
						else
						{
							n[y3][p1] = x1 + ((rand() % 3) + 1) * 65 + 30;
							for (int i = 0; i < 5; i++)
								if (n[y3][p1] == l[i][p1])
									c = 0;
							if (c)
								p1++;
							else
							{
								n[y3][p1] = x1 + ((rand() % 3) + 1) * 65;
								p1++;
							}
						}
						n[y3][p1] = y1 + ((rand() % 3) + 1) * 65;
						y3++;
						}
					}
					break;
			case 7:
				myRect(x1, y1, x2, y2, w, g);
				shield(x1, y1);
				break;
				}
			}
		}
		}

		gsnake(n, 5, 4, y3);
		ladder(l, y4);
		counting();
		qr = false; 
}
int yes(int board[][10], int o, int y, int obj[][5], bool a, bool b = 0,bool p=1)
{
	int c = 0;
	int q;
	if (!a)
		q = 0;
	else
		q = 1;
	int i = (o - 30) / 65;
	int j = (y - 30) / 65;
	if (b)
	{
		switch (board[i][j])
		{
		case 0:
			myRect(o, y, o + 65, y + 65, white, green);
			obj[q][0] += 10;
			c=1;
			break;
		case 1:
			myRect(o, y, o + 65, y + 65, white, green);
			obj[q][1] += 10;
			c = 1;
			break;
		case 2:
			myRect(o, y, o + 65, y + 65, white, green);
			obj[q][2] += 5;
			c = 1;
			break;
		case 3:
			obj[q][3] -= 20;
			c = 1;
			p = 0;
			break;
		case 4:
			obj[q][4] += 50;
			myRect(o, y, o + 65, y + 65, white, green);
			c = 1;
			break;
		case 7:
			myRect(o, y, o + 65, y + 65, white, green);
			obj[q][5] += 20;
			c = 1;
			break;
		}
		if (c == 1)
		{
			myRect(65 * 11, 400, 65 * 14, 500, green, green);
			if (q==0)
			myDrawText(65 * 11, 400, 34, "score of player 1:", white, black);
			else
				myDrawText(65 * 11, 400, 34, "score of player 2:", white, black);
			int number = obj[q][0] + obj[q][1] + obj[q][2] + obj[q][3];
			int y = 34;
			if (!(number > 0))
			{
				number = (-number);
				if (q==1)
				myDrawText(65 * 11, 400, 34, "score of player 2: -", white, black);
				else
					myDrawText(65 * 11, 400, 34, "score of player 1: -", white, black);
			}
			if (number == 0)
			{
				numbers(i, 65 * 14 - y, 420, 20);
				number = -1;
			}
			while (number >0)
			{
				int i = number % 10;
				numbers(i,65*14-y,420,20);
				number = number / 10;
				y = y + y;
			}
		}
	}
	return p;
}
int play1(int boad[][10], int n[][4], int l[][4], int& y1,bool&p, int x1 = 9 * 65 + 30)
{
	int bq;
	int c = 0;
	int q = 9* 65+30;
	int y = y1;
	int o;
	bool h;
	myDrawText(700, 100, 30, "press 1 to roll", white, random);
	cin >> h;
	draw(boad, qr);
	player2(black, x1 + 65, y);
    dice();
	int r= DiceNo();
	o = x1 - ((r-1) * 65);
	if (o >= 30)
	{
		for (int i = 0; i < 5; i++)
			if (o == n[i][0] && y == n[i][1])
			{
				myDrawText(750, 100, 23, "if you want to kill snake press 1", black, white);
				cin >> bq;
				if (!(bq > 0 && c == 0))
				{
					o = n[i][2], y = n[i][3];
					i = 5;
					player1(RGB(255, 0, 0), o, y);
					for (int i = 0; i < 5; i++)
						if (o == n[i][0] && y == n[i][1])
						{
							myDrawText(750, 100, 23, "if you want to kill snake press 1", black, white);
							cin >> bq;
							if (!(bq > 0 && c == 0))
							{
								o = n[i][2], y = n[i][3];
								i = 5;
								player1(RGB(255, 0, 0), o, y);
								y1 = y;
								return o - 65;
							}
						}

					return o - 65;
				}
			}
		for (int i = 0; i < 2; i++)
				if (o == l[i][2] && y == l[i][3])
				{

					o = l[i][0], y = l[i][1];
				
					i = 2;
					player1(RGB(255, 0, 0), o, y);
					y1 = y;
					return o - 65;
				}
		player1(RGB(255, 0, 0), o, y);
		myDrawText(400, 0, 34, "do you want to pick this object enter 1", white, black);
		bool c;
		cin >> c;
		p=yes(boad, o, y, objects, 0, c,p);
		y1 = y;
	}
	else
	{
		int u=x1;
		int m=0;
		while (u >30)
		{
			u = u - 65;
			m++;
		}
		r = r - m;
			o = q - ((r - 1) * 65), y = y1 - 65;
			for (int i = 0; i < 5; i++)
				if (o == n[i][0] && y == n[i][1])
				{
					myDrawText(750, 100, 23, "if you want to kill snake press 1", black, white);
					cin >> bq;
					if (!(bq > 0 && c == 0))
					{
						o = n[i][2], y = n[i][3];
						i = 5;
						player1(RGB(255, 0, 0), o, y);
						y1 = y;
						yes(boad, o, y, objects, 0);
						return o - 65;
					}
				}
			for (int i = 0; i < 2; i++)
					if (o == l[i][2] && y == l[i][3])
					{

						o = l[i][0], y = l[i][1];

						i = 2;
						player1(RGB(255, 0, 0), o, y);
						yes(boad, o, y, objects, 0);
						y1 = y;
						return o - 65;
					}
		player1(RGB(255, 0, 0), o,y);
		myDrawText(400, 0, 34, "do you want to pick this object enter 1", white, black);
		bool c;
		cin >> c;
	p=	yes(boad, o, y, objects, 0, c,p);
		y1 = y;
		return o-65;
	}
	return o-65;
}
int play2(int boad[][10], int n[][4], int l[][4], int& y1,bool& p, int x1 = 9 * 65 + 30)
{
	int c = 0;
	bool bq = true;
	int q = 9 * 65 + 30;
	int y = y1;
	int o;
	bool h;
	myDrawText(700, 100, 30, "press 1 to roll", white, random);
	cin >> h;
	draw(boad, qr);
	player2(black, x1 + 65, y);
	dice();
	int r = DiceNo();
	player2(black);
	o = x1 - ((r - 1) * 65);
	if (o >= 30)
	{
		for (int i = 0; i < 5; i++)
		{
			if (o == n[i][0] && y == n[i][1])
			{
				myDrawText(750, 100, 23, "if you want to kill snake press 1", black, white);
				cin >> bq;
				if (!(bq>0&&c==0))
				{ 
				o = n[i][2], y = n[i][3];
				i = 5;
				player2(RGB(0, 0, 255), o, y);
				for (int i = 0; i < 5; i++)
				{
					if (o == n[i][0] && y == n[i][1])
					{
						myDrawText(750, 100, 23, "if you want to kill snake press 1", black, white);
						cin >> bq;
						if (!(bq > 0 && c == 0))
							o = n[i][2], y = n[i][3];
						i = 5;
						player1(RGB(255, 0, 0), o, y);
						c++;
						y1 = y;
						return o - 65;
					}
					c++;
					y1 = y;
					return o - 65;
				}
				}
			}
		}
		for (int i = 0; i < 2; i++)
			if (o == l[i][2] && y == l[i][3])
			{

				o = l[i][0], y = l[i][1];

				i = 2;
				player2(RGB(0, 0, 255), o, y);
				yes(boad, o, y, objects, 1);
				y1 = y;
				return o - 65;
			}
		myDrawText(400, 0, 34, "do you want to pick this object enter 1", white, black);
		bool c;
		cin >> c;
		p=yes(boad, o, y, objects, 1, c,p);
		y1 = y;
		player2(RGB(0, 0, 255), o, y);
	}
	else
	{
		int u = x1;
		int m = 0;
		while (u >30)
		{
			u = u - 65;
			m++;
		}
		r = r - m;
		o = q - ((r - 1) * 65), y = y1 - 65;
		for (int i = 0; i < 5; i++)
		{
			if (o == n[i][0] && y == n[i][1])
			{
				myDrawText(750, 100, 23, "if you want to kill snake press 1", black, white);
				cin >> bq;
				if (!(bq> 0&&c==0))
					o = n[i][2], y = n[i][3];
					i = 5;
					player1(RGB(255, 0, 0), o, y);
					c++;
					y1 = y;
					return o - 65;	
			}
		}
		for (int i = 0; i < 2; i++)
			if (o == l[i][2] && y == l[i][3])
			{

				o = l[i][0], y = l[i][1];

				i = 2;
				player1(RGB(0, 0, 255), o, y);
				y1 = y;
				return o - 65;
			}
		player2(RGB(0, 0, 255), o, y);
		myDrawText(400, 0, 34, "do you want to pick this object enter 1", white, black);
		bool c;
		cin >> c;
		p=yes(boad, o, y, objects,1, c,p);
		y1 = y;
		return o - 65;
	}
	return o - 65;
}
void savegame(int x, int y, int x1, int y1,int y3,int y4)
{
	ofstream fout;
	fout.open("kami&&iffi.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fout << board[i][j] << " ";
		}
		fout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fout << n[i][j] << " ";
		}
		fout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fout << l[i][j] << " ";
		}
		fout << endl;
	}
	for (int i = 0; i < 2; i++)
	{		for (int j = 0; j < 5; j++)
		{
			fout << objects[i][j] << " ";
		}
	fout << endl;
}
		x = (x - 30) / 65;
		y = (y - 30) / 65;
		x1 = (x1 - 30) / 65;
		y1 = (y1 - 30) / 65;
		fout << x<<" ";
		fout << y<<" ";
		fout << x1<<" ";
		fout << y1<<" ";
		fout << y3 << " ";
		fout << y4 << " ";
		fout.close();
}
void savedgame()
{
	char ch;
	ifstream fin;
	fin.open("kami&&iffi.txt");
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			fin >> board[i][j];
		}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
		{
			fin >> n[i][j];
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			fin >> l[i][j];
		}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
		{
			fin >> objects[i][j];
		}
	int x, x1, y, y1;
	fin >> x;
	fin >> y;
	fin >> x1;
	fin >> y1;
	fin >> y3;
	fin >> y4;
	fin.close();
	qr = 0;
	int c4 = 0;
	int end=0;
	int c3 = 0;
	int c1 = 0;
	int c2 = 0;
	bool p1 = true;
	bool p2 = true;
	x = 30 + (x * 65);
	y = 30 + (y * 65);
	x1 = 30 + (x1 * 65);
	y1 = 30 + (y1 * 65);
	draw(board, qr);
	player1(RGB(255,0,0),y,x);
	player2(blue,y1,x1);
	system("cls");
	while (x >= 30 && x1 >= 30)
	{
		c3++;
		if (c3 == 7)
		{
			myDrawText(0, 600, 34, "to save game press any key in 1 second or wait", black, white);
			cin >> end;
		}
		if (end == 0)
		{
			if (p1)
			{
				myDrawText(65 * 11, 130, 30, "player 1 turn", white, black);
				y = play1(board, n, l, x, p1,y );
				system("cls");
			}
			else
			{
				c1++;
				myDrawText(65 * 11, 130, 30, "player 1 is not allowed yet", white, black);
				if (c1 >= 3)
					p1 = true;
			}
			if (p2)
			{
				myDrawText(65 * 11, 130, 30, "player 2 turn", white, black);
				y1 = play2(board,n, l, x1, p2, y1);
				system("cls");
			}
			else
			{
				c2++;
				myDrawText(65 * 11, 130, 30, "player 2 is not allowed yet", white, black);
				if (c2 >= 3)
					p2 = true;
			}
		}
		else
		{
			savegame(x,y,x1,y1,y3,y4);
			x = 0;
			c4 = 1;
		}
	}
	if (c4 == 0)
	{
		int sum1 = objects[0][0] + objects[0][1] + objects[0][2] + objects[0][3];
		int sum2 = objects[1][0] + objects[1][1] + objects[1][2] + objects[1][3];
		if (x <30 && sum1>sum2)
			myDrawTextWithFont(65 * 4, 65 * 4, 100, "player 1 won", white, random1);
		else if (x1<30 && sum2>sum1)
			myDrawTextWithFont(65 * 4, 65 * 4, 100, "player 2 won", white, black);
		else
			myDrawTextWithFont(65 * 4, 65 * 4, 100, "it is draw", white, black);
		cout << "the score of 1st player" << sum1;
		cout << "the score of 2nd player" << sum2;
		Sleep(1000);
	}
}
void go()
{
	srand((unsigned)time(NULL));	
	qr = true;
	int c5 = 0;
	int c3 = 0;
	int end=0;
	int c1 = 0;
	int c2 = 0;
	bool p1 = true;
	bool p2 = true;
	int x=9*65+30;
	int x1 = 9 * 65 + 30;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			
			board[i][j] = rand() %	8;
		}
	draw(board,qr);
	player1();
	player2();
	myDrawText(65 * 11, 130, 30, "player 1 turn", white, black);
	int y = play1(board, n, l, x,p1);
	myDrawText(65 * 11, 130, 30, "player 2 turn", white, black);
	int y1 = play2(board, n, l, x1,p2);
	system("cls");
	while (x >= 30 && x1 >= 30)
	{
		c3++;
		if (c3 == 7)
		{
			myDrawText(0, 600, 34, "to save game press any key in 1 second or wait", black, white);
			cin >> end;
			c3 = 0;
		}
		if (end==0)
		{
			if (p1)
			{
				myDrawText(65 * 11, 130, 30, "player 1 turn", white, black);
				y = play1(board, n, l, x, p1, y);
				system("cls");
			}
			else
			{
				c1++;
				myDrawText(65 * 11, 130, 30, "player 1 is not allowed yet", white, black);
				if (c1 >= 3)
					p1 = true;
			}
			if (p2)
			{
				myDrawText(65 * 11, 130, 30, "player 2 turn", white, black);
				y1 = play2(board, n, l, x1, p2, y1);
				system("cls");
			}
			else
			{
				c2++;
				myDrawText(65 * 11, 130, 30, "player 2 is not allowed yet", white, black);
				if (c2 >= 3)
					p2 = true;
			}
		}
		else
		{
			savegame(x,y,x1,y1,y3,y4);
			x = 0;
		}
	}
	int sum1 = objects[0][0] + objects[0][1] + objects[0][2] + objects[0][3];
	int sum2 = objects[1][0] + objects[1][1] + objects[1][2] + objects[1][3];
	if (x <30 && sum1>sum2)
		myDrawTextWithFont(65 * 4, 65 * 4, 100, "player 1 won", white, random1);
	else if (x1<30&&sum2>sum1)
		myDrawTextWithFont(65 * 4, 65 * 4, 100, "player 2 won", white, black);
	else
		myDrawTextWithFont(65 * 4, 65 * 4, 100, "it is draw", white, black);
		cout <<"the score of 1st player"<< sum1;
	cout << "the score of 2nd player" << sum2;
	menu();
}
void menu()
{
	
	int e;
	myEllipse(0, 0, 680, 650, green, blue);
	myDrawTextWithFont(100, 100, 50, "The Ludo", white, black);
	myDrawTextWithFont(100, 150, 30, "by iffat and kamran", white, black);
	myRect(200, 250, 600, 400, white, RGB(0, 255, 0));
	myDrawTextWithFont(220, 250, 40, "press 1 for new game", white, black);
	myDrawTextWithFont(220, 300, 40, "press 2 for saved game", white, black);
	myDrawTextWithFont(220, 350, 40, "press 0 for exit", white, black);
	cin >> e;
	if (e==1)
		go();
	else if (e==2)
		savedgame();
}
int main()
{
	menu();
	system("pause");
	return 0;
}