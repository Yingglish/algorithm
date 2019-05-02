#include <iostream>
#include <queue>
using namespace std;

/* 图的邻接表存储表示 */
#define MAX_VERTEX_NUM 20  //最大顶点数
#define OK 1
#define ERROR 0

typedef int Status;
typedef int InfoType; 
typedef char VertexType; //顶点的类型
 
/* 边表结点 */
typedef struct ArcNode{
    int adjvex;                 //邻接点域 ，存储该顶点对应的下标
    struct ArcNode *nextarc;    //链域 ，指向下一条弧的指针
    //InfoType *info;              //该弧相关信息的指针(如权值)
}ArcNode;
/* 顶点表结点 */
typedef struct VNode{
//    int inDegree;                 //顶点入度
    VertexType data;        //顶点的值
    ArcNode *fistarc;       //邻接链表头指针
}VNode,AdjList[MAX_VERTEX_NUM];
/* 图 */
typedef struct{
    AdjList vertices;       //图的邻接表
    int vexnum,arcnum;      //图的当前顶点数和弧数
}ALGraph;

// /* 获取顶点下标 */
// int getPosition(ALGraph &graph , char value){
//     for(int i = 0 ; i < graph.vexnum ; i++){
//         if(graph.vertices[i].data == value){
//             return i;
//         }
//     }
//     return ERROR;
// }

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

void BFSTraverse(ALGraph &graph){
    int temp;
    queue<int> quene;
    ArcNode *arcNode;
    bool *visited;
    visited = new bool[graph.vexnum]; //记录标记顶点是否被访问过
    // 将所有的顶点标为未访问
    for(int i = 0 ; i < graph.vexnum ; i++){
        visited[i] = false;
    }
    cout << "BFSTraverse :" << endl;
    //对每一个顶点进行遍历
    for(int j = 0 ; j < graph.vexnum ; j++){
        if(!visited[j]){ //若是顶点未访问过
            visited[j] = true ; //设置当前顶点被访问过
            cout << graph.vertices[j].data << " " ;  //打印
            quene.push(j);       
            while(!quene.empty()){
                temp = quene.front();
                quene.pop();
                arcNode = graph.vertices[temp].fistarc;  //找到当前顶点边表链表表头指针
                while(arcNode){
                    if(!visited[arcNode->adjvex]){
                        //若此顶点未被访问过
                        visited[arcNode->adjvex] = true; //将找到的此顶点标记为已访问  
                        cout << graph.vertices[arcNode->adjvex].data << " ";
                        quene.push(arcNode->adjvex); //将顶点入对列
                    }
                arcNode = arcNode->nextarc; //指针指向下一个邻接点
                }
            }
        }       
    }
    cout << endl;
}
int main(){
    ALGraph graph;
    createGraph(graph);
    BFSTraverse(graph);
    system("PAUSE");
    return 0;
}
