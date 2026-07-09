#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:

    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        for(string token : tokens)
        {
            if(token!="+" &&
               token!="-" &&
               token!="*" &&
               token!="/")
            {
                st.push(stoi(token));
            }
            else
            {
                int operand2 = st.top();
                st.pop();

                int operand1 = st.top();
                st.pop();

                if(token=="+")
                    st.push(operand1+operand2);

                else if(token=="-")
                    st.push(operand1-operand2);

                else if(token=="*")
                    st.push(operand1*operand2);

                else
                    st.push(operand1/operand2);
            }
        }

        return st.top();
    }
};