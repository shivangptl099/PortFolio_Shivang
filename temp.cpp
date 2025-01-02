class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int i = 0;
        while(i < expression.length()){
            if(expression[i] != ')' && expression[i] != ','){
                st.push(expression[i]);
            }
            else if(expression[i] == ')'){
                vector<char> temp;
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char symbol = st.top();
                st.pop();
                char ans;
                if(symbol == '|'){
                    ans = 'f';
                    for(char c : temp){
                        if(c == 't'){
                            ans = 't';
                            break;
                        }
                    }
                }
                else if(symbol == '&'){
                    ans = 't';
                    for(char c : temp){
                        if(c == 'f'){
                            ans = 'f';
                            break;
                        }
                    }
                } else {
                    if(temp[0] == 't') ans = 'f';
                    else ans = 't';
                }
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};