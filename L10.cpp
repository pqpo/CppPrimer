#include <iostream>

using namespace std;

class Foo {
	public:
		string a;
		int b;
		Foo() { //默认构造函数
			cout << "default constuctor" << endl;
		}
		Foo(string x): a(x), b(0){ //普通构造函数
			cout << "general constructor 1" << endl;
		}
		Foo(string x, int y): a(x),b(y){ //普通构造函数
			cout << "general constructor 2" << endl;
		}
		Foo(const Foo &orig):a(orig.a),b(orig.b) { //拷贝构造函数
			cout << "copy consrtuctor" << endl;
		}
		~Foo(){ //析构函数
			cout << "destructor" << endl;
		} 
		Foo& operator=(const Foo &other) { //拷贝赋值表达式
			a = other.a;
			b = other.b;
			cout << "copy-assignment operator" << endl;
			return *this;
		}
		void operator()() { //函数调用运算符
			cout << "a:" << a << " b:" << b << endl;
		}
};

Foo operator+(const Foo &l, const Foo &r) { //非成员运算符函数
	Foo sum = l;
	sum.a += r.a;
	sum.b += r.b;
	return sum;
}


int main(int arg, char* args[]) {
	Foo a; //调用默认构造函数
	Foo b = a; //调用拷贝构造函数
	Foo c("xxx", 2.1);
	c = a; //调用拷贝赋值表达式
	string param = "yyyy";
	Foo d = param; //隐式调用构造函数Foo(string x)
	
	Foo r("r", 2);
	Foo l("l", 3);
	Foo sum =  r + l;//调用非成员运算符函数，等价于 sum = operator+(r, l);
	cout << sum.b << endl;
	sum(); //调用函数调用运算符，等价于 sum.operator()();
}