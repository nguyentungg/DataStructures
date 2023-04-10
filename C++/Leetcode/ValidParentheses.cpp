#include<iostream>>
#include<stack>;
using namespace std;

int main(){
    stack<char> stack;

        for(char c : s){
            switch(c){
                case '(':
                case '{':
                case '[':
                stack.push(c);
                break;

                case ')':
                case '}':
                case ']': {
                    if(stack.empty()) return false;

                    char expected;
                    if(c == ')') expected = '(';
                    if(c == '}') expected = '{';
                    if(c == ']') expected = '[';
                    if(stack.top() == expected){
                        stack.pop();
                    } else {
                        return false;
                    }
                }
                break;

                default:
                return false;
            }
        
        }
        return stack.empty();
}