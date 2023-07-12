#include <iostream>
#include "Consola.h"
#include<cstring>
using namespace std;
#include "Util.h"
#include "keycode.h"
#define MAP_X1 10
#define MAP_Y1 4
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#include "Model.h"
#include "pushpush.h"
#include "View.h"

int map1[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,4,1,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,0},
		{0,1,1,1,2,0,2,4,1,0},
		{0,1,4,0,2,5,1,1,1,0},
		{0,1,1,1,1,2,1,0,0,0},
		{0,0,0,0,1,4,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
};

int map1end = 4;

int map2[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0},
	{0,1,5,0,0,1,0,0,0,0},
	{0,1,0,2,2,1,0,1,1,1},
	{0,1,0,2,0,1,0,1,4,1},
	{0,1,1,1,0,1,1,1,4,1},
	{0,0,0,1,0,0,0,0,4,1},
	{0,0,1,0,0,0,1,0,0,1},
	{0,0,1,0,0,0,1,1,1,1},
	{0,0,1,1,1,1,1,0,0,0}
};
int map2end = 3;

int map3[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0},
	{0,1,4,0,0,1,0,0,0,0},
	{0,1,4,1,0,1,0,0,0,0},
	{0,1,0,0,2,1,1,1,0,0},
	{0,1,0,1,5,0,0,1,0,0},
	{0,1,0,0,2,0,0,1,0,0},
	{0,1,4,0,2,0,0,1,0,0},
	{0,1,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};
int map3end = 3;
int map4[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0},
	{0,1,1,0,5,1,1,1,0,0},
	{0,1,0,2,2,2,0,1,0,0},
	{0,1,0,1,0,0,0,1,0,0},
	{0,1,4,0,0,4,1,1,0,0},
	{0,1,0,1,0,0,1,0,0,0},
	{0,1,4,0,0,0,1,0,0,0},
	{0,1,1,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};
int map4end = 3;
int map5[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,1,1,1,0,5,1,0,0,0},
	{0,1,4,4,2,2,1,1,1,0},
	{0,1,0,0,2,0,0,0,1,0},
	{0,1,4,1,2,0,0,4,1,0},
	{0,1,0,0,0,0,1,1,1,0},
	{0,1,1,0,0,0,1,0,0,0},
	{0,0,1,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};
int map5end = 4;

//memcpy(map, mapData, sizeof(mapData));
//int crow, ccol;
const char* cellSymbol[] = { "  ", "▒▒", "■", "▣" ,"□", "★" };
void drawCell(int mapData[10][10],int col, int row) {
	int cell = mapData[row][col];
	textcolor((cell == 1) ? WHITE : LIGHTGREEN);
	gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
	puts(cellSymbol[cell]);
}

void drawMap(int mapData[10][10]) {
	system("cls");
	for (int row = 0; row < MAP_HEIGHT; row++)
		for (int col = 0; col < MAP_WIDTH; col++)
			drawCell( mapData, col, row);
}
/*
void findCharacter() {
	for (int row = 0; row < MAP_HEIGHT; row++)
		for (int col = 0; col < MAP_WIDTH; col++)
			if (mapData[row][col] == 5) {
				crow = row;
				ccol = col;
				cout << crow << ", " << ccol;
			}
}
*/
void drawCharacter(int x, int y) {
	textcolor(YELLOW);
	Util::xyputs((MAP_X1 + 1 + x) * 2, MAP_Y1 + 1 + y, "★");
}


int findbox(int mapData[10][10]) {
	int count = 0;
	for (int row = 0; row < MAP_HEIGHT; row++)
	{

		for (int col = 0; col < MAP_WIDTH; col++)
		{
			if (mapData[row][col] == 3)
			{
				count++;
			}
		}
	}
	return count;
}
int tempmap[10][10];

