#pragma once
#include <iostream>
#include "Consola.h"
using namespace std;
#include "Util.h"
#include "keycode.h"
class View
{
public:
	void startMenu() {
		system("cls");
		gotoxy(4, 4);
		cout << "\n\n\n";
		cout << "\t####    #   #    ###    #   #   ####    #   #    ###    #   #\n";
		cout << "\t#   #   #   #   #       #   #   #   #   #   #   #       #   #\n";
		cout << "\t####    #   #   ####    #####   ####    #   #   ####    #####\n";
		cout << "\t#       #   #       #   #   #   #       #   #       #   #   #\n";
		cout << "\t#        ###    ####    #   #   #        ###    ####    #   #\n";
		cout << "\n\t\t\t\t\t\t2020301006 김가은";
	}

	int getMenu() {
		int x = 39;
		int y = 15;
		gotoxy(x - 2, y);
		cout << "> 게 임 시 작 ";
		gotoxy(x, y + 1);
		cout << "게 임 정 보";
		gotoxy(x, y + 2);
		cout << "   종 료   ";

		while (1) {
			int key = Util::getkey();
			switch (key) {
			case UPKEY: if (y > 15) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			} break;
			case DOWNKEY:
				if (y < 17) {
					gotoxy(x - 2, y);
					cout << " ";
					gotoxy(x - 2, ++y);
					cout << ">";
				}break;
			case SPACE:
				return y - 14;
			}
		}
	}

	void gameEnd(int map1end, int map2end, int map3end, int map4end, int map5end) {//
		gotoxy(4, 4);
		cout << "\n\n";
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # " << endl;
		cout << "#      각 판의 이동횟수                                   # " << endl;
		cout << "#                                                         #" << endl;
		cout << "#      MAP1: " << map1end << "                                           #" << endl;
		cout << "#                                                         #" << endl;
		cout << "#      MAP2: " << map2end << "                                           #" << endl;
		cout << "#                                                         #" << endl;
		cout << "#      MAP3: " << map3end << "                                           #" << endl;
		cout << "#                                                         #" << endl;
		cout << "#      MAP4: " << map4end << "                                           #" << endl;
		cout << "#                                                         #" << endl;
		cout << "#      MAP5: " << map5end << "                                           #" << endl;
		cout << "#                                                         #" << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # " << endl;
	}
	void gameInfo() {//gameInfo
		system("cls"); //화면을 모두 지우기
		cout << "\n\n\t\t\t[ 게 임 조 작 법 ]\n\n";
		cout << "\t\t\t이 동 : 방 향 키 보 드\n\n";
		cout << "\t\t\t선 택 : 스 페 이 스 바\n\n";
		cout << "\t\t\t맵 초 기 화 : 스 페 이 스 바\n\n";
		cout << "\t\t\t맵 초 기 화 : 엔 터 키\n\n";
		cout << "\t\t\t홈 화 면 으 로 : E S C 키\n\n";
		cout << "\t\t\t해 당 맵 으 로 : 각 숫 자 키 (1, 2, 3, 4, 5)\n\n";

	}



};

