#include "animal.h"
#include <map>

class Base {
	protected:
		int x;
		int y;
	public:
		Base() = default;
		Base(int _x, int _y):x(_x), y(_y){}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
		virtual int getXY() {
			return x*y;
		}
		virtual int add();
};

class Boo: public Base {
	public:
		int add(){
			return 1;
		}
};

int main() {
	map<string, int> hh;
	hh["a"] = 1;
	hh["b"] = 2;
	for(auto iter = hh.begin(); iter != hh.end(); ++iter) {
		cout << iter -> first << iter -> second << endl;
	}
	return 0;
}

