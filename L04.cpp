#include <iostream>

using namespace std;

void swap(int &x, int &y);

int main(int arg, char* args[]) {
	int x = 10;
	int y = 20;
	
	void (*methodPtr)(int &x, int &y);//声明一个函数指针
	methodPtr = &swap; //函数指针赋值
	methodPtr = swap;//取地址符可省略,效果和上面一致
	methodPtr(x, y); //像给函数起了一个别名，可以直接使用（）调用
	cout << "x:" << x << " y:" << y << endl; //x:20 y:10
}

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}