//============================================================================
// Name        : Css.cpp
// Author      : chenli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include "../head/Css.h"
#include "../head/Men.h"
#include "catandmouse/Cat.cpp"
#include "catandmouse/Mouse.cpp"
#include "virtual/ClassB.cpp"
#include <iostream>
#include <fstream>
#include <fcntl.h>		// 文件操作
#include "LinkList/LinkList.h"
#include <io.h>
//#include <stdlib.h>

typedef struct {
	string name;
	int age;
} person;

void catCatchMouse(); //类的初使用 猫抓老鼠模拟
void virtualTest(); //继承和虚函数测试
bool write(char* name, string txt); //测试写文件
void linux_file_operate(string name, string txt);	//linux 创建读写文件测试
void charStringTest();	//字符数组  字符指针  字符串指针 测试
void yinYongTest();//测试引用
void yinYongTest2(int &i),readArray(char *str); //测试引用   函数声明方式多样性
void (*fun)(char *str);
void function1(),function2(),function3(),(*function)(void),doFunction();	//函数指针测试
void readWrite(char *filename1 ,char * filename2);//拷贝文件 c中非标准文件读写测试
void pointTest();		//指针测试

typedef void (*Function)();	//给函数定义别名
typedef struct {			//给结构体定义别名  一个是函数名字符串  一个是函数指针
	string name;
	Function fun;
}funStruct;

string funName[]={"function1","function3"};  //通过这个数组执行函数

funStruct funStructArry[] = {				//定义 funStruct 数组
		"function1",function1,
		"function2",function2,
		"function3",function3,
};



Cat cat(50); //猫
Mouse mouse(10);//鼠

//类成员函数放在外面写测试
void Mouse::eat(float food) {
	this->weidgt += food;
	cout << "我偷吃了，现在体重是：" << weidgt << endl;
}

void Mouse::run() {
	this->weidgt -= 0.4;
	if (this->weidgt <= 0) {
		this->die();
	}
	cout << "跑的好辛苦，现在体重是：" << weidgt << endl;
}

void Mouse::die() {
	cout << "跑不动了，归西了~~~" << endl;
}

int main() {
	cout << "Hello World!!!" << endl; //
	vector<string> m_vec_str;
	m_vec_str.push_back("sss");
	cout << m_vec_str[0] << endl;

	vector<person> persons;
	person zhangsan;

	zhangsan.name = "zhang_san";
	zhangsan.age = 28;

	persons.push_back(zhangsan);
	cout << persons[0].name << endl;

	Men lisi("li_si", 25);
	Men *wangwu = new Men("wang_wu", 88); 	//new 返回的是一个指针
	cout << wangwu->getName() << endl;
	wangwu->show();
	Men::show();
	Men::shiXian();
	vector<Men> mens;
	mens.push_back(lisi);
	mens.push_back(*wangwu);
	for (int i = 0; i < mens.size(); i++) {
		cout << mens[i].getName() << endl;
	}
	friendMethod(*wangwu);
	delete wangwu;

	virtualTest();			//继承以及虚函数测试
	catCatchMouse();		//猫抓老鼠 类逻辑测试

	//write("text.txt", "今天天气好晴朗");	//文件流读写测试
	//linux_file_operate("ssss", "ssss");
	charStringTest() ;  //char[] he char* 测试
	yinYongTest();//引用测试

	char arrayChar[] = "this english";
	readArray(arrayChar);

	fun =readArray;
	(*fun)(arrayChar);
   char *s ="sssasdasdasdasds";
   delete s;
   free(s);				//什么情况下释放掉？ 这里并没有起作用
   //s = NULL;
   cout<< s<<endl;
	//函数指针测试
	doFunction();



	//-------链表测试-----------
	LinkList linkList;
	linkList.createStudentList(10,2);
	for (int i = 1; i <= 5; i++) {
		linkList.insertStudent(linkList.createStudent(i,i));
	}
	cout<<"链表个数"<<linkList.getSize()<<endl;
	linkList.deleteStudent(2);
	linkList.printStudent();
	cout<<"链表个数"<<linkList.getSize()<<endl;
	cout<<"链表测试完毕"<<endl;
	//---------------------------
	char *file1="F:\\chenli\\chenli.txt";
	char *file2 ="F:\\chenli\\chenli2.txt";
	readWrite(file1,file2);//拷贝文件测试

	pointTest();//指针

	//运算符重载
	ClassB operatotA(1,2);
	ClassB operatorB(25,11);
	cout<<"b:"<<(operatotA.operator +(operatorB).b)<<endl;
	cout<<"c:"<<(operatotA.operator +(operatorB).c)<<endl;
	return 0;
}


