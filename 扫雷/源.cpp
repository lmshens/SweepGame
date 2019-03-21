#include<graphics.h>
#include<ctime>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct{
	int *top;
	int *base;
	int stacksize;
}SqStack;
//***********************************************
bool InitStack(SqStack &s)
{
	s.base = new int[STACK_INIT_SIZE];
	if (!s.base)
	{
		cout << "初始化失败！" << endl;
		return false;
	}
	s.stacksize = STACK_INIT_SIZE;
	s.top = s.base;
	return true;
}
//***********************************************
bool DestoryStack(SqStack &s)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	s.stacksize = 0;
	delete s.base;
	cout << "销毁栈" << endl;
	return true;
}
//***********************************************
bool ClearStack(SqStack &s)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	InitStack(s);
	cout << "清空栈" << endl;
	return true;
}
//***********************************************
bool StackEmpty(SqStack s)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	if (s.top == s.base)
	{
		cout << "该栈为空" << endl;
		return true;
	}
	else
	{
		cout << "该栈非空" << endl;
		return false;
	}
}
//***********************************************
int StackLength(SqStack s)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return 0;
	}
	int *q;
	int i = 0;
	q = s.base;
	while (q != s.top)
	{
		i++;
		q++;
	}
	return i;
}
//***********************************************
bool GetTop(SqStack s, int &e)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	e = *(--s.top);
	return true;
}
//***********************************************
bool Push(SqStack &s, int e)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	if (!s.top)
	{
		int * newbase = (int *)realloc(s.base, (s.stacksize + STACKINCREMENT)*sizeof(int));
		if (!newbase) exit(0);
		s.base = newbase;
		s.stacksize += STACKINCREMENT;
	}
	*s.top = e;
	s.top++;
	return true;
}
//***********************************************
bool Pop(SqStack &s, int &e)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	s.top--;
	e = *(s.top);
	*(s.top) = *(s.top + 1);
	return true;
}
//***********************************************
bool StackTraverse(SqStack s)
{
	if (!s.base)
	{
		cout << "该栈不存在！" << endl;
		return false;
	}
	int *p;
	p = s.base;
	while (p != s.top)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
	return true;
}
//***********************************************

typedef struct QNode{
	int data;
	QNode *next;
}QNode, *QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//*************************************
bool InitQueue(LinkQueue &q)
{
	q.front = new QNode;
	if (!q.front)
	{
		cout << "初始化失败！" << endl;
		return false;
	}
	q.rear = q.front;
	q.rear->next = NULL;
}
//*************************************
bool DestoryQueue(LinkQueue &q)
{
	if (!q.front)
	{
		cout << "该队列不存在！" << endl;
		return false;
	}
	QNode *p;
	p = q.front;
	while (p)
	{
		p = q.front->next;
		delete q.front;
		q.front = p;
	}
	cout << "销毁队列" << endl;
	return true;
}
//*************************************
bool ClearQueue(LinkQueue &q)
{
	if (!q.front)
	{
		cout << "该队列不存在！" << endl;
		return false;
	}
	InitQueue(q);
	cout << "清空列队" << endl;
	return true;
}
//*************************************
bool QueueEmpty(LinkQueue q)
{
	if (!q.front)
	{
		cout << "该队列不存在！" << endl;
		return false;
	}
	if (q.rear == q.front)
		return true;
	else
		return false;
}
//*************************************
int QueueLength(LinkQueue q)
{
	if (!q.front)
	{
		cout << "该队列不存在！" << endl;
		return 0;
	}
	int i = 0;
	QNode *p;
	p = q.front->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
//*************************************
bool GetHead(LinkQueue q, int &e)
{
	if (QueueEmpty(q))
	{
		cout << "该队列为空！" << endl;
		return false;
	}
	e = (q.front)->next->data;
	return true;
}
//*************************************
bool EnQueue(LinkQueue &q, int e)
{
	if (!q.front)
	{
		cout << "该队列不存在！" << endl;
		return false;
	}
	QNode *p = new QNode;
	if (!p)
	{
		cout << "插入失败！" << endl;
		return false;
	}
	p->data = e;
	p->next = NULL;
	(q.rear)->next = p;
	q.rear = p;
	return true;
}
//*************************************
bool DeQueue(LinkQueue &q, int &e)
{
	if (QueueEmpty(q))
	{
		cout << "该队列为空！" << endl;
		return false;
	}
	QNode *p = (q.front)->next;
	e = p->data;
	(q.front)->next = p->next;
	delete p;
	return true;
}
//*************************************
bool QueueTraverse(LinkQueue q)
{
	if (!q.front || QueueEmpty(q))
	{
		cout << "该队列不存在或为空！" << endl;
		return false;
	}
	QNode *p;
	p = (q.front)->next;
	while (p != q.rear)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << q.rear->data << endl;
	return true;
}
//*************************************

void cube(int n)
{
	int length = 630 / n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n;j++)
	{
		setfillcolor(LIGHTBLUE);
		fillrectangle(0 + j*length, 0 + i*length, length*(j + 1), length*(i + 1));
	}
}

