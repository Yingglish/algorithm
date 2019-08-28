#include <iostream>
using namespace std;

#define MAX_SIZE 20 //顺序表的最大长度

typedef int KeyType;  //定义关键字类型为整数类型

typedef struct{
    KeyType key;  //关键字的值
}RedType; //记录类型

typedef struct{
    RedType r[MAX_SIZE + 1]; //r[0] 闲置或用作哨兵单元
    int length; //顺序表长度
}SqList;  //顺序表类型

void ShellInsert(SqList &L , int increment){
    //对顺序表进行希尔差入排序 ，increment为增量
    int j;
    /* 从increment + 1开始，每隔increment就进行一次直接插入排序 */
    for(int i = increment + 1 ; i < L.length ; ++i){ 
        if(L.r[i].key < L.r[i - increment].key){  //如果新调取的关键字的值，比子表中最后一个记录的关键字小，说明需要将该值调换位置
            L.r[0] = L.r[i]; //将要换位置的元素暂存在L.r[0]
            //进行直接插入排序，若r[0]的关键字比r[j]的小，则向后一个下标为j的值，为新插入的元素腾出空间
            for(j = i - increment ; j > 0 && (L.r[0].key < L.r[j].key) ; j -= increment){
                L.r[j + increment] = L.r[j];
            }
            L.r[j + increment] = L.r[0];  //跳出循环后，将新的记录值插入到出的空间中，即完成了一次直接插入排序
        }
    }
}
/* 通过调用不同的增量值（记录），实现对多个子表分别进行直接插入排序 */
void ShellSort(SqList &L , int dlta[] , int t){
    //按增量序列dlta[0..t-1]对顺序表L做希尔排序
    for(int k = 0 ; k < t ; ++k){
        ShellInsert(L , dlta[k]);
    }
}

SqList CreateList(int n){
    KeyType elem = 0;
    SqList List;
    cout << "输入数据\n";
    for(int i = 1 ; i < n + 1 ; i++){
        cin >> elem;
        List.r[i].key = elem;
    }
    List.length = n;
    return List;
}

void ListTraverse(SqList &L){
    for(int i = 1 ; i <= L.length ; i++){
        cout << L.r[i].key << " ";
    }
    cout << endl;
}

int main(){
    int n = 0;
    int dlta[3] = {5 , 3 , 1}; //1表示每间隔一个，也就是最后一次对整张表的直接插入排序
    cout << "请输入要排序元素的个数\n" ;
    cin >> n;
    SqList List = CreateList(n);
    ShellSort(List , dlta ,3);
    cout << "排序后\t";
    ListTraverse(List);
    system("PAUSE");
}
