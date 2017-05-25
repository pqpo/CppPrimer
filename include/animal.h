#ifndef ANIMAL_HEADER
#define ANIMAL_HEADER

#include <iostream>
#include <string>

using namespace std;

class animal {
	private:
		string name;
		int age;
	public:
		animal() = default;
		animal(string inname);
		void sayHello();
};

#endif