/**************************************************************************
 * 指针测试
 */


/**
 * 一、指针运算  以及一位数组和指针的关系
 * 注意比较循环体中的 当指针++下移一位的时候指针已经改变
 * 当是字符数组的时候*(pChar++) 是错的
 * 数组是常量 地址值不可改变
 * 定义上的区别: 指针是个变量，可以进行加或减运算，可以改变其指向的内存地址值，而数组是个常量，其内存地址的值不可改变。
 *
 * 精华：
 * 		1、在C语言中，当数组出现在表达式中，就退化为指针了
 * 		2、但在C语言中，printf一遇到地址，就打印出地址里面的内容值，直到/0为止
 */
void pointOperation(){
	char *pChar={"pin yin"};
	//char pChar[]={"wo yong de shi pin yin"};
	int length = strlen(pChar);
	for(int i=0;i<length;i++){
		cout<<"第"<<i<<"个"<<pChar[i]<<endl;
		cout<<"第_"<<i<<"个"<<*(pChar++)<<endl;
	}

}

/**
 * 二 、二维数组与指针的关系   指针数组本质上是数组，数组指针本质上是指针。
 * 		*指针数组：指针数组是一种特殊的数组，这类数组里面存放的全是指针。
 *			指针数组元素个数： 因为指针数组里面存放的都是首地址，所以每个元素大小都是4 然后数组总大小除以单位大小，则得到的就是个数了
 *
 *		*数组指针: 数组指针是指向一个数组的指针。 如 char(*c)[4]([]的优先级比*高，因此要有括号). 定义了一个指向长度为4的数组的指针。
 */
void arrayPoint(){
	char *str[] ={"tian","qi","hao"};
	int length = sizeof(str)/sizeof(str[0]);
	cout<<"数组的长度:"<<length<<endl;
	for(int i=0;i<length;i++){
		cout<<str[i]<<endl;
	}
	const int size = sizeof("耐");

	cout<<"一个汉字字符串大小："<<size<<endl;

	char c[][size]={"che","kei","成" ,"功","找","方","法"};
	char (*p)[size];    //可以看成 *p char[4];  p指向一维数组的首地址  或是看成 char[4]=>M  M *P;
	p=c;
	length =sizeof(c)/sizeof(c[0]);
	for(int i=0;i<length;i++){
		cout<<"行数"<<i<<p[i]<<endl;
		//cout<<"行数"<<i<<*p++<<endl; //对的 为了测试屏蔽了
		cout<<"行数"<<i<<p[i][0]<<endl;
	}
}

//指针测试主函数
void pointTest(){
	pointOperation();//指针运算测试
	arrayPoint();//二维数组和指针的关系 以及指针数组和数组指针
}
//***************************************************************************

/************************************************************************************
 * 函数指针测试
 */
//遍历funStruct 数组 调用数组中的方法  //如果一定要传整个数组，可以放结构体里。  传输组而不是传地址！！！！
void doFunction(){
	int count =sizeof(funName)/sizeof(funName[0]);
	int functionCount = sizeof(funStructArry)/sizeof(funStructArry[0]);
	cout<<"个数："<<count<<endl;
	for (int j = 0; j < functionCount; j++) {
		for (int i = 0; i < count; i++) {
			if (funName[j].compare(funStructArry[i].name)==0) {
				funStructArry[j].fun();
			}
		}
	}
}

void function1() {
	cout << "function1" << endl;
}

void function2() {
	cout << "function2" << endl;
}

void function3() {
	cout << "function3" << endl;
}

/************************************************************************************/


/**
 * 指针参数测试
 */
void readArray(char *str){
	int length = strlen(str);
	for(int i=0;i<length;i++){
		cout<<"str:"<<str[i]<<endl;
	}
}
/**
 * 引用的规则：

（1）引用被创建的同时必须被初始化（指针则可以在任何时候被初始化）。
（2）不能有NULL引用，引用必须与合法的存储单元关联（指针则可以是NULL）。
（3）一旦引用被初始化，就不能改变引用的关系（指针则可以随时改变所指的对象）。
 */
