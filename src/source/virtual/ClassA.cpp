/*
 * ClassA.cpp
 *
 *  Created on: 2013-12-14
 *      Author: Administrator
 */

#include "../../head/Css.h"

class ClassA {
public:
	int a;
	int b;
	//ClassA(){}


	ClassA(int a,int b): a (a),b(b){
		cout << "A 被构造"<<endl;
	}
	void a_showMethod1() {
		cout << "a_1" << endl;
	}
	void a_showMethod2() {
		cout << "a_2" << endl;
	}

	virtual void show(){
		cout << "a_show" << endl;
	}
};

