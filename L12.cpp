#include <iostream>
#include <string>

using namespace std;

class Foo;

class Boo {
	public:
		void printName(Foo &foo);
};

class Foo {
	friend void Boo::printName(Foo &foo);
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