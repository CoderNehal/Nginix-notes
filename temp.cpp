//  Question:  Given a string, find the number of fake palindromes present in it. A fake palindrome is a string which can be made a palindrome by rearranging the characters of the string and not necessarily using all the characters of the string.

#include <iostream>
#include <unordered_map>
using namespace std;

int countFakePalindrome(string s) {
    int state = 0;
    int ans = 0;
    unordered_map<int, int> hmap;
    hmap[0] = 1;
    for (int i = 0; i < s.length(); i++) {
        int ch = s[i] - 'A';
        int mask = (1 << ch);
        state = (state ^ mask);

        for (int j = 0; j < 26; j++) {
            mask = (1 << j);
            int temp = (state ^ mask);
            if (hmap.count(temp)) {
                int pans = hmap[temp];
                ans += pans;
            }
        }
        if (hmap.count(state)) {
            int pans = hmap[state];
            ans += pans;
        }
        hmap[state] = hmap[state] + 1;
    }
    return ans;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int result = countFakePalindrome(input);
    cout << "The count of fake palindromes is: " << result << endl;
    return 0;
}
