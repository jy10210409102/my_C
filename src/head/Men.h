#include "css.h"
class Men{
private:
	string name;
	int age;
public :
	Men(string name ,int age){
		this->name = name;
		this->age = age;
	};
	~Men(){
		//cout<<"destruct"<<endl;
	};
	string getName();
	int getAge();
	void setName(string name);
	void setAge(int age);
	static void show();
	static void shiXian(){
		cout<<"this is static method"<<endl;
	}

	friend void friendMethod(Men &obj);   //友元函数

};
