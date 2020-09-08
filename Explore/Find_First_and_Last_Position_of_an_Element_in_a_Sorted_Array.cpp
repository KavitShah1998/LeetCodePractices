/*
Approach: Binary Search
Runtime:16 ms (beats 99.18% submissions)
Memory: 13.7 MB (beats 80.46% submissions)
*/
class Solution {
public:
    vector<int> Explore (vector<int>& nums, int target, int lb, int ub){
        int size = nums.size();
        while(ub < size-1 && nums[ub+1] == target) ub++;
        while(lb > 0 && nums[lb-1] == target) lb--;
        return {lb, ub};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb{0};
        int size = nums.size();
        
        if (size == 1 && nums[0]!= target)
            return {-1, -1};
        else if(size == 1 && nums[0]==target)
            return {0,0};
        
        int ub{size-1};
        int mid{0};
        

        
        while(lb<=ub){
            mid = (lb+ub)/2;
            if(nums[lb] == target){
                //ub = lb;
                return Explore (nums, target, lb, lb);
            }
            else if(nums[ub] == target){
                lb = ub;
                return Explore (nums, target, ub, ub);
            }
            else if(target== nums [mid]){  
                //lb = ub = mid;                
                return Explore (nums, target, mid, mid);
            }
            else if(target < nums[mid]){ 
                ub = mid -1;
                //if(nums[lb] < target && nums[ub] > target && lb == ub-1) break;
            }
            else //(target > nums[mid])
            {                
                lb = mid +1;
                //if(nums[lb] < target && nums[ub] > target && lb == ub-1) break;
            }

            
        }

        return {-1, -1};
    }
};
