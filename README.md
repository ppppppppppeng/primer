# 第一章 开始
### cout和注释
+ cout想要输出/* 或 */ 必须首先遇到"" 并输出""包裹的内容，如果首先遇到的是`/*`或`*/`则视为注释 
# 第二章 变量和基本类型
## unsigned类型转换
+ 将有符号转给无符号时，取模
+ 将无符号转给有符号时，得到的值是未定义的
### 含有unsigned类型的表达式类型转换
+ 如果表达式中含有unsigned会有以下几种方式
	+ 如果无符号类型的容量小于有符号的，则无符号或转成有符号
	+ 否则有符号转成无符号
```
	unsigned u = 10;
	int i = -42;
	std::cout << i + i << endl;
	std::cout << u + i << endl;
```
+ i + i 不会类型转换，结果为-84
+ u + i int会隐式转换为unsigned int
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
+ vector和string通过下标只能访问以存在的元素
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
+ 其他运算符求职顺序未定义，在复合表达式中使用修改和使用同一变量的结果是未知的
```
	int n = 0;
	cout << n << ++n << endl; //错误，<< n 和 << ++n 执行的顺序不定
	while(beg != s.end() && !isspace(*beg))
		*beg = toupper(*beg); //错误
	// 编译器可能会按照下面的任一种思路处理
	*beg = toupper(*beg);
	*(beg + 1) = toupper(*beg);
```  
### 取余运算符
+ 只能有整型参与取余运算符
+ ` (-m) % n `等价于 `-(m % n)`
+ `m % (-n)`等价于`m % n`
### 条件运算符的优先级很低
+ 输出条件运算符，需要加()
```
	cout << ( (grade < 60) ? "fail" : "pass"); //正确
	cout << (grade < 60) ? "fail" : "pass"; //错误，<<优先级高于？优先级
```
## 位运算
+ char在进行位运算时，其拷贝会先提升为int，在对这个int进行位运算
# 第五章 语句
### switch内部定义变量
+ 对于多个case分支，属于一个块内，不能绕过变量的初始化跳到该变量作用域的另一个位置
,所以switch语句不允许对变量初始化
	+ 若想对变量初始化，可以使用{}包裹限定作用域
```
	case true:
		string file_name; //错误，流程控制绕过一个仪式初始化变量
		int ival = 0;	  //错误，流程控制绕过一个显示初始化变量
		int jval;		  //正确，jval没有进行初始化操作

		break;
	case false:
		jval = next_num()； //正确

//使用{}限定作用域
	case true:
		{	
			string file_name = get_file_name();
		}
		break;
	case false:
		if(file_name.empty()) //错误，file_name不在作用域内
	
		
```
### 范围for的迭代器失效
+ 范围for内部实现用到了迭代器，所以不能在范围for里对本容器添加元素或改变容量
### do while条件的作用域
+ do while的条件必须定义在循环体之外
+ do while的()中不能定义变量
### goto
+ 会无条件跳到同一个函数的另一个语句的位置
	+ goto向下跳转时会忽略到目的语句间的所有代码，如果这个代码里定义了变量，后边的语句若使用了它将找不到定义而出错
### try catch
+ 一个函数的try里调用另一个函数的try
	+ catch的捕获顺序是由内而外的，和函数调用顺序相反
	+ 如果在当前函数中没有找到对应的catch会终止当前函数，并去调用当期啊函数的函数那里去寻找对应的catch，到了main函数还没找到，进程会转去执行terminate库函数，导致程序非正常退出
+ try catch的目的是为了让异常出现时不会退出进程而是解决异常并继续正常执行
+ throw一旦执行， 剩下的语句不会执行
+ catch执行后，会继续执行catch控制块下面的语句
+ 异常安全
	+ 当异常发生时，剩下的语句都不会执行
	+ 如果剩下的语句包含一些重要操作，比如回收资源，就会导致资源泄露
	+ 对于捕获异常时要注意回收这些资源
# 第六章 函数
### 多个形参不是逗号表达式
+ 如果函数有多个形参，初始化顺序不定
+ 每个形参都要定义类型，不能`(int a, b)`
### 局部静态static
+ 在程序执行到第一次定义时才会在全局区开辟内存
### 数组形参
+ 数组形参中[]里面可以指定一个值，但是这个值没有卵用
### 数组引用参数
+ 数组的引用是绑定到数组上而不是绑定到第一个元素上
```
	void print(int (&arr)[])
	{
		for(auto elem : arr)
			cout << elem << endl;
	}	
```
### 多维数组传参
+ 多维数组的参数必须指定数组指针的长度
	+ 数组传参的本质是指针，因此多维数组传参本质是数组的指针，定义数组的指针必须指定所指向数组的长度 
