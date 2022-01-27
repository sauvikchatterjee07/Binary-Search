    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {search(nums, target, "F" ), search(nums, target, "L")};   //Call the Binary Search algorithm with one more parameter for first and last occurance, make a vector and return
    }
    
    //Normal Binary Search algorithm
	
    int search(vector<int>& nums, int target, string find) {
        int start = 0;
        int end = nums.size()-1;
        int result = -1;
        
        while(start <= end){
            int mid = start+((end - start)/2);
            if(nums[mid] == target){
            
                result = mid; //Store the mid index because this is the candidate for final answer
				
				 //Even if you find the element check if any other occurance is present in the left side (in case of first occurance) or right side (in case of last occurance). 
				 //In terms of finding first occ. end pointer will point to mid-1 index and for the last occ, start pointer will point to mid+1 index. 
                (find == "F")? end = mid-1 : start = mid+1;

            }
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return result; //Finally result will give us the first or last occurance depending upon the parameter that is passed
    }
