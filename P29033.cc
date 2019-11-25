#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int > > Graph;

bool DFS_res(int x, vector<bool>& visited, const Graph& g, vector<bool>& color){
	
	for(int i=0; i<g[x].size();i++){
	
		int t=g[x][i];
	
		if(not visited[t]){
		
			visited[t]=true;
		
			color[t]=!color[x];
		
	
			if(not DFS_res(t,visited,g,color)) return false;
	
	
		}

		else if(color[t]==color[x]) return false;
	
		
	}
	return true;	
	
}


int main(){
	
	
	int n, m;
	int x,y;
	
	
	
	while(cin >> n >> m){ //ponemos elementos
		
		Graph g (n, vector<int> (0,0));
		
		for(int i=0; i<m; i++){
	
			cin >> x >> y;
		
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
	vector<bool> visited(n,false);
	vector<bool> color(n,false);
	
	bool si= true;
	
	for(int i=0; i<n and si; i++){
		
		if(not visited[i]){
			
			bool color_actual=color[i];
			
			visited[i]=true;
			
			 si=DFS_res(i,visited,g,color);
			
			
		}
		
	}
	if(si )cout << "yes" << endl;
	else cout << "no" << endl; 	
		
		
		
		
		
	}
}




