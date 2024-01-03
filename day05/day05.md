* 初始化类成员列表

  如果类中成员元素有其他类成员的时候，如果不按照此方法构造类成员时，就会造成两次成员类构造，一次构建类a时，顺带构建类b，调用类a的构造函数时，还会再次构造类b，造成两次类b构造，造成性能浪费

  * A
    * B

* 三元运算符

* 创建持续变量

  * 栈变量（生存周期对应花括号结束）Entity entity ，自动回收
  * 堆变量（生存周期）Entity* e = new Entity("Cherno");，delete e; 需要手动回收
  * 如果忘记回收就会造成内存泄漏

* 隐式转换

  * 隐式构造函数（不常用）
  * explicit 取消隐式转换

* c++对象生存周期

* 智能指针（#include<memory>）

  * unique_ptr不能复制，即两个unique_ptr指向一个地址

    * 只能显式调用

    * ```c++
      std::unique_ptr<Entity> entity(new Entity());
      std::unique_ptr<Entity> entity = std::make_unique<Entity>();
      ```

    * 作用域结束后自动销毁(delete)

* 共享指针(shared_ptr)

  * 引用计数器

* 虚弱指针(weak_ptr) 

  * 可以指向shared_ptr，但是不会增加计数引用