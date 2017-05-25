#include <iostream>

using namespace std;

//执行结果：
//global_str: global_int:0
//local_str: local_str2:Hello local_int:4200843

string global_str; //非显式地初始化为一个空字符串
int global_int; //函数体外的内置类型初始化为0

int main(int argsSize, char* args[]) {
	string local_str; //非显式地初始化为一个空字符串（不管在函数体内还是外）
	string local_str2("Hello"); //显式地初始化字符串
	int local_int;//函数体内的内置类型不初始化，变量的值是未定义，不可预计，避免不初始化
	cout << "global_str:" << global_str << " global_int:" << global_int << endl;
	cout << "local_str:" << local_str << " local_str2:" << local_str2 << " local_int:" << local_int << endl;
	return 0;
}