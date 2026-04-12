// Accepted

#include <iostream>

using namespace std;

vector<double> internalAngles(vector<int> sides) {
    if(sides[0] + sides[1] <=  sides[2]) return {};
    if(sides[0] + sides[2] <=  sides[1]) return {};
    if(sides[1] + sides[2] <=  sides[0]) return {};

    vector<double> angles;

    double angle1 = acos((pow(sides[0], 2.0) + pow(sides[1], 2.0) - pow(sides[2], 2.0)) / (double)(2.0 * sides[0] * sides[1]))  * 180 / M_PI;

    angles.push_back(angle1);

    double angle2 = acos((pow(sides[1], 2.0) + pow(sides[2], 2.0) - pow(sides[0], 2.0)) / (double)(2.0 * sides[1] * sides[2]))  * 180 / M_PI;

    angles.push_back(angle2);

    double angle3 = acos((pow(sides[0], 2.0) + pow(sides[2], 2.0) - pow(sides[1], 2.0)) / (double)(2.0 * sides[0] * sides[2]))  * 180 / M_PI;

    angles.push_back(angle3);

    sort(angles.begin(), angles.end());

    return angles;
}

int main() {
    vector<double> angles = internalAngles({2, 4, 2});

    for(auto a : angles) cout << a << " ";

    cout << endl;
    return 0;
}