class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            // cnt number less than equal to mid
            for(int i : nums)
            {
                if(i <= mid)
                    ++count;      //1, 3, 4, 2, 2
            }
            // binary search on left
            if(count <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
};
