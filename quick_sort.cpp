/*******
quick sort implemented with
random pivot selection to
prevent the worst case
*******/
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
    
    swap(a[b],a[split]);
    return split;
}

bool quick_sort(int* a, int b, int e){
    if(e-b>=1){
        int pivotIndex=rand()%(e-b+1)+b;
        int boudary = partiton(a,pivotIndex,b,e);
        quick_sort(a,b,boudary-1);
        quick_sort(a,boudary+1,e);
        return true;
    }else if(e==b){
        return true;
    }else{
        return false;
    }
}



int main(){
    srand (time(NULL));
    //int a[10]={0,5,10,2,9,3,1,4,6,8};
    int a[4]={3,2,5,1};
    int upper_bound = 3;
    quick_sort(a,0,upper_bound);
    for(int i = 0 ; i <= upper_bound; i++){
        cout << a[i] << " " << endl;
    }
    return 0;
}