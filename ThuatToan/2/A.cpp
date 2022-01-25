#include <bits/stdc++.h>
using namespace std;
const int N = 1000002;
int n;
long long h[N];
long long Left[N], Right[N];
stack<long long> st;
unsigned long long answer, S;

void HIST() {
	while (!st.empty())
		st.pop();
	for (int i = 1; i <= n + 1; i++) {
		while (!st.empty() && h[st.top()] > h[i]) {
			Right[st.top()] = i; st.pop();
		}
		st.push(i);
	}

	for (int i = n; i >= 0; i--) {
		while (!st.empty() && h[st.top()] > h[i]) {
			Left[st.top()] = i; st.pop();
		}
		st.push(i);
	}
	for (int i = 1; i <= n; i++) {
		S = (Right[i] - Left[i] - 1) * h[i];
		if (S > answer)
			answer = S;
	}
	cout << answer << endl;
}

int main() {
	while (true) {
		answer = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
			cin >> h[i];
		h[0] = 0;
		h[n + 1] = 0;
		HIST();
	}
}
