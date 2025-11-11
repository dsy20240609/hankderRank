This problem is to get you familiar with virtual functions. 
Create three classes Person, Professor and Student. 
The class Person should have data members name and age. 
The classes Professor and Student should inherit from the class Person.
The class Professor should have two integer members: publications 
and cur_id.
There will be two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age 
and publications of the professor. 
The function putdata should print the name, age, publications and the cur_id of the professor.

The class Student should have two data members: marks, 
which is an array of size  and cur_id. 
It has two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age, 
and the marks of the student in  subjects. 
The function putdata should print the name, age, sum of the marks 
and the cur_id of the student.

For each object being created of the Professor or the Student class, 
sequential id's should be assigned to them starting from .
Solve this problem using virtual functions, constructors 
and static variables. You can create more data members if you want.
Note: Expand the main function to look at how the input is being handled.

Input Format

The first line of input contains the number of objects 
that are being created. If the first line of input 
for each object is , it means that the object being 
created is of the Professor class, you will 
have to input the name, age and publications of the professor.
If the first line of input for each object is , 
it means that the object is of the Student class, 
you will have to input the name, 
age and the marks of the student in  subjects.
Constraints
, where  is the length of the name.
, where marks is the marks of the student in each subject.
Output Format
There are two types of output depending on the object.
If the object is of type Professor, 
print the space separated name, age, publications and id on a new line.
If the object is of the Student class, 
print the space separated name, age, 
the sum of the marks in  subjects and id on a new line.


class Person {
    public:
    string name;
    int age;
    virtual void putdata()=0 override;
    virtual void getdata()=0 override; 
}

Professor::count=0;

// 继承的时候 public 后面不需要加 class
class Professor : public Person {
    public:
    Professor(): {
        cur_id=Professor::count;
        Professor::count++;
    }
    string publications;
    int cur_id;
    static int count;
    virtual void putdata() override;
    virtual void getdata() override;
}

Professor::getdata(){
    cin>> name>> age >> publications;
}
Professor::putdata() {
    cout<< name << age << publications;
}

Student::count=0;

class Student : public Person {
    Student() {
        cur_id=Student::count;
        Student::count++;
    }
    vector<int> marks;
    int cur_id;
    static int count;
    virtual void putdata() override;
    virtual void getdata() override;
}

Student::getdata() {
    cin>>name>>age;
    for(int i =0; i < 6;++i) {
        int mark;
        cin>>mark;
        marks.push_back(mark);   
    }
}

Student::putdata() {
    cout<<name<<age;
    for(size_t i =0; i< marks.size();++i) {
        cout<<makrs[i];
    }
}


questions：
子类有同名的函数，但是返回值不一样，可以用虚函数吗？
同名函数返回值类型不同，是重写还是重载？
重载(override) 和 重写 (overwrite) 有什么区别。
虚函数的机制是利用的哪一种。

子类可以 access 父类的 public  member field  和 memeber function？
什么样的变量被设计成 static variables.
in this case, the cur_id could be designed to be static variable
since you need to know globally how many professors have been generated
那么 static member 是跟着 class 走还是 可以有一个全局的 static memebr

父类的 static member 子类如何继承
共用一个全局的，因此修改通过子类/父类修改都会变


类的 static member 需要在 class 外部进行一次带类型的初始化。
class 写完了后面需要有一个分号;

构造函数 定义完了的 （） 后面加上 {} 写实现的时候，中间不需要冒号

类的 static member 的初始化，需要在 class 定义出现了之后，不然该 class 会被认为不认识。


虚函数肯定是 override，因为在写虚函数的时候，子类里面就要写 override;


// correct runnale version
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person {
    public:
    string name;
    int age;
    virtual void putdata()=0 ;
    virtual void getdata()=0 ; 
};





class Professor : public Person {
    public:
    Professor() {
        Professor::count++;
        cur_id=Professor::count;
    }
    int publications;
    int cur_id;
    static int count;
    virtual void putdata() override;
    virtual void getdata() override;
};

int Professor::count=0;
void Professor::getdata(){
    cin>> name>> age >> publications;
}
void Professor::putdata() {
    cout<< name <<" "<< age << " " << 
    publications <<" " << cur_id<<endl;
}



class Student : public Person {
    public:
    Student() {
        Student::count++;
        cur_id=Student::count;
    }
    vector<int> marks;
    int cur_id;
    static int count;
    virtual void putdata() override;
    virtual void getdata() override;
};

