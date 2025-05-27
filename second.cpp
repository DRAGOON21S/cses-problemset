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
        if(arr[j]==0)
        continue;
        if(i!=j)
        swap(arr[i],arr[j]);
        i++;
    }
    printarr(arr,size);
}

void temp_arr_pointers(int arr1[],int size1, int arr2[],int size2){
    vector<int> temp;
    for(int i=0,j = 0; i<size1 || j<size2;){
        if(arr1[i]==arr2[j]){
            if(temp.size() == 0 || temp.back() != arr1[i])
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
        if(arr1[i]>arr2[j]){
            if(temp.size() == 0 || temp.back() != arr1[j])
            temp.push_back(arr2[j]);
            j++;
            
        }
        if (arr1[i]<arr2[j]){
            if(temp.size() == 0 || temp.back() != arr1[i])
            temp.push_back(arr1[i]);
            i++;
        }
    }
    for(auto x:temp){
        cout<<x;
    }
}

void union_ordered_map(int arr1[],int size1, int arr2[],int size2){
    map <int,int> freq;
    vector<int> temp;
    for(int i=0;i<size1;i++)
        freq[arr1[i]]++;
    for(int i=0;i<size2;i++)
        freq[arr2[i]]++;
    for (auto & it: freq)
        temp.push_back(it.first);
    for(auto x:temp)
        cout<<x;
    
}

void missing_number_with_xor(int arr[], int n){
    int xor1=0,xor2=0;
    for(int i=0;i<n-1;i++){
        xor1 = xor1^arr[i];
        xor2 = xor2 ^(i+1);
    }
    xor2 ^= n^xor1;
    // int r = xor2^xor1;
    cout << xor2;
}

void sum_subarray(int arr[], int size, int n){
    int sum = 0;
    int k =0;
    int start=-1,end=-1;
    for(int i=0;i<size;i++){
        sum = 0;
        for(int j=i;j<size;j++){
            sum += arr[j];
            // cout << sum<<endl;
            if(sum == n){
                if(k<(j-i+1))
            {    k=j-i+1;
                start = i;
                end = j;}
            }
            if (sum > n){
                break;
            }
        }
    }
    // cout << k <<" "<<start<<" "<< end;
    while(start<=end){
        cout << arr[start];
        start++;
    }
}

int main(){
    int arr []={2,3,5,1,9};
    int arr2 []={1,2,3,5,6,7,8,9};
    sum_subarray(arr,sizeof(arr)/sizeof(int),9);
    // temp_arr_pointers(arr,sizeof(arr)/sizeof(int), arr2,sizeof(arr2)/sizeof(int));
    // cout<<sizeof(arr)/sizeof(int)<<endl<<endl;
    // move_zero_using_pointers(arr,sizeof(arr)/sizeof(int));
    // rotate_left_by_n(arr,sizeof(arr)/sizeof(int),14);
    // remove_duplicates(arr,sizeof(arr)/sizeof(int));
    // cout << status;

}