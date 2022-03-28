#Efficient Solution

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        
        while(low <= high){
            mid = low+(high - low)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[low] <= nums[mid]){
                if(target <= nums[mid]  && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{
                if(target >= nums[mid] && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};

















int search(vector<int>& nums, int target) {

    int x = 0;
    int end = nums.size()-1;

    while(x<end){
        if(nums[x+1]>nums[x])
        x++;
        else
        break;
    }

    int s1 = 0, e1 = x, s2 = x+1, e2 = end; 

    while(s1<=e1){
        int mid=s1+(e1-s1)/2;
            if(nums[mid]>target)
                e1=mid-1;
            else if(nums[mid]<target)
                s1=mid+1;
            else
                return mid;
    }
    while(s2<=e2){

        int mid=s2+(e2-s2)/2;
            if(nums[mid]>target)
                e2=mid-1;
            else if(nums[mid]<target)
                s2=mid+1;
            else
                return mid;
    }
    return -1;
}