void Student::getdata() {
    cin>>name>>age;
    for(int i =0; i < 6;++i) {
        int mark;
        cin>>mark;
        marks.push_back(mark);   
    }
}
int Student::count=0;
void Student::putdata() {
    cout<<name<< " "<<age << " ";
    int sum=0;
    for(size_t i =0; i< marks.size();++i) {
        sum+=marks[i];
    }
    cout<<sum<< " " << cur_id<<endl;
}
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}


c++ 给我一个共有继承的例子
当然可以 👍
下面是一个 C++ 公有继承（public inheritance） 的简单例子，用来说明父类与子类的继承关系、成员访问控制等
#include <iostream>
using namespace std;

// 基类（父类）
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }

    void sleep() {
        cout << "Animal is sleeping." << endl;
    }
};

// 派生类（子类）通过公有继承
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking!" << endl;
    }
};

int main() {
    Dog myDog;

    // 子类可以访问父类的 public 成员
    myDog.eat();   // 继承自 Animal
    myDog.sleep(); // 继承自 Animal
    myDog.bark();  // Dog 自己的成员函数

    return 0;
}
class Dog : public Animal
表示 Dog 公有继承 Animal。
公有继承意味着：

父类的 public 成员 → 仍然是 public

父类的 protected 成员 → 仍然是 protected

父类的 private 成员 → 无法访问

这是一种最常见的继承方式，表示 “是一种（is-a）”关系。
例如：

Dog 是一种 Animal ✅
class Dog : private Animal
那父类的 eat() 和 sleep() 会变成 private，外部代码（main()）就无法直接调用它们。
这时只能在 Dog 的成员函数中调用。

子类有同名的函数，但是返回值不一样，可以用虚函数吗？
很好的问题！👏

这是 C++ 函数重写（override） 与 函数重载（overload） 的经典区别之一。
❌ 不可以仅仅靠“返回值不同”来当作虚函数重写。
C++ 要求虚函数的 函数签名（signature） 必须完全相同（包括返回值类型的兼容性），否则它不是“重写”，而是“隐藏”。

#include <iostream>
using namespace std;

class Base {
public:
    virtual int foo() {
        cout << "Base::foo()" << endl;
        return 1;
    }
};

class Derived : public Base {
public:
    // ❌ 返回类型不同：不是重写，而是隐藏（hides）
    virtual double foo() {
        cout << "Derived::foo()" << endl;
        return 2.0;
    }
};

int main() {
    Base* b = new Derived();
    b->foo(); // ⚠️ 调用的是 Base::foo()，不是 Derived::foo()
    delete b;
}

Base::foo()
在上面的代码中：

Derived::foo() 的返回类型是 double，而 Base::foo() 返回 int。

虽然名字一样，但 C++ 认为这是两个不同的函数。

因此不会发生虚函数多态，基类指针仍然调用 Base::foo()。

如果想要正确重写（override），必须：

参数类型、个数完全一致

返回类型必须兼容（可以是协变返回类型 — covariant return type）

#include <iostream>
using namespace std;

class Base {};
class DerivedType : public Base {};

class Parent {
public:
    virtual Base* create() {
        cout << "Parent::create()" << endl;
        return new Base();
    }
};

class Child : public Parent {
public:
    // ✅ 协变返回类型：DerivedType* 是 Base* 的子类型
    DerivedType* create() override {
        cout << "Child::create()" << endl;
        return new DerivedType();
    }
};

int main() {
    Parent* p = new Child();
    Base* obj = p->create(); // 多态成功
    delete p;
    delete obj;
}


Child::create()
| 情况              | 是否多态 | 说明           |
| --------------- | ---- | ------------ |
| 名字相同，参数不同       | ❌    | 重载（overload） |
| 名字相同，返回值不同      | ❌    | 隐藏（hiding）   |
| 名字、参数都相同，返回类型兼容 | ✅    | 重写（override） |
父类的 static member 子类如何继承

🧩 简短回答：

在 C++ 中，

子类会继承父类的静态成员（static member），
但静态成员 属于整个类本身，而不属于某个对象实例。

也就是说：

子类可以“访问”父类的静态成员；

但其实它们共享同一个静态变量/函数，并没有复制一份。

🧩 简短回答：

在 C++ 中，

子类会继承父类的静态成员（static member），
但静态成员 属于整个类本身，而不属于某个对象实例。

