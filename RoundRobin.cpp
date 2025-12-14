#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;

void RR(int n, vector<int> arr, int tq)
{
    const int ITERATIONS = 10000;

    // Declare data array outside the loop
    int data[n][3];

    auto x = chrono::high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            q.push(arr[i]);
        }

        int i = -1;
        int sh = 0;
        while (!q.empty())
        {
            i++;
            int curr = q.front();
            q.pop();

            if (curr <= tq)
            {
                sh += curr;
                if (iter == 0)
                    data[i % n][0] = sh; // Only store on first iteration
                continue;
            }
            curr -= tq;
            sh += tq;
            q.push(curr);
        }
    }

    auto y = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = y - x;
    double avg_time = (duration.count() * 1000000000) / ITERATIONS;

    cout << "\nAverage time per execution: " << avg_time << " nanoseconds\n";

    // Now data is accessible here
    cout << "P\t| AT\t| BT\t| CT\t| TAT | WT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t 0 \t" << arr[i] << " \t" << data[i][0] << " \t" << data[i][0] << "\t" << data[i][0] - arr[i] << endl;
    }
}

int main()
{

    int n, tq;

    cout << "Number of processes: ";
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << " -> burst = ";
        cin >> arr[i];
    }

    cout << "Time Quantum: ";
    cin >> tq;

    RR(n, arr, tq);

    return 0;
}

// 1,04,542
//   52,792
// 1,23,125
// 1,81,167

//   56,458
//   23,333
//   51,041
//   18,291

//     1774.27
//     1825.05