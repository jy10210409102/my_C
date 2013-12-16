/*
 * Mouse.cpp
 *
 *  Created on: 2013-12-14
 *      Author: Administrator
 */
#include "../../head/Css.h"
class Mouse {
public:
	Mouse(float weidgt) {
		this->weidgt = weidgt;
	}
	void eat(float food);	//吃
	void run();				//逃跑
	void die();				//死了
	void mock() {			//嘲讽
		cout << "大笨猫你抓不到我~~~：" << weidgt << endl;
	}

	float getWidget(){
		return this->weidgt;
	}
private:
	float weidgt;
};
