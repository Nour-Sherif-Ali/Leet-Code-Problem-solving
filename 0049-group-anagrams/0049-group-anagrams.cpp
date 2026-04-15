class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
	unordered_map<string, vector<string>> anagramGroups;
	for (auto c : strs)
	{
		string sortedstr = c;
		sort(sortedstr.begin(), sortedstr.end());
		anagramGroups[sortedstr].push_back(c);
	}
	vector<vector<string>> result;
	for (auto group : anagramGroups)
	{
		result.push_back(group.second);
	}
	return result;

}
};