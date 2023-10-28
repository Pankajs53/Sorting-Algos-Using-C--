#include <iostream>
#include<vector>
using namespace std;


// merging sorted arrays
void mergesorted(int arr[], int s, int e, int mid){
    int n1=mid-s+1;
    int n2=e-mid;

    // copying the left part
    int *left = new int[n1];
    for(int i=0; i<n1; i++){
        left[i]=arr[s+i];
    }

    // copying the right part
    int *right= new int[n2];
    for(int i=0; i<n2; i++){
        right[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=s;
    // comparing values
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i++];
            // i++;
        }
        else{
            arr[k]=right[j++];
            // j++;
        }
        k++;
    }

    // copy remianing element
    while(i<n1){
        arr[k++]=left[i++];
        // i++,k++;
    }

    while(j<n2){
        arr[k++]=right[j++];
        // j++,k++;
    }

    // deallocate the memory from heap
    delete[] left;
    delete[] right;

}

// merge 2 sorted array
void mergeSort(int arr[],int s , int e){
    if(s>e){
        return;
    }
    if(s==e){
        return;
    }

    // calc mid
    int mid = (s+e)/2;

    // left call
    mergeSort(arr,s,mid);
    
    // right call
    mergeSort(arr,mid+1,e);

    // merge the sorted arrays
    mergesorted(arr,s,e,mid);
}

int main(){
    int arr[]={10,5,3,12,1,200,-1,0,1,-1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=size-1;
    mergeSort(arr,s,e);
    for(int result: arr){
        cout << result << " " ;
    }

    return 0;
}