#include<bits/stdc++.h>
using namespace std;

void TestCase(int T)  {
	cout << "Case #" << T << ": ";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<char> Operation = {'+', '-', '*', '/', '='};
	vector<string> OperationS = {"plus", "substract", "multiple", "division", "equals"};
	vector<string> Num = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30", "40", "50", "60", "70", "80", "90", "100"};
	vector<string> NumS = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty", "hundred" } ;

	int totalEquation;
	cin >> totalEquation;
	for (int T = 1; T <= totalEquation; T++) {
		TestCase(T);
		vector<string> equation;
		string s;
		while (true) {
			cin >> s;
			if (s == "and" || s == " ") continue;
			if (s == "=" || s == "equals") {
				equation.push_back(s);
				cin >> s;
				equation.push_back(s);
				break;
			}
			equation.push_back(s);
		}

		for (auto& op : equation) {
			int it = find(OperationS.begin(), OperationS.end(), op) - OperationS.begin();
			if (it != (int)OperationS.size()) {
				op = Operation[it];
			}
			it = find(NumS.begin(), NumS.end(), op) - NumS.begin();
			if (it != (int)NumS.size()) {
				op = Num[it];
			}
		}

		double LHS = 0, RHS = 0;
		double previous = -1;
		char previousOperation = '#';
		bool IsNegeative = false;
		for (int i = 0; i < (int)equation.size(); i++) {
			if (('0' <= equation[i][0] && equation[i][0] <= '9') || (previousOperation == '=')) {
				if (equation[i][0] == '-') {
					IsNegeative = true;
					equation[i] = equation[i].substr(1);
				}
				if (previous == -1) {
					previous = stod(equation[i]);
				} else {
					if (equation[i] == "100") {
						previous *= stod(equation[i]);
					} else {
						previous += stod(equation[i]);
					}
				}
			} else {
				if (previousOperation == '#') {
					LHS = previous;
				} else {
					if (previousOperation == '+') {
						LHS += previous;
					} else if (previousOperation == '-') {
						LHS -= previous;
					} else if (previousOperation == '*') {
						LHS *= previous;
					} else if (previousOperation == '/') {
						LHS /= previous;
					}
				}
				previous = -1;
				previousOperation = equation[i][0];
			}
		}
		RHS = (IsNegeative ? -previous : previous);
		cout << (LHS == RHS ? "true" : "false") << endl;
	}
}