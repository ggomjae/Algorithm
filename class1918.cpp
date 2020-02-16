#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main() {
 
    string str;
    cin >> str;
    stack<char> stack;
    string result;
 
    for(int i=0; i<str.length(); i++) {
        
        if(str[i] == '+' || str[i] == '-') {
            while(!stack.empty() && stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.push(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/') {
            while(!stack.empty() && (stack.top() == '*' || stack.top() == '/')) {
                result += stack.top();
                stack.pop();
            }
            stack.push(str[i]);
        }
        else if(str[i] == '(') {
            stack.push(str[i]);
        }
        else if(str[i] == ')') {
            while(stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else{
            result += str[i];
        }
    }
    while(!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    cout << result << "\n";
    return  0;
}

