#pragma once
#pragma warning
#include <iostream>
#include "Consola.h"
using namespace std;
#include "Util.h"
#include "keycode.h"
#include "Model.h"
#include "View.h"
#define MAP_X1 10
#define MAP_Y1 4
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

class pushpush
{
public:
	Model model;
	View view;
	

	void drawCell(int map[10][10], int col, int row) {
		int cell = map[row][col];
		textbackground((cell == 1) ? DARKGRAY : BLACK);
		gotoxy((10 + col + 1) * 2, 4 + row + 1);
		puts(model.cellSymbol[cell]);
	}

	void drawMap(int map[10][10]) {
		for (int row = 0; row < MAP_HEIGHT; row++)
			for (int col = 0; col < MAP_WIDTH; col++)
				drawCell(map, col, row);
	}

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

	int game(int mapData[10][10], int mapend, bool isEnd) {
		system("cls");
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
		int in_x, in_y;
		model.isEnd = false;
		while (!model.isEnd) {
			oldx = nposx = posx;
			oldy = nposy = posy;

			int key = Util::getkey();
			if (key == 'q') exit(1);

			switch (key) {
			case LEFTKEY: if (posx > 0) nposx--; in_y = 0, in_x = -1; ++move; break;//
			case UPKEY: if (posy > 0) nposy--; in_y = -1, in_x = 0; ++move; break;//
			case RIGHTKEY: if (posx < MAP_WIDTH)  nposx++; in_y = 0, in_x = 1; ++move; break; //
			case DOWNKEY: if (posy < MAP_HEIGHT)  nposy++; in_y = 1, in_x = 0; ++move; break; //
			case ESC: view.gameInfo(); break;//조작 방법 보여주기
			case 49: game(model.map1, model.map1end, model.isEnd); break; //숫자 1키를 눌렀을 때 맵 1로
			case 50: game(model.map2, model.map2end, model.isEnd); break; //숫자 2키를 눌렀을 때 맵 2로
			case 51: game(model.map3, model.map3end, model.isEnd); break; //숫자 3키를 눌렀을 때 맵 3으로
			case 52: game(model.map4, model.map4end, model.isEnd); break; //숫자 4키를 눌렀을 때 맵 4로
			case 53: game(model.map5, model.map5end, model.isEnd); break; //숫자 5키를 눌렀을 때 맵 5로
			}

			if (mapData[nposy][nposx] == 0) {//통로면
				posx = nposx;
				posy = nposy;
			}
			if (mapData[nposy][nposx] == 1) { //벽으로 계속 움직일 때는 움직이는 횟수를 세지 않음
				move--;
			}

			else if (mapData[nposy][nposx] == 2) { //상자를 옮길 때
				if (mapData[posy][posx] == 4) { //현재 목적지일 때
					if (mapData[nposy + in_y][nposx + in_x] == 4) {
						mapData[nposy + in_y][nposx + in_x] = 3;
						mapData[nposy][nposx] = 0;
					}
					else {
						mapData[nposy + in_y][nposx + in_x] = mapData[nposy][nposx];
						mapData[nposy][nposx] = 0;
					}
					
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
			
			if (oldx != posx || oldy != posy) { //이동했으면
				drawMap(mapData);
			}
			drawCharacter(posx, posy);


			gotoxy(20, 10);
			cout << "\n\n\n\n\nmove: " << move << endl;
			if (findbox(mapData) == mapend) {
				gotoxy(10, 23);
				model.isEnd = true;
				cout << "\n\n\n\n\nSUCCESS";
			}
		}
		return move;
	}

};

