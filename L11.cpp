#include <iostream>
#include <memory>

using namespace std;

class Foo{
	public:
		Foo() {
			cout << "default constructor" << endl;
		}
		~Foo() {
			cout << "destructor" << endl;
		}
		void print() {
			cout << "print" << endl;
		}
};

void foo1() {
	Foo f; // 局部变量在栈中分配内存，自动析构，所以不能返回给调用者
}

Foo* foo2() {
	return new Foo(); // 使用new关键字在堆中分配内存，可以返回给调用者，使用完毕之后需要及时delete，防止内存泄漏
}


shared_ptr<Foo> foo3() {
	auto ptr = make_shared<Foo>(); //引用计数为1
	return ptr; //函数返回试一次拷贝，引用计数加1
} //函数出栈引用计数减1

int main(int arg, char* args[]) {
	
	foo1();
	
	Foo *f = foo2();
	delete f; //不容易管理
	
	//使用智能指针,引用计数
	auto fPtr = foo3();
	
	fPtr -> print();//使用智能指针，和普通指针一致
	
	auto fPtr2(fPtr);//引用计数加1
	
	cout << "count:" << fPtr.use_count() << endl; //共享的指针数量
	fPtr2.reset();//引用计数减1
	cout << "count:" << fPtr.use_count() << endl;
	fPtr.reset();//引用计数减1,此时引用计数为0，执行析构函数
	cout << "count:" << fPtr.use_count() << endl;
	
	//同一时刻只能有一个unique_ptr指向一个给定对象
	unique_ptr<Foo> uptr1(new Foo);
	unique_ptr<Foo> uptr2;
	uptr2.reset(uptr1.release());//转移指针所有权
	uptr2.reset();//释放对象
	
}