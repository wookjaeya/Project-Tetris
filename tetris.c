#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h> 



clock_t DropT, end, start;
RECT blockSize;
int BlockShape;
int RotateBlock = 0;
int key;
int x=8, y=0;
int point=0;

int block[7][4][4][4] = {
	{ // T 블럭
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{    // reverse z 블럭
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{   // z 블럭 
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		}
	},
	{   // l 블럭
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		}
	},
	{   // L 블럭
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,0,0,0}
		}
	},
	{   // reverse L 블럭
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{1,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	},
	{   // ㅁ 블럭
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	}
};

int Field[16][12] = {  
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};


void Init() { //콘솔창 커서 지우기
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	srand(time(NULL));
	return 0;
}
void gotoxy(int x, int y) { //좌표지정
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void OpenField() { //0은 필드
	gotoxy(0, 0);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 12; j++) { //1은 벽
			if (Field[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("□");
			}
			else if (Field[i][j] == 2) { //2는 블록
				gotoxy(j * 2, i);
				printf("■");
			}
		}
	}
}

int CheckWall(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[BlockShape][RotateBlock][i][j] == 1) { //[블록종류][블록회전][4][4]
				int c = Field[i + y][j + x / 2]; //x좌표는 2를 놔눠야 y좌표와 값이 맞음
				if ( c == 1) { // 벽일 때 1반환
					return 1; 
				}
				else if (c == 2) { // 블럭일 때
					return 1; 
				}
			}
		}
	}
	return 0;
}


void DropB() {
	end = clock();
	if ((float)(end - DropT) >= 800) {
		if (CheckWall(x, y + 1) == 1) {
			return;
		}
		y++;
		DropT = clock();
		start = clock();
		system("cls"); //콘솔창 비우기
	}
}
void Change() { //
	if (CheckWall(x, y + 1) == 1) { // y축 한 칸 아래 checkwall가 참일때
		if ((float)(end - start) > 1600) { //아래가 1이고 1.6초간 
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) { 
					if (block[BlockShape][RotateBlock][i][j] == 1) { //블락이라면
						Field[i + y][j + x / 2] = 2;
					}
				}
			}
			x = 8;
			y = 0;
			BlockShape = rand() % 7; //다음 블록 랜덤 지정, 좌표이동
		}
	}
}
void ClearBlock(){
	for (int i = 15; i > -1; i--) { // 벽빼고 10X15 안에서
		int Line = 0;
		for (int j = 1; j < 11; j++) { 
			if (Field[i][j] == 2) {
				Line++; //필드의 값이 벽이된 블락(2)라면 line 증가
			}
		}
		if (Line > 9) { //한줄 완성 : Line = 10이라면 전체 배열 한줄씩 내림
			for (int k = 0; i - k > -1; k++) {
				for (int l = 1; l < 11; l++) {
					if (i - k - 1 >= 0)
						Field[i - k][l] = Field[i - k - 1][l];
					else
						Field[i - k][i] = 0;
				}
			}
			point = point + 100;
		}
	}
}

void CreateBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[BlockShape][RotateBlock][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("■");
			}
		}
	}
}
void InputKey() {
	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 32: // space
			RotateBlock++;
			if (RotateBlock > 3) {
				RotateBlock = 0;
			}
			start = clock();
			break;
		case 75: // left
			if (CheckWall(x - 1, y) == 0) {
				x -= 2;
				start = clock();
			}
			break;
		case 77: // right
			if (CheckWall(x + 1, y) == 0) {
				x += 2;
				start = clock();
			}
			break;
		case 80: // down
			if (CheckWall(x, y + 1) == 0)
				y++;
			break;
		}
		system("cls");
	}
}

void pointer() {
	gotoxy(30, 5);
	printf("POINT : %d", point);
}


int main() {
	Init();
	DropT = clock();
	BlockShape = rand() % 7;
	

	while (1) {
		pointer();
		OpenField();
		CreateBlock();
		DropB();
		Change();
		ClearBlock();
		InputKey();
	}
	return 0;
}
