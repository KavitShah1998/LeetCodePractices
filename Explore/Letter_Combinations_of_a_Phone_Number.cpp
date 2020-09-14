/* Approach: Iterative:
Runtime: 0ms, beats 100% of submission
Memory: 6.7MB, beats 42.65% of submission
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int size = digits.length();
        
        if (size == 0)
            return {};
        std::vector<string> db{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        std::vector<string> s{""};
        
        int pos{0};
        while((*(s.begin())).length()!=size ){
            while((*(s.begin())).length() != pos+1){
                string top = *(s.begin());
                s.erase(s.begin());

                int ind = (digits[pos])-'0';

                for(int i=0; i<(db[ind]).length(); i++){
                    s.push_back(top+(db[ind])[i]);
                }            
            }
            pos++;
        }
        
        return s;
    }
};
