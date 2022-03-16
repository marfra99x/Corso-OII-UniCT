#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct cannolo {
	int delta;
	int idx;
};

bool _cmp(cannolo a, cannolo b) {
	return a.delta > b.delta;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	for (int task = 0; task < 100; task++) {

		int N;
		in >> N;

		int M[N+1], F[N+1];
		cannolo vassoio[N+1];

		for (int i = 0; i < N; i++) {
			in >> M[i] >> F[i];
			vassoio[i].delta = M[i]-F[i];
			vassoio[i].idx = i;
		}

		sort(vassoio, vassoio+N, _cmp);
		// for (int i = 0; i < N; i++) cout << vassoio[i].idx << " : " << vassoio[i].delta << '\n';

		int res = 0;
		for (int i = 0; i < N/2; i++) res += M[vassoio[i].idx];
		for (int i = N/2; i < N; i++) res += F[vassoio[i].idx];

		out << res << endl;

	}
	
	in.close();
	out.close();

	return 0;
}