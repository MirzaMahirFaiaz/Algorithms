//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;

int heap_size = 9;
int heap[ ] = {0,19,7,12,3,5,17,10,1,2};

void max_heapify(int heap[], int heap_size, int i){
    int l,r,larg,tmp;
    l = 2*i;
    r = 2*i +1;
    if(l<=heap_size && heap[l]>heap[i]){
        larg= l;
    }else{
    larg= i;
    }
    if(r<= heap_size && heap[r]>heap[larg]){
        larg =r;
    }

    if(larg!= i){
        tmp = heap[i];
        heap[i]= heap[larg];
        heap[larg]=tmp;

        max_heapify(heap, heap_size, larg);
    }

}
void build_max_heap(){
    int i;
    for(i=heap_size/2;i>=1;i--){
        max_heapify(heap, heap_size,i);
    }
}

int pop(){
    int boroMan = heap[1];
    heap[1]= heap[heap_size];
    heap_size-=1;
    max_heapify(heap,heap_size,1);
    return boroMan;
}

int enqueue(int data){
    int i,p,tmp;
    heap_size +=1;
    heap[heap_size]= data;
    i = heap_size;
    while(i>1 && heap[i]>heap[i/2]){
        p = i/2;
        tmp= heap[p];
        heap[p]= heap[i];
        heap[i]=tmp;
        i = p;
    }
    return heap_size;

}
void print_heap(int heap[], int heap_size){
    int i;
    for(i=1;i <= heap_size;i++){
        cout<<heap[i]<<" ";
    }
cout<<endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,i,j;
    print_heap(heap, heap_size);
    build_max_heap();


    print_heap(heap, heap_size);
   enqueue(77);
   enqueue(3);

    print_heap(heap, heap_size);
    ll p = pop();
    cout<<p<<endl;
    p = pop();
    cout<<p<<endl;
    print_heap(heap, heap_size);

return 0;
}