```
	void print(int matrix[][10], int rowSize)
	{
	}
	
	void print(int (*matrix)[10], int rowSize)
	{
	}
```
### initializer_list可变形参
+ 必须是同一类型的形参
+ 可以和其他参数一起传
+ 使用方法类似vector
```
	void error_msg(initializer_list<string> il)
	{
		for(auto &elem : il)
			cout << elem << " ";
		cout << endl;
	}

	error_msg({"finctionX", s1, s2});
	error_msg({"finctionX", "okey"});
```
### 每个分支都要有返回值
+ 对于有返回值的函数，如果使用了流程控制，注意在最后可能属于另一分支，要加返回值
### 返回值是一个对象
+ 函数的调用表达式可以参与其他表达式，参与者是返回值，参与方式由返回值是一个左值还是右值决定
+ 可以在return 后面直接写返回值的初始化
+ 比如列表初始化返回值
```
	vector<string> process()
	{
		if(s1.empty())
			return {};
		else if(s1 == s2)
			return {"functionX", "okey"};
		else 
			return {"functionX", s1, s2};
	}
```
### 返回数组指针
+ 传统方式
```
	int (*func(int i))[10] 
	{
	} 
```
+ 声明别名
```
	typedef int arrT[10]; //arrT类型是int[10]
	using arrT = int[10]; //同上
	
	arrT *func（int i）;
```
+ 尾置返回类型
```
	auto func(int i) -> int (*)[10]
	{
	
	}
```
+ decltype
```
	int odd[10];
	decltype(odd) *func()
	{
		
	}
```
### 调用重载函数
+ 编译器会逐个对比形参和实参
	+ 优先找最佳类型匹配
	+ 其次找可转换类型匹配
		+ 优先类型提升
		+ 其次算数类型
	+ 如果没有最佳类型匹配，且有多个匹配一样好，发生 二义性调用 错误
	+ 如果没有匹配，发生 无匹配 错误
### 函数指针和返回函数指针的函数
+ 函数指针的类型必须声明为指针，给函数指针类型赋值/初始化可以用函数名（此时函数名当成指针处理）
+ 指向重载函数的函数指针必须精确匹配
# 第七章 类
### 常量成员函数和this
+ this指针是一个顶层const指针
`Sale_data *const this`
+ 不能显式定义名为this的指针
+ const函数会修改该函数的this指针变为底层const
`const Sales_data *const this`
	+ const函数不能修改成员
	+ const成员函数只能调用const成员函数
	+ const对象只能调用const成员函数
### 合成默认构造
+ 只有在没有定义构造函数时编译器才会自动合成默认构造
+ 使用 `= default;`声明构造函数会等价于合成默认构造的执行
+ 如果初始化列表中没有给成员赋初值，则根据成员的初始值初始化，若无初始值，则执行默认初始化
+ 如果成员中有对象没有默认构造函数，则该类的默认构造函数也无法正常执行
### class和struct
+ 唯一的区别就是默认访问权限
### 友元
+ 友元的声明只是声明友元，而不是函数或对象的声明，如果需要使用它，则需要专门声明函数或对象
### 可变数据成员mutable
`mutable size_t access_ctr`声明可变数据成员，即使函数是const，也可以改变这个值
### 类内定义函数和类外定义函数
+ 类内定义的函数会隐式转化为inline
+ 类内声明类外定义的函数不会隐式转化为inline
### const函数返回*this指向const对象
+ const函数的this是`const *this`
+ 返回引用使用`return *this`时返回的是`const &`
+ const和非const的同名函数可以实现重载关系
### 类的声明和类的定义
+ 类可以被声明，但是类必须被定义才能创建该类类型的对象
	+ 类中不能含有该类型的对象，因为该类还没有被定义
	+ 类中可以包含指向该类类型的引用或指针，因为该类已被声明

### 类外定义成员函数
+ 类外定义成员函数的返回值如果是类内定义的类型，需要加类名作用域
	+ 出返回值外，其他的成员都在类名作用域之内，可以不用声明
### 委托构造函数
+ 委托构造函数会先调用委托的函数
+ 委托构造函数可以被委托
### 隐式类类型转换
+ 一个类类型的形参在接收一个不是该类型但是可以给其初始化的实参时，发生隐式类类型转换
	+ 该函数必须只有一个参数
	+ 该函数的形参可以被实参一步初始化
```
	//用null_bool初始化combine的参数，创建一个Sales_data类型的临时对象
	//combine是一个常量引用，可以用一个临时变量变量初始化
	string null_book = "9-999-99999-9";
	item.combine(null_book);
```
+ 编译器只允许一步类类型转换
```
	//错误，需要先转string 在转Sales_data
	item.combine("9-999-99999-9");
	
	//正确
	item.combine(string("9-999-99999-9"));
	item.combine(Sales_data("9-999-99999-9"));
```
### explicit
+ 只能在类的声明处使用，不能在定义处使用
+ 只能用于只有一个参数的构造函数
+ 创建对象时如果调用了声明expilcit的构造函数，则
	+ 只能用()的形式直接初始换，不能用=的形式直接初始化
	+ 不能使用隐式转换，但依然可以使用显式转换

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
+ 重载是指在同一区域内的多个函数,参数必须不同，函数名必须相同
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
