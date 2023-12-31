#include<iostream>
#include "../Head.h"

#define LOG(x) std::cout << x << std::endl;
void Sett();
enum Example : unsigned char { // unsigned char�ɼӿɲ��ӣ�����ǹ涨����Ԫ�����͵ģ� �����ǵ���1��������float
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
	//static int x, y; //��̬������������Ҫʵ���ࣨ����ı�������Ϊһ����ֵ����ȫ��ýṹ��ı���ֵ���䡣
	int x, y;
	void print() {
		std::cout << x << ", " << y << std::endl;
	}
	/*
		//����ṹ���о�̬�������ܷ��ʷǾ�̬����
		int x1, y1;

		static void print() {
			std::cout << x1 << ", " << y1 << std::endl;
		}
	*/
};
	/*
	//�ࣨ�ṹ�壩�еľ�̬����������
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

	// =========�ṹ������ static =============
	/*
	//�ࣨ�ṹ�壩�еľ�̬����������
	int Entity::x; //ȫ�ֶ���
	int Entity::y; //ȫ�ֶ���

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