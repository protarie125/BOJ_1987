#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vc = vector<char>;
using vs = vector<string>;

int r, c;
vs board;
int ans;
vc passed;

const auto dx = vi{ -1,1,0,0 };
const auto dy = vi{ 0,0,-1,1 };

void backtracking(int y, int x) {
	if (ans < passed.size()) {
		ans = passed.size();
	}

	for (auto d = 0; d < 4; ++d) {
		const auto nx = x + dx[d];
		const auto ny = y + dy[d];

		if (nx < 0 || c <= nx ||
			ny < 0 || r <= ny) {
			continue;
		}

		const auto& nextChar = board[ny][nx];
		if (passed.end() != find(passed.begin(), passed.end(), nextChar)) {
			continue;
		}

		passed.push_back(board[ny][nx]);
		backtracking(ny, nx);
		passed.pop_back();
	}
}

void solve() {
	ans = 0;
	passed = vc{};

	passed.push_back(board[0][0]);
	backtracking(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> r >> c;
	board = vs(r);
	for (auto&& s : board) {
		cin >> s;
	}

	solve();
	cout << ans;

	return 0;
}