#include <iostream>
using namespace std;

int potencia(int x,  int n, int m){

	if(n==0) return 1;
	int  y= potencia(x,  n/2, m);
	if (n%2 ==0) {
		return y%m * y%m;
		//return y*y;
	}
	
	return y%m * y%m *  x%m;
		//return y*y*x;
		
}

int main(){

	int x,n,m;
	int mod;
	
	while(cin >> x >> n >> m){
		
	cout << potencia(x,n,m)  << endl;

	
}
}

