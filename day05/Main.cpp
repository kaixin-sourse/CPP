#include<iostream>
#include<string>
#include<memory>

class Entity {
public:
	int x, y;
	Entity() :
		x(1), y(1) {

	}
	Entity(int x, int y) {
		this->x = x;
		this->y = y;
		PrintEntity(this);
	}
	int GetX() const {
		const Entity* e = this; // 这里必须加const，因为此函数const是说明不能改变该类中内容的。
		PrintEntity(e);
		return e->x; // this->x;
		
	}
};

void PrintEntity(const Entity* e);
void PrintEntity(const Entity*  e) {
	//print;
	std::cout << e->x << std::endl;
}

int main() {
	{
   		//std::unqiue_ptr<Entity> entity = std::make_unqiue<Entity>();写错了
		/*
			unique_ptr 这个类型的指针，在作用域（说的不准确，但是这个道理是对的）结束后就会自动delete
			shared_ptr 这个跟作用域没关系，等引用块数量记为0时，才会自动delete
			weak_ptr 虚弱指针，现在看来感觉没什么用，或者说可以是shared_ptr的一个引用，但是计数器一到0，指向的内容就会自动销毁(delete)
			但是weak_ptr还指向那块地址，里面也没什么东西了
		*/
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // 上面的好
		std::unique_ptr<Entity> entity(new Entity());
		std::shared_ptr<Entity> sharedentity = std::make_shared<Entity>(); //这个shared_ptr中包含一个引用块（记录指向当前地址的shared_ptr的指针数量），用于存放当前地址有几个shared_ptr指针指着，如果用下面的方法
		std::shared_ptr<Entity> sharedentity(new Entity()); //会分配两次，一次Entity，一次shared_ptr，故尽量使用上面的构造（分配的）方法
		std::weak_ptr<Entity> weakeddentity = sharedentity;//但是不会增加计数器
		//weakeddentity = entity; unique_ptr只能由它自己指向，别人动不了

	}



}