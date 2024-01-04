// 静态库
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

//extern "C" int glfwInit(); 这个是C语言中的函数，在不引用GLFW头文件时，可用这个，只是个例，这个在C语言中实现了.



int main() {
	int a = glfwInit();
	std::cout << a << std::endl;
	std::cin.get();
}

void work4() {
	std::vector<Vector3> a; // 未优化代码，3个元素复制了6次
	a.push_back({ 1,2,3 }); // 在main函数构建一个变量，再复制到vector中
	a.push_back({ 4,5,6 });
	a.push_back({ 7,8,9 });
	std::vector<Vector3> b;
	b.reserve(3); // 定义vector长度，直接分配3个空间。省去空间不够的优化
	b.emplace_back(1, 2, 3); // 直接进行传参，不需要再main函数中构建变量，
	b.emplace_back(4, 5, 6); // 二十再vector空间中直接定义这个元素，这里传的是构建元素的参数
	b.emplace_back(7, 8, 9);

}

void work3() {
	int index = (int)&((Vector3*)8)->z; //找到基址为8的结构体中z的地址16，一个float占4个字节
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