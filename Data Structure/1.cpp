#include <stdio.h>
#define Maxsize 10

typedef struct{
    int data[Maxsize];
    int length;
}SqList;

void InitList(SqList L){
    for(int i=0; i<Maxsize; i++)
        L.data[i]=0;
    L.length=0;
}

bool Del_Min(SqList L, int value){
    if(L.length==0)
        return false;
    value=L.data[0];
    int pos=0;
    for(int i=1;i<L.length;i++)
        if(L.data[i]<value){
            value=L.data[i];
            pos=i;
        }
    L.data[pos]=L.data[L.length-1];
    L.length--;
    return true;
}

int main() {;
    SqList L;
    InitList(L);
}