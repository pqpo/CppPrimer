#include <iostream>
#include <string>

using namespace std;

class Base {
	
	public:
		Base(string name, int age):name(name),age(age){}
		virtual void say() {
			cout << "Base say: my name is " <<  name << endl;
		}
	protected:
		string name;
		int age;
	
};

class Son: public Base {
	
	public:
		Son(string name, int age):Base(name,age){}
		void say() override {
			cout << "Son say: my name is " << name << endl;
		}
	
};

int main(int arg, char* args[]) {
	Son son("Tom", 12);
	Base& base = son;
	base.say();
	
	base.Base::say();
}