/* import c++ libraries*/
#include<iostream>
using namespace std;
#define MaxSIZE 100
/* Using template classes instead of element attributes */
template<class ElemType>
struct StaticLIST{
    ElemType data[MaxSIZE];
    int length;
};

/* achieve the basic funtion of LIST*/
template<class ElemType>
void CreateLIST(StaticLIST<ElemType> &L,ElemType datas[],int size){
    L.length = size;
    for(int i=0;i<size;i++){
        L.data[i] = datas[i];
    }
    cout<<"LIST init successfully!"<<endl;
    return;
};

template<class ElemType>
void DestroyLIST(StaticLIST<ElemType> &L){
    L.length = 0;
    return;
};

template<class ElemType>
bool EmptyLIST(StaticLIST<ElemType> &L){
    if(L.length==0){
        return true;
    }
    return false;
}

template<class ElemType>
bool InsertLIST(StaticLIST<ElemType> &L,int loc,ElemType e){
    if(loc>L.length || loc<=0){
        return false;
    }
    for(int i=L.length-1;i>=loc-1;i--){
        L.data[i+1] = L.data[i];
    }
    L.data[loc-1] = e;
    L.length ++;
    return true;
}

template<class ElemType>
bool DeleteEle(StaticLIST<ElemType> &L,int loc,ElemType &e){
    if(loc>L.length || loc<=0){
        return false;
    }
    e = L.data[loc-1];
    for(int i=loc-1;i<L.length-1;i++){
        L.data[i] = L.data[i+1];
    }
    L.length--;
    return true;
}

template<class ElemType>
void PrintLIST(StaticLIST<ElemType> &L){
    if(EmptyLIST(L)==true){
        cout<<" LIST is NULL"<<endl;
    }
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){

    std::cout<<"hello world"<<endl;
    StaticLIST<int> L;
    int initdata[5] = {1,2,3,4,5};
    CreateLIST(L,initdata,5);
    PrintLIST(L);
    InsertLIST(L,1,10);
    PrintLIST(L);
    int e = -1;
    DeleteEle(L,1,e);
    std::cout<<"element "<<e<<" is deleted!"<<endl;
    PrintLIST(L);
    DestroyLIST(L);
    PrintLIST(L);
}