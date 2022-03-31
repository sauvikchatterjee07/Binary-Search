class Solution {
private:
    bool isPossible(vector<int>& nums, int mid, int m){
        int sa = 1;
        int sum = 0;
        for(int i =0; i< nums.size(); i++){
            sum+=nums[i];
            if(sum > mid){
                sa++;
                sum = nums[i];
            }
        }
        return sa <= m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int mx = 0;
        int sum = 0;
        
        for(int val : nums){
            sum += val;
            if(val > mx) mx = val; 
        }
        
        if(m == nums.size()) return mx;
        
        int lo = mx;
        int hi = sum;
        int ans = 0;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossible(nums, mid, m)){
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};
