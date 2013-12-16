/*
 * LinkList.cpp
 *
 *  Created on: 2013-12-15
 *      Author: chenli
 */
#include "LinkList.h"

/**
 * 创建只有一个节点的链表，此函数带回一个指向链表头的指针；		如果要用到下标 只能遍历链表了 因为链表内存上是不连续的
 * 思路：
 * 		p2是一个temp指针 永远指向表示表尾 也就是不停的调整位置指向表尾
 */
struct student * LinkList::createStudentList(long num, float score) {
	struct student *head;
	head=NULL;
	this->n++;
	if(n==1){
		head = (struct student *) malloc(LEN);    		/*创建第一个节点*/
		head->num = num;
		head->score = score;
		head->next = NULL;
		this->head = head; /*保存到成员函数 以后不需要每次都返回链表头*/
		return this->head ;
	}else{
		cout<<"错误！ 链表已存在通过:getLinkList()函数获得链表指针"<<endl;
		return NULL;
	}
	return head;
}

/**创建studnet*/
struct student * LinkList::createStudent(long num, float score){
	if(num<=0 || score<0){
		return NULL;
	}
	struct student *student;
	student = (struct student *) malloc(LEN);    		/*创建第一个节点*/
	student->num = num;
	student->score = score;
	student->next = NULL;
	return student;
}

/**获得链表头指针*/
struct student * LinkList::getLinkList(){
	if(head == NULL){
		cout<<"尚未创建链表！请调用 LinkList::createStudentList(long num, float score) 函数创建链表"<<endl;
	}
	return head;
}


/**插入student 到链表末尾*/
struct student * LinkList::insertStudent(struct student *stud) {
	if(stud==NULL ){
		cout<<"stud = NULL 创建失败"<<endl;
		return this->head;
	}
	struct student *current,*back;		/*指向当前节点的指针和指向链表结尾节点的指针*/
	if(this->head==NULL){
		return this->getLinkList();
	}
	current = this->head;
	while(current!=NULL){			/*循环得到链表最后一个节点 back*/
		back = current;
		current = /*(struct student *)*/current->next;
	}
	this->n++;				/*节点个数+1*/
	back->next = stud;		/*末尾添加节点*/
	stud->next=NULL;		/*防止传入的stud末尾不为NULL而不能继续添加节点*/
	return this->head;
}

/**删除student  num 是唯一的*/
struct student * LinkList::deleteStudent(long num) {
	struct student *current ,*pre; /*当前指针和当前节点的前一个节点*/
	current = this->head;
	while(current->num!=num && current->next!=NULL){		//找到节点或是到达表尾结束
		pre = current;
		current = /*(struct student *)*/current->next;
	}
	if(current->num!=num){/*如果没找到 则return*/
		cout<<"没有找到此学生！"<<endl;
		return this->head;
	}

	if(current == this->head){
		this->head = /*(struct student *)*/this->head->next;	/*下一个为空也没关系*/
	}else{
		pre->next=current->next;	/*把当前节点从链表中删除*/
	}
	cout<<"删除学生:"<<num<<endl;
	free(current);
	current =NULL;
	this->n--;
	return this->head;
}

/**打印学生信息*/
void LinkList::printStudent() {
	struct student *current;
	current = head;
	do{
		cout<<"学号："<< current->num<<" 分数："<<current->score<<endl;
		current = /*(struct student *)*/current->next;
	}while(current!=NULL);
}

/**获得学生个数*/
int LinkList::getSize(){
	return this->n;
}

/**释放所有学生内存*/
bool LinkList::freeAllStudent(){
	struct student *current ,*pre;
		current = head;
		do{
			pre = current;
			current = /*(struct student *)*/current->next;
			cout<<"释放内存"<<endl;
			free(pre);
			pre = NULL;
		}while(current!=NULL);
	return true;
}

/**析构函数*/
LinkList::~LinkList(){
	cout<<"开始析构····"<<endl;
	this->freeAllStudent();
}
