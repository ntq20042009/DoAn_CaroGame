#include"view.h"
#include "Control.h"
#include"Function_C.h"
struct _POINT { int x, y, c; }; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
_POINT _A[76][42]; //Ma trận bàn cờ
bool _TURN; //true là lượt người thứ nhất và false là lượt người thứ hai
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int _X, _Y;
void ResetData() {
	for (int i = 3; i < 76; i++) {
		for (int j = 2; j < 43; j++) {
			_A[i][j].x = 5; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 3; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy 
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[5][3].x; _Y = _A[5][3].y; // Thiết lập lại tọa độ hiện hành ban đầu
}
void MoveRight() {
	if (_X < _A[76-3 - 1][43-2 - 3].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft() {
	if (_X > _A[5][3].x) {
		_X -= 4;
		GotoXY(_X, _Y);

	}
}
void MoveDown() {
	if (_Y < _A[76-3-1][43-2 - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp() {
	if (_Y > _A[5][3].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

void test() {
	bool validEnter = true;
	while (validEnter==1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 'A') MoveLeft();
		else if (_COMMAND == 'W') MoveUp();
		else if (_COMMAND == 'S') MoveDown();
		else if (_COMMAND == 'D') MoveRight();
	}
}

