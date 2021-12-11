#include<bits/stdc++.h>
using namespace std;

int maxSubstring(vector<int> &v , int k){
    int left = 0;
    int localSum =0 ;
    int globalSum =0;
    for(int i=0; i<k;i++){
        localSum = localSum + v[i];
    }
    globalSum = localSum;
    for(int i = k; i<v.size(); i++){
        localSum = localSum+v[i] - v[left];
        if(localSum > globalSum){
            globalSum = localSum;
        }
        left++;
    }

    return globalSum;
}


int main(){
    vector<int> vect = {1,1,1,1,1,1,2};
    
    cout<<maxSubstring(vect ,2) <<endl;
}