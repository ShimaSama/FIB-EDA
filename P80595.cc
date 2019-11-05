#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& a, int l, int m, int r){
	
	if(l>=r) return 0;
	int n=r-l+1;
	vector<int> aux(n);
	int i=l;
	int j=m+1;
	int k=0;
	int inv=0;
	while(i<=m and j<=r){
		if(a[i] <= a[j]){
			aux[k] = a[i];
			i++;

		}
		else{
			aux[k] = a[j];
			j++;
			inv +=(m-i+1);
		}
		++k;
		
	}
	while(i<=m){
	aux[k] = a[i];
	i++;
	k++;	
	} 
	while(j<=r){
		aux[k] = a[j];
		++j;
		++k;
		
	}
	for (int p=0; p<n; ++p) a[l+p] = aux[p];
		return inv;
}

int inv_rec(vector<int>& v, int l, int r){

	if(l>=r) return 0;
	int m=(l+r)/2;
	return inv_rec(v, l ,m) + inv_rec(v, m+1 ,r) + merge(v,l,m,r);


}
int main(){
	
	int n;
	while (cin >> n){

	if(n==0) cout << 0 << endl;


	else{
		vector<int> v(n);
		for(int i=0; i<n;i++) cin >> v[i];
		
		cout << inv_rec(v,0,n-1) << endl;

		}
}

}
