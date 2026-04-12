class Solution {
public:
   bool isValid(string s)
{
	stack<char> st;
	unordered_map<char, char> match;
	match[')'] = '(';
	match[']'] = '[';
	match['}'] = '{';
	for (char c : s)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			st.push(c);
		}
		else {
			if (st.empty()) return false;
			if (st.top() != match[c]) return false;
			st.pop();
		}
	}
	return st.empty();
}
};