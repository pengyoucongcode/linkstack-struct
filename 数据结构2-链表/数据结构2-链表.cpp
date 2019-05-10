// 数据结构2-链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
typedef struct LNode   //定义一个节点
{
	int data;  //节点中的数据域
	LNode *pNext; //指针域
}*List;

void CreateLA(List &l, int *n,int length) //创建链表LA，参数1为LA的地址，参数2为初始化LA用的数组，参数三为数组长度
{
	l = new LNode;
	l->pNext = NULL;
	List p_a, r_a;
	r_a = l;
	for (int i = 0; i < length; i++)
	{
		p_a = new LNode;
		p_a->data = n[i];  //将数组中的数值按序添加到链表中
		p_a->pNext = NULL;
		r_a->pNext = p_a;
		r_a = p_a;
	}
	cout << endl;
}

void CreateLB(List &l, int *n, int length)
{
	l = new LNode;
	l->pNext = NULL;
	List p, r;
	r = l;
	for (int i = 0; i < length; i++)
	{
		p = new LNode;
		p->data = n[i];
		p->pNext = NULL;
		r->pNext = p;
		r = p;
	}
}

void Sort(List &l,int len)//将链表排序，参数len为长度，以下皆如此
{
	List p, r;
	if (l->pNext == NULL) cout << "空表！" << endl;
	else
	{
		int i, j;
		for(i=0,p=l->pNext;i<len;i++,p=p->pNext)
			for (j = i + 1, r = p->pNext; j < len; j++, r = r->pNext)
			{
				if (p->data < r->data)//当当前节点的数据与之后的节点中的数据小，交换两个节点的位置
				{
					int temp = p->data;
					p->data = r->data;
					r->data = temp;
				}
			}
	}
}

void Display(List l,int len)//向屏幕打印链表
{
	if (l->pNext == NULL)
		cout << "空表！" << endl;
	else
	{
		List p1 = new LNode;
		p1 = l->pNext;
		int i = 0;
		while (i<len)
		{
			cout << p1->data << " ";
			p1 = p1->pNext;
			i++;
		} 
		cout << endl;
		cout << "当前线性表长度：" << i << endl;
	}
}

void MergeLists(List l1, List l2,List &l3,int len1,int len2,int &len3)//合并链表LA和LB成新链表LC
{
	int i = 0;
	l3 = new LNode;
	l3->pNext=NULL;
	List p, r;
	r = l3;
	for (i = 0; i < len1; i++)
	{
		l1 = l1->pNext;
		p = new LNode;
		p->data = l1->data;
		p->pNext = NULL;
		r->pNext = p;
		r = p;
	}
	for (i = 0; i < len2; i++)
	{
		l2 = l2->pNext;
		p = new LNode;
		p->data = l2->data;
		p->pNext = NULL;
		r->pNext = p;
		r = p;
	}
	len3 = len1 + len2;
}

void SerchOfData(List l, int n)//按值查找
{
	if (l->pNext == NULL) cout << "空表！" << endl;
	else
	{
		int num;
		cout << "请输入你想查找的值：";
		cin >> num;
		int i = 0;
		List p = l->pNext;
		while (true)
		{
			if (p->data == num)
				break;
			p = p->pNext;
			i++;
		}
		if (p->pNext != NULL)
			cout << num << "在线性表中的位置是：" << i + 1 << endl;
		if (i>n)
			cout << "所查找数值在线性表中并不存在" << endl;
	}
}

void SerachOfIndex(List l, int n)  //按址查找
{
	int index;
	cout << "请输入索引值:";
	bool key = false;
	while (true)
	{
		cin >> index;
		if (index > n || index < 0)
			cout << "输入错误，请重新输入：";
		else
		{
			key = true;
			break;
		}
	}
	if (key)
	{
		List p = l->pNext;
		int i = 0;
		while (i < index-1)
		{
			p = p->pNext;
			i++;
		}
		cout << "第" << index << "位的数据值是" << p->data << endl;
	}
}

void PopOfNum(List &l,int &n)  //按值删除
{
	if (l->pNext == NULL)cout << "空表，不能进行删除操作！" << endl;
	else
	{
		bool key = false;
		int num;
		cout << "请输入你想从线性表中删除的数值：";
		cin >> num;
		List p = l->pNext;
		while (true)
		{
			if (p->pNext->data == num)
			{
				key = true;
				break;
			}
			p = p->pNext;
		}
		if (key)
		{
			List q = p->pNext;
			p->pNext = q->pNext;
			delete q;
			n = n - 1;
		}
		if (!key)
		{
			cout << "输入的值有误，无法进行删除！" << endl;
		}
	}
}

void PopOfIndex(List &l, int &n)  //按址删除
{
	if(l->pNext==NULL)cout << "空表，不能进行删除操作！" << endl;
	else
	{
		int index;
		bool key = false;
		cout << "输入你想从线性表删除的位置：";
		while (true)
		{
			cin >> index;
			if (index<0 || index>n)
				cout << "下标错误，请重新输入：";
			else
			{
				break;
			}
		}
		List p=l->pNext;
		int i = 0;
		while (true)
		{
			i++;
			if (i == index-1)
			{
				key = true;
				break;
			}
			p = p->pNext;
		}
		if (key)
		{
			List q = p->pNext;
			p->pNext = q->pNext;
			delete q;
			n = n - 1;
		}
	}
}

void Insert(List l, int &n)  //向链表插值
{
	int sum;
	cout << "输入你想插入线性表的数值个数：";
	cin >> sum;
	int *num = new int[sum];
	cout << "请逐个输入你想插入线性表中的数值：";
	for (int i = 0; i < sum; i++)
		cin >> num[i];
	List p = new LNode;
	for (int i = 0; i < sum; i++)
	{
		p = l->pNext;
		while (p->pNext != NULL)
		{
			if (p->data >= num[i] && p->pNext->data < num[i])
				break;
			p = p->pNext;
		}
		List s = new LNode;
		s->data = num[i];
		s->pNext = p->pNext;
		p->pNext = s;
		n++;
	}
	delete[] num;
}

int main()
{
	List LA;
	int n1[] = { 78,64,37,30,29,24,18,12,9,2 };
	CreateLA(LA, n1,10);
	cout << "LA:";
	Display(LA, 10);
	List LB;
	int n2[] = {93,82,73,65,44,35,31,28,26,17,15 };
	CreateLB(LB, n2, 11);
	cout << "LB:";
	Display(LB, 11);
	List LC;
	int len1=10,len2=11,len3 = 21;
	MergeLists(LA, LB, LC, 10, 11,len3);
	Sort(LC, len3);
	cout << "LC:";
	Display(LC, len3);
	cout << "以下是线性表LC的操作：" << endl;
	SerchOfData(LC, len3);
	SerachOfIndex(LC, len3);
	PopOfNum(LC, len3);
	cout << "LC:";
	Display(LC, len3);
	PopOfIndex(LC, len3);
	cout << "LC:";
	Display(LC, len3);
	Insert(LC, len3);
	cout << "LC:";
	Display(LC, len3);
	cout << "LA进行插值";
	Insert(LA, len1);
	cout << "新LA:";
	Display(LA, len1);
	cout << "LB进行插值";
	Insert(LB, len2);
	cout << "新LB:";
	Display(LB, len2);
	MergeLists(LA, LB, LC, len1, len2, len3);
	Sort(LC, len3);
	cout << "新LC:";
	Display(LC, len3);
	return 0;
}