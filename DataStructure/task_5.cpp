#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int Status; //Status时函数的类型，其值是函数结构状态码

typedef char TElemType;

/* 二叉树的二叉链表存储表示 */
typedef struct BiTNode{
	TElemType data ; //结点数据
	struct BiTNode *lchild , *rchild; //左、右孩子指针
}BiTNode , *BiTree; //Bitree为指向节点的指针

/* 按照先序序列创建二叉树 */

Status createBiTree(BiTree &T){
	// 按先序次序输入二叉树结点的值(一个字符型数据)，#表示空树
	TElemType elem;
	cin >> elem;
	if(elem == '#'){
		T = NULL; //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
	}else{ //构造二叉链表表示的二叉树T
		T = new BiTNode;
		if(!T) throw "存储分配失败";
		T->data = elem; //生成根结点
		createBiTree(T->lchild); //构造左子树
		createBiTree(T->rchild); //构造右子树
	}
	return OK;
}

// /* 访问函数 */
// bool visit(TElemType e){
// cout << e << '\t';
// return true;
// }

// /* 先序遍历 */

// Status preOrderTraverse(BiTree &T , bool (* visit)(TElemType e)){
// if(T){
// if(visit(T->data)){
// if(preOrderTraverse(T->lchild,visit)){
// if(preOrderTraverse(T->rchild,visit)){
// return OK;
// }
// }
// }
// return ERROR;
// }else{
// return OK;
// }
// }

/* 先序遍历 */
Status preOrderTraverse(BiTree &T){
	if(T){
		cout << T->data << " ";
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
	}
return OK;
}

/* 中序遍历 */
Status inOrderTraverse(BiTree &T){
	if(T){
		inOrderTraverse(T->lchild);
		cout << T->data << " ";
		inOrderTraverse(T->rchild);
	}
	return OK;
}

/* 后序遍历 */
Status postOrderTraverse(BiTree &T){
	if(T){
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
	return OK;
}

/*  输出所有从根到叶子的路径 */
Status allPath(BiTree &T , TElemType path[] , int pathlen){   //初始调用是path[]为空,path为0
	//采用递归方法输出从叶子结点到根结点的路径
	int i = 0; //计数器
	if(T){
		if(T->lchild == NULL && T->rchild == NULL){ //到了叶子结点
           // cout << "-------" << pathlen << endl ;
			cout << "到根结点路径:\t" << T->data << " ";  // T->data表示叶子节点
			for(i = pathlen - 1 ; i >= 0 ; i--){
				cout << path[i] << " " ;
			}
			cout << endl ;
		}else{
			path[pathlen] = T->data ; //存入当前结点,路径长度＋1
			pathlen++;
			allPath(T->lchild,path,pathlen) ; //扫描左子树
            //cout << pathlen << "--------" <<endl;
			allPath(T->rchild,path,pathlen) ; //扫描右子树
			pathlen--; //环境恢复,删除path存储的叶子结点
            cout << pathlen << "------\n" ;
		}
        
	}
	return 0;
}

int main(){
	BiTree biTree = NULL;
	TElemType path[20];
	createBiTree(biTree); //建立从上到下、从左到右为123456的树的话，要输入123##4##56###
	cout << "前序遍历\t";
	preOrderTraverse(biTree);
	cout << endl ;
	cout << "后序遍历\t";
	postOrderTraverse(biTree);
	cout << endl ;
	cout << "中序遍历\t";
	inOrderTraverse(biTree);
	cout << endl ;
	allPath(biTree,path , 0);
	system("PAUSE");
	return 0;
}
