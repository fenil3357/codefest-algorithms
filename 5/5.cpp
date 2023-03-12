#include<bits/stdc++.h>
using namespace std;

void TestCase(int T)  {
	cout << "Case #" << T << ": ";
}


int main() {
	int appleProfit = 400 / 5 * 150, appleDays = 10;
	int orangeProfit = 280 / 7  * 250, orangeDays = 6;
	int mangoProfit = 2200 / 8 * 100, mangoDays = 15;
	int lemonProfit = 1500 / 10 * 50, lemonDays = 5;
	int coconutProfit = 75 / 15 * 1600, coconutDays = 15;
	int TC;
	cin >> TC;
	for (int T = 1; T <= TC; T++) {
		TestCase(T);
		long long int N, D;
		cin >> N >> D;
		int single_max_tree = N * (0.4);
		single_max_tree--;
		vector<long long int> maxProfits = {appleProfit * (D / appleDays), orangeProfit * (D / orangeDays), mangoProfit * (D / mangoDays), lemonProfit * (D / lemonDays), coconutProfit * (D / coconutDays)};
		sort(maxProfits.begin(), maxProfits.end());
		long long int ans = accumulate(maxProfits.begin(), maxProfits.end(), 0);
		int rem = N - 5;
		ans += maxProfits[4] * min(rem, single_max_tree);
		rem -= min(rem, single_max_tree);
		// single_max_tree--;
		maxProfits.pop_back();
		reverse(maxProfits.begin(), maxProfits.end());
		for (int i = 0; i < 3; i++) {
			ans += maxProfits[i] * min(rem, single_max_tree);
			rem -= min(rem, single_max_tree);
		}
		cout << ans << endl;
	}
}
