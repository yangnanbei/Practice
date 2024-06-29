#include <iostream>
#include <string>

using namespace std;

/*
 *给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 *
 *如果剩余字符少于 k 个，则将剩余字符全部反转。
 *如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 */

class Solution {
public:
	void reverse(string& s, int start, int end) {
		for (int i = start, j = end; i < j; i++, j--) {
			swap(s[i], s[j]);
		}
	}
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)) {
			if (i + k <= s.size()) {
				reverse(s, i, i + k - 1);
				continue;
			}
			reverse(s, i, s.size() - 1);
		}
		return s;
	}
};

int main() {
	Solution s;
	string str = "aabbccddeeffgghhhhhhssssaaaaaxxx";

	cout << "str is " << str << endl;
	cout << "reverse str is " << s.reverseStr(str, 10) << endl;
	return 0;
}
