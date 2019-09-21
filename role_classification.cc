#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct player {
	int elo;
	string user;
};

bool comp(player &p1, player &p2){
    
  if(p1.elo==p2.elo) return p1.user<p2.user;
    return p1.elo>p2.elo;

}


int main(){
    
        string n;
        map<string, pair<bool, int> > m;
        map<string, pair<bool, int>>::iterator it;
        map<string, pair<bool, int>>::iterator it2;
        string username;
        string loser;
        
        while(cin >> n){
            
                if(n=="LOGIN"){
                    
                        cin >> username;
                        
                        it=m.find(username);
                        if(it==m.end()) m[username].second = 1200;
                        m[username].first=true;
                       
                }
                else if(n=="PLAY"){
                    
                    cin >> username >> loser;
                 
                    it= m.find(username);
                    it2 = m.find(loser);
                    if(it == m.end() or it2 == m.end() or m[username].first==false or m[loser].first==false) cout <<"player(s) not connected" << endl;
                        
                    else{  
                        m[username].second+=10;
                           if(m[loser].second>1200) m[loser].second-= 10;
                    }
                    
                    
                }
                else if(n=="LOGOUT"){
                    
                    cin >> username;
                     it= m.find(username);
                     if(it!=m.end()) {
                         
                            m[username].first=false;
                         
                     }
                }
                else if(n=="GET_ELO"){
                    
                    cin >> username;
                    it= m.find(username);
                    
                    
                    if(it!=m.end()) cout << username << " " << m[username].second << endl;
                   
                }
            
            }
          
            
    
        cout << endl;
            cout << "RANKING" << endl;
            
            vector<player> v(m.size());
            it=m.begin();
            for(int i=0; i<v.size(); i++){
                
               v[i].user= (*it).first;
               v[i].elo = it->second.second;
                
             it++;   
            }
            
            sort(v.begin(), v.end(), comp);
            
            for(int i=0; i<v.size(); i++){
                
                cout << v[i].user << " " << v[i].elo << endl;
                
            }
            
}
