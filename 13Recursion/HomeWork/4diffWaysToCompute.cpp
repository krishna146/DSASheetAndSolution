//Problem Link - https://leetcode.com/problems/different-ways-to-add-parentheses/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> storeDiffWaysToCompute(string expression){
    vector<int> fans;
    if(expression.size() == 1 || expression.size() == 2){
        fans.push_back(stoi(expression));
        return fans;
    }
    for(int i = 0 ; i < expression.size() ; i++){
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
            char op = expression[i];
            vector<int> left;
            vector<int> right;
            string leftExpr = expression.substr(0, i);
            string rightExpr = expression.substr(i+1);
                left = storeDiffWaysToCompute(leftExpr);
                right = storeDiffWaysToCompute(rightExpr);
            
            for(auto leftEl: left){
                for(auto rightEl : right){
                    switch(op){
                        case '*':
                            fans.push_back(leftEl * rightEl);
                            break;
                            case '+':
                            fans.push_back(leftEl + rightEl);
                            break;
                            default:
                            fans.push_back(leftEl - rightEl);
                        
                            
                    }
                }
            }
        }
    }
    return fans;
}
int main(){
    string expr = "2-1-1";
    for(auto el : storeDiffWaysToCompute(expr)){
        cout << el << " ";
    }
}