#include <bits/stdc++.h>
using namespace std;

void largestinarray(int arr[],int size){
    int key = INT_MIN;
    int key2 = 0;
    // if(key2>key)
    // swap(key,key2);
    for (int i = 0; i<size;i++){
        if (arr[i]>key)
        {
            key2 = key;
            key = arr[i];}
        // if (arr[i]>key2 && arr[i]<key)
        // {
        //     // key2 = key;
        //     key2 = arr[i];}   
    }
    // for (int i = 0; i<size;i++){
    //     if (arr[i]>key2 && arr[i]<key)
    //     {
    //         // key2 = key;
    //         key2 = arr[i];}
    // }

    cout << key2<<" "<<key <<"  "<<INT_MIN;

}

bool check_sorted(int arr[],int size){
    int n = size;
    if (n==1 || n==2 || n==0)
    return true;
    if(arr[n-1]<=arr[n-2]){
        while(arr[n-2]<=arr[n-3]&&n>2){
            if (n==3)
            return true;
            n--;
    }}
    // n = size;
    else {while(arr[n-1]>=arr[n-2]&&n>1){
        if (n==2)
        return true;
        n--;
    }}
    return false;
}

void printarr(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
}

void remove_duplicates(int arr[], int size){
    int unique=1;
    for (int i = 0; i<size-1;i++){
        if (arr[i]==arr[i+1])
        continue;
        arr[unique]=arr[i+1];
        unique++;
    }
    printarr(arr,unique);
}

void rotate_left_by_n(int arr[],int size, int n){
    n=n%size;
    if (n == 0){
        printarr(arr,size);
        return;}
    int temp[n];
    for (int i = 0 ; i<n;i++)
        temp[i]=arr[i];
    for (int i=0;i<size-n;i++)
        arr[i]=arr[i+n];
    for (int i = 0 ; i<n;i++)
        arr[size - n +i]=temp[i];
    printarr(arr,size);
}

void move_zero_to_end(int arr[],int size){
    int non_zero=0;
    for (int i=0;i<size;i++){
        if(arr[i]==0){
            continue;
        }
        non_zero++;
        arr[non_zero-1]=arr[i];
    }
    for (int i=0;i<size-non_zero;i++){
        arr[i+non_zero]=0;
    }
    printarr(arr,size);
}

void move_zero_using_pointers(int arr[],int size){
    int i = 0;
    for(int j=0;j<size;j++){
        
    }
}

int main(){
    int arr []={0,0,0,0,1,2,3,4,0,0,0,0,5,6,7,0,0,0,0};
    cout<<sizeof(arr)/sizeof(int)<<endl<<endl;
    move_zero_to_end(arr,sizeof(arr)/sizeof(int));
    // rotate_left_by_n(arr,sizeof(arr)/sizeof(int),14);
    // remove_duplicates(arr,sizeof(arr)/sizeof(int));
    // cout << status;

}