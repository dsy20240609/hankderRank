instance variable 是什么意思

instance variable（实例变量） 是面向对象编程（OOP）里的一个基本概念。简单说，它是：

属于某个对象（instance）本身的数据成员，不同对象各自有自己的副本。

class Person {
public:
    string name;   // instance variable（实例变量）
    int age;       // instance variable（实例变量）
};


🧩 对比一下其他变量类型：
类型	所属	是否共享	示例
Instance variable（实例变量）	属于对象	❌ 各对象独立	this->name
Class variable（类变量 / static 变量）	属于类	✅ 所有对象共享	static int count;
Local variable（局部变量）	属于函数或方法	❌ 每次调用新建	函数内部定义的变量