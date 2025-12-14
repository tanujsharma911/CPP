#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixExponentite(vector<vector<int>> &a, long long p)
{
    int n = a.size();

    if(n == 0){
        vector<vector <int>> i(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            a[i][i] = 1;
        }
        return i;
    }
    else if(n == 1){
        return a;
    }

    

    // int n = a.size();
    // vector<vector<int>> ans(n, vector<int>(n, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         for (int k = 0; k < n; k++)
    //         {
    //             ans[i][j] += a[i][k] * a[k][j];
    //         }
    //     }
    // }

    // return ans;
}

int main()
{
    long long n;
    cin >> n;

    vector<vector<int>> k = {{1, 1},
                             {1, 0}};

    vector<vector<int>> ans = matrixExponentite(k, n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}