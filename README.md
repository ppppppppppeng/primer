# 第一章 开始
### cout和注释
+ cout想要输出/* 或 */ 必须首先遇到"" 并输出""包裹的内容，如果首先遇到的是/*或*/则视为注释 
# 第二章 变量和基本类型
## unsigned类型转换
+ 将有符号转给无符号时，取模
+ 将无符号转给有符号时，得到的值是未定义的
### 含有unsigned类型的表达式类型转换
+ 如果表达式中含有unsigned，则其他类型也会转换为unsigned
```
	unsigned u = 10;
	int i = -42;
	std::cout << i + i << endl;
	std::cout << u + i << endl;
```
+ i + i 不会类型转换，结果为-84
+ u + i int会隐式转换为unsigned int
+  
+ 如果表达式中有unsigned，则最终结果会转成unsigned
```
	usigned u1 = 42, u2 = 10;
	std::cout << u1 - u2;
	std::cout << u2 - u1; 
```  
+ u2 - u1 先得到一个负值，在对这个负值取模
+ 无符号类型不能小于0，作为条件时时刻注意u <= 0,u >= 0 可能会造成的死循环
### 列表初始化
+ 初始化一个变量的方式
	+ int units_sold = 0;
	+ int units_sold = {0};
	+ int units_sold{0};
	+ int units_sold(0)
+ 列表初始化 
	+ 使用花括号
	+ C++11标准
+ 列表初始的特点
	+ 用于内置变量的初始化时，如果存在潜在风险，会编译出错
```
	long double ld = 3.1415926536;
	int a{ld}, b = {ld}; //错误：转换未执行，因为存在丢失信息的风险
	int c(ld), d = ld; //正确：转换执行，且丢失了部分数据
```  
## 引用
+ 注意引用不是类型修饰符，而是变量修饰符，所以对于连续声明，都要加&
	+ 指针的声明符 * 同理
```
	int a = 1024;
	int &r = i, b = 1024;
```
+ 非const引用的初始值必须和引用的类型相同
```
	double dval = 3.14;
	int &r = dval; //出错
```
### const引用
+ const 引用的初始值可以是
	+ 一个任意类型的变量或常量，该变量或常量可以化为该引用的类型
```
	int i = 42;
	const int  &r1 = i;
	double d = 3.14;
	const int &r2 = d;
```
	+ 一个表达式，它的结果可以转化为该引用的类型
```
	const int  &r3 = r1 * 2;  
```
	+ 一个字面值
```
	const int &r4 = 42;
```
+ 在对const引用初始化一个其他类型时，实际上是分两步
	+ 创建一个临时变量
```
	const int temp = d；
```
	+ 让const引用指向这个临时变量
```
	const int &r2 = temp;
```
### 指针的引用 
```
	int i = 0;
	int *p = &i;
	int *&r = p;
```
## C++指针
+ 指针不能指向引用，因为引用无地址
+ 指针的类型必须和它指向的变量类型相同
### 指向const的指针
+ 指向const的指针可以赋值成任意该类型变量的地址（可以是const或非const），不能通过该指针解引用直接修改指向的变量
```
	double d = 3.14;
	const double *p = &d;
```
+ 如果指针指向的变量是顶层const，那么这个指针一定要定义成底层const
### const指针
+ 在变量名之前加const
+ const指针必须初始化
+ const指针中保存的地址不可变
```
	int i = 0;
	int *const  pi = &i;  //p1是一个指向i的常量指针
	const double d = 3.14;
	const double *const pd = &d; //pd是一个指向常量的常量指针 
```
### 顶层const和底层const
+ 顶层const修饰变量，底层const修饰指向的变量
+ 两个指针/引用赋值/初始化时，不能将底层是const的赋值/初始化给底层不是const的
### 指针常量和类型别名
```
	typedef char *pstring;
	const pstring cstr = 0; //cstr是指向char的 常量指针
	const pstring *ps		//ps是一个指针，它指向一个常量指针，这个常量指针指向char
	// 对于pstring 指针的别名，用const修饰pstring时，顶层const
	const char *cstr = 0; 	//是对const pstring cstr的错误理解，这里的类型是char，创造出的变量是*cstr,而pstring类型是char *的别名，两者不一样
```
### auto 和 const
+ auto会忽略顶层const
+ auto在声明复合类型是，保留底层const
```
	const int ci = 0, &cr = ci;
	auto b = ci; //b是int，const被忽略
	auto c = cr; //c是int，cr是ci的别名，c忽略ci的顶层const
	auto e = &ci; //e是const int *e，是底层const
	
	auto &g = ci; //g是一个整型常量引用
	auto &h = 42; //错误：不能为非常量引用绑定字面值
	const auto &j = 42 //正确

	int i = 0;
	auto &n = i, *p2 - &ci; //错误 i是int ci是const int
	
```
### decltype
+ decltype 会保留顶层const和& *
```
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0; //x的类型是const int
	decltype(cj) y = x; //y的类型是const int &, y绑定到x
	decltpye(cj) z; 	//错误，z是一个引用，必须初始化
```
# 第三章 字符串、向量和数组
## string
### cin>>
+ 对string cin会忽略输入的空格
	+ 对于字符前面的空格，直接忽略
	+ 对于字符后面的空格视为结束符
	+ 对于'\n'视为结束符，从缓冲区读入但不会放入s中
