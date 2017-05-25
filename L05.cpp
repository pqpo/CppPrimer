#include <iostream>
#include <vector>

using namespace std;

void mMap(vector<int> list, void (*fun)(int item));
void log(int item);

int main(int arg, char* args[]) {
	vector<int> list = {2,3,4,3,2,1,2};
	mMap(list, &log);
	//mMap(list, log);
}

void log(int item) {
	cout << item << endl; 
}

void mMap(vector<int> list, void (*fun)(int item)) {
	for(int it : list) {
		fun(it);
	}
}