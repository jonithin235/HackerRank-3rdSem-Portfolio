/*
 * Problem  : Diagonal Difference (HackerRank)
 * Topic    : 2D Arrays / Matrices
 * Language : C++20
 *
 * Approach : Only the two diagonals matter, so we do not need to look at
 *            every cell. For row i, the primary diagonal element is
 *            arr[i][i] and the secondary diagonal element is arr[i][n-1-i].
 *            One loop over the rows adds both diagonals, then we return
 *            the absolute difference of the two sums.
 *
 * Time     : O(N)  - one pass over the N rows
 * Space    : O(1)  - only two sum variables
 *
 * Note: HackerRank supplies its own main(), so only diagonalDifference()
 * is needed there. The main() below is a small driver so this file
 * compiles and runs on its own.
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(const vector<vector<int>>& arr) {
    int n = arr.size();
    int primary = 0;    // arr[0][0], arr[1][1], ...
    int secondary = 0;  // arr[0][n-1], arr[1][n-2], ...

    for (int i = 0; i < n; i++) {
        primary += arr[i][i];
        secondary += arr[i][n - 1 - i];
    }

    return abs(primary - secondary);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    cout << diagonalDifference(arr) << endl;
    return 0;
}
