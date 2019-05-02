#include <iostream>
using namespace std;

/* 图的邻接表存储表示 */
#define MAX_VERTEX_NUM 20  //最大顶点数
#define OK 1
#define ERROR 0

typedef int Status;
typedef int InfoType; 
typedef int VertexType; //顶点的类型
 
/* 边表结点 */
typedef struct ArcNode{
    int adjvex;                 //邻接点域 ，存储该顶点对应的下标
    struct ArcNode *nextarc;    //链域 ，指向下一条弧的指针
    //InfoType *info;              //该弧相关信息的指针(如权值)
}ArcNode;
/* 顶点表结点 */
typedef struct VNode{
    int inDegree;                 //顶点入度
    VertexType data;        //顶点的值
    ArcNode *fistarc;       //邻接链表头指针
}VNode,AdjList[MAX_VERTEX_NUM];
/* 图 */
typedef struct{
    AdjList vertices;       //图的邻接表
    int vexnum,arcnum;      //图的当前顶点数和弧数
}ALGraph;

/* 图的创建 */
void createGraph(ALGraph &graph){
    int i = 0 , j = 0;
    ArcNode * arcNode = NULL;
    cout << "请输入顶点数和边数(空格分隔)\n";
    cin >> graph.vexnum >> graph.arcnum;
    for(int m = 0 ; m < graph.vexnum ; m++){
        cout << "输入第" << m+1 << "个顶点数据:\n";
        cin >> graph.vertices[m].data;
        graph.vertices[m].fistarc = NULL; //将边表置为空表
    }
    /* 建立边表 */
    for(int n = 0 ; n < graph.arcnum ; n++){  
        cout << "输入边(vi , vj)的顶点序号(空格分离)\n"; 
        cin >> i >> j;  //输入无序对(i,j)
        arcNode = new ArcNode;
        arcNode->adjvex = j;    //临接序号为j
        /* 将arcNode的指针指向当前顶点指向的结点 */
        arcNode->nextarc = graph.vertices[i].fistarc;
        graph.vertices[i].fistarc = arcNode; //将新结点arcNode插入顶点vi的边表头部

        arcNode = new ArcNode;
        arcNode->adjvex = i;  //临接序号为j
        arcNode->nextarc = graph.vertices[j].fistarc;
        graph.vertices[j].fistarc = arcNode;  // 将新结点arcNode插入顶点vj的边表头部
    }
}

/* 拓扑排序算法 */
Status Topologicalsort(ALGraph &graph){
    ArcNode *arcNode;
    int j,gettop;
    int top = 0 ; //用于栈指针下标索引
    int count = 0; // 输出顶点个数
    int *stack; //存储入度为0的顶点
    
    stack = new int[graph.vexnum];
    for(int i = 0; i < graph.vexnum ; i++){
        if(0 == graph.vertices[i].inDegree){
            stack[++top] = i ; //将度为0的顶点入栈
        }
    }

    while(0 != top){
        gettop = stack[top--];
        cout << graph.vertices[gettop].data; //出栈
        count++;

        for(arcNode = graph.vertices[gettop].fistarc ; arcNode ; arcNode= arcNode->nextarc){
            j = arcNode->adjvex ;
            //将j号顶点的入度-1，因为它的前驱已消除，接着判断k号顶点入度是否为0，如果为011则入栈
            if(!(--graph.vertices[j].inDegree)){
                stack[++top] = j;
            }
        }
    }

   return (count < graph.vexnum)? ERROR: OK ;  //如果count小于顶点数，说明存在环  
}

 void BFSTraverse(ALGraph &graph){
	ArcNode *arcNode;
	for(int i = 0 ; i < graph.vexnum; i ++ ){
		cout << graph.vertices[i].data << ": ";
		arcNode = graph.vertices[i].fistarc;
		while(arcNode){
			cout << arcNode->adjvex << "\t";
			arcNode = arcNode->nextarc;
		}
		cout << endl;
	}
}
/* 顶点入度 */
void inDegree(ALGraph &graph){
    ArcNode *arcNode;
    int count;
    for(int i = 0 ; i < graph.vexnum ; i++){
        count = 0;
        arcNode = graph.vertices[i].fistarc;
        while(arcNode){
            count++;
            arcNode = arcNode->nextarc;
        }
        graph.vertices[i].inDegree = count;
    }
}

int main()
{
    ALGraph graph;
    createGraph(graph);
    inDegree(graph);
	Topologicalsort(graph);
	BFSTraverse(graph);
    system("PAUSE");
    return 0;
}
