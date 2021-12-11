#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums , int target){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(nums[low] <= nums[mid]){
            if(target >= nums[low] && target <= nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else {
            if(target >= nums[mid] && target <=nums[high]){
                low= mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
        return -1;

}


int main(){
    vector<int> nums ={3,1};
    int target =1;
    cout<<search(nums,target)<<endl;
}