#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v, int n, int t){

	if(t<n){
		int aux=t+1;
		v[t]=0;
		print(v,n,aux);
		v[t]=1;
		print(v,n,aux);
			
	}
	else{
		
		cout << v[0];
		for(int i=1; i<n; i++){
		
			cout <<" " <<  v[i];

		}
		cout << endl;
	}
}


int main(){

	int n;

	cin >> n;

	vector<int> v(n);

	print(v,n,0);


}
