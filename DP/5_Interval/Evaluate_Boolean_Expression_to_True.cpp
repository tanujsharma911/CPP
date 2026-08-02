/*
Boolean Parenthesization / Counter number of ways to evaluate boolean expression to true (Hard)

You are given a boolean expression s containing
'T' ---> true
'F' ---> false

and following operators between symbols
&   ---> boolean AND
|   ---> boolean OR
^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of
expression evaluates to true.

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways:
((T|T)&(F^T))
(T|(T&(F^T)))
(((T|T)&F)^T)
(T|((T&F)^T))

Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).

*/


#include <iostream>
using namespace std;

int helper(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>>& memo){
    if(i > j){
        return 0;
    }
    if(i == j) {
        if(isTrue) return (s[i] == 'T');
        else return (s[i] == 'F');
    }

    if(memo[i][j][isTrue] != -1) return memo[i][j][isTrue];

    int cnt = 0;

    for(int k = i + 1; k < j; k += 2){
        int left_trues = helper(i, k - 1, 1, s, memo);
        int right_trues = helper(k + 1, j, 1, s, memo);

        int left_falses = helper(i, k - 1, 0, s, memo);
        int right_falses = helper(k + 1, j, 0, s, memo);

        if(s[k] == '|'){
            if(isTrue){
                cnt += left_trues * right_trues + left_trues * right_falses + left_falses * right_trues;
            }
            else {
                cnt += left_falses * right_falses;
            }
        } else if (s[k] == '&'){

            if(isTrue){
                cnt += left_trues * right_trues;
            }
            else {
                cnt += left_falses * right_falses + left_trues * right_falses + left_falses * right_trues;
            }
        } else {
            if(isTrue){
                cnt += left_trues * right_falses + left_falses * right_trues;
            }
            else {
                cnt += left_falses * right_falses + left_trues * right_trues;
            }
        }
    }

    return memo[i][j][isTrue] = cnt;
}
int countWays(string &s) {
    int n = s.length();

    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));

    return helper(0, n - 1, 1, s, memo);
}

int main()
{
    string s = "T|T&F^T";

    cout << "Number of ways: " << countWays(s);


    cout << endl;
    return 0;
}
