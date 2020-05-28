#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<vector<string>> work, int day) {
	cout << work[day].size() << " ";
	for (auto x : work[day]) {
		cout << x << " ";
	}
	cout << endl;
}

vector<vector<string>> next_m(vector<vector<string>> work, int mounth) {
	vector<vector<string>> temp(32);
	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int next_m;
	if (mounth == 11) {
		next_m = 0;
	} else {
		next_m = mounth + 1;
	}
	if (days[mounth] <= days[next_m]) {
		return work;
	} else {
		int z = days[next_m];
		int curr;
		for (int i = 0; i <= days[mounth]; ++i) {
			if (i <= z) {
				curr = i;
			}
			else {
				curr = z;
			}
			for (auto x : work[i]) {
				temp[curr].push_back(x);
			}
		}
	}
	return temp;
}

int main() {
	vector<vector<string>> work(32);
	int curr_mounth = 0;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string operat;
		cin >> operat;
		if (operat == "ADD") {
			int day;
			string curr_work;
			cin >> day >> curr_work;
			work[day].push_back(curr_work);
		} else if (operat == "DUMP") {
			int day;
			cin >> day;
			print(work, day);
		} else if (operat == "NEXT") {
			work = next_m(work, curr_mounth);
			if (curr_mounth == 11) {
				curr_mounth = 0;
			} else {
				curr_mounth++;
			}
		}
	}
	return 0;
}
