#include <iostream>
using namespace  std;

#define LIST_INIT_SIZE 15

/* 静态查找表的顺序存储结构 */
typedef int ElemType;

typedef struct{
    ElemType *elem;
    int length;  //表长度
}SSTable;

int InitList(SSTable &ST){
    ST.elem = new ElemType[LIST_INIT_SIZE];
    if(!ST.elem) throw "存储分配失败";
    ST.length = 0 ; //空表长度为0
    return 0;
}

void CreateList(SSTable &ST){
    InitList(ST);
    int listLen;
    ElemType item ; 
    cout << "请输入顺序表长度" <<endl;
    cin >> listLen;
    if(listLen > LIST_INIT_SIZE){
        throw "传入的顺序表长度过长";
    }
    cout << "请输入元素的值(从小到大输入)" << endl ;
    for(int i = 0 ; i < listLen ; i++){
        cin >> item ; 
        ST.elem[i] = item ;
        ST.length ++ ;
    }
}

/* 在有序表ST折半查找其关键字等于key的数据元素，返回其下标 */
int  Search_Bin(SSTable &ST , ElemType key , int low , int high){
    if(low > high) return -1;
    
    int mid = (low + high) / 2 ; //防止溢出
    if(key == ST.elem[mid]){
        return mid;
    } else if(key < ST.elem[mid]){
        return Search_Bin(ST,key,low,mid - 1);
    }else{
        return Search_Bin(ST,key,mid + 1 , high);
    }
}

int main(){
    SSTable ST;
    ElemType key = 0;
    CreateList(ST);
    cout << "请输入想要查找的数\n";
    cin  >> key ; 
    cout << "此元素位置是第" << Search_Bin(ST,key,0,ST.length - 1) + 1 << "位\n";
    system("pause");
    return 0;
}
