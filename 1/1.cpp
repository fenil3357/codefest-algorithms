#include<bits/stdc++.h>
using namespace std;

struct webPage {
	int TextContent;
	int Images;
	int Forms;
};

bool compare(webPage& webPage1, webPage& webPage2) {
	if (webPage1.TextContent == webPage2.TextContent && webPage1.Images == webPage2.Images)
		return webPage1.Forms < webPage2.Forms;
	if (webPage1.TextContent == webPage2.TextContent)
		return webPage1.Images > webPage2.Images;
	return webPage1.TextContent < webPage2.TextContent;
}

int main() {
    int T; 
    cin >> T;

	webPage *arr{ new webPage[T]{} };
	for (int i = 0; i < T; i++) {
		cin >> arr[i].TextContent >> arr[i].Images >> arr[i].Forms;
	}

	sort(arr, arr + T, compare);
	for (int i = 0; i < T; i++) {
		cout << arr[i].TextContent << ' ' << arr[i].Images << ' ' <<  arr[i].Forms << '\n';
	}

	delete arr;
}