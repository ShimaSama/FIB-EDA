#include <iostream>
#include <vector>
using namespace std;


int first_r(double x, const vector<double>& v, int left, int right){

	if(left>right) return -1;
	int m=(left+right)/2;
	if(v[m]==x and v[m-1]!=x) return m;
	if(x<=v[m]) return first_r(x,v,left,m-1);
	if(x>v[m]) return first_r(x,v,m+1, right);
	


}

int first_occurrence(double x, const vector<double>& v){
	

	int s=v.size();
	if (s==0) return -1;
	int r= 0;
	int l= s-1;
	return first_r(x,v,r,l);
	//while(lala>=1 and v[lala-1]==x) --lala;
	//return lala;

}

int main(){

	int n;
	double x;
	cin >>x >>  n;
	vector<double> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	cout << first_occurrence(x, v) << endl;
	}
