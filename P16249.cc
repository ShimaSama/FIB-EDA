#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <list>
using namespace std;

typedef vector<vector<int > > graph;

list<string> topo(graph& g, int n, map<int,string> &noti, map<string,int> &nots){
	
	
	priority_queue <string, vector<string>, greater<string> > queue;
	
	list<string> l;
	
	vector<int> antes(n,0);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<g[i].size(); j++){
			
			antes[g[i][j]]++; //los q dependen de otros
			
			
		}
	}
	map<string, int>::const_iterator it = nots.begin();
	
	
	while(it != nots.end()){
		
		
		if(antes[it->second]==0) queue.push(it->first);
		it++;
	}
		
	
	while(not queue.empty()){
			
		string num= queue.top();
		queue.pop();
		l.push_back(num);
		int numi=nots[num];
		
		for(int i=0; i<g[numi].size(); i++ ){
			
			
			int number= g[numi][i];
			string numbers = noti[number];
			antes[number]--;
			
			
			if(antes[number]==0){
				
				queue.push(numbers);
			}	
		}	
	}
	if(n!= l.size()){
		cout << "NO VALID ORDERING";
		list<string> l;
		return  l; 
	} 
	return l;
	
	
	
}

int main(){
	
	int n,m;
	string x,y;
	
	
	while(cin >> n){
		
		map<string,int> nots;
		map<int,string> noti;
		
		graph g (n, vector<int> (0,0));
		
       
		
		for(int i=0; i<n; i++){
			
			cin >> x;
			nots.insert(make_pair(x,i)); //insert al map
			noti.insert(make_pair(i,x));
		
			
			
			
		}	
		cin >> m;
		
		for(int i=0; i<m;i++){
			
			cin >> x >> y;
		
			g[nots[x]].push_back(nots[y]);
			
			
			
		}
		list<string> l = topo(g, n, noti, nots);
		
		
	
		while(not l.empty()){ //imprimir lista
		
			cout << l.front();
			l.pop_front();
		
		
		}
		cout << endl;
		
		
	}
}
