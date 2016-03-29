class Solution {
public:
	int list[256];

	int lengthOfLongestSubstring(string s) {
		memset(list, -1, sizeof(int)*256);
		int i = 0, max_len = 0;

		for (int j = 0; j<s.size(); j++)
		{
			char current_char = s[j];
			cout<<current_char<<endl;
			int& last_appear = list[current_char-'\0'];
			if (last_appear >= i)
				i = last_appear + 1;
			last_appear = j;

			max_len = max(max_len, j - i + 1);
		}
		return max_len;
	}
};