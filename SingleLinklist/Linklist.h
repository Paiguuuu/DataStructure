/* Linklist Datastructure
* @by 林逸钿
* @lasted： 2020/08/14
*/
#pragma once
#include <iostream>
//template <T>   //使用类型模板
struct Node {
	int data;
	Node* next;
};

class Linklist {
public:
	Node* head;
	int length;
	Linklist(){    //default construction function
		head = NULL;
		length = 0;
	}
	Linklist(int n);//Create a Linklist by input. Need inputing head pointer and length
	bool isNull();//isNull
	//bool isFull();//isFull
	Node* getElem(int i); //getElem(i): return no.i Node pointer
	int insert(Node &n, int i);  //Insert n to no.i of  the linklist
	int delElem(int i);  // Delete no.i Element
	int findElem(int wantted);
	void printList();  //trasever the datas of list
	
};