#include <iostream>
#include <conio.h>
using namespace std;

bool GameOver;
const int width = 25;
const int hight = 25;
int x, y, score;
int fruitX, fruitY;

enum directions
{
	STOP =0,UP,DOWN,LEFT,RIGHT
};

directions dir;

void Setup() {
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = hight / 2;
	fruitX = rand() % width;
	fruitY = rand() % hight;
	if (fruitX == width / 2 && fruitY == hight / 2) {
		fruitX = rand() % width;
		fruitY = rand() % hight;
	}

	score = 0;
}


void Draw(){
	system("cls");

	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == width - 1) {
				cout << "*";
			}
			else if (j == 0 || j == width - 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}




}
void game_Input() {

}


void logic() {

}



int main() {
	Setup();
	Draw();
	game_Input();
	logic();
	while (!GameOver) {

	}

	return 0;
}