#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void oneThreadTask()
{
    int ans = 0;

    for (int i = 0; i < INT_MAX; i++)
    {
        ans = (ans + i) % INT_MAX;
    }
}
void twoThreadTask()
{
    int ans = 0;

    for (int i = 0; i < INT_MAX / 2; i++)
    {
        ans = (ans + i) % INT_MAX;
    }
}

int main()
{
    // thread t(oneThreadTask);

    thread t1(twoThreadTask);
    thread t2(twoThreadTask);

    auto x = chrono::high_resolution_clock::now(); // Mark start point

    t1.join();
    t2.join();

    auto y = chrono::high_resolution_clock::now(); // Mark end point

    chrono::duration<double> duration = y - x; // Diff bt/w Start and End

    cout << "Result : " << duration.count() << " seconds\n";

    return 0;
}

// Single thread takes: 6.16602 seconds
// Double thread takes: 3.13238 seconds