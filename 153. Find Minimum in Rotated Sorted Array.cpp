int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        int mid;

        while(start<=end){

            if(nums[start] <= nums[end])
            {
                return nums[start];
            }


            mid = start + (end-start)/2;
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;

            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];
            
            if(nums[start] <= nums[mid]) //if the first part is sorted, search in the second part
                start = mid+1;
            else if(nums[end] >= nums[mid])//if the second part is sorted, search in the first part
                end = mid-1;
        }
        return nums[mid];
    }
