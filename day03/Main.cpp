#include<iostream>
#include<string>
class Base {
public:
	virtual std::string Name() = 0; //完全虚函数
};
class Entity :public Base{
public:
	virtual std::string Name() override{
		return "Https";
	}
	virtual std::string getName() { //基类函数
		return "Entity";
	}
};

class Player : public Entity,Base {
private:
	std::string m_Name;
public:
	std::string Name() override {
		return "Http";
	}
	Player(const std::string& name) : m_Name(name) {}
	std::string getName() override { //子类函数
		return m_Name;
	}
};

void work_class() {
	Entity* entity = new Entity;
	std::cout << entity->getName() << std::endl;
	Player* p = new Player("Player");
	std::cout << p->Name() << std::endl;
	std::cout << p->getName() << std::endl;
	Entity* tt = p;
	std::cout << tt->getName() << std::endl;
}

void Array_work() {
	int example[5];
	for (int i = 0; i < 5; i++) {
		example[i] = i;
	}
	example[4] = 32;
	int* p = example;
	//example[2] = 3;
	*(int*)((char*)p + 8) = 3; //这三行等价
	//*(p + 2) = 3;
}

void class_and_Array() {
	class Arrayy {
	public:
		//int s[5];
		int* s = new int[5];
		Arrayy() {
			for (int i = 0; i < 5; i++) {
				s[i] = 2;
			}
		}
		~Arrayy() {
			delete[] s;
		}
		void print() {
			for (int i = 0; i < 5; i++) {
				std::cout << s[i] << std::endl;
			}
		}
	};
	Arrayy e;
	e.print();
}

void add_and_print(std::string& stringg) {
	stringg += "h";
	std::cout << stringg << std::endl;
}

void string_and_char() {
	std::string name = "Cherno";// + "hello!"; 为什么不行的原因是 "Cherno"双引号中包括的是字符数组而不是std::string,两种修改方法
	name += " hello!"; // 解决办法1，
	std::string name1 = std::string("Cherno") + " hello!"; //解决方法2，强制转换类型
	std::cout << name << std::endl << name1 << std::endl;
	add_and_print(name);
	std::cout << name << std::endl;
}
int main() {
	const char* name = "Cherno";
	//char* name2 = "asdjkl";
	char name3[6] = { 'C','h','e','r','n','o' };
	std::cout << name3 << std::endl;
	string_and_char();
	std::cin.get();
}