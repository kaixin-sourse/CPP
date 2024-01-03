#include<iostream>

class Empty {
private:
public:
	Empty() {
		std::cout << 1 << std::endl;
		std::cout << "create Entity" << std::endl;
	}
	Empty(int x) {
		std::cout << 2 << std::endl;
		std::cout << "create Entity with " << x << std::endl;
	}
};
/*
	class Entity {

	private:
		Empty M_x;
		std::string M_name;
	public:
		Entity():M_x(),M_name("Cherno") {

		}
		Entity(Empty a, std::string name) :
			M_x(a), M_name(name) {
		}
		const std::string get_Name() {
			return M_name;
		}
	};
*/
//static int s_Level = 2;
//static int s_Speed = 2;



/*

	class Entity {
	public:
		std::string m_Name;
		int Age;
	public:
		explicit Entity(int age) :
			m_Name("Unknown"), Age(age) {
		}
		Entity(std::string name) :
			m_Name(name), Age(-1) {

		}
		Entity operator+ (Entity& other) const {
			return Entity(Age + other.Age);
		}
		Entity operator* (Entity& other) const {
			return Entity(Age * other.Age);
		}
	};

	std::ostream& operator<<(std::ostream& stream, const Entity& other) {
		stream << other.Age << " " << other.m_Name << std::endl;
		return stream;
	}




*/

//void PrintEntity(const Entity& entity) {
	//Printing;
//}

/*
	int main() {
		/*
			Empty b;
			std::cout << "====================" << std::endl;
			Entity a(b,std::string("name"));
		*/
		//std::string rank = s_Level > 10 ? "master" : "beginner";

		/*
			Entity* e;
			{
				Entity* entity = new Entity();
				e = entity;
				std::cout << e->get_Name() << std::endl;
				std::cout << entity->get_Name() << std::endl;
				delete entity;
			}

		*/
		/*
			int a = 2;
			int* b = new int[50]; // 200bytes

			delete e;
			delete[] b;
		*/
/*
	PrintEntity(Entity(20));
	//PrintEntity(20); // 类中构造函数取消隐式链接了，所以不能这样赋值
	PrintEntity(std::string("Cherno"));
	Entity a = std::string("Cherno");
	Entity b(22);
	Entity c = Entity(30);
	c = b + c;
	std::cout << c << std::endl;
	std::cin.get();
	}
*/

