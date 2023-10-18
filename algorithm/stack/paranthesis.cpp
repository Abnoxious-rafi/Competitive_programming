#include <iostream>
#include<vector>
using namespace std;
string isBalanced(string s)
{
	vector<char> str;
	str.push_back('0');
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ')' && str[str.size() - 1] == '(')
			str.pop_back();
		else if (s[i] == '}' && str[str.size() - 1] == '{')
			str.pop_back();
		else if (s[i] == ']' && str[str.size() - 1] == '[')
			str.pop_back();
		else
			str.push_back(s[i]);
	}
	if (str.size() == 1)
	{
		string a = "YES";
		return a;
	}
	else
	{
		string a = "NO";
		return a;
	}
}
int main()
{
	string s;
	cin >> s;
	cout << isBalanced(s) << endl;
	return 0;
}
