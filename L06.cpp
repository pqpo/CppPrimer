#include <iostream>

using namespace std;

int main(int arg, char* args[]) {
	
	int i = 100;
	const int *ptrI = &i;//指向常量的指针
	// *ptrI = 200; 不可改变该常量的值
	int j = 200;
	ptrI = &j; //指针本身非常量，可以指向其他对象
	
	int x = 300;
	int *const ptrX = &x; //一个常量指针
	*ptrX = 400; //可以改变对象的值
	//ptrX = &j; //但不许指向其他对象
	
	const int *const ptrY = &x; //甚至可以这样定义
	

}
