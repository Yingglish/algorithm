#include <iostream>
using namespace std;

typedef int SElemType;

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量

typedef struct{
	SElemType *base;  //在栈构造之前和销毁之后，base的值为NULL
	SElemType *top;  //栈顶指针
	int stacksize;   //当前已分配的空间
}SqStack;

/* 构造一个空栈 */
void InitStack(SqStack &S){
	S.base = new SElemType[STACK_INIT_SIZE];
	if(S.base == NULL){
		throw "动态存储分配失败";
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE; //初始容量值
}

/* 插入元素e为新的栈顶元素 */
int Push(SqStack &S , SElemType &e){
	if((S.top - S.base)>= S.stacksize){
		//栈满,追加空间
		S.base = new SElemType[STACK_INIT_SIZE + STACKINCREMENT];
		if(S.base == NULL){
			throw "动态存储分配失败";
		}
		S.top = S.base + S.stacksize;  // 栈底指针的改变，导致栈顶指针随之改变
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; //栈顶指针加1同时把e赋给栈顶
	return 1;
}

/* 删除S的栈顶元素,用e返回其值 */
SElemType pop(SqStack &S){
	SElemType e = 0;
	if(S.top == S.base){ //top与base重合时，栈为空
		throw "栈为空,无法进行操作";
	}else{
		e = * --S.top; //top指向栈中当前栈顶元素的上一个空间，所以要先将其位置减一,再取元素
	}
	return e;
}
/* 获取栈顶元素 */
SElemType getTop(SqStack &S){
	SElemType e = 0;
	(S.top == S.base) ? throw "栈为空,无法进行操作" : e = * (S.top - 1);
	// if(S.top == S.base){ //top与base重合时，栈为空
	// 	throw "栈为空,无法进行操作";
	// }else{
	// 	e = * (S.top - 1);
	// }
	return e;
}

/* 栈遍历 */
void StackTravel(SqStack S){
    while(S.top>S.base){
		cout << *(--S.top) << endl;
    }                    
}

/* 判断是否为空 */
string IsEmpty(SqStack &S)//判空
{
	return (S.top == S.base) ? "为空栈\n":"不是空栈\n";
}
/* 销毁栈 */
void Destroy(SqStack &S)
{
	delete S.base;
}

/* 清空栈 */
void clear(SqStack &S){
	S.base = S.top;
}
//获取栈元素个数
int StackLength(SqStack &S){
    if(S.base==S.top){
        return 0;
    }
    return S.top-S.base;
}

SqStack createStack(){
	int n = 0 ;  //计数器
	SqStack s ;
	InitStack(s);
	SElemType e = 0;
	cout << "请输入要构建栈的长度\n" ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++){
		cout << "请输入第" << i << "个元素\n";
		cin >> e ; 
		Push(s , e);  //压栈
	}
	return s;
}
int main(){
	SElemType e = 0;
	SqStack s = createStack();
	cout << "栈元素个数为" << StackLength(s) << endl;
	StackTravel(s); //栈遍历
	cout << IsEmpty(s);
	cout << "被删除的栈顶元素为" << pop(s) << endl;
	cout << "删除之后栈顶元素为 :" << getTop(s) <<endl;
	clear(s);
	IsEmpty(s);
	Destroy(s);
    system("pause");
}
