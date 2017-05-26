#include <iostream>
#include <dlfcn.h>

using namespace std;

static const char * const LIB_PATH = "./libcaculate.so";

typedef int (*CACULATE_FUNC)(int, int);

int main() {

	void* symAdd = nullptr;
	void* symMul = nullptr;
	char* errorMsg = nullptr;

	dlerror();
	
	void* handle = dlopen(LIB_PATH, RTLD_NOW);

	if(handle == nullptr) {
		cout << "load error!" << endl;
		return -1;
	}

	if ((errorMsg = dlerror()) != nullptr) {
		cout << "errorMsg:" << errorMsg << endl;
		return -1;
	}
	
	cout << "load success!" << endl;

	symAdd = dlsym(handle, "add");
	if(symAdd == nullptr) {
		cout << "dlsym failed!" << endl;
		if ((errorMsg = dlerror()) != nullptr) {
		cout << "error message:" << errorMsg << endl;
		return -1;
	}
	}
	CACULATE_FUNC addFunc = reinterpret_cast<CACULATE_FUNC>(symAdd);
	cout << "1 + 2 = " << addFunc(1, 2) << endl;

	dlclose(handle);
	return 0;
}
