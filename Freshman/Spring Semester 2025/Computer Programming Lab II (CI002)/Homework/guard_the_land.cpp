#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // number of nights

    for (int night = 1; night <= n; ++night) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        int totalArea = 10000; // 100 x 100

        // Area guarded by guard 1
        int area1 = (x2 - x1) * (y2 - y1);

        // Area guarded by guard 2
        int area2 = (x4 - x3) * (y4 - y3);

        // Calculate overlap
        int overlapLeft = max(x1, x3);
        int overlapRight = min(x2, x4);
        int overlapBottom = max(y1, y3);
        int overlapTop = min(y2, y4);

        int stronglySecured = 0;
        if (overlapLeft < overlapRight && overlapBottom < overlapTop) {
            stronglySecured = (overlapRight - overlapLeft) * (overlapTop - overlapBottom);
        }

        int weaklySecured = (area1 + area2) - 2 * stronglySecured;
        int unsecured = totalArea - stronglySecured - weaklySecured;

        cout << "Night " << night << ": " 
             << stronglySecured << " " 
             << weaklySecured << " " 
             << unsecured << endl;
    }

    return 0;
}
