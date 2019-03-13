#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

vector<int> A, s;
vector<vector<int> > ret;

int getIdx(int val) {
	return lower_bound(s.begin(), s.end(), val) - s.begin();
}

int dp(int start){
	int& ret = cache[start];
	if(ret != -1) return ret;
	
	for(int i = start+1; i < n; i++){
		if(s[start] < s[i])
			ret = max(ret , 1+ dp(i));
	}
	return ret;
}

void solve() {
	int idx;
	for (int i = 0; i < A.size(); i++) {
		idx = getIdx(A[i]);
		if (idx == s.size()) 
			s.push_back(A[i]);	

		else 
			s[idx] = A[i]; 	
			
		ret[idx].push_back(A[i]);
	}
	
}
int main() {
	cin >> N;
	A.assign(N + 1,-1);

	ret.resize(N);
	
	for (int i = 0; i < N; i++)
		cin >> A[i];
	solve();
	int idx;
	cout << s.size() << endl;
	A[s.size()] = 1000000001;
	for (int i = s.size() - 1; i >= 0; i--) {	
		idx = ret[i].size() - 1;
		A[i] = ret[i][idx];
	}
	for (int i = 0; i < s.size(); i++)
		cout << A[i] << " ";
	
}
