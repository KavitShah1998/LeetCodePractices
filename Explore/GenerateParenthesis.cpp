class Solution {
public:

    /* Method 1: using vector of tuples*/
    // Runtime: 820 ms, faster than 5.19%
    // Memory:  7.7 MB, less than 94.42%
    typedef std::tuple<string, int, int> T;
    
    vector<string> generateParenthesis(int n) {
        if (n==0)
            return {""};
        std::vector<T> V{std::make_tuple("(",1,0)};
        
        std::vector<string> result;
        while(!V.empty()){
            auto tup = V.front();
            V.erase(V.begin());
            string ele = std::get<0>(tup);
            int nO = std::get<1>(tup);
            int nC = std::get<2>(tup);
            
            if (nO == n && nC==n)
                break;
            
            if(nO < n){ // can insert an opening bracket
                V.push_back(std::make_tuple(ele+"(", nO+1,nC));
            }
            if(nC < nO) { // can insert a closing bracket
                V.push_back(std::make_tuple(ele+")",nO,nC+1));
                if(nO==n && nC==n-1)
                    result.push_back(ele+")");
            }
            
            
        }
        return result;      
    
        
    }
    
    /* Method2: Without using tuples*/
    //Runtime: 416 ms, faster than 5.19%
    //Memory: 7.4 MB, less than 96.09%
    vector<string> generateParenthesis(int n) {
        if (n==0)
            return {""};
        //std::vector<T> V{std::make_tuple("(",1,0)};
        std::vector<string> V{"("};
        std::vector<int> nO_Vec{1};
        std::vector<int> nC_Vec{0};
        
        //std::vector<string> result;
        while(!V.empty()){
            
            string ele = V.front();
            int nO = nO_Vec.front();
            int nC = nC_Vec.front();
            
            
            if (nO == n && nC==n)
                break;
            
            if(nO < n){ // can insert an opening bracket
                V.push_back(ele+"(");
                nO_Vec.push_back(nO+1);
                nC_Vec.push_back(nC);
            }
            if(nC < nO) { // can insert a closing bracket
                V.push_back(ele+")");
                nO_Vec.push_back(nO);
                nC_Vec.push_back(nC+1);
                
            }
            
            V.erase(V.begin());
            nO_Vec.erase(nO_Vec.begin());
            nC_Vec.erase(nC_Vec.begin());
            
        }
        return V;      
    
        
    }
    
    /*Method3: Recursive*/
    //Runtime: 12 ms, faster than 29.69% 
    //Memory: 15.1 MB, less than 41.78% 
    
    std::vector<string> result;
    int n;
    
    //recursion_generateParenthesis
    void R(string ele, int nO, int nC){
        
        if(ele.length()==2*n){
            result.push_back(ele);
            return;
        }
        
        if(nO<n){ // insert open parenthesis
            R(ele+"(", nO+1, nC);
        }
        if(nC<nO){ // inesrt closing parenthesis
            R(ele+")", nO, nC+1);
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int N) {
        if (N==0)
            return {""};
        n=N;
        R("",0,0);
        return result;      
    
        
    }
};

/*n=2
()()

(())
    
    
    
n=3
(())()
()(())
    
(()())
    
()()()
((()))*/
