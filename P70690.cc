#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matrix;

bool DFS_rec ( Matrix& m, int a1, int a2, int ti, int na){
	
	if(a1<0 or a2<0 or a1>=ti or a2>=na) return false;

	if(m[a1][a2]=='t') return true;
	else if(m[a1][a2]=='X') return false;
	else if(m[a1][a2]=='.') {
		
		m[a1][a2]='y';
		return (DFS_rec(m,a1+1,a2,ti,na) 
			or DFS_rec(m,a1,a2+1,ti,na) 
			or DFS_rec(m,a1-1,a2,ti,na)
			or DFS_rec(m,a1,a2-1,ti,na));
		

	} 
	else return false;


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
	if(DFS_rec(map,pos1-1,pos2-1,n,m)) cout << "yes" << endl;
	else cout << "no" << endl;

}
