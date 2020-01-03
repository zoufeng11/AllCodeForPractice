#include <iostream>
using namespace std;


//对结构体或类进行表示, 设置对齐方式为8字节
struct alignas(8) S {};

//struct alignas(1) U { S s; }  // warning

//有字节对齐(以4字节为对齐方式)
struct Foo
{
	int i;
	float f;
	char c;
};

struct Empty {};

struct alignas(64) Empty64 {};

struct alignas(8) Double {
	double d;
};

//以四字节为对齐方式, 即sizeof(Obj) == 8
struct Obj {
	char a;
	int b;
};


void alignInfo()
{
	cout << "sizeof(Obj)        : " << sizeof(Obj) << endl; // 8
	cout << "alignof(Obj)       : " << alignof(Obj) << endl; // 4
	cout << "sizeof(Foo)        : " << sizeof(Foo) << endl; // 12
	cout << "sizeof(Double)     : " << sizeof(Double) << endl; // 8
	cout << "sizeof(Empty64)    : " << sizeof(Empty64) << endl; // 64

	cout << "\n";

	cout << "Alignment of " << endl;
	cout << "- char             : " << alignof(char) << endl; // 1
	cout << "- pointer          : " << alignof(int*) << endl; // 8
	cout << "- class Foo        : " << alignof(Foo) << endl; // 4
	cout << "- empty class      : " << alignof(Empty) << endl; // 1
	cout << "- alignas(64) Empty: " << alignof(Empty64) << endl; // 64
	cout << "- alignas(1) Double: " << alignof(Double) << endl; // 8
}

double add(double a, double b)
{
	return a + b;
}
/******** Auto show *********/
double get_fun(int a)
{
	return a;
}

void showAuto()
{
	int aa = 1 + 2;
	auto a = 1 + 2;
	cout << "type of a: " << typeid(a).name() << endl;

	auto b = add(1, 1.2);
	cout << "type of b: " << typeid(b).name() << endl;

	auto c = { 1, 2 };
	cout << "type of c: " << typeid(c).name() << endl;

	auto my_lambda = [](int x) { return x + 3; };
	std::cout << "my_lambda: " << my_lambda(5) << endl;

	auto my_fun = get_fun(2);
	cout << "type of my_fun: " << typeid(my_fun).name() << endl;
	cout << "my_fun: " << get_fun(3) << endl;

}

struct Base
{
	virtual ~Base() {}
};

struct Derived : public Base
{
	virtual void name() {}
};

void testDynatic_cast()
{
	Base* b1 = new Base();
	//拥有基类指针, base指针-->derived指针, 失败      
	if (Derived * d = dynamic_cast<Derived*> (b1))
	{
		cout << "donwcast from b1 to d successful\n";
		d->name();    // safe to call                 
	}

	Base* b2 = new Derived();
	//成功, 因为b2的确指向derived                     
	if (Derived * d = dynamic_cast<Derived*> (b2))
	{
		cout << "donwcast from b2 to d successful\n";
		d->name();    // safe to call                 
	}
}
/*指定构造函数或转换函数 (C++11 起)为显式，即它不能用于隐式转换和复制初始化*/
struct A
{
	A(int) { }      // 转换构造函数
	A(int, int) { } // 转换构造函数 (C++11)
	operator bool() const { return true; }
};

struct B
{
	explicit B(int) { }
	explicit B(int, int) { }
	explicit operator bool() const { return true; }
};

void testExplicit()
{
	A a1 = 1;      // OK ：复制初始化选择 A::A(int)
	A a2(2);       // OK ：直接初始化选择 A::A(int)
	A a3{ 4, 5 };   // OK ：直接列表初始化选择 A::A(int, int)
	A a4 = { 4, 5 }; // OK ：复制列表初始化选择 A::A(int, int)
	A a5 = (A)1;   // OK ：显式转型进行 static_cast
	if (a1);      // OK ：A::operator bool()
	bool na1 = a1; // OK ：复制初始化选择 A::operator bool()
	bool na2 = static_cast<bool>(a1); // OK ：static_cast 进行直接初始化

  //B b1 = 1;      // 错误：复制初始化不考虑 B::B(int)
	B b2(2);       // OK ：直接初始化选择 B::B(int)
	B b3{ 4, 5 };   // OK ：直接列表初始化选择 B::B(int, int)
//  B b4 = {4, 5}; // 错误：复制列表初始化不考虑 B::B(int,int)
	B b5 = (B)1;   // OK ：显式转型进行 static_cast
	if (b2);      // OK ：B::operator bool()
//  bool nb1 = b2; // 错误：复制初始化不考虑 B::operator bool()
	bool nb2 = static_cast<bool>(b2); // OK ：static_cast 进行直接初始化
}
int main()
{
	//alignInfo();
	//showAuto();
	//testDynatic_cast();
	testExplicit();
	return 0;
}