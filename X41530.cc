#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int > > Graph;

//apply dfs on every node
void DFS(int x, vector<bool> & visited, const Graph& g, bool& ci,int ant){
	
	if(visited[x]){
		
		ci=true;
		return;

	}
	visited[x]=true;
	for(int i=0; i<g[x].size(); i++){
	//for (int i: g[i]){	
		if(g[x][i]!=ant){
			
			if(visited[g[x][i]]==false) DFS(g[x][i],visited,g,ci,x);
			
		}

	}
	
}
int num(const Graph& g,int n){
	
	int num=0; //number of trees
	vector<bool> visited(n,false);
	bool ci; //if cycle
	for(int i=0; i < n; i++){
		
		if(visited[i]==false){
			
			ci=false;
			DFS(i,visited,g,ci,i);
			if(ci) return n;
			num++;
		}
	}
	return num;	
	
}

int main(){
	
	int n,m;
	
	while(cin >> n >> m){
		
		if (m==0) cout << n << endl;
		
		else{
			
			Graph g(n, vector<int> (0,0));
			
			int x,y;
			for(int i=0; i<m; i++){ //input
				
				cin >> x >> y;
				g[x].push_back(y);
				g[y].push_back(x);	
				
				
			}
			int number=num(g,n);
			
			if(n-number==m) cout << number << endl;
			else cout << "no" << endl;
		}
	}
}
