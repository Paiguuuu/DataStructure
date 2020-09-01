#pragma once
#include "Linklist.h"


//isNull: judge whether the list is empty or not
bool Linklist::isNull() {
	if (!head && length> 0) return false;
	else return true;
}//isNull

//release the list
Linklist::Linklist(int n) {
	using namespace std;
	cout << "Input the length of list:";
	cin >> n;
	head = new Node ;   // head pointer assisn
	head->data = n;  //store length in head node
	head->next = NULL;
	length = n;

	for (int i = 0; i < n; ++i)
	{
		Node *inode= new Node;
		if(inode){
			cout << "请输入第" << (i + 1) << "个元素的数据：";
			cin >> inode->data;
			//cout << endl;
			//cout << inode->next << endl;
			inode->next = head->next;
			head->next = inode;
			
		}
		else { cout <<  "第" << (i + 1) << "个元素的数据节点申请失败！"<<endl; }  //Output the error message
	}
}

void Linklist::printList() {
	using namespace std;
	Node *tem = new Node;
	tem = head;
	cout << "列表元素：" << endl;
	while (tem->next)
	{
		tem = tem->next;
		cout << tem->data << "\t";
	}
	cout << "输出完毕！" << endl;
	//delete tem;
}

//Get no.i element node pointer
Node* Linklist::getElem(int i) {
	using namespace std;
	Node *tem =this->head;

	//legal check 
	if (!(this->head)) {
		cout << "List is empty!" << endl;
		return NULL;
	}
	if (i > length)
	{
		cout << "Index out of Length！" << endl;
		return NULL;
	}

	//tem = head;
	//cout << tem->data << "\t" << tem->next << endl;

	for (int count = 0; count < i; ++count)
	{
		if(tem->next)
		tem = tem->next;
			
		else { 
			cout << "下标溢出" << endl;
			return NULL;
			}
	}
		return tem;

	//traval to i 
	//for(int count=0; count < i;count++)
}

//insert element
int Linklist::insert(Node &n, int i) {
	using namespace std;
	int length = this->length;

	//check legitimacy of i and list head pointer
	if (i > length+1) {
		cout << "Index out of range!" << endl;
		return -1;
	}
	if (!(this->isNull())) {
		cout << "List is Empty!" << endl;
		return 1;
	}
		
	Node *font = this->getElem(i-1);  //find the original element i-1 

	(&n)->next = font->next;
	font->next = &n;
	//test 
	this->length += 1;
	this->head->data += 1;
	return 0;
}

//find node
int Linklist::findElem(int wantted) {
	using namespace std;
	Node * result = new Node;
	result = this->head->next;  //the pointer of first data node 

	//legal check 
	if (!(this->head)) {
		cout << "List is empty!" << endl;
		return -1;
	}
	
	for (int i = 0; i < this->length; ++i) {
		if ((result->data) == wantted) {
			cout << "Index of "<< wantted	<<" is " << (i + 1) << endl;
			return (i+1);
		}
		result = result->next;

	}
	cout << "Can Not Find the data: " << wantted << endl;
	return -1;
}

//delete element in the list
int Linklist::delElem(int i) {
	using namespace std;
	if (i > length || i < 0) {
		cout << "Index illegal." << endl;
		return -1;
	}

	Node *node_font = this->getElem(i-1);
	node_font->next = node_font->next->next;
	delete node_font->next;
	return 0;
}