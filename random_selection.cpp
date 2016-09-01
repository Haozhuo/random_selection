#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partiton(int *a, int pivotIndex, int b, int e){
    //swap the pivot with the first element
    swap(a[b],a[pivotIndex]);
    int left = b, right = e,split=b-1;
    while(true){
        if(left>right){
            break;
        }
        //a[b] becomes the pivot value
        if(a[left] <= a[b]){
            left++;
            split++;
            continue;
        }
        
        if(a[right] >= a[b]){
            right--;
            continue;
        }
        
        if(a[left] > a[b] && a[right] < a[b]){
            swap(a[left],a[right]);
            continue;
        }
    }
    //split will be the pivot index
    swap(a[b],a[split]);
    /*
    for(int i = b; i <=e; i++)
        cout << a[i] << " ";
    cout << endl;*/
    return split;
}

int ith_smallest(int* a, int b, int e, int i){
    if(e-b>=1){
        int pivotIndex=rand()%(e-b+1)+b;
        int boudary = partiton(a, pivotIndex, b, e);
        //the pivot element is (order) smallest element
        int order = boudary-b+1;
        
        if(order==i){
            return a[boudary];
        }else if(order>i){
            return ith_smallest(a, b, boudary-1, i);
        }else{
            return ith_smallest(a, boudary+1, e, i-order);
        }
        
        }else if(e==b){
        if(i==1){
            return a[b];
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}



int main(){
    srand (time(NULL));
    int a[7]={0,5,10,2,9,3,1};
    //int a[4]={3,4,1,2};
    cout << ith_smallest(a,1,5,1) << endl;
    return 0;
}