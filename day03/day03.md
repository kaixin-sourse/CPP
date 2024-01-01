* 未继承（虚函数）版本

  ```c++
  #include<iostream>
  #include<cstring>
  class Entity {
  public:
  	std::string getName() { //基类函数
  		return "Entity";
  	}
  };
  
  class Player : public Entity {
  private:
  	std::string m_Name;
  public:
  	Player(const std::string& name) : m_Name(name) {}
  	std::string getName() { //子类函数
  		return m_Name;
  	}
  };
  
  int main() {
  	Entity* entity = new Entity;
  	std::cout << entity->getName() << std::endl;
  	Player* p = new Player("Player");
  	std::cout << p->getName() << std::endl;
  	Entity* tt = p;
  	std::cout << tt->getName() << std::endl; // 此项输出还是基类的 "Entity"
  }
  ```

  

* 继承虚函数版本：

  ```c++
  #include<iostream>
  #include<cstring>
  class Entity {
  public:
  	std::string getName() { //基类函数
  		return "Entity";
  	}
  };
  
  class Player : public Entity {
  private:
  	std::string m_Name;
  public:
  	Player(const std::string& name) : m_Name(name) {}
  	std::string getName() { //子类函数
  		return m_Name;
  	}
  };
  
  int main() {
  	Entity* entity = new Entity;
  	std::cout << entity->getName() << std::endl;
  	Player* p = new Player("Player");
  	std::cout << p->getName() << std::endl;
  	Entity* tt = p;
  	std::cout << tt->getName() << std::endl; //此项输出为player
  }
  ```

* 引入虚函数的两个缺点（不明显）

  * 需要在基类建造一个v表（存放虚函数的）占用额外存储空间
  * 每次找虚函数时，都需要遍历v表，造成额外的查找时间
  * 除非是嵌入式那些cpu较差的器件，其他地方使用虚函数一般没什么问题

* C++的可见性，private，protected，public
* 数组
* new 和 delete一一对应
* char name3[6] = { 'C','h','e','r','n','o' };
* ![image-20231231170859273](C:\Users\27996\AppData\Roaming\Typora\typora-user-images\image-20231231170859273.png)

* Output:
* * ![image-20231231170944375](C:\Users\27996\AppData\Roaming\Typora\typora-user-images\image-20231231170944375.png)