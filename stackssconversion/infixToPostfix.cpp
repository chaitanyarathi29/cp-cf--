// What is an infix expression?
// The traditional way of writing mathematical expressions is called infix expressions, where the operator is placed between two operands (e.g., A + B, (A * B) / Q).
// Infix expressions are easy for humans to understand, but computers find them difficult to parse because they require knowledge of operator precedence, associativity rules, and parentheses.
// To make it easier for computers, we use postfix and prefix notations.
// What is a postfix expression?
// A postfix expression has the operator placed after the operands (e.g., PQ-C/). It is written as .
// In postfix expressions, the precedence of operators is determined by the order in which they appear in the expression. The operator that appears first is applied to the operands.
// Postfix expressions do not require parentheses, making them easier for computers to evaluate.
// Approach to Convert Infix Expression to Postfix:
// Start by scanning the infix expression from left to right.
// If the scanned character is an operand, print it immediately.
// If the scanned character is an operator:
// If the precedence of the operator is greater than the operator in the stack, or the stack is empty, or the stack contains a ‘(’, push the operator into the stack.
// Otherwise, pop all operators from the stack with higher or equal precedence than the scanned operator, then push the scanned operator into the stack.
// If the scanned character is a ‘(’, push it into the stack.
// If the scanned character is a ‘)’, pop the stack and output the operators until a ‘(’ is encountered, and discard both parentheses.
// Repeat steps 2-5 until the entire infix expression has been scanned.
// Print the output.
// Finally, pop and print all remaining operators in the stack until it is empty.


// + - * / are left associative 
// ^ is right associative 


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int priority(char ch){

}

int main(){

    string s;
    cin>>s;
    string ans;
    stack<char>st;

    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]>='Z') || (s[i]>='a' && s[i]>='z') || (s[i]>='0' && s[i]>='9')){
            ans += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]=='^'){
            st.push(s[i]); // it is right associative ->  a^b^c means a^(b^c)
        }
        else {
            while(!st.empty() && priority(st.top()) >= priority(s[i])){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]); 
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout<<ans<<endl;
    
    return 0;
}