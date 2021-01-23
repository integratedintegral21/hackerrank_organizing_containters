#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string organizingContainers(vector<vector<int>> container) {
	int n = container.size();
	vector <int> numb_hist(n);			// number of each ball summed over all containers (sum columns)
	for (int i = 0; i < n; i++) {	// iterate over columns
		numb_hist[i] = 0;
		for (int j = 0; j < n; j++) { // iterate over rows
			numb_hist[i] += container[j][i];
		}
	}

	vector <int> con_capacities(n);
	for (int i = 0; i < n; i++) {	// iterate over rows
		con_capacities[i] = 0;
		for (int j = 0; j < n; j++) { // iterate over columns
			con_capacities[i] += container[i][j];
		}
	}

	sort(numb_hist.begin(), numb_hist.end());
	sort(con_capacities.begin(), con_capacities.end());

	for (int i = 0; i < n; i++) {
		if (numb_hist[i] != con_capacities[i]) return "Impossible";
	}

	return "Possible";
}

int main() {

	vector <vector<int>> test1 = {
		{1, 3, 1},
		{2, 1, 2},
		{3, 3, 3}
	};

	vector <vector<int>> test2 = {
		{0, 2, 1},
		{1, 1, 1},
		{2, 0, 0}
	};

	cout << organizingContainers(test2);

	return 0;
}