void game(int mapData[10][10], int mapend) {
	Model model;
	int crow, ccol;
	for (int row = 0; row < MAP_HEIGHT; row++)
		for (int col = 0; col < MAP_WIDTH; col++)
			if (mapData[row][col] == 5) {
				crow = row;
				ccol = col;
			}
	int posx = ccol, posy = crow; //posx=0~9, posy=0~9
	mapData[posy][posx] = 0;
	int nposx, nposy;
	int oldx, oldy;
	int move = 0;
	_setcursortype(_NOCURSOR);
	drawMap(mapData);
	drawCharacter(posx, posy);
	int box = findbox(mapData);
	int count = 0;
	int in_x, in_y;
	while (1) {
		move++;
		int key = Util::getkey();
		if (key == 'q') break;
		if (key == 32) {
			game(model.map1, mapend);
			break;
		}
		oldx = nposx = posx;
		oldy = nposy = posy;
		switch (key) {
		case LEFTKEY: if (posx > 0) nposx--; in_y = 0, in_x = -1; break;//
		case UPKEY: if (posy > 0) nposy--; in_y = -1, in_x = 0; break;//
		case RIGHTKEY: if (posx < MAP_WIDTH)  nposx++; in_y = 0, in_x = 1; break; //
		case DOWNKEY: if (posy < MAP_HEIGHT)  nposy++; in_y = 1, in_x = 0; break; //
		case ESC: exit; move--; break; //홈 화면으로 가기
		}

		if (mapData[nposy][nposx] == 0) {//통로면
			posx = nposx;
			posy = nposy;
		}

		else if (mapData[nposy][nposx] == 2) { //상자를 옮길 때
			if (mapData[posy][posx] == 4) {
				mapData[nposy + in_y][nposx + in_x] = mapData[nposy][nposx];
				mapData[nposy][nposx] = 0;
				posx = nposx;
				posy = nposy;
			}
			if (mapData[nposy + in_y][nposx + in_x] == 4) //도착지점이면
			{
				if (mapData[posy][posx] == 4) {
					mapData[nposy + in_y][nposx + in_x] = 3;
					mapData[nposy][nposx] = 0;
				}
				else {
					mapData[nposy + in_y][nposx + in_x] = 3;
					mapData[nposy][nposx] = mapData[oldy][oldx];
				}
				posx = nposx;
				posy = nposy;
			}
			else if (mapData[nposy + in_y][nposx + in_x] == 0) {//통로면
				mapData[nposy + in_y][nposx + in_x] = mapData[nposy][nposx];
				mapData[nposy][nposx] = mapData[posy][posx];
				posx = nposx;
				posy = nposy;
				move -= 1;
			}

		}

		else if (mapData[nposy][nposx] == 3) {
			if (mapData[nposy + in_y][nposx + in_x] == 4) {
				mapData[nposy + in_y][nposx + in_x] = 3;
				mapData[nposy][nposx] = 4;
			}
			else if (mapData[nposy + in_y][nposx + in_x] == 0) {
				mapData[nposy + in_y][nposx + in_x] = 2;
				mapData[nposy][nposx] = 4;
			}
			posx = nposx;
			posy = nposy;
		}

		if (mapData[nposy][nposx] == 4) {
			posy = nposy;
			posx = nposx;
		}
		//성공 여부를 알기 위해
		for (int row = 0; row < MAP_HEIGHT; row++)
		{

			for (int col = 0; col < MAP_WIDTH; col++)
			{
				if (mapData[row][col] == 3)
				{
					count++; //model->moveCount;
				}
			}
		}
		if (oldx != posx || oldy != posy) { //이동했으면
			drawMap(mapData);
		}
		drawCharacter(posx, posy);


		gotoxy(20, 10);
		cout << "\n\n\n\n\nmove: " << move << endl;
		/*
		if (oldx != posx || oldy != posy) {
			Util::xyputs(oldx, oldy, "  ");
			Util::xyputs(posx, posy, "★");
		}
		*/

		if (findbox(mapData) == mapend) {
			gotoxy(10, 23);
			cout << "\n\n\n\n\nSUCCESS";
			return;
		}
	}
}


int main() {
	Model model;
	View view;
	pushpush p;
	Controller c;
	game(map3, map3end);

	//model.settempmap(model.map1);
	//game(model.getmap(), model.map1end);
}

/*
system("cls");
	view.startMenu();
	int menu = c.printMenu(model.x, model.y);
	if (menu == 1) {
		game(mapData, 4);
	}
	else if (menu == 2) {
		view.gameInfo();
	}
	else if (menu == 3) {
		exit(0);
	}
*/
