#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool GameOver;

//map size
const int width = 25;
const int hight = 25;

//player position and score 
int x, y,speed;
int tailX[100], tailY[100],tailLength;

//tail position
int ftposX, ftposY, stposX, stposY;


//fruit position
int fruitX, fruitY;


//Game variables
enum directions
{
	STOP =0,UP,DOWN,LEFT,RIGHT
};
int score;
directions dir;

void Setup() {
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = hight / 2;
	fruitX = rand() % width;
	fruitY = rand() % hight;
	while (fruitX == width / 2 && fruitY == hight / 2) {
		fruitX = rand() % width;
		fruitY = rand() % hight;
	}

	score = 0;
	speed = 1;
}


void Draw(){
	system("cls");

	//map,player and fruit
	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == width - 1) {
				cout << "*";
			}
			else if (j == 0 || j == width - 1) {
				cout << "*";
			}
			else if (i == y && j == x) {
				cout << "0";
			}
			else if (i == fruitY && j == fruitX) {
				cout << "f";
			}
			else {
				bool tail = false;
				for (int k = 0; k < tailLength; k++) {
					if (j == tailX[k] && i == tailY[k]) {
						cout << "o";
						tail = true;
					}
				}
				if (!tail) {
					cout << " ";
				}
			}
			
		}
		cout << endl;
	}
	cout << "Score: " << score;


}
void game_Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT) {
				dir = LEFT;
			}
			break;
		case 'd':
			if (dir != LEFT) {
				dir = RIGHT;
			}
			break;
		case 'w':
			if (dir != DOWN) {
				dir = UP;
			}
			break;
		case 's':
			if (dir != UP) {
				dir = DOWN;
			}
			break;
		case 'n':
			GameOver = true;
			break;
		}

	}

}


void logic() {
	//taill
	ftposX = tailX[0];
	ftposY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tailLength; i++) {
		stposX = tailX[i];
		stposY = tailY[i];
		tailX[i] = ftposX;
		tailY[i] = ftposY;
		ftposX = stposX;
		ftposY = stposY;
	}

	//movment

	switch (dir)
	{
	case UP:
		y -= speed;
		break;
	case DOWN:
		y += speed;
		break;
	case LEFT:
		x -= speed;
		break;
	case RIGHT:
		x += speed;
		break;
	}

	//player touch the wall
	if (x <= 0 || x >= width -1 || y <= 0 || y > hight-1 ) {
		GameOver = true;
	}

	//player touch the taill
	for (int i = 0; i < tailLength; i++) {
		if (x == tailX[i] && y == tailY[i]) {
			GameOver = true;
		}
	}

	//player touch the fruit
	if (x == fruitX && y == fruitY) {
		fruitX = rand() % width;
		fruitY = rand() % hight;
		fruitX = rand() % width;
		fruitY = rand() % hight;
		fruitX = rand() % width;
		fruitY = rand() % hight;
		score++;
		tailLength++;
	}

}



int main() {
	Setup();
	while (!GameOver)
	{
		Draw();
		game_Input();
		logic();
		Sleep(30);
	}

	return 0;
}