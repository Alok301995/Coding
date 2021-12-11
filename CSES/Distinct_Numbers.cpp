#include<bits/stdc++.h>
using namespace std;



int distinctNumber(int arr[] , int n){
    sort(arr ,arr+n);
    int count =1;
    for(int i=0; i<n-1; i++){
        if(arr[i] != arr[i+1]){
            count++;
        }
    }
    return count;

}
int main(){
    int N;
     cin>> N;
     int arr[N];
     for(int i=0; i<N; i++){
         cin>> arr[i];
     }
     cout<<distinctNumber(arr, N)<<endl;


}