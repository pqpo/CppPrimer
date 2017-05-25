#include "animal.h"

animal::animal(string inname):name(inname){}

void animal::sayHello() {
	cout << "Hello! my name is " << name << " my age is " << age << endl;
}