void yinYongTest(){
	int a=5;
	int &b =a;
	int c = 10;
	b=c;
	//&b = c;//错误
	cout<<"b:"<<b<<endl;
	cout<<"a:"<<a<<endl;
	yinYongTest2(b);
	cout<<"a:"<<a<<endl;
}

// 引用在函数里
void yinYongTest2(int &i){
	i= 100;
}

/**
 * 字符数组  字符指针  字符串指针 测试
 *
 * 对于语句  char *a="hello";
 * 即正确顺序是：1.分配内存给字符指针；2.分配内存给字符串；3.将字符串首地址赋值给字符指针；
 *
 * 字符数组与字符串指针的区别
（1）存储方式：字符数组：分配一个存放元素的单元。
                 字符串指针：分配一个存放元素地址的单元，地址指向元素首地址。不
                             是将整个字符串放到字符指针变量中。
（2）赋值方式：
		  字符数组：char str[16]={“a,b,c”}  char a[]=”abc”;
          字符串指针： char *str=”abc”    char *str; str=”abc”;
（3）定义方式：
		  字符数组:char str[10];scanf(“%s”,str);
          字符串指针：char *str,a[10];str=a;scanf(“%s”,str); 指针str必须得指向一个数组，
          不然就是野指针了。
（4）运算方面
		  字符数组：字符数组名是常量，不能进行运算，不能改变值。如：
             char a[]=”abc”; a=a+1;这是错误的。
          字符串指针： 指针变量的值是可以改变的，可以进行运算，如++，==等操作。
             如：char *a=”abc”; a=a+1;这是正确的

             不能用sizeof来计算指针大小，用strlen；

 */
void charStringTest() {
	char charArray[] = "charArray";
	char *stringPoint = "stringPoint";
	string stringClass = "this is string";
	cout<<charArray<<endl;
	cout<<stringPoint<<endl;
	//stringPoint = charArray;//字符串首地址赋给字符串指针
	cout<<stringPoint<<endl;
	cout<<"sizeof(stringPoint):"<< sizeof(stringPoint)<<"strlen(stringPoint):"<<strlen(stringPoint)<<endl;
	int count = strlen(stringPoint);
	for(int i=0; i<count;i++){
		cout<<"stringPoint:"<<stringPoint[i]<<endl;
	}
	for(int i = 0; i<sizeof(charArray)/sizeof(char)-1;i++){
		charArray[i] = stringPoint[i];
	}
	cout<<"sizeof(charArray) :"<<sizeof(charArray)<< "sizeof(char) " <<sizeof(char)<<"sizeof(charArray)/sizeof(char)"<<sizeof(charArray)/sizeof(char) <<endl;
	cout<<charArray<<endl;

	//string转正 char*
	const char *stringP= stringClass.data();//方式一 返回的是一个const指针		//const 修饰的指针可以赋值，但是不能改变； 如下
	//stringP[2] ='s'; //错的 编译报错
	stringP = stringClass.c_str();			//方式二 返回的是一个const指针
	int stringPointCount = strlen(stringP);
		for(int i=0; i<stringPointCount;i++){
			cout<<"stringPointCount:"<<stringP[i]<<endl;
		}
}


/********************************************************************************
 * 写文件测试
 * 一、头文件：
 * 		1、iostream 从流中读取写入
 * 		2、fstream  从文件读写数据
 * 		3、sstream  从string读写数据
 *
 * 二、特性
 * 		IO对象无拷贝或赋值，因此不能讲形参或返回类型设为流对象
 * 			如ofstream a,b; a=b;   错误
 *
 *疑问创建读写指定路径的文件
 */
bool write(char* name, string txt) {
	const char filename[] = "text.txt";
	ifstream m_ifstream;
	ofstream m_ofstream(name);  //输出文件类对象
	string fileText;
	if (m_ofstream < 0) {
		cout << "文件打开失败" << endl;
	}
	for (int i = 0; i < 100; i++) {
		m_ofstream << "、" + txt << endl;
	}

	m_ofstream.close();
	m_ifstream.open(filename);
	if (m_ifstream.is_open()) {
		while (m_ifstream.good()) {
			m_ifstream >> fileText; 		//将读出的流写到fileText中
			cout << "读取出：" + fileText << endl;
		}
	} else {
		//cout << "文件：" + name + "打开失败！" << endl;
	}
	return false;
}


