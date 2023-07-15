/* import c++ libraries*/
#include<iostream>

#define MaxSIZE 5
using namespace std;
/* Using template classes instead of element attributes */
template<class ElemType>
struct StaticLIST{
    ElemType *data = new ElemType[MaxSIZE];
    int maxsize = MaxSIZE;
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
    delete[] L.data;
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
    if(loc > L.maxsize ||loc>L.length || loc<=0){
        return false;
    }
    if(L.length >= L.maxsize){
        cout<<"LIST FULL![maxsize: "<<L.maxsize<<"][LIST Length: "<<L.length<<"]"<<endl;
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
void ExternMaxsize(StaticLIST<ElemType> &L,int maxsize){
    if(maxsize<=L.maxsize){
        cout<<" Expect a larger number than original maxsize " << L.maxsize <<endl;
        return;
    }
    ElemType *temp = L.data;
    /* apply a new store for data*/
    L.data = new ElemType[maxsize];
    for(int i=0;i<=L.length;i++){
        L.data[i] = temp[i];
    }
    L.maxsize = maxsize;
    delete[] temp;
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
        cout<<"LIST is NULL"<<endl;
    }
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){

    StaticLIST<int> L;
    /* init list*/
    int initdata[5] = {1,2,3,4,5};
    CreateLIST(L,initdata,5);
    PrintLIST(L);
    /* extern the max size of list*/
    ExternMaxsize(L,6);
    cout<<"LIST MAXISZE: "<<L.maxsize<<endl;
    /* insert element into list*/
    InsertLIST(L,1,10);
    PrintLIST(L);
    InsertLIST(L,5,100);
    PrintLIST(L);
    /*Delete element from LIST*/
    int e = -1;
    DeleteEle(L,1,e);
    cout<<"element "<<e<<" is deleted!"<<endl;
    PrintLIST(L);
    DeleteEle(L,1,e);
    cout<<"element "<<e<<" is deleted!"<<endl;
    PrintLIST(L);

    /* Destroy list*/
    DestroyLIST(L);
    PrintLIST(L);
}