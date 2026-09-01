#include <iostream>
#include <vector>

using namespace std;

int partitions(vector<int>&arr , int low , int high){
    int ind = low-1;
    int pivot = arr[high];
    for(int i = low;i<high;i++){
        if(arr[i]<pivot){
            swap(arr[++ind] ,arr[i]);
        }
    }
    swap(arr[ind+1] , arr[high]);
    return ind;
}
void quicksort(vector<int>&arr , int low , int high){
    if(low<high){
        int ind = partitions(arr , low , high);
        quicksort(arr , low ,ind-1);
        quicksort(arr , ind+1 , high);
    }
}

int main(){
    vector<int>arr = { 12 , 4 , 2 , 19 , 54};
    int n = arr.size();
    quicksort(arr , 0 , n-1);
    cout<<"Sorted array is : ";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
