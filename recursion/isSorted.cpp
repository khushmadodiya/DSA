#include<iostream>
using namespace std;

bool isSorted(int arr[], int size) {

    //base case
    if(size == 0 || size == 1 ){
        return true;
    }

    if(arr[0] > arr[1])
        return false;
    else {
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }

}
int sum(int *arr,int size,int s){
    if(size<0){
        return s;
    }
   s+=arr[0];
    return sum(arr+1,size-1,s);

}

int LinearSearch(int *arr,int n, int key){
    if(n<0){
        return -1;
    }
    if(arr[0]==key ){
        return arr[0];
    }
   return LinearSearch(arr+1,n-1,key);
}

bool BinarySearch(int *arr , int key,int low,int high){
    int mid = low+high/2;
    if(low>high){
        return false;
    }
    if(key==arr[mid]){
        return true;
    }
    if(key>arr[mid])
    return BinarySearch(arr,key,mid+1,high);
    else{
         return BinarySearch(arr,key,low,mid-1);
    }
    

}

int main() {

    int arr[5] = {2,4,9,9,9};
    int size = 5;
    int s=0;

    // bool ans = isSorted(arr, size);
    // if(ans){
    //     cout << "Array is sorted " << endl;
    // }
    // else {
    //     cout << "Array is not sorted " << endl;
    // }


    // cout<<sum(arr,size-1,s);
    
    // int index = LinearSearch(arr,size,8);
    // if(index==-1){
    //     cout<<"not found";
    // }
    // else{
    //     cout<<index;
    // }
   bool index = BinarySearch(arr,9,0,size-1);
   if(index){
    cout<<"exist";
   } 
   else{
    cout<<"not found";
   }

    return 0;
}