#include <iostream>
#include <vector>
using namespace std;

int fixed(int x, const vector<int>& v, int left, int right){

	//left = 0, right=n-1
  
	if(left>right) return -1;
	int m=(left+right)/2;
	if((x+v[m])>= (m+1)){
		 int i= fixed(x,v,left,m-1);
		if(i!= -1) return i;
		else{
			if( (v[m] +x)==(m+1)) return (m+1);
			return -1;
		}
	}
	return fixed(x,v,m+1,right);
}




int main(){

	int n;
	int cont=1;
	while(cin >> n){
	
		vector<int> v(n);

		for(int i=0;i<n; i++) cin >> v[i];

		int n1;
		cin >> n1;
	
		cout << "Sequence #" << cont << endl;
		for(int i=0; i<n1; i++) {
		
			int x;
			cin >> x;
		
			int yes=fixed(x,v,0,n-1);		
		
			if(yes==-1) cout << "no fixed point for " << x << endl;
 	
			else cout << "fixed point for " << x << ": " << yes << endl; 	
		}
		cout << endl;
		cont++;
	}
}



