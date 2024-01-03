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
		const Entity* e = this; // ��������const����Ϊ�˺���const��˵�����ܸı���������ݵġ�
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
   		//std::unqiue_ptr<Entity> entity = std::make_unqiue<Entity>();д����
		/*
			unique_ptr ������͵�ָ�룬��������˵�Ĳ�׼ȷ��������������ǶԵģ�������ͻ��Զ�delete
			shared_ptr �����������û��ϵ�������ÿ�������Ϊ0ʱ���Ż��Զ�delete
			weak_ptr ����ָ�룬���ڿ����о�ûʲô�ã�����˵������shared_ptr��һ�����ã����Ǽ�����һ��0��ָ������ݾͻ��Զ�����(delete)
			����weak_ptr��ָ���ǿ��ַ������Ҳûʲô������
		*/
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // ����ĺ�
		std::unique_ptr<Entity> entity(new Entity());
		std::shared_ptr<Entity> sharedentity = std::make_shared<Entity>(); //���shared_ptr�а���һ�����ÿ飨��¼ָ��ǰ��ַ��shared_ptr��ָ�������������ڴ�ŵ�ǰ��ַ�м���shared_ptrָ��ָ�ţ����������ķ���
		std::shared_ptr<Entity> sharedentity(new Entity()); //��������Σ�һ��Entity��һ��shared_ptr���ʾ���ʹ������Ĺ��죨����ģ�����
		std::weak_ptr<Entity> weakeddentity = sharedentity;//���ǲ������Ӽ�����
		//weakeddentity = entity; unique_ptrֻ�������Լ�ָ�򣬱��˶�����

	}



}