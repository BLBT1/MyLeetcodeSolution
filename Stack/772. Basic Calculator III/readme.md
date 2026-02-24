# 772. Basic Calculator III

# Example: 
2*(1+(5+5*2))/3+(6/2+8)-1
           i 


1. need first eval the part in parathesis.
`2*(1-(5+5*2))` => `2*-14`

store the un-eval string in the stack.
if see (, put thing in stack to calculate later
if see ), finish eval for curr part, pop from stack. 

2. the result from eval can be positive or negative
so we might see `2*-14`, so this mononmial is -28, we need to consider this
`2*(1+(5+5*2))/3+(6/2+8)-1` => 2*-28/3 + 11 - 1

We need to call eval the part in calculate / or * first, then +/-
We also need to handle the postive/negative for each monomial

Will use a array to store result for each monomial, at the end we will sum up all monomials to get res.
`vector<int> monomials;`

+1 +-2 + 3*-2 
   i 
        j

`2*-28/3`
 i
  j

if we see a * or /, we just need to times or divided by at the back of monomials.

*-28
X,X,X,X, 2, we just `monomials.back() * -28`

``` c++
class Solution {
public:
    int calculate(string s) {
        string currStr; // curr uneval string
        stack<string> unevals;
        for(int i =0; i < s.size(); ++i){
            if(s[i] == '('){
                unevals.push(currStr);
                currStr = "";
            } else if(s[i] == ')') {
                int localRes = evaluate(currStr);         
                string uneval = unevals.top();
                unevals.pop();
                currStr = uneval+to_string(localRes);
            } else{
                currStr.push_back(s[i]);
            }
        }

        return evaluate(currStr);
    }

    int evaluate(string s) {
        s = "+" + s;

        vector<int> monomials;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '+' || s[i] == '-') {
                int j = i+1;
                if(s[j] == '+'|| s[j] == '-')
                    ++j;
                while(j < s.size() && isdigit(s[j])) 
                    ++j;
                
                int localRes = stoi(s.substr(i+1,j-i-1));
                if (s[i] == '+')
                    monomials.push_back(localRes);
                else
                    monomials.push_back(localRes*-1);
                
                i = j;
            } else if (s[i] == '*' || s[i] == '/') {
                int j = i+1;
                if(s[j] == '+'|| s[j] == '-')
                    ++j;
                while(j < s.size() && isdigit(s[j])) 
                    ++j;
                int localRes = stoi(s.substr(i+1,j-i-1));

                // modify the back of monomials
                if (s[i] == '*')
                    monomials.back() = monomials.back()*localRes;
                else
                    monomials.back() = monomials.back()/localRes;
                
                i = j;
            }
        }

        int res = 0;
        for(auto m: monomials) {
            res += m;
        }
        return res;
    }
};

// Example: 
// 2*(1+(5+5*2))/3+(6/2+8)-1
//            i 


// 1. need first eval the part in parathesis.
// `2*(1-(5+5*2))` => `2*-14`

// store the un-eval string in the stack.
// if see (, put thing in stack to calculate later
// if see ), finish eval for curr part, pop from stack. 

// 2. the result from eval can be positive or negative
// so we might see `2*-14`, so this mononmial is -28, we need to consider this
// `2*(1+(5+5*2))/3+(6/2+8)-1` => 2*-28/3 + 11 - 1

// We need to call eval the part in calculate / or * first, then +/-
// We also need to handle the postive/negative for each monomial

// Will use a array to store result for each monomial, at the end we will sum up all monomials to get res.
// `vector<int> monomials;`

// +1 +-2 + 3*-2 
//    i 
//         j

// `2*-28/3`
//  i
//   j

// if we see a * or /, we just need to times or divided by at the back of monomials.

// *-28
// X,X,X,X, 2, we just `monomials.back() * -28`
```