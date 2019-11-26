#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef vector<vector<char> > Matrix;

int BFS( Matrix& map, int x2, int y2, int n, int m){
	int max=-1;
	
	queue<pair<pair<int,int >,int> > q;
	q.push(make_pair(make_pair(x2,y2),0));


	while(!q.empty()){
		
		int ixi[]={ 1, -1, 0, 0};
		int wai[]={0,0,1,-1};
		
		
		int x2=q.front().first.first;
		int y2=q.front().first.second;
		int dist2=q.front().second;
			
			
		q.pop();
		map[x2][y2]='X'; //visited
		
		for(int i=0; i<4; i++){
			
			
			int x=x2+ixi[i];
			int y=y2+wai[i];
		
			if(x>=0 and x<n and y>=0 and y<m){
				
				 if(map[x][y]!='X' ){
				 	int dist=dist2+1;
					if(map[x][y]=='t'){
						
						if (dist>max) max=dist; 
						
					}
					map[x][y]='X';
					
					q.push(make_pair(make_pair(x,y),dist));
				}	
			}
		}		
	}	

	return max;
}


int main(){
	
	
	int n,m;
	
	cin >> n >> m;
	
	Matrix map(n,vector<char>(m));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
		} 
	
	}
	
	int pos1,pos2;
	cin >> pos1 >> pos2;
	

	int res=BFS(map,pos1-1,pos2-1,n,m) ;
	if(res==-1)	cout <<"no treasure can be reached" << endl;
	else cout<< "maximum distance: " << res<< endl;	
	
	
	
	
}
