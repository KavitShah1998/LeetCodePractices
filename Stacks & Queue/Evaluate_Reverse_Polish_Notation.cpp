/*
Runtime: 20 ms (beats 99.55% submissions)
Memory: 12.2 MB (beats 20% submissions)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> STk;
        int size = tokens.size();
        
        for(int i=0; i<size; i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                STk.push(stoi(tokens[i]));
            }
            else{
                int num2{STk.top()};
                STk.pop();
                int num1{STk.top()};
                STk.pop();
                
                if(tokens[i]=="+")
                    STk.push(num1+num2);
                else if(tokens[i]=="-")
                    STk.push(num1-num2);
                else if(tokens[i]=="*")
                    STk.push(num1*num2);
                else 
                    STk.push(num1/num2);
            }
        }
        
        int ans{STk.top()};
        STk.pop();
        return ans;
    }
};
