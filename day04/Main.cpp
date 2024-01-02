#include<iostream>
#include<string>

class Entity {
private:
	int m_X, m_Y;
	int* A;
	mutable int var; // 可变变量，即使在const函数中
public:

	const int* const GetA() const {
		var = 2;
		return A;
	}

	int GetX() const{ //这个const说明该函数是只读类，不能修改类中元素
		//m_X = 3;
		return m_X;
	}
	void SetX(int x) { // 这里不能加const，因为要修改类中内容
		m_X = x;
	}
};

int main() {
	/* 
		char name[8] = u8"Che\0rno";  //utf8 1个字节8位
		char* name5 = (char*)"ASdasd";
	
		//const char* name = "Che\0rno"; 这样就不能改name【2】了，因为是只读变量区
		//宽字符
		const wchar_t* name2 = L"Cheron";
		const char16_t* name3 = u"Cheron"; //utf16 两个字节16位 
		const char32_t* name4 = U"Cheron"; //utf32 四个字节32位
		name[2] = 0;

		std::cout << name << std::endl;
		using namespace std::string_literals;
		std::string name0 = "Cheron"s + "hello";
	*/

	/*
		const int MAX_AGE = 90;
		int* a = new int;
		a = (int*)&MAX_AGE;

		int data = 2;
		const int* p = new int;
		p = &data;
		//*p = 3;//这个是修改不了的指针指向的内容是const int类型的

		int temp_date = 3;
		int* const pp = new int; // 这个是说明指针p是const int*类型的
		//pp = &data; // 无法修改指针
		//pp = &temp_date; //无法修改指针
		*pp = 4; //但是能修改指针里面的值
	*/
	int x = 8;
	auto f = [&]() { // [&]表示传的是引用， [=] 表示传的是值（可以类比复制）
		x++;
		std::cout << x << std::endl;
	};
	f();
	auto ff = [=]() mutable {
		//x++; // 没加mutable的话，不能直接这么写，因为传的是值，所以在函数内部找不到x这个元素，可以用下面两行代替
		//int y = x;
		//y++;
		x++; // 加了mutable可以这么写了，但是最终不会改变x的值，其实和上面两行同理
		std::cout << x << std::endl;
	};
	ff();
	int a = 2, b = 3;
	auto fff = [&]() {
		a = 3;
		b = 4;
		std::cout << a << " " << b << std::endl;
	};
	fff();
	std::cout << a << " " << b << std::endl;

	int c = 1, d = 2;
	auto ffff = [&](int& c, int& d) {
		c = 2;
		d = 3;
		std::cout << c << " " << d << std::endl;
	};
	ffff(c,d);
	std::cout << c << " " << d << std::endl;
	



	std::cin.get();

}