/**失败*/
void linux_file_operate(string name, string txt) {
	int from_fd;
	/* 打开源文件 */
	const char filename[] = "E:\\mytext.txt";
	if ((from_fd = open(filename, O_RDWR | O_CREAT | O_EXCL, 0666)) < 0) {
		cout << "文件打开失败" << endl;
		// fprintf(stderr, "Open %s Error：%s\n",name, strerror(errno));
	}
}



//c中标准读写 和非标准读写 非标准效率更高 标准每次只能读一个字符和写一个字符  非标准等依赖系统

/**
 * 非标准读写测试
 * 一般用于二进制文件 只有成块读写二进制数据
 *		一、建立非标准文件
 * 			写 ：文件不存在或虽然存在但要对其内容进行重写，用creat（char *str ,int mode）,建立新文件
 * 				mode 的几种选择 ：
 * 					1、S_IWRITE 允许写； 2、S_IREAD 允许读； 3、S_IWRITE|S_IREAD 允许读写
 * 		二、打开和关闭
 * 			int open(char *fileName , mode);  可以包含文件路径
 * 			mode 指定了文件操作代码符号
 * 			 MODE:只读、只写、读写、追加、文件不存在则建立，否则无效、将文件裁为0 、及二进制方式打开文件、以字符方式打开文件  （10种《有一种与creat一起用》）
 *			打开后，文件指针指向文件头；打开失败返回-1
 *			close(int handle); 关闭文件；
 *		三、读写
 *			read(int handle,void *buffer ,int count);
 *				解析：从handle标示的文件中读取count个字节，送到buffer指定内存缓冲中
 *				返回值： 读取的字节数 ， 0：标示结束  -1：标示操作失败
 *			write(int handle ,void *buffer,int count)
 *				解析：类容read
 *				返回值： 写入字节数 -1：标示失败；
 *				O-APPEND 在文件后面开始写
 *			fseek()随机读写文件：暂不弄
 */

//读写测试  将一个文件复制到另一个文件中   路径和文件名不能含中文
#define BUFFSIZE 512
#define	_S_IWRITE	0x0080
void readWrite(char *filename1 ,char * filename2){
	int fd1,fd2;
	int size1,size2;
	char buff[BUFFSIZE];
	cout<<"文件："<<filename1<<endl;
	if((fd1=open(filename1,O_RDONLY))<0){		/*只读打开文件*/
		cout<<"打开文件失败"<<endl;
		return;
	}else{
		cout<<"打开文件成功"<<endl;
	}

	if((fd2 = creat(filename2 ,_S_IWRITE))==EOF){//创建要写的文件
		cout<<"创建失败！"<<endl;
		close(fd1); //创建失败关闭源文件
		return;
	}else{
		cout<<"创建成功！"<<endl;
	}

	while((size1=read(fd1,buff,BUFFSIZE))>0){			//精髓
		size2= write(fd2,buff,size1);
		if(size2!=size1){
			cout<<"size2!=size1 失败！！"<<endl;
			close(fd1);
			close(fd2);
			return;
		}
	}
	close(fd1);
	close(fd2);
	cout<<"拷贝完成"<<endl;
}

//****************************************************************************


//虚函数测试
void virtualTest() {
	ClassA a(650, 222);
	cout << a.a << endl;
	cout << a.b << endl;
	ClassB b(100,2);
	cout << b.b << endl;
	cout << b.a << endl;
	ClassA *a_b = new ClassB(100,3);
	a_b->show();
}

//猫抓老鼠
void catCatchMouse() {
	if (mouse.getWidget() <= 0 || cat.getWidget() <= 0) {
		return;
	}
	cat.catchMouse();
	mouse.run();
	catCatchMouse();
}

//可以用类中的私有成员（函数或字段）
void friendMethod(Men &obj) {
	cout << "这是友元函数:" << obj.getName() << endl;
	cout << "友元函数显示私有字段:" << obj.name << endl;
}

string Men::getName() {
	return this->name;
}
int Men::getAge() {
	return this->age;
}
void Men::setName(string name) {
	this->name = name;
}

void Men::setAge(int age) {
	this->age = age;
}

void Men::show() {
	cout << "I'am show" << endl;
}

