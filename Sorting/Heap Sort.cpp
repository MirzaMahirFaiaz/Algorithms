//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
//Using Array

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

void print_heap(int heap[], int heap_size){
    int i;
    for(i=1;i <= heap_size;i++){
        cout<<heap[i]<<" ";
    }
cout<<endl;
}
void build_max_heap(int heap[], int heap_size){
    int i;
    for(i=heap_size/2;i>=1;i--){
        max_heapify(heap, heap_size,i);
    }
}
void heap_sort(int heap[], int heap_size){
    build_max_heap(heap, heap_size);
    int i,tmp;
    for(i = heap_size;i>1;i--){
        tmp = heap[1];
        heap[1] = heap[i];
        heap[i] = tmp;
        //cout<<"\ntese"<<endl;
       // print_heap(heap,heap_size);

        heap_size-=1;
        max_heapify(heap, heap_size,1);
       // print_heap(heap,heap_size);
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,i,j;
    int heap_size = 9;
    int heap[ ] = {0,19,7,12,3,5,17,10,1,2};
    print_heap(heap, heap_size);
   // max_heapify(heap, heap_size, 3);
   heap_sort(heap, heap_size);
    print_heap(heap, heap_size);

return 0;
}
