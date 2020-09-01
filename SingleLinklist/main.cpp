#include <iostream>
//#include "Rleq.h"
#include ".\Linklist.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	int n = 0;
	Linklist slist = Linklist(n);
	slist.printList();
	int numi;
	cout << "Which element do you want:";
	cin >> numi;
	//Node *tem = new Node;
	//tem = slist.getElem(numi);
	//cout << "data:" << tem->data << endl;
	if (slist.getElem(numi)) {
		cout << "data:" << slist.getElem(numi)->data << endl;
	}
	else cout << "Can not get the element wantted!" << endl;
	
	cout << "----Insert Test-----------" << endl;
	Node *innode = new Node;
	innode->data = 100;
	innode->next = NULL;

	int index_insert =0;
	cout << "Enter the index wantted to be inserted:";
	cin >> index_insert;
	slist.insert(*innode, index_insert);

	cout << "²åÈëÁË£º" << slist.getElem(index_insert)->data << endl;
	slist.printList();
	slist.findElem(100);

	//delete test
	int del_num = 0;
	cout << "----Delete Test-----------" << endl;
	cout << "Enter index of element to delete:";
	cin >> del_num;
	slist.delElem(del_num);
	slist.printList();
	system("pause");
	return 0;
}
