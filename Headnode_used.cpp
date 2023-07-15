/*  Implement a singly linked list with a leading node
 * @time: 2023/06/25 21:31
 * @author: LWJ
 * @insititue: BUPT
 * */

#include<iostream>
using namespace std;

/*  define the basic structure of Node and Linklist
 * LNode: the structure of node
 * LinkList: the structure of link list.
 * */
template<typename ElemType>
struct LNode{
    ElemType val;
    LNode<ElemType> *next;
};

template<typename ElemType>
struct LinkList{
    LNode<ElemType> *head;
    int length;
};

/* Implement basic functions of link list
 * InitLinkList: creat a new link list which have a head node.
 *
 * */
template<typename ElemType>
LinkList<ElemType> CreateLinkList(int n,ElemType arr[],bool pre){
    LinkList<ElemType> list;
    list.length = 0;
    list.head = new LNode<ElemType>;
    list.head->next = nullptr;

    if(n<=0){
        return list;
    }
    /* Initializing a linked list using the head insertion method */
    if(pre){
        cout << "==========================================================" << endl;
        cout << "Initializing a linked list using the head insertion method" << endl;
        cout << "==========================================================" << endl;
        for(int i=0;i<n;i++){
            if(list.head->next== nullptr){
                LNode<ElemType> *newnode = new LNode<ElemType>;
                if(newnode == NULL){ 
                    cout << "Fail to request a new storage" << endl; 
                    return list; 
                }

                newnode->val = arr[i];
                list.head->next = newnode;
            }
            else{
                InsertPreNode(list.head->next,arr[i]);
            }
            list.length++;
        }
    }
    /* Tail insertion method for initializing linked lists */
    else{
        cout << "==========================================================" << endl;
        cout << "Initializing a linked list using the tail insertion method" << endl;
        cout << "==========================================================" << endl;
        LNode<ElemType> *temp = NULL;
        for(int i=0;i<n;i++){

            if(list.head->next == NULL){
                LNode<ElemType> *newnode = new LNode<ElemType>;
                if(newnode == NULL){ 
                    cout << "Fail to request a new storage" << endl; 
                    return list; 
                }

                newnode->val = arr[i];
                list.head->next = newnode;
                temp = newnode;
            }
            else{
                temp = InsertNextNode(temp,arr[i]);
            }
            list.length++;
        }
    }
    
    return list;
}

template<typename ElemType>
LNode<ElemType>* InsertPreNode(LNode<ElemType> *p, ElemType e){
    if(p == NULL){
        return NULL;
    }
    /* create a new node for e*/
    LNode<ElemType> *newnode = new LNode<ElemType>;
    newnode->val = e;
    newnode->next = p->next;
    p->next = newnode;
    /* exchange the value of p and newnode */
    newnode->val = p->val;
    p->val = e;
    return p;
}

template<typename ElemType>
LNode<ElemType>* InsertNextNode(LNode<ElemType> *p, ElemType e){
    if(p == NULL){
        cout << "input node is NULL \n\tnote:[e= " << e << "]" <<endl;
        return NULL;
    }
    /* create a new node for e*/
    LNode<ElemType> *newnode = new LNode<ElemType>;
    if(newnode == NULL){
        cout << "Fail to request a new storage for " << e <<endl;
        return NULL;
    }
    newnode->val = e;
    newnode->next = NULL;

    newnode->next = p->next;
    p->next = newnode;
    return newnode;
}

template<typename ElemType>
void PrintfLinkList(LinkList<ElemType> L){
    cout<<"The Length of Link List: "<< L.length <<endl;
    LNode<ElemType> *temp = L.head->next;
    for(int i=1;i<=L.length;i++){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;
}

/* 单链表基本操作：按位插入*/
template<typename ElemType>
void DestroyLinkList(LinkList<ElemType> &L){
    cout<<"Destroy Link List..."<<endl;
    LNode<ElemType> *temp = L.head->next;
    for(int i=0;i<L.length;i++){
        L.head = temp;
        temp = temp->next;
        delete(L.head);
    }
    return;
}

template<typename ElemType>
bool InsertviaLoc(LinkList<ElemType> &L,int i, int e){
    if(i<=0 || i>L.length+1){
        cout << " the location to be inserted is invalid! " << endl;
        return false;
    }
    /* 寻找到第i-1个结点的位置 */
    LNode<ElemType> *temp = SearchNode_Loc(L,i-1);
    if(temp == NULL){
        return false;
    }
    // 使用后插法插入该结点
    InsertNextNode(temp,e);
    L.length ++;
    return true;
}

/* 单链表基本操作： 按位查找*/
template<typename ElemType>
LNode<ElemType> *SearchNode_Loc(LinkList<ElemType> L,int loc){
    if(loc<0 || loc>L.length){
        return NULL;
    }
    int i = 0;
    LNode<ElemType> *temp = L.head;
    while(i!=loc && temp!=NULL){
        temp = temp->next;
        i++;
    }

    return temp;
}

/* 按值查找，注意只能查找第一个 */
template<typename ElemType>
LNode<ElemType> *SearchNode_Val(LinkList<ElemType> L,ElemType e){
    LNode<ElemType> *temp = L.head;
    while(temp->val!=e){
        temp = temp->next;
    }
    return temp;
}

/* 按位删除元素 */
template<typename ElemType>
bool DeleteLocNode(LinkList<ElemType> &L,int loc){
    if(loc<=0 || loc>L.length){
        cout<< "The location to be deleted is invalid" << endl;
        return false;
    }
    /* 查找第i个结点 */
    LNode<ElemType> *temp = SearchNode_Loc(L,loc-1);
    if(temp == NULL){
        return false;
    }

    /* 删除第i个结点 */
    LNode<ElemType> *deletenode = temp->next;
    cout << deletenode->val << " are deleted from link list!";
    temp->next = deletenode->next;
    delete(deletenode);
    L.length --;
    return true;
}

/* 按值删除 */
template<typename ElemType>
bool DeleteValNode(LinkList<ElemType> &L,ElemType e){
    LNode<ElemType> *temp = L.head;
    while(temp->next->val != e){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << e <<" not in the linke list!" << endl;
        return false;
    }
    /* 删除该结点的指定结点 */
    LNode<ElemType> *deletenode = temp->next;
    temp->next = deletenode->next;
    delete(deletenode);
    L.length --;
    return true;
}

int main(){
    cout<< "=== The Test to Basic Function of LINK LIST " << endl;
    LinkList<int> list;
    int arr[5] = {1,2,3,4,5};
    /* 头插法实现单链表构造 */
    list = CreateLinkList(5,arr,true);
    PrintfLinkList(list);
    // DestroyLinkList(list);

    /* 尾插法实现单链表构造 */
    LinkList<int> list1;
    list1 = CreateLinkList(5,arr,false);
    PrintfLinkList(list1);

    /* 插入某个值*/
    InsertviaLoc(list1,0,10);
    InsertviaLoc(list1,3,10);
    InsertviaLoc(list1,200,200);
    PrintfLinkList(list1);

    /* 删除某个值 */
    int e = 0;
    DeleteLocNode(list1,1);
    DeleteLocNode(list1,100);
    DeleteLocNode(list1,list1.length);
    PrintfLinkList(list1);
    
    DeleteValNode(list1,10);
    PrintfLinkList(list1);
    
    /* 查找某个值 */
    LNode<int> *find_node = NULL;
    find_node = SearchNode_Loc(list1,2);
    cout << find_node->val << endl;

    find_node = SearchNode_Val(list1,2);
    cout << find_node->val << endl;

    DestroyLinkList(list1);
    system("pause");
    
}
