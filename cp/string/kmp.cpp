#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> calculate_lps(string pattern)
{
	vector<int> lps;
	int n = pattern.size();
	int i = 1;
	int till = 0;
	lps.push_back(0);
	while (i < n) {
		if (pattern[i] == pattern[till]) {
			till++;
			lps.push_back(till);
			i++;
			continue;
		}
		if (till == 0) {
			lps.push_back(till);
			i++;
			continue;
		}
		till = lps[till-1];
	}
	return lps;
}


void kmp(string text, string pattern, vector<int> lps)
{
	int n = text.size();		int m = pattern.size();
	int i,j;
	i = 0;		j = 0;

	while (i < n) {
		if (j == m) {
			cout << "matched pattern at position: " << i-m << endl;
			j = lps[j-1];
		}

		if (text[i] == pattern[j]) {
			i++;
			j++;
			continue;
		}
		if (j == 0) {
			i++;
			continue;
		}
		j = lps[j-1];
	}
	if (j == m) {
		cout << "matched pattern at position: " << i-m << endl;
	}
}

int main()
{
	string pattern = "amam";
	string text = "aamamamam";

	vector<int> lps = calculate_lps(pattern);
	kmp(text, pattern, lps);
	return 0;
}