#include <iostream>
using namespace std;

int main() {
    int n = 4;

    int a[2][4] = {
        {4, 5, 3, 2},
        {2, 10, 1, 4}
    };

    int t[2][3] = {
        {7, 4, 5},
        {9, 2, 8}
    };

    int entry[2] = {10, 12};
    int exitTime[2] = {18, 7};

    int line1[n], line2[n];

    // First station
    line1[0] = entry[0] + a[0][0];
    line2[0] = entry[1] + a[1][0];

    // Remaining stations
    for (int i = 1; i < n; i++) {
        line1[i] = min(
            line1[i - 1] + a[0][i],
            line2[i - 1] + t[1][i - 1] + a[0][i]
        );

        line2[i] = min(
            line2[i - 1] + a[1][i],
            line1[i - 1] + t[0][i - 1] + a[1][i]
        );
    }

    int result = min(
        line1[n - 1] + exitTime[0],
        line2[n - 1] + exitTime[1]
    );

    cout << "Minimum time required = " << result;

    return 0;
}