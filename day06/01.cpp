#include<iostream>

class String {
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string) {
		std::cout << "qian" << std::endl;
		m_Size = strlen(string) + 1;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other) :
		m_Size(other.m_Size) { // ���
		std::cout << "+++++++++++++++++++++" << std::endl;
		std::cout << "shen" << std::endl;
		std::cout << other.m_Buffer << std::endl;
		std::cout << "=====================" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String() {
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index) {
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const  String& string) {
	std::cout << string << std::endl;
	std::cout << "*************************" << std::endl;
}

class test {
private:
	int x, y;
public:
	test(int xx, int yy) :
		x(xx), y(yy) {
	}
	~test() {

	}
};

void work1() {

	String string = "Cherno";
	//String second = string; // ǳ����
	//second[2] = 'a';
	//std::cout << string << std::endl;// Tips��ǳ����ֻ�Ǹ��ƣ�ָ�����ݶ�һ��
	//std::cout << second << std::endl; // ����1��ʹ��ǳ��������ֱ�ӽ��������б���������һ�飬�����ڶ����࣬����������ʱ������������������һ�����������������ǵڶ����࣬��������ͬ���ַ�����ַ��
									  // ���Եڶ�������ʱ���Ǹ���ַ�������Ѿ��������ˣ��������ˡ�
	PrintString(string);
	//PrintString(second);
}


int main() {
	test a(1, 2);
	test b = a;
	std::cin.get();
}