#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matrix;

int DFS_rec ( Matrix& m, int a1, int a2, int ti, int na){
	
	if(a1<0 or a2<0 or a1>=ti or a2>=na) return 0;

	if(m[a1][a2]=='t'){
		m[a1][a2]='y';
		 return 1 +  (DFS_rec(m,a1+1,a2,ti,na) 
			+ DFS_rec(m,a1,a2+1,ti,na) 
			+ DFS_rec(m,a1-1,a2,ti,na)
			+ DFS_rec(m,a1,a2-1,ti,na));
		
;
	}
	else if(m[a1][a2]=='X') return 0;
	else if(m[a1][a2]=='.') {
		
		m[a1][a2]='y';
		return (DFS_rec(m,a1+1,a2,ti,na) 
			+ DFS_rec(m,a1,a2+1,ti,na) 
			+ DFS_rec(m,a1-1,a2,ti,na)
			+ DFS_rec(m,a1,a2-1,ti,na));
		

	} 
	else return 0;


}

int main(){

	int n,m;

	cin >> n>>m;
	
	Matrix map(n,vector<char>(m));	

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		} 
	
	}

	int pos1,pos2;
	cin >> pos1 >> pos2;	
	cout << (DFS_rec(map,pos1-1,pos2-1,n,m)) << endl;
	

}
