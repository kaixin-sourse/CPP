// ��̬��
#include<iostream>
#include<vector>
#include<GLFW/glfw3.h>
class Entity {
public:
	int x, y;
public:
	void print() {
		// do printing
	}
};

class ScopedPtr {
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity) :
		m_Obj(entity)
	{

	}
	~ScopedPtr() {
		delete m_Obj;
	}
	Entity* operator->() {
		return m_Obj;
	}
	const Entity* operator->() const {
		return m_Obj;
	}
};

struct Vector3 {
	float x, y, z;
	Vector3(float xx, float yy, float zz) :
		x(xx), y(yy), z(zz) {

	}
	Vector3(const Vector3& other) :
		x(other.x), y(other.y), z(other.z)
	{
		std::cout << "copy!" << std::endl;
	}
};

//extern "C" int glfwInit(); �����C�����еĺ������ڲ�����GLFWͷ�ļ�ʱ�����������ֻ�Ǹ����������C������ʵ����.



int main() {
	int a = glfwInit();
	std::cout << a << std::endl;
	std::cin.get();
}

void work4() {
	std::vector<Vector3> a; // δ�Ż����룬3��Ԫ�ظ�����6��
	a.push_back({ 1,2,3 }); // ��main��������һ���������ٸ��Ƶ�vector��
	a.push_back({ 4,5,6 });
	a.push_back({ 7,8,9 });
	std::vector<Vector3> b;
	b.reserve(3); // ����vector���ȣ�ֱ�ӷ���3���ռ䡣ʡȥ�ռ䲻�����Ż�
	b.emplace_back(1, 2, 3); // ֱ�ӽ��д��Σ�����Ҫ��main�����й���������
	b.emplace_back(4, 5, 6); // ��ʮ��vector�ռ���ֱ�Ӷ������Ԫ�أ����ﴫ���ǹ���Ԫ�صĲ���
	b.emplace_back(7, 8, 9);

}

void work3() {
	int index = (int)&((Vector3*)8)->z; //�ҵ���ַΪ8�Ľṹ����z�ĵ�ַ16��һ��floatռ4���ֽ�
	std::cout << index << std::endl;
}

void work2() {
	ScopedPtr entity = new Entity;
	entity->print();
}

void work1() {
	Entity e;
	e.print();
	Entity* ptr = &e;
	(*ptr).print();
	e.x = 2;
	ptr->x = 2;
}