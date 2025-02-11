#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstring>

using namespace std;

int f[100][100];

struct rec
{
	int d,t;
	rec(){}
	rec(int a,int b)
	{
		d=a;t=b;
	}
	bool operator<(const rec &a)const
	{
		return t<a.t;
	}
}z[100];

class GUMIAndSongsDiv1 {
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int n=duration.size();
		for (int a=0;a<n;a++)
			z[a]=rec(duration[a],tone[a]);
		sort(z,z+n);
		memset(f,0x3f,sizeof(f));
		f[0][0]=0;
		f[0][1]=z[0].d;
		for (int a=1;a<n;a++)
			for (int b=0;b<=a+1;b++)
				if (!b) f[a][b]=0;
				else
				{
					for (int c=0;c<a;c++)
						f[a][b]=min(f[a][b],f[c][b-1]+z[a].d+(b==1 ? 0 : z[a].t-z[c].t));
				}
		int ans=0;
		for (int a=0;a<n;a++)
			for (int b=1;b<=n;b++)
				if (f[a][b]<=T) ans=max(ans,b);
		return ans;
		
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	GUMIAndSongsDiv1 *obj;
	int answer;
	obj = new GUMIAndSongsDiv1();
	clock_t startTime = clock();
	answer = obj->maxSongs(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	freopen("meet.in","r",stdin);
	freopen("meet.out","w",stdout);

	vector<int> duration;
	vector<int> tone;
	int n,T;
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
	{
		int v;
		scanf("%d",&v);
		duration.push_back(v);
	}
	for (int a=1;a<=n;a++)
	{
		int v;
		scanf("%d",&v);
		tone.push_back(v);
	}
	scanf("%d",&T);
	GUMIAndSongsDiv1 *obj;
	int answer;
	obj = new GUMIAndSongsDiv1();
	answer = obj->maxSongs(duration, tone, T);
	printf("%d\n",answer);
	/*bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {3,5,4,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,3,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 17;
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {100,200,300};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 99;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 100;
	p3 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {9,11,13,17};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 20;
	p3 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 212;
	p3 = 12;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;*/
}
// END KAWIGIEDIT TESTING


