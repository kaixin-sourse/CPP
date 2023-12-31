#include<iostream>
#include "../Head.h"

#define LOG(x) std::cout << x << std::endl;
void Sett();
enum Example : unsigned char { // unsigned char可加可不加，这个是规定其中元素类型的， 而且是递增1，不能是float
	A = 1, B, C
};
void test_enum() {
	Example a = B;
	if (a == B) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
}

int a = 10;

struct Entity { 
	//static int x, y; //静态变量甚至不需要实现类（具体的变量），为一个赋值，则全体该结构体的变量值都变。
	int x, y;
	void print() {
		std::cout << x << ", " << y << std::endl;
	}
	/*
		//类与结构体中静态函数不能访问非静态变量
		int x1, y1;

		static void print() {
			std::cout << x1 << ", " << y1 << std::endl;
		}
	*/
};
	/*
	//类（结构体）中的静态变量的声明
	int Entity::x;
	int Entity::y;
	*/

class Singleton {
private:
	static Singleton* s_Instance;
public:
	static Singleton& get() {
		return *s_Instance;
	}
	void hello() {
		std::cout << "Hello World!" << std::endl;
	}
};

Singleton* Singleton::s_Instance = nullptr;

int main() {
	char* buffer = new char[8];
	memset(buffer, 1, 8);
	char** ptr = &buffer;
	delete[] buffer;
	
	/*int a = 5;
	int b = 8;
	int* ptr = &a;
	*ptr = 8;
	ptr = &b;
	*ptr = 5;
	LOG(a);
	LOG(b);
	
	LOG(a);*/

	// =========结构体与类 static =============
	/*
	//类（结构体）中的静态变量的声明
	int Entity::x; //全局定义
	int Entity::y; //全局定义

		Entity e;
		e.x = 1, e.y = 2;
		e.print();
		Entity e1;
		e1.x = 1, e1.y = 2;
		e1.print();

	OutPut:
		1, 2
		1, 2
	*/

	/*
	 struct Entity { 
		int x, y;
		void print() {
			std::cout << x << ", " << y << std::endl;
		}
	}; 
	Entity e = { 1,2 };
	Entity e1;
	e1.x = 3;
	e1.y = 4;
	e.print();
	e1.print();
	OutPut:
		1, 2
		3, 4
	*/

	//Singleton::get().hello();
	test_enum();
	Sett();
	std::cin.get(); 

	return 0;
}