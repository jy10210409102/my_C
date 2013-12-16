/*
 * LinkList.h
 *
 *  Created on: 2013-12-15
 *      Author: CHENLI
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "../../head/Css.h"

#define LEN sizeof(struct student)
/**student结构*/
typedef struct student{
	long num;
	float score;
	struct student *next;
}node;


/**
 * 链表测试类
 */
class LinkList{

public :
	~LinkList();
	int n;
	LinkList():n(0),head(NULL){};
	struct student *createStudentList(long num, float score);							//创建student链表
	struct student *createStudent(long num, float score);								//创建student
	struct student *insertStudent(struct student *stud);								//插入student
	struct student *deleteStudent(long num);											//删除student
	void printStudent();																//输出所有student
	struct student * getLinkList();														//获得链表
	int getSize();	//获得学生个数
private:
	struct student * head;	/*链表指针*/
	bool freeAllStudent(); //释放所有为学生新建的内存
};




#endif /* LINKLIST_H_ */