### getline
+ string::getline()是static函数，直接使用，不能用s.getline()
+ getline返回的是一个istream &
+ getline会读取取空格
+ getline直到'\n'才停止读取，并且读取缓冲区的'\n' ，但不会放入s中
### size()
+ s.size()不包含\0;
### size_type
+ string：：size_type 是size()的返回值，是一个unsigned整型，注意避免和有符号整型用在一起做表达式
### string +
+ string可以对""和''相加，在对""相加时会忽略'\0'
+ +运算符是左结合的，所以string的连续+的第一个+号左右必须有一个是string对象
## vector
### vector的列表初始化和()初始化
``` 
	vector<int> v1(10) // v1有10个元素，每个的值是0
	vector<int> v2{10} // v2有1个元素，这个元素值为10

	vector<int> v3(10, 1) //v3有10个元素，每个的值是1
	vector<int> v4{10, 1} //v4有2个元素， 分别是10和1
	
```
+ vector的()初始化只能有以下情况
``` 
	vector<T> v1(t) //t是T类型的对象
	vector<T> v2(v1) //v2和v1是同一类型，v2被初始化和v1的数据相同
	vector<T> v3(10) //括号里是一个unsigned整型，代表默认初始化元素的数量
	vector<T> v4(10, t) //括号里的第一个是unsigned整型，第二个是符合T类型的对象，代表初始化10个t
```
### 注意`vector<string>`
```
	vector<string> v(10, "hi") //正确
	vector<string> v("hi")	   //错误
```
### vector的列表初始化
+ vector的列表初始化会匹配初始化内容的类型和vector元素的类型
	+ 如果相同，视为列表初始化
	+ 如果不同，且第一个数为int，视为默认初始化 
```
	vector<string> v5{"hi"} //列表初始化，v5只有一个元素
	vector<string> v6("hi") //错误，不能使用字符串字面值初始化vector对象
	vector<string> v7{10}  //虽然是使用的{},但是元素是int而不是string，视为(),初始化了10个元素，每个元素是空字符串
	vector<string> v8{10, "hi"} //虽然使用的{}，但是第一个是int型，所以视为(),初始化了10个元素,每个string的值为"hi"
	
```
### vector和string
+ vector和string只能通过下标访问以存在的元素
	+ 这里的访问可以是读或修改，但是如果是const v或者const s不能修改
+ vector和string不能通过下标添加元素
### for(auto x : v)
+ 遍历每一个底层变量
	+ vector<T> 就是T类型的变量
	+ string 就是字符
	+ 数组就是数组的元素
+ x是当前底层变量的复制品而不使v里的变量
	+ 对x的修改不会影响v
	+ 如果想想让x代表v中的变量，就要声明为 auto &x
+ auto也可以写成具体的类型
+ x每对一个对象遍历都进行的是初始化操作而不是赋值操作  
## 迭代器
### begin() end()
+ 都是成员函数，必须通过对象 v.begin(), v.end()调用
	+ 对于数组也有begin()end()库函数，但是不能使用.而是传递数组的元素地址
+ string不是容器，但支持迭代器
+ 两个函数返回的迭代器类型是对象中元素的类型而不是对象的类型
+ end()返回指向最后一个元素的下一个位置（称为“尾后”）的迭代器，又叫“尾后迭代器”
+ 如果容器/string为空，则begin()和end()返回的迭代器都指向尾后
+ 迭代器就是指针，指向容器中的元素，用法和指针相同
	+ 迭代器不能通过对对象取地址的方式获取
	+ 不嫩对end()返回的迭代器进行以下操作
		+ 解引用*iter
		+ 自增 ++iter
	+ 所有容器的迭代器都定义了!=运算符，而大多数容器的迭代器没有定义<运算符 
