#include<iostream>
#include<string>

class Entity {
private:
	int m_X, m_Y;
	int* A;
	mutable int var; // �ɱ��������ʹ��const������
public:

	const int* const GetA() const {
		var = 2;
		return A;
	}

	int GetX() const{ //���const˵���ú�����ֻ���࣬�����޸�����Ԫ��
		//m_X = 3;
		return m_X;
	}
	void SetX(int x) { // ���ﲻ�ܼ�const����ΪҪ�޸���������
		m_X = x;
	}
};

int main() {
	/* 
		char name[8] = u8"Che\0rno";  //utf8 1���ֽ�8λ
		char* name5 = (char*)"ASdasd";
	
		//const char* name = "Che\0rno"; �����Ͳ��ܸ�name��2���ˣ���Ϊ��ֻ��������
		//���ַ�
		const wchar_t* name2 = L"Cheron";
		const char16_t* name3 = u"Cheron"; //utf16 �����ֽ�16λ 
		const char32_t* name4 = U"Cheron"; //utf32 �ĸ��ֽ�32λ
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
		//*p = 3;//������޸Ĳ��˵�ָ��ָ���������const int���͵�

		int temp_date = 3;
		int* const pp = new int; // �����˵��ָ��p��const int*���͵�
		//pp = &data; // �޷��޸�ָ��
		//pp = &temp_date; //�޷��޸�ָ��
		*pp = 4; //�������޸�ָ�������ֵ
	*/
	int x = 8;
	auto f = [&]() { // [&]��ʾ���������ã� [=] ��ʾ������ֵ��������ȸ��ƣ�
		x++;
		std::cout << x << std::endl;
	};
	f();
	auto ff = [=]() mutable {
		//x++; // û��mutable�Ļ�������ֱ����ôд����Ϊ������ֵ�������ں����ڲ��Ҳ���x���Ԫ�أ��������������д���
		//int y = x;
		//y++;
		x++; // ����mutable������ôд�ˣ��������ղ���ı�x��ֵ����ʵ����������ͬ��
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