/*
 * ClassB.cpp
 *
 *  Created on: 2013-12-14
 *      Author: Administrator
 */
//#include "../../head/Css.h"
#include "classA.cpp"
class ClassB: public ClassA {
public:
	int b;
	int c;
//	ClassB(int a,int b,int c):ClassA(c){
//		this->a=a;
//		this->b=b;
//		cout << "B 被构造"<<endl;
//	}
	ClassB(int m,int n) :ClassA(m, n), b(10),c(n) {
		cout << "B 被构造" << endl;
	}
	void b_showMethod1() {
		cout << "b_1" << endl;
	}
	void b_showMethod2() {
		cout << "b_2" << endl;
	}
	
	/*virtual*/	void show(){
		cout << "b_show" << endl;
	}

	ClassB operator +( ClassB obj){
		ClassB temp(0,0);
		temp.b =obj.b + this->b;
		temp.c = obj.c +this->c;
		return temp;
	}
};

