// First Question of Challange 1
// Question Name:-
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Leetcode #150

#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string s = tokens.back();
        tokens.pop_back();

        //  here it is an operand...
        if(s != "+" && s != "-" && s != "*" && s != "/"){
            return stoi(s);
        }
        //  now this is an operator...
        int A = evalRPN(tokens);  //  getting the left operator...
        int B = evalRPN(tokens);  //  getting right operator...

        //  return the operation of A and B according to the operator...
            ////  Addition      ||   Subtraction  || Multiplication || Division
        return (s == "+") ? A+B :((s == "-") ? B-A : ((s == "*") ? A*B : B/A));
    }
};