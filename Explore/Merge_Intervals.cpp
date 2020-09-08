/*
Runtime: 28 ms, faster than 99.78% solutions 
Memory: 15 MB, better than31% solutions
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        int size = intervals.size();
        if(size==0)
            return result;       
        
        
        int min{INT_MAX};
        int max{INT_MIN};
        for(int i=0; i < size; i++){
            min = std::min(min, intervals[i][0]); // find the min of entire data
            max = std::max(max, intervals[i][1]); // find the max of entire data 
        }
        
        
        std::vector<int> r{0,0}; // r to store the current pair as a vector.
        
        
        //creating an array to store the end of intervals starting at i.
        // this will be stored my shifting the data with 'min'. 
        // The idea being, we will use the lower value of interval as a lookup key of an array which will store the upper interval.
        
        // since it is possible that many intervals start from a particular value, we store the maximum end-index value.
        std::vector<int> vecData(std::vector<int>(max-min+1,-1));
        
        for(int i=0; i <size; i++){
            vecData[(intervals[i][0])-min] = std::max(vecData[(intervals[i][0])-min],(intervals[i][1])-min);
        }

        // for indexing and storing data in arrays we are subtracting min from data. While storing the data back in the result vector, we need to add back the min to data.
        for(int i=0; i<vecData.size(); i++){
            if(vecData[i]!=-1){ // it has an interval
                vector<int> row;
                bool flag = evaluate(r, {i, vecData[i]}, row);
                
                if(!flag){ // overlap does not exists
                    // store the current overlapping interval so far in the result vector.
                    
                    r[0] +=min;
                    r[1] +=min;
                    result.push_back(r);
                    r.clear();
                    r.push_back(i);
                    r.push_back(vecData[i]);
                }
                // if the overlapping between intervals does exist, ans is stored in row, put that vector in r for next iterations
                else{r = row;}
            }
        }
        // adding the final non-overlapping pair found.
        r[0] +=min;
        r[1] +=min;
        result.push_back(r);
        return result;        
    }

    
    //this function returns true if the two Intervals are OVERLAPPING, if yes, it stores the resultant interval in the res. 
    // if no overlap, then it returns false.
    bool evaluate(vector<int>& prev, vector<int> curr, vector<int>& res){
        std::vector<int> a;
        std::vector<int> b;
        
        // a & b vectors are used for ease of comparison at the end of this function
        if(prev[0] < curr[0]){
            a = prev;
            b = curr;
        }
        else if(prev[0] == curr[0]){
            if(prev[1] > curr[1]){
                a = prev;
                b = curr;
            }
            else{
                a = curr;
                b = prev;
            }
        }
        else{
            a = curr;
            b = prev;
        }
        
        if(b[0] <= a[1]){// 1 number overlap {
                if(a[1] > b[1]){
                    b[1] = a[1];
                }
                if(a[0] < b[0]){
                    b[0] = a[0];
                }
            res=b;
            return true;
        }
        return false;

    }
};
//[[2,3],[1,9],[8,10],[15,18]]
