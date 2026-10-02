/*
 * Problem  : Dynamic Array (HackerRank)
 * Topic    : Data Structures / Vectors
 * Language : C++20
 *
 * Approach : Keep a vector of n vectors (arr) and a variable lastAnswer.
 *            For every query we compute idx = (x ^ lastAnswer) % n and then:
 *              type 1 -> push y at the end of arr[idx]
 *              type 2 -> lastAnswer = arr[idx][y % size of arr[idx]],
 *                        and save lastAnswer in the answers list
 *            Each query is handled directly with indexing, so there is no
 *            searching or shifting of elements.
 *
 * Time     : O(N + Q)  - O(N) to create the arrays, O(1) per query
 * Space    : O(N)      - the n arrays (plus the stored values and answers)
 *
 * Note: HackerRank supplies its own main(), so only dynamicArray() is
 * needed there. The main() below is a small driver for running locally.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamicArray(int n, const vector<vector<int>>& queries) {
    vector<vector<int>> arr(n);  // n empty arrays
    vector<int> answers;         // results of the type 2 queries
    int lastAnswer = 0;

    for (const auto& q : queries) {
        int type = q[0];
        int x = q[1];
        int y = q[2];

        // x can be as large as 10^9, so % n keeps idx inside 0..n-1
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            arr[idx].push_back(y);
        } else {
            lastAnswer = arr[idx][y % static_cast<int>(arr[idx].size())];
            answers.push_back(lastAnswer);
        }
    }

    return answers;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];

    vector<int> result = dynamicArray(n, queries);
    for (int value : result)
        cout << value << "\n";

    return 0;
}
