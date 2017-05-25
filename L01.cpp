#include <iostream>

using namespace std;

//bool size:1
//char size:1
//short size:2
//int size:4
//long size:4
//long long size:8
//long size:4
//double size:8
//long double size:12

int main(int argsSize, char* args[]) {
	bool aBool = true;
	cout << "bool size:" << sizeof(aBool) << endl; 
	char aChar = 'a';
	cout << "char size:" << sizeof(aChar) << endl;
	short aShort = 0xee;
	cout << "short size:" << sizeof(aShort) << endl;
	int aInt = 10;
	cout << "int size:" << sizeof(aInt) << endl;
	long aLong = 10L;
	cout << "long size:" << sizeof(aLong) << endl;
	long long aLongLong = 10L;
	cout << "long long size:" << sizeof(aLongLong) << endl;
	float aFloat = 10.0f;
	cout << "long size:" << sizeof(aLong) << endl;
	double aDouble = 10.0;
	cout << "double size:" << sizeof(aDouble) << endl;
	long double aLongDouble = 10.0;
	cout << "long double size:" << sizeof(aLongDouble) << endl;
	return 0;
}