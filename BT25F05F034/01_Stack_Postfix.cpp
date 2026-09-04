#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    stack<int> st;
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix)
    {
        // If character is a digit, push it into stack
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        // If character is an operator
        else
        {
            int operand2 = st.top();
            st.pop();

            int operand1 = st.top();
            st.pop();

            int result;

            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                case '%':
                    result = operand1 % operand2;
                    break;

                default:
                    cout << "Invalid operator!" << endl;
                    return 1;
            }

            st.push(result);
        }
    }

    cout << "Result = " << st.top() << endl;

    return 0;
}