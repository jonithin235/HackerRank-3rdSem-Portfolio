/*
 * Problem  : Sparse Arrays (HackerRank)
 * Topic    : Hash Maps / Strings
 * Language : C++20
 *
 * Approach : Instead of scanning the whole string list for every query
 *            (which would be O(N * Q)), count every string once in an
 *            unordered_map<string, int>. Then each query is just a
 *            lookup in the map; a string that is not in the map has
 *            count 0.
 *
 * Time     : O(N + Q)  - N insertions + Q lookups (average O(1) each,
 *                        strings are at most 20 characters)
 * Space    : O(N)      - the map stores the strings from the list
 *
 * Note: HackerRank supplies its own main(), so only matchingStrings() is
 * needed there. The main() below is a small driver for running locally.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> matchingStrings(const vector<string>& stringList,
                            const vector<string>& queries) {
    unordered_map<string, int> count;
    for (const string& s : stringList) {
        count[s]++;                     // build frequency table
    }

    vector<int> results;
    for (const string& q : queries) {
        auto it = count.find(q);
        results.push_back(it == count.end() ? 0 : it->second);
    }

    return results;
}

int main() {
    int n;
    cin >> n;
    vector<string> stringList(n);
    for (int i = 0; i < n; i++) cin >> stringList[i];

    int q;
    cin >> q;
    vector<string> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i];

    vector<int> results = matchingStrings(stringList, queries);
    for (int r : results)
        cout << r << "\n";

    return 0;
}
