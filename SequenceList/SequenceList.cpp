/*˳����C++ʵ��
* ���ݣ���ɾ���
* @Linyitian
* @2020/09/10
*/
#include <iostream>
#include <stdlib.h>
const int MAXSIZE= 256;
using namespace std;

//����˳������
template <class T>
class Sqlist{
public:
	T *data;
	int length;
	Sqlist() {  
		this->length = 0;
		this->data = NULL;
	}//Ĭ�Ϲ��캯�������ձ�
	
	Sqlist(T*arr_in, int len);//�����д���˳���
	
	bool insert(int index, T data_inset);//����
	
	bool delete_elem(int index, T &data_delete);//ɾ��
	
	void traverse();//�������
	
	bool find_elem(T elem_wantted);//����Ԫ��
	
	bool isEmpty() { //����Ƿ�Ϊ�ձ�
		if (this->data == NULL) return true;
		else return false;
	}
};

/*�ຯ������*/

//�����д���˳���
template <class T>
Sqlist<T>::Sqlist(T*arr_in, int len)
{
	//�ж������Ƿ�Ϸ�
	if (len > MAXSIZE || len < 0) {
	}

	this->data = new T[len]; //���ٶ���洢�ռ�
	this->length = len;

	for (int i = 0; i < len; i++)
	{
		data[i] = arr_in[i];
	}
	cout << "�����ɹ�" << endl;
}

//����
template <class T>
bool Sqlist<T>::insert(int index, T data_inset)
{
	//���Ϸ���
	if ( this->length > MAXSIZE || index>(this->length+1) ) {
		cout << "�±����" << endl;
		return false;
	}
	//length += 1;
	//Ԫ�غ���
	for (int i = length-1; i >= index-1; i--)
	{
		*(this->data + i + 1) = *(this->data + i);
	}
	//Ŀ�����
	data[index - 1] = data_inset;
	this->length += 1;
	return true;
}

//ɾ��
template <class T>
bool Sqlist<T>::delete_elem(int index, T &data_delete)
{
	//���Ϸ���
	if (this->isEmpty()|| index>(this->length + 1)) {
		cout << "ɾ������ʧ�ܣ�" << endl;
		return false;
	}

	data_delete = *(this->data+index - 1);

	//��index-1��ʼǰ��Ԫ��
	for (int i = index - 1; i < this->length; i++)
	{
		*(this->data + i) = *(this->data + i + 1);
	}
	this->length -= 1;

	return true;
}


//�������
template <class T>
void Sqlist<T>::traverse()
{
	//�������Ϸ���
	if (this->isEmpty()) {
		cout << "�˱�Ϊ���б�" << endl;
	}

	//���
	for (int i = 0; i < this->length; i++)
	{
		cout << this->data[i] << '\t';
	}
	cout << endl;
}

//����Ԫ��
template <class T>
bool Sqlist<T>::find_elem(T elem_wantted)
{}


//main����
int main(int argc, char** argv) {
	using namespace std;
	//���������������Ϊ128����������
	int arr_len = 10;
	int *arr = new int[arr_len]; 
	//���鸳ֵ
	cout << "��������Ϊ��";
	for (int i = 0; i < arr_len; i++)
	{	
		arr[i] =(rand()%(100-0));
		cout << arr[i] << "\t";
	}
	cout << endl;

	/*����������*/
	Sqlist<int> int_seq =  Sqlist<int>(arr, arr_len); 
	cout << "����˳���Ϊ��";
	int_seq.traverse();

	/*�������*/
	int insert_num = 999;
	int_seq.insert(11, insert_num);
	cout << "�����˳���Ϊ��";
	int_seq.traverse();

	/*ɾ������*/
	int index = 10;
	int delete_elem = 0;
	int &elem = delete_elem;
	int_seq.delete_elem(index, elem);

	cout << "ɾ����˳���Ϊ��";
	int_seq.traverse();
	cout << "ɾ��Ԫ��Ϊ��"  << delete_elem << endl;
	return 0;
}