void main()
{
	int bomb[9][9];					//定义9*9个炸弹位置
	for (int i = 0; i < 9;i++)				//初始化，不放炸弹		
		for (int j = 0; j < 9; j++)
			bomb[i][j] = 0;
	srand(time(0));
	for (int n = 0; n < 16; n++)				//随机生成20%个炸弹
	{
		int i = rand() % 9;
		int j = rand() % 9;
		bomb[i][j] = 1;
	}

	int count = 0;				//炸弹的个数
	for (int i = 0; i < 9; i++)
	for (int j = 0; j < 9; j++)
		count += bomb[i][j];

	//画图
	initgraph(630, 630);
	cube(9);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, "楷体");
	settextcolor(BLACK);
	int i, j;
	MOUSEMSG m;
	while (true)
	{
	if (MouseHit())
		{
		m = GetMouseMsg();
		if (m.y < 630)
		{
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
			{
								   for (i = 0; i < 9; i++)
								   if (m.x>i * 70 && m.x < (i + 1) * 70)
									   break;
								   for (j = 0; j<9; j++)
								   if (m.y>j * 70 && m.y < (j + 1) * 70)
									   break;
								   if (bomb[i][j] == 0)
								   {
									   int number;
									   if (i == 0 && j == 0) number = bomb[0][1] + bomb[1][0] + bomb[1][1];
									   else if (i == 0 && j == 8) number = bomb[0][7] + bomb[1][7] + bomb[1][8];
									   else if (i == 8 && j == 0) number = bomb[7][0] + bomb[7][1] + bomb[8][1];
									   else if (i == 8 && j == 8) number = bomb[8][7] + bomb[7][7] + bomb[7][8];
									   else if (i == 0) number = bomb[i][j - 1] + bomb[i + 1][j] + bomb[i][j + 1] + bomb[i + 1][j - 1] + bomb[i + 1][j + 1];
									   else if (i == 8) number = bomb[i][j - 1] + bomb[i - 1][j] + bomb[i][j + 1] + bomb[i - 1][j - 1] + bomb[i - 1][j + 1];
									   else if (j == 0) number = bomb[i - 1][j] + bomb[i][j + 1] + bomb[i + 1][j] + bomb[i - 1][j + 1] + bomb[i + 1][j + 1];
									   else if (j == 8) number = bomb[i - 1][j] + bomb[i][j - 1] + bomb[i + 1][j] + bomb[i - 1][j - 1] + bomb[i + 1][j - 1];
									   else number = bomb[i - 1][j - 1] + bomb[i][j - 1] + bomb[i + 1][j - 1] + bomb[i - 1][j] + bomb[i + 1][j] + bomb[i - 1][j + 1] + bomb[i][j + 1] + bomb[i + 1][j + 1];

									   setfillcolor(WHITE);
									   floodfill(m.x, m.y, WHITE);
									   outtextxy(i * 70 + 32, j * 70 + 32, '0' + number);
								   }
								   else if (bomb[i][j] == 1)
								   {
									   setfillcolor(RED);
									   floodfill(m.x, m.y, WHITE);
									   outtextxy(i * 70 + 32, j * 70 + 32, "砰！");
									   Sleep(1000);
									   closegraph();
									   return;
								   }
			}	break;
			case WM_RBUTTONDOWN:
			{
								   if (getpixel(m.x, m.y) == YELLOW)
								   {
									   setfillcolor(LIGHTBLUE);
									   floodfill(m.x, m.y, WHITE);
								   }
								   else
								   {
									   setfillcolor(YELLOW);
									   floodfill(m.x, m.y, WHITE);
								   }

			}	break;
			case WM_LBUTTONDBLCLK:
				return;
				break;
			}
		}
		}
	int flag = 0, wflag = 0;
	for (i = 0; i < 9;i++)
	for (j = 0; j < 9; j++)
	{
		if (bomb[i][j] == 1 && getpixel(i * 70 + 35, j * 70 + 35) == YELLOW)
			flag += 1;
		if (bomb[i][j] == 0 && getpixel(i * 70 + 35, j * 70 + 35) == YELLOW)
			wflag += 1;
	}
	if (flag == count && wflag==0)
	{
		settextstyle(50,0,"黑体");
		settextcolor(RED);
		outtextxy(250, 300, "恭喜过关！");
		outtextxy(200, 350, "按任意键退出");
		_getch();
		closegraph();
		return;
	}
	}
}