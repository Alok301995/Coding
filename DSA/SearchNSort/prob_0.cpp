#include<bits/stdc++.h>
using namespace std;


int findRightIndex(int arr[] , int n, int x){
    int low =0 ;
    int high = n-1;
    int rightIndex =-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= x){
            if(arr[mid] ==x){
                rightIndex = mid;
            }
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return rightIndex;

}
int findLeftIndex(int arr[] , int n , int x){
    int low =0;
    int high = n-1;
    int leftIndex =-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            if(arr[mid] ==x){
                leftIndex = mid;
            }
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return leftIndex;

}

vector<int> find(int arr[] ,int n , int x){
    vector<int> vect;
    int left = findLeftIndex(arr,n ,x);
    int right = findRightIndex(arr ,n ,x);
    if(left!=-1 && right != -1){
        vect.push_back(left);
        vect.push_back(right);
    }
    else{
        vect.push_back(-1);
        vect.push_back(-1);
    }
    return vect;

}

int main(){


    int arr[] ={1, 3, 5, 5, 5, 5, 7, 123, 125};
    int x =7;
    int n =9;
    find(arr,n ,x);


}