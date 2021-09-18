
#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a + b);
        }
        else if (tokens[i] == "-")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(a - b);
        }
        else if (tokens[i] == "*")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a * b);
        }
        else if (tokens[i] == "/")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int div = floor(a / b);
            s.push(div);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
}

int main()
{
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens);
    return 0;
}