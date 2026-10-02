/*
 * Problem  : Time Conversion (HackerRank)
 * Topic    : Strings & Logic
 * Language : C++20
 *
 * Approach : The input always looks like hh:mm:ssAM or hh:mm:ssPM, so the
 *            minutes and seconds never change. Only the hour needs fixing:
 *              12 AM -> 00          (midnight)
 *              12 PM -> 12          (noon)
 *              other PM hours -> hour + 12
 *              other AM hours -> unchanged
 *            Then we put the new hour in front of the original ":mm:ss".
 *
 * Time     : O(1)  - the string always has the same fixed length (10)
 * Space    : O(1)  - a few small variables
 *
 * Note: HackerRank supplies its own main(), so only timeConversion() is
 * needed there. The main() below is a small driver for running locally.
 */

#include <iostream>
#include <string>
using namespace std;

string timeConversion(const string& s) {
    int hour = stoi(s.substr(0, 2));  // first two characters
    bool isPM = (s[8] == 'P');        // 9th character is 'A' or 'P'

    if (hour == 12) {
        hour = isPM ? 12 : 0;         // 12 PM stays 12, 12 AM becomes 00
    } else if (isPM) {
        hour += 12;                   // 1 PM..11 PM -> 13..23
    }

    string h = to_string(hour);
    if (h.size() < 2) h = "0" + h;    // keep two digits, e.g. "07"

    return h + s.substr(2, 6);        // s.substr(2, 6) is ":mm:ss"
}

int main() {
    string s;
    cin >> s;

    cout << timeConversion(s) << endl;
    return 0;
}
