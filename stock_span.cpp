/*
  stock_span_problem.cpp
 
  Key Terminologies:
    • Stack: Used to store indices of previous higher stock prices.
    • Span: Number of consecutive days the stock price was less than or equal to today.
 
  Usage:
    1. Compile: g++ stock_span_problem.cpp -o stock_span
    2. Run:     ./stock_span
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    // Stock prices for 7 days
    vector<int> price = { 100, 80, 60, 70, 60, 75, 85 };

    // Resultant span array
    vector<int> ans(price.size());

    // Stack to store indices of previous higher prices
    stack<int> s;

    // Traverse through each day's price
    for(int i = 0; i < price.size(); i++){
        // Pop elements from stack while the current price is higher than stack top's price
        while(!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }

        // If stack is empty, no greater price to the left
        if(s.empty()){
            ans[i] = i + 1;
        }
        else{
            ans[i] = i - s.top(); // i - index of previous higher price
        }

        // Push current index into stack
        s.push(i);
    }

    // Output the span values
    cout << "Stock Span Values:\n";
    for(int val : ans){
        cout <<  val << " ";
    }
    cout << endl;

    return 0;
}
