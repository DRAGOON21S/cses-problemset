#include <bits/stdc++.h>
using namespace std;

void count(int arr[], int size){
    
    vector<bool> visited(size,false);
    for (int i=0; i<size; i++){
        // cout << arr[i];
        if (visited[i]==true){
            // cout << "hello";
            continue;
            // cout << "hello";
        }
        

        // cout << "hello";
        int count =1;
        for (int j=i+1;j<size;j++){
            int q = arr[i];
            if (q==arr[j]){
            visited[j]=true;
            count++;}
            // cout << j*10;
        }
        // cout << i;
        cout << arr[i] << "  " << count << endl;
        
    }
}

void count_map(int arr[], int size){
    unordered_map<int,int> map;
    
    for (int i=0 ; i <  size; i++){
        map[arr[i]]++;;
    }
    int z = 0;
    int e = 0;
    for (auto x : map){
        if (x.second>z){
            z = x.second;
            e = x.first;
        }
        else if(x.second==z){
            if(x.first<e){
                z = x.second;
                e = x.first;
            }
        }
    } 
    cout << e<<endl<<endl;
    
    // for (int i=0; i<sizeof(map)/sizeof(unordered_map<int,int>);i++){
    //     if (map[i].second < map[])
    // }
}

void swap(int arr[], int q, int w){
    int temp = arr[q];
    arr[q] = arr[w];
    arr[w] = temp;
}
void printarr(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
}

void selection_sort(int arr[], int n){
    for (int i=0; i<n; i++){
        int temp = arr[i];
        int index = i;
        for  (int j=i+1;j<n;j++){
            if (arr[j]<temp){
                index = j;
                temp = arr[j];
            }
        }
        // cout<<"hello";
        if (index != i)
        swap (arr, index, i);
    }
    printarr(arr,n);
}

void bubble_sort(int arr[], int n){
    for(int i=0;i<n; i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped)
        break;
    }
    printarr(arr,n);
}

void insertion_sort(int arr[],int n){
    for (int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(arr[j]>key&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        // cout << j <<endl ;
        arr[j+1]=key;
    }
    printarr(arr,n);
}


void merge(int arr[], int low, int mid, int high) {
    int size = high - low + 1;
    vector<int> temp(size);
    int left = low;
    int right = mid + 1;
    int index = 0; // Index for temp array
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[index++] = arr[left++];
        } else {
            temp[index++] = arr[right++];
        }
    }
    
    while (left <= mid) {
        temp[index++] = arr[left++];
    }
    
    while (right <= high) {
        temp[index++] = arr[right++];
    }
    
    for (int i = 0; i < size; i++) {
        arr[low + i] = temp[i];
    }
}
void merge_sort(int arr[], int low, int high) {
    if (low >= high) { // Base case
        return;
    }
    
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);      // Sort left half
    merge_sort(arr, mid + 1, high); // Sort right half
    merge(arr, low, mid, high);     // Merge sorted halves
}

void rec_bubble(int arr[],int n){
    bool swapped = false;
    for(int i=0;i<n-1;i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            swapped=true;    
        }
    }
    n--;
    if (n>0&&swapped==true){
        rec_bubble(arr,n);
    }
    return;
}

void rec_insertion(int arr[],int index,int n){
    if(index==n)
    return;
    for (int i=index-1;i>=0;i--){
        bool swapped = false;
        if(arr[i+1]<arr[i]){
            swap(arr[i+1],arr[i]);
            swapped = true;
        }
        if(!swapped)
        break;
    }
    index++;
    
    rec_insertion(arr,index,n);    
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low+1;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<high+1)
        i++;
        while(arr[j]>pivot&&j>low)
        j--;

        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(int arr[],int low,int high){
    if(high>low){
        int pindex = partition(arr,low,high);

        quick_sort(arr,low,pindex-1);
        quick_sort(arr,pindex+1,high);
    }
}



int main() {
    int arr []={510,0,15,11,51,03,10,10,20,300};
    // quick_sort(arr,0,sizeof(arr)/sizeof(int));
    // printarr(arr,sizeof(arr)/sizeof(int));
    // rec_insertion(arr,0,sizeof(arr)/sizeof(int));
    // printarr(arr,sizeof(arr)/sizeof(int));
    // rec_bubble(arr,sizeof(arr)/sizeof(int));
    // printarr(arr,sizeof(arr)/sizeof(int));
    // merge_sort(arr,0,sizeof(arr)/sizeof(int)-1);
    // printarr(arr,sizeof(arr)/sizeof(int));
    // insertion_sort(arr,sizeof(arr)/sizeof(int));
    // bubble_sort(arr,sizeof(arr)/sizeof(int));
    // swap (arr[1],arr[2]);
    // selection_sort(arr,sizeof(arr)/sizeof(int));
    // printarr(arr,sizeof(arr)/sizeof(int));
    // swap (arr,2,1);
    // printarr(arr,sizeof(arr)/sizeof(int));
    // count_map(arr, sizeof(arr)/sizeof(int));
    // count(arr, sizeof(arr)/sizeof(int));
    // cout <<sizeof(arr)/sizeof(int);
    return 0;
}   