+ 对于所有容器/string，迭代器都有效，[]只对string和vector有效
### const_iterator
+ const_iterator是常量迭代器
	+ 如果容器/string是常量容器，则必须使用常量迭代器
	+ 如果容器/string是非常量容器，则const_iterator和iterator都可用
### cbegin() cend()
+ 无论容器/string是不是常量，都返回const_iterator 
### 迭代器失效
+ 对一个容器修改容量
+ 对一个vector push_back()
## 数组
### decltype()数组返回数组类型而不是指针类型
```
	int a[] = {1, 2, 3};
	decltype(a) a = {4, 5, 6}; //正确
	decltype(a) b = &a[0]; //错误
	a[0] = 1; 				//正确
``` 
### 数组的尾后指针
+ 指向数组元素指针可以指向尾后指针，但是不能对尾后指针进行解引用和++
```
	constexpr size_t sz = 5;
	int arr[sz] = {1, 2, 3, 4, 5};
	int *p = arr + sz; 	//正确
	int *e = &arr[sz];	//正确
```

### 数组下标
+ 数组的下标可以是负数
+ vector和string的下标不能是负数
### c_str()返回指向string中字符数组的指针
```
	string s；
	char *str = &s; //错误
	const char *str = s.c_str(); //正确
```
+ c_str()的返回值必须是底层const，不能改变s的底层字符数组
### 使用数组初始化vector
```
	int  nums[] = {0, 1, 2, 3};
	vector<int> v1(begin(nums), end(nums));
	vector<int> subVec(nums + 1, nums + 3);
```
### 数组的引用
```
	int a[4];
	int (&ra)[4] = a; //ra是长度为4的int型数组的引用，而不是int的引用
	int b[3][4];
	int (&rb)[4] = b[1];
```
### 多维数组的for(auto i : ia)
```
	int ia[3][4] = {0};
	//正确，auto &row是数组的引用
	for(const auto &row : ia)
		for(auto coi : row)
			cout << coi << endl;

	//错误，auto row是int *类型
	for(auto row : ia)
		for(auto coi : row)
```
+ 要是用范围for对多维数组遍历时，除最内层循环外，其他循环控制变量都必须使用&
# 第四章 表达式
## 运算符
### 运算符的求值顺序
+ 4种运算符定义了求值顺序
	+ && 
	+ ||
	+ ?: 
	+ ,
+ 其他运算符求职顺序未定义，连续使用对同一个变量的操作是错误的
```
	int n = 0;
	cout << n << ++n << endl; //错误，<< n 和 << ++n 执行的顺序不定
```  
### 取余运算符
+ 只能有整型参与取余运算符
+ ` (-m) % n `等价于 `-(m % n)`
+ `m % (-n)`等价于`m % n`
###
###
## 虚析构
+ 子类无法重写父类虚析构
+ 销毁对象时，会从子类往父类依次调用析构函数
+ 一般delete谁就只调用谁的析构函数，但是对于虚析构，delete会依次调用从子类到父类所有的析构函数
+ 虽然从子类到父类的有多个析构函数，但只占用一个虚表中的指针，位置位于子类中析构函数的声明位置，虚析构无法通过虚表里的函数指针调用
## 重写 重载 隐藏
### 重写
+ 重写是指子类重写父类虚函数，重写的函数 函数名 返回值 参数类型和个数  必须和父类完全一致，否则不视为重写
+ 子类的虚函数指针会覆盖虚表中父类的虚函数指针，但不代表父类的函数就会消失，依然存在于代码区，依然可以被调用
### 重载
+ 重载是指在同一区域内的多个函数 除参数不同外，函数名和返回值均相同同，若返回值不同，则编译出错
+ 父类和子类之间的函数不存在重载关系（不属于同一区域）
### 隐藏
+ 父类和子类的同名函数存在隐藏关系
+ 对于非虚函数
	+ 对象是啥类型，就调用啥类型所属的函数
	+ 对象的指针是啥类型，无论对象是啥类型，只调用指针类型所属的函数
+ 对于虚函数
	+ 如果父类和子类的函数 返回值或参数有不同，就存在隐藏关系而不是重写
+ 对于相同名的数据成员，同样遵循隐藏关系
+ 对于全局变量和局部变量，同样存在隐藏关系  
## 重载运算符
## 继承时子类定义和父类相同成员名
+ 只要是继承，都会把父类和子类的全部成员开辟内存，如果子类的成员变量和成员函数相同，编译器会隐式的修改函数名或变量名使其不同，而不是使子类的成员覆盖父类的
