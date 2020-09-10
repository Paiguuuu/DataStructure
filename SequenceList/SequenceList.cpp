/*顺序表的C++实现
* 内容：增删查改
* @Linyitian
* @2020/09/10
*/
#include <iostream>
#include <stdlib.h>
const int MAXSIZE= 256;
using namespace std;

//定义顺序表的类
template <class T>
class Sqlist{
public:
	T *data;
	int length;
	Sqlist() {  
		this->length = 0;
		this->data = NULL;
	}//默认构造函数创建空表
	
	Sqlist(T*arr_in, int len);//用数列创建顺序表
	
	bool insert(int index, T data_inset);//插入
	
	bool delete_elem(int index, T &data_delete);//删除
	
	void traverse();//遍历输出
	
	bool find_elem(T elem_wantted);//查找元素
	
	bool isEmpty() { //检测是否为空表
		if (this->data == NULL) return true;
		else return false;
	}
};

/*类函数定义*/

//用数列创建顺序表
template <class T>
Sqlist<T>::Sqlist(T*arr_in, int len)
{
	//判断输入是否合法
	if (len > MAXSIZE || len < 0) {
	}

	this->data = new T[len]; //开辟对象存储空间
	this->length = len;

	for (int i = 0; i < len; i++)
	{
		data[i] = arr_in[i];
	}
	cout << "创建成功" << endl;
}

//插入
template <class T>
bool Sqlist<T>::insert(int index, T data_inset)
{
	//检查合法性
	if ( this->length > MAXSIZE || index>(this->length+1) ) {
		cout << "下标溢出" << endl;
		return false;
	}
	//length += 1;
	//元素后移
	for (int i = length-1; i >= index-1; i--)
	{
		*(this->data + i + 1) = *(this->data + i);
	}
	//目标插入
	data[index - 1] = data_inset;
	this->length += 1;
	return true;
}

//删除
template <class T>
bool Sqlist<T>::delete_elem(int index, T &data_delete)
{
	//检查合法性
	if (this->isEmpty()|| index>(this->length + 1)) {
		cout << "删除操作失败！" << endl;
		return false;
	}

	data_delete = *(this->data+index - 1);

	//从index-1开始前移元素
	for (int i = index - 1; i < this->length; i++)
	{
		*(this->data + i) = *(this->data + i + 1);
	}
	this->length -= 1;

	return true;
}


//遍历输出
template <class T>
void Sqlist<T>::traverse()
{
	//检查输入合法性
	if (this->isEmpty()) {
		cout << "此表为空列表" << endl;
	}

	//输出
	for (int i = 0; i < this->length; i++)
	{
		cout << this->data[i] << '\t';
	}
	cout << endl;
}

//查找元素
template <class T>
bool Sqlist<T>::find_elem(T elem_wantted)
{}


//main函数
int main(int argc, char** argv) {
	using namespace std;
	//用随机数创建长度为128的整数数组
	int arr_len = 10;
	int *arr = new int[arr_len]; 
	//数组赋值
	cout << "生成数组为：";
	for (int i = 0; i < arr_len; i++)
	{	
		arr[i] =(rand()%(100-0));
		cout << arr[i] << "\t";
	}
	cout << endl;

	/*创建语句测试*/
	Sqlist<int> int_seq =  Sqlist<int>(arr, arr_len); 
	cout << "创建顺序表为：";
	int_seq.traverse();

	/*插入测试*/
	int insert_num = 999;
	int_seq.insert(11, insert_num);
	cout << "插入后顺序表为：";
	int_seq.traverse();

	/*删除测试*/
	int index = 10;
	int delete_elem = 0;
	int &elem = delete_elem;
	int_seq.delete_elem(index, elem);

	cout << "删除后顺序表为：";
	int_seq.traverse();
	cout << "删除元素为："  << delete_elem << endl;
	return 0;
}
