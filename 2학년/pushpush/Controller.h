#pragma once
#pragma warning
#include"Model.h"
#include "View.h"
#include "pushpush.h"
#include <iostream>
#include "Consola.h"
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;
using namespace std;
#include "Util.h"
#include "keycode.h"
class Controller
{
public:
	Model model;
	View view;
	pushpush p;

	void gameMenu() {
		system("cls");
		view.startMenu();
		int menu = view.getMenu();
		PlaySound(TEXT("bgm.wav"), 0, SND_FILENAME | SND_ASYNC);
		
		if (menu == 1) {
			model.map1count = p.game(model.map1, model.map1end, model.isEnd);
			model.map2count = p.game(model.map2, model.map2end, model.isEnd);
			model.map3count = p.game(model.map3, model.map3end, model.isEnd);
			model.map4count = p.game(model.map4, model.map4end, model.isEnd);
			model.map5count = p.game(model.map5, model.map5end, model.isEnd);
			view.gameEnd(model.map1count, model.map2count, model.map3count, model.map4count, model.map5count);
			
		}
		else if (menu == 2) {
			view.gameInfo();
			while (1) {
				int key = Util::getkey();
				switch (key)
			case ESC: gameMenu(); break;
			}
		}
		else if (menu == 3) {
			exit(0);
		}

	};
};
