#include <iostream>

using namespace std;

void swap1(int &x, int &y);
void swap2(int *x, int *y);

int main(int arg, char* args[]) {
	int x = 10;
	int y = 20;
	swap1(x, y);
	cout << "x:" << x << " y:" << y << endl; //x:20 y:10
	swap2(&x, &y);
	cout << "x:" << x << " y:" << y << endl; //x:10 y:20
}

void swap1(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void swap2(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}