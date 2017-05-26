#include <iostream>
#include <functional>

using namespace std;

function<int()> addLater(int a, int b) {
	return [a, b]()->int{ return a + b; };
}

int add(int a, int b) {
	return a + b;
}

int (*fun(int a))(int, int) {
	cout << a << endl;
	return add;
}

int main(int arg, char* args[]) {
	function<int()> addResult = addLater(1, 2);
	cout << addResult() << endl;
	
	int (*addFunc)(int, int);
	addFunc = fun(10)
	cout << addFunc(1, 10) << endl;
}