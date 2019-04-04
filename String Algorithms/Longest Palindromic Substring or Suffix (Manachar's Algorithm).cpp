/*
* Can find longest palindromic substring or suffix
* Also we can find the longest palindromic prefix by reversing the string and then getting longest palindromic suffix
* Usage :
*   Manachar lps(s);
*   string substring = lps.getPalindromeSubstring();
*/

class Manachar {
private:
    int maxPalindrome=0, maxPalindromeSuffixSize=0;
    int n;
    string s,palindrome_substring, palindrome_suffix;
    vector < int > P;

    string convertToNewString(const string &s) {
        string newString = "@";

        for (int i = 0; i < s.size(); i++)
            newString += "#" + s.substr(i, 1);

        newString += "#$";
        return newString;
    }

    void longestPalindromeSubstring() {
        string Q = convertToNewString(s);
        int c = 0, r = 0;

        for (int i = 1; i < Q.size() - 1; i++) {
            int iMirror = c - (i - c);

            if(r > i) {
                P[i] = min(r - i, P[iMirror]);
            }

            while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
                P[i]++;
            }

            if (i + P[i] > r) {
                c = i;        
                r = i + P[i];
            }
        }

        int centerIndex = 0;
        int centerIndexSuffix = 0;

        for (int i = 1; i < Q.size() - 1; i++) {

            if (P[i] > maxPalindrome) {
                maxPalindrome = P[i];
                centerIndex = i;
            }
            if (P[i] > maxPalindromeSuffixSize && i+P[i] == Q.size()-2 ) {
                maxPalindromeSuffixSize = P[i];
                centerIndexSuffix = i;
            }
        }  

        palindrome_substring = s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
        palindrome_suffix = s.substr( (centerIndexSuffix - 1 - maxPalindromeSuffixSize) / 2, maxPalindromeSuffixSize);
    }
public:
    Manachar(string str) {
        n = str.size();
        s = str;
        P.resize(4*n+100,0);
        longestPalindromeSubstring();
    }
    int getPalindromeSubStringSize() {
        return maxPalindrome;
    }

    string getPalindromeSubstring() {
        return palindrome_substring;
    }

    int getPalindromeSuffixSize() {
        return maxPalindromeSuffixSize;
    }
    string getPalindromeSuffix() {
        return palindrome_suffix;
    }

};
