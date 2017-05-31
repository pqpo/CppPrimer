#include <iostream>
#include <string>

using namespace std;

int main(int arg, char* args[]) {
	double d = 1.0;
	void *p = &d;
	double *dp = static_cast<double*>(p);
	
	const char *pc;
	char *p = const_cast<char*>(pc);//此时虽然p指针不是const,但是通过p写值是未定义的
	
	int *ip;
	char *pc = reinterpret_cast<char*>(ip);//很容易出现错误
	
	
	char a1[] = {'a', 'b', 'c', 'd'}; // 定义并初始化一个char数组
	char (*a2)[4] = &a1; //a2是一个指针，指向长度为4的char数组
	char (&a3)[4] = *a2; //a3是一个引用，引用指针a2的内容，即a1
	char a4[] = {'e', 'f', 'g'};
	char* a5[] = {a1, a4}; //a5是一个数组，数组内容是指向char的指针（a1, a4声明为数组，也表示为指向首元素的指针）
	
	cout << a1[3] << endl;
	cout << *(a1 + 3) << endl;
	
	for(auto item : a1) {
		cout << item << endl;
	}
	
	for(int i = 0; i < 4; ++i) {
		cout << *(a1 + i) << endl;
	}
	
	char* e = a1 + 4; //尾元素下一个位置
	for(char* b = a1; b != e; ++b) {
		cout << *b << endl;
	}
	
	char* pbeg = a1;//或者 begin(a1)
	char* pend = end(a1);//使用标准库函数获取尾元素的下一个位置
	while(pbeg != pend) {
		cout << *pbeg++ << endl;
	}
	
	
}