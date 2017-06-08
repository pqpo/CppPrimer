#include <iostream>
#include <string>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) {
		return -1;
	}
	if (v1 > v2) {
		return 1;
	}
	return 0;
}

template <typename T> class Plus {
	public:
		Plus(const T a,const T b):a(a),b(b){}
		T getResult() {
			return a + b;
		}
	
	private:
		T a;
		T b;
	
};

int main(int arg, char* args[]) {
	cout << compare(1, 2) << endl;
	Plus<int> intPlus(1,2);
	cout << intPlus.getResult() << endl;
	string a("Hello ");
	string b("C++");
	Plus<string> stringPlus(a, b);
	cout << stringPlus.getResult() << endl;
}