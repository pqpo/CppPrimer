#include <iostream>
#include <string>

using namespace std;

class Foo;

class Boo {
	public:
		void printName(Foo &foo);
};

class Foo {
	friend void Boo::printName(Foo &foo); // 声明友元，代表这个方法可以范围我的私有成员，也可以写类名，表示这个类的的所有方法都可以范围。
	public: 
		Foo(string name);
	private:	
		string name;
};


void Boo::printName(Foo &foo) {
	cout << foo.name << endl;
}

Foo::Foo(string name):name(name) {}

int main(int arg, char* args[]) {
	Foo foo("a");
	Boo boo;
	boo.printName(foo);
}