/* 析构函数
 析构函数(destructor)是一个特殊的成员函数，它的作用与构造函数相反，它的名字是类名的前面加一个“～”符号。
 在C++中“～”是位取反运算符，从这点也可以想到：
 析构函数是与构造函数作用相反的函数。
 当对象的生命期结束时，会自动执行析构函数。
 具体地说如果出现以下几种情况，程序就会执行析构函数：
 ①如果在一个函数中定义了一个对象(它是自动局部对象)，当这个函数被调用结束时，对象应该释放，在对象释放前自动执行析构函数。
 ②static局部对象在函数调用结束时对象并不释放，因此也不调用析构函数，只在main函数结束或调用exit函数结束程序时，才调用static局部对象的析构函数。
 ③如果定义了一个全局对象，则在程序的流程离开其作用域时(如main函数结束或调用exit函数)时，调用该全局对象的析构函数。
 ④如果用new运算符动态地建立了一个对象，当用delete运算符释放该对象时，先调用该对象的析构函数。
 析构函数的作用并不是删除对象，而是在撤销对象占用的内存之前完成一些清理工作，使这部分内存可以被程序分配给新对象使用。
 程序设计者事先设计好析构函数，以完成所需的功能，只要对象的生命期结束，程序就自动执行析构函数来完成这些工作。
 析构函数不返回任何值，没有函数类型，也没有函数参数。
 因此它不能被重载。
 一个类可以有多个构造函数，但只能有一个析构函数。
 实际上，析构函数的作用并不仅限于释放资源方面，它还可以被用来执行“用户希望在最后一次使用对象之后所执行的任何操作”，例如输出有关的信息。

 只有当一个类被用来作为基类的时候，才把析构函数写成虚函数。


 如果你自己不实现系统会帮你实现，不过系统实现的析构函数什么也不做。你自己实现的目的是delete掉你new的东西。比如你有一个类class Test,析构函数就是：~test(){delete a; a=NULL;};
 a就是你Test类中new的对象.
 */

/* 友元函数和友元类

 采用类的机制后实现了数据的隐藏与封装，类的数据成员一般定义为私有成员，成员函数一般定义为公有的，依此提供类与外界间的通信接口。但是，有时需要定义一些函数，这些函数不是类的一部分，但又需要频繁地访问类的数据成员，这时可以将这些函数定义为该函数的友元函数。除了友元函数外，还有友元类，两者统称为友元。友元的作用是提高了程序的运行效率（即减少了类型检查和安全性检查等都需要时间开销），但它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员。

 友元函数 ：
 友元函数是可以直接访问类的私有成员的非成员函数。它是定义在类外的普通函数，它不属于任何类，但需要在类的定义中加以声明，声明时只需在友元的名称前加上关键字friend，其格式如下：
 friend  类型 函数名(形式参数);

 友元函数的声明可以放在类的私有部分，也可以放在公有部分，它们是没有区别的，都说明是该类的一个友元函数。
 一个函数可以是多个类的友元函数，只需要在各个类中分别声明。
 友元函数的调用与一般函数的调用方式和原理一致。

 友元类 ：
 友元类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员）。
 当希望一个类可以存取另一个类的私有成员时，可以将该类声明为另一类的友元类。定义友元类的语句格式如下：
 friend class 类名;
 其中：friend和class是关键字，类名必须是程序中的一个已定义过的类。

 例如，以下语句说明类B是类A的友元类：
 class A
 {
 …
 public:
 friend class B;
 …
 };
 经过以上说明后，类B的所有成员函数都是类A的友元函数，能存取类A的私有成员和保护成员。

 使用友元类时注意：
 (1) 友元关系不能被继承。
 (2) 友元关系是单向的，不具有交换性。若类B是类A的友元，类A不一定是类B的友元，要看在类中是否有相应的声明。
 (3) 友元关系不具有传递性。若类B是类A的友元，类C是B的友元，类C不一定是类A的友元，同样要看类中是否有相应的申明
 */

/**  构造函数的写法
 *  如类有两个字段
 *	ClassA{
 *		public:
 *			int a;
 *			int b;
 *	}
 *
 *	1、构造函数
 *		ClassA(int a,int b):a(a),b(b){}
 *	2、构造函数
 *		ClassA(int a,int b){
 *			this->a = a;
 *			this->b = b;
 *		}
 * 继承的时候构造
 * 		ClassB :: public ClassA{
 * 		    public:
 * 		    	int count;
 * 		    	//构造函数
 * 		    	ClassB(int a,int b, int count):ClassA(a,b),count(count){}
 *
 * 		}
 *
 *
 *
 *
 *
 */
