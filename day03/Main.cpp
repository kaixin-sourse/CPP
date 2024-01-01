#include<iostream>
#include<string>
class Base {
public:
	virtual std::string Name() = 0; //��ȫ�麯��
};
class Entity :public Base{
public:
	virtual std::string Name() override{
		return "Https";
	}
	virtual std::string getName() { //���ຯ��
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
	std::string getName() override { //���ຯ��
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
	*(int*)((char*)p + 8) = 3; //�����еȼ�
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
	std::string name = "Cherno";// + "hello!"; Ϊʲô���е�ԭ���� "Cherno"˫�����а��������ַ����������std::string,�����޸ķ���
	name += " hello!"; // ����취1��
	std::string name1 = std::string("Cherno") + " hello!"; //�������2��ǿ��ת������
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