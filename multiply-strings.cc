#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.length()+num2.length()+1, '0');
        string rnum1(num1.rbegin(), num1.rend());
        string rnum2(num2.rbegin(), num2.rend());
        for (std::size_t i=0; i<rnum1.length(); ++i) {
            int x = rnum1[i] - '0';
            int carry = 0;
            for (std::size_t j=0; j<rnum2.length(); ++j) {
                int exist = result[i+j] - '0';
                int y = rnum2[j] - '0';
                int r = x * y + carry + exist;
                result[i+j] = r % 10 + '0';
                carry = r / 10;
            }
            if (carry) {
                result[i+num2.length()] = carry + '0';
            }
        }
        std::reverse(result.begin(), result.end());
        int pos = result.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return result.substr(pos);
    }
};

int main() {
    Solution solution;
    std::cout << solution.multiply("128371923718237987897", "9781283971239879") << std::endl;
    return 0;
}
