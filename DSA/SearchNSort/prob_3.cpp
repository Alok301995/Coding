#include<bits/stdc++.h>
using namespace std;


int countSquare(int N){
    long long low = 0;
    long long high = N;
    int count =0;
    while(high -low >1){
        long long mid = low + (high-low)/2;
        if(mid*mid > N){
            high = mid-1;
        }
        else{
            count = mid;
            low = mid+1;
        }
    }
    if(low * low < N){
        count = low;
    }
    if(high * high < N){
        count = high;
    }
    // cout<<low <<" "<< high << endl;
    return count;
    
}


int main(){
    // int N= 41165056;
    // int N =9;
    int N = 20148714;
    cout<<countSquare(N)<< endl;




}