#include <iostream>
using namespace std;

#define MAX_SIZE 20  //最大队列长度

typedef int QElemType;

typedef struct{
    QElemType* base;    //初始化的动态分配存储空间
    int front;          //头指针,若队列不为空，指向队列头元素
    int rear;           //尾指针,若队列不为空，指向队列尾元素的下一个位置
}SqQueue;

/* 初始化一个队列 */
void initQueue(SqQueue &Q){
    Q.base = new QElemType[MAX_SIZE];
    if(!Q.base){
        throw "存储分配失败\n";
    }
    Q.front = Q.rear = 0;
}

/* 获取队列长度 */
int queueLength(SqQueue &Q){
    return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE ;
}

/* 插入元素E为Q的新的队尾元素 */
void enQueue(SqQueue &Q , QElemType &e){
    if((Q.rear + 1) % MAX_SIZE == Q.front){
        throw "队列已满";
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;  
}

/* 获取队列头元素 */
QElemType getHead(SqQueue &Q){
    QElemType e = 0;
    if(Q.front == Q.rear){
        throw "队列为空,无法进行操作";
    }
    e = Q.base[Q.front];
    return e;   
}

/* 删除队列的头元素，并用e返回其值 */
QElemType deQueue(SqQueue &Q){
    QElemType e = 0;
    if(Q.front == Q.rear){
        throw "队列为空,无法进行操作";
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return e;
}

/* 删除队列的头元素，并用e返回其值 */
QElemType deQueue(SqQueue &Q){
    QElemType e = 0;
    if(Q.front == Q.rear){
        throw "队列为空,无法进行操作";
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return e;
}

/* 创建 */
void createQueue(SqQueue &Q){
    int num = 0 ;
    QElemType elem = 0;
    cout << "请输入需创建队列的长度 \n";
    cin >> num ;
    for(int i = 1 ; i <= num ; i++){
        cout << "请输入第" << i << "个元素的值\n";
        cin >> elem;
        enQueue(Q , elem);
    }
}

/* 舞伴配对 */
void findDancingPartner(SqQueue &male , SqQueue &female){
    //int min ; 
    //min = (queueLength(male) < queueLength (female))?queueLength(male):queueLength(female);
    int count = 0;      //舞会次数
    int m = 0,n = 0; //计数器
    cout << "请输入舞曲数目\n";
    cin >> count ;
    for(int i = 0 ; i < count ; i++){
        if(!(m < queueLength(male))){
            m = 0;
        }
        if(!(n < queueLength(female))){
            n = 0;
        }
        cout << "第" << i + 1 << "配对:\n";
        cout << male.base[m++] << "和" << female.base[n++] <<endl;
    }
}
int main(){
    SqQueue male , female;
    cout << "创建男舞伴\n" <<endl;
    initQueue(male);
    createQueue(male);
    cout << "创建女舞伴\n" <<endl;
    initQueue(female);
    createQueue(female);
    findDancingPartner(male , female);
    system("PAUSE");
    return 0;
}
