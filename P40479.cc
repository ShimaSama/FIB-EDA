#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char > > Matrix;

void DFS(Matrix& g, int i, int j,char c){
	
		
		if(g[i][j]=='.' ){
			
			g[i][j]=c;
			DFS(g,i+1,j,c);
			DFS(g,i,j+1,c);
			DFS(g,i-1,j,c);
			DFS(g,i,j-1,c);
			
		} 
	
	
}

int main(){
	
	
	int n,m;
	
	while (cin >> n >> m){
		
			Matrix g (n,vector<char>(m));
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				
				cin >> g[i][j];
				
			}
			
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				
				if(g[i][j]!='#' and g[i][j]!='.') {
					
					char c=g[i][j];
					DFS(g,i+1,j,c);
					DFS(g,i,j+1,c);
					DFS(g,i-1,j,c);
					DFS(g,i,j-1,c);
				}
				
			}
			
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				
			cout << g[i][j];
				
			}
			cout << endl;
			
		}
		cout << endl;
		
		
		
	}
	
	
	
}