也就是说：

子类可以“访问”父类的静态成员；

但其实它们共享同一个静态变量/函数，并没有复制一份。

通过父类访问: Base::count = 10
通过子类访问: Derived::count = 10
Base::count = 99
Derived::count = 99

说明：

Derived 可以访问 Base 的 static count，就像它是自己的静态成员一样；

但它们指向同一个内存中的变量，改一个两个都变；

因为静态成员属于类本身（class scope），而不是实例。

class Base {
public:
    static void hello() {
        cout << "Hello from Base!" << endl;
    }
};

class Derived : public Base {};

int main() {
    Derived::hello(); // ✅ 可以直接调用
    Base::hello();    // ✅ 一样可以调用
}

⚙️ 静态成员函数同样被继承，但不能是虚函数，因为：

静态成员函数没有 this 指针，不存在多态关系。

🚫 注意：静态成员不会“独立复制”

如果你这样写：
Derived::count = 5;
Base::count = 20;
它们其实是同一个变量，最终值就是 20。
如果你希望子类有自己独立的一份静态变量，必须在子类中重新定义一个同名的静态变量：
class Derived : public Base {
public:
    static int count; // 重新定义，不共享
};

int Derived::count = 200;

| 成员类型   | 是否继承 | 是否共享     | 可否多态     |
| ------ | ---- | -------- | -------- |
| 普通成员变量 | ✅    | ❌ 每个对象独立 | ✅（通过虚函数） |
| 静态成员变量 | ✅    | ✅ 所有类共享  | ❌        |
| 静态成员函数 | ✅    | ✅ 所有类共享  | ❌        |


给我一个初始化全局变量的例子

#include <iostream>
using namespace std;

// 全局变量（全局作用域）
int g_counter = 10;          // 直接初始化
const double PI = 3.14159;   // 常量全局变量
string g_name = "ChatGPT";   // 对象类型全局变量

// 全局变量依赖于函数返回值初始化
int getInitialValue() {
    return 42;
}
int g_value = getInitialValue();

int main() {
    cout << "g_counter = " << g_counter << endl;
    cout << "PI = " << PI << endl;
    cout << "g_name = " << g_name << endl;
    cout << "g_value = " << g_value << endl;

    // 修改全局变量
    g_counter += 5;
    cout << "g_counter after update = " << g_counter << endl;

    return 0;
}

9
g_name = ChatGPT
g_value = 42
g_counter after update = 15

⚡ 说明：

全局变量定义在所有函数之外，作用域从定义处到文件末尾（或通过 extern 在其他文件引用）。

可以使用：

常量初始化：int x = 10;

对象初始化：string s = "abc";

函数返回值初始化：int y = getInitialValue();

全局变量的初始化顺序：

同一文件内：按定义顺序初始化

不同文件间：跨文件初始化顺序不保证（可能需要用函数封装或 C++11 的 inline 变量）

✅ 拓展技巧

如果全局对象依赖其他全局对象的初始化，可以用 函数封装初始化：
int& getCounter() {
    static int counter = 100; // 局部 static，首次调用初始化
    return counter;
}

int main() {
    cout << "Counter = " << getCounter() << endl;
}
示例：类的 static 成员初始化

#include <iostream>
using namespace std;

class MyClass {
public:
    static int count;          // 静态成员声明
    static const double PI;    // 静态常量声明 (可直接在类内初始化)
    static string name;        // 静态对象声明

    static void show() {
        cout << "count = " << count << ", name = " << name << ", PI = " << PI << endl;
    }
};

// 类外初始化（非 const/非 inline）
int MyClass::count = 10;
string MyClass::name = "ChatGPT";

// const 成员可以类内初始化（C++11+），如果不初始化在类外也可以
const double MyClass::PI = 3.14159;

int main() {
    // 通过类访问静态成员
    MyClass::show();

    // 修改静态成员
    MyClass::count += 5;
    MyClass::name = "OpenAI";

    MyClass::show();

    return 0;
}
说明：

声明 vs 定义

在类里：static int count; → 只是声明

在类外：int MyClass::count = 10; → 定义并初始化

常量静态成员

static const int/ double 可以在类内初始化（C++11+）

如果你希望修改，仍需要在类外定义

静态成员函数

可以访问静态成员

不需要对象即可调用：MyClass::show();

所有对象共享同一份静态成员

不管你创建多少个 MyClass 实例，count 都是同一份