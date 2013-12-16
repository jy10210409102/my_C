/*
 * Cat.cpp
 *
 *  Created on: 2013-12-14
 *      Author: Administrator
 */
#include "../../head/Css.h"
/**
 * 猫
 */
class Cat{

public :
	Cat(float weidgt){
		this->weidgt = weidgt;
	}

	void catchMouse(){				//抓老鼠
		this->weidgt-=0.6;
		if(this->weidgt<=0){
			this->die();
		}
		cout << "猫：老鼠！别跑！我狂追~~~" << weidgt << endl;
	}

	void die(){						//死了
		cout << "猫：抓不到了，我死了~~~" << endl;
	}

	float getWidget(){
			return this->weidgt;
	}
private :
	float weidgt;//体重

};


