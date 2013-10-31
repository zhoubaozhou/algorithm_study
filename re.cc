// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// 
// The matching should cover the entire input string (not partial).
// 
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
// 
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true


//
// 一个比较变态的case是：s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac"
//                       p = "a*a*a*a*a*a*a*a*a*a*ab"
//
//  这种除了合并相同的sub re，还有其它办法么？
//
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        if (*p == '\0') return *s == '\0';
        if (*p != '\0' && *(p+1) == '*' && *p == *(p+2) && *(p+3) == '*') {
            return isMatch(s, p+2);
        }
        if (*(p+1) == '*') {
            if (isMatch(s, p+2)) return true;
            if (((*p == '.' && *s != '\0') || (*p == *s)) && isMatch(s+1, p+2)) return true;
            // '.' match more than one
            while (*p == *s || (*p == '.' && *s != '\0')) {
                if (isMatch(s, p+2)) return true;
                s++;
            }
            return isMatch(s, p+2);
        } else {
            if ((*p == '.' && *s != '\0')|| *s == *p) return isMatch(s+1, p+1);
        }
        return false;
    }
};
