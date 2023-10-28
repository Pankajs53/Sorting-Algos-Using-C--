#include <iostream>
#include<vector>
using namespace std;


int partition(int arr[],int s, int e){
    // choose the pivotIndex
    int pivotIndex=s;
    int pivotElement= arr[pivotIndex];
    int count=0;

    // COUNT THE VALUES<PIVOTELEMENT
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=arr[pivotIndex]){
            count++;
        }
    }
    // now replace the value
    int rightIndex = s+count; 
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;

    // now check if pivotValue is at right place in left and right
    int i=s;
    int j=e;
    while (i<pivotIndex && j>pivotIndex){
        while (arr[i]<pivotElement){
            i++;
        }
        while (arr[j]>pivotElement)
        {
            j--;
        }     

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }  
    }

    return pivotIndex;
}

void quickSort(int arr[],int s,int e){
    // base case
    if(s>=e){
        return;
    }

    //partition logic 
    int p=partition(arr,s,e);
    
    // call for left recursio
    quickSort(arr,s,p-1);

    // call for right recursion
    quickSort(arr,p+1,e);

}

int main(){
    int arr[]={1,20,50,30,-1,0,-1 };
    int size=sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=size-1;
    quickSort(arr,s,e);
    for(int result: arr){
        cout << result << " " ;
    }

    return 0;
}