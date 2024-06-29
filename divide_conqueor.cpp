// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// void mergeTwoArrays(int arr1[], int arr2[], int n, int m, vector<int> &ans)
// {
//     int i = 0, j = 0;
//     while (i < n && j < m)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             ans.push_back(arr1[i]);
//             i++;
//         }
//         else
//         {
//             ans.push_back(arr2[j]);
//             j++;
//         }
//     }
// if(j<=m){
//     ans.push_back(arr2[j]);
//     j++;}
// }
// int main()
// {
//     int arr1[] = {1, 3, 5, 7};
//     int arr2[] = {0, 2, 6, 8, 9};
//     int n = sizeof(arr1) / sizeof(arr1[0]);
//     int m = 5;
//     vector<int> ans;
//     mergeTwoArrays(arr1, arr2, n, m, ans);
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(int arr[],int start,int end,int mid){
   
    int arrayLeftSize=mid-start+1;
    int arrayRightSize=end-mid;
    int *arrLeft=new int[arrayLeftSize];
    int *arrRight=new int[arrayRightSize];
    int index=start;
    for(int i=0;i<arrayLeftSize;i++){
        arrLeft[i]=arr[index];
        index++;

}index=mid+1;
for(int i=0;i<arrayRightSize;i++){
    arrRight[i]=arr[index];
    index++;
}
int i=0;
int j=0;
int k=start;
while(i<arrayLeftSize && j<arrayRightSize){
    if(arrLeft[i]<arrRight[j]){
        arr[k]=arrLeft[i];
        i++;
    }
    else{
        arr[k]=arrRight[j];
        j++;
    }
    k++;
}
while(i<arrayLeftSize){
    arr[k]=arrLeft[i];
    i++;
    k++;
}
while(j<arrayRightSize){
    arr[k]=arrRight[j];
    j++;
    k++;
}
}
void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    } 
    int mid=(start+end)/2;
 
  mergeSort(arr,start,mid);

  mergeSort(arr,mid+1, end);
merge(arr,start,end,mid);
}

int main(){
    int arr[]={10, 80, 30, 90, 40, 50, 70};
    int size=sizeof(arr)/sizeof(arr[0]);
    int start=0;
    int end=size-1;
   
    cout<<"Array before sorting: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }  cout << endl;
   
    mergeSort(arr,start,end);
     cout<<"Array After sorting: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }  cout << endl;
    return 0;

}