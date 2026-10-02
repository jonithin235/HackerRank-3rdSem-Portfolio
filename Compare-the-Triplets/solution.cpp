/*
 * Problem  : Compare the Triplets (HackerRank)
 * Topic    : Basic Implementation
 * Language : C++20
 *
 * Approach : Compare a[i] and b[i] for i = 0, 1, 2.
 *            If a[i] > b[i], Alice gets a point.
 *            If a[i] < b[i], Bob gets a point.
 *            If they are equal, nobody gets a point.
 *            Return {Alice's score, Bob's score}.
 *
 * Time     : O(1)  - always exactly 3 comparisons
 * Space    : O(1)  - two counters and a result of size 2
 *
 * Note: HackerRank supplies its own main(), so only compareTriplets() is
 * needed there. The main() below is a small driver for running locally.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> compareTriplets(const vector<int>& a, const vector<int>& b) {
    int alice = 0;
    int bob = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice++;
        } else if (a[i] < b[i]) {
            bob++;
        }
        // equal -> no points
    }

    return {alice, bob};
}

int main() {
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];

    vector<int> result = compareTriplets(a, b);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
