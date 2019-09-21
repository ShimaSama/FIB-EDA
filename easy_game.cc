
#include <iostream>
#include <string>
#include <set>

using namespace std;


struct comp{
	bool operator() (const string& a, const string& b) const {
		if (a.size() < b.size()) return true;
		else if (a.size() > b.size()) return false;
		else return (a < b);
	}
};

int main(){
    
 set<string> has;
 set<string, comp> had;
 int game=1;
    
  set<string>::iterator it;
  set<string,comp>::iterator it2;
 
    string n;
    
    while(cin >> n and n!="QUIT"){
        
        if(n=="END"){
            cout << "GAME" << " #" << game << endl;
            game++;
            cout << "HAS:" << endl;
            for(it=has.begin(); it!=has.end(); it++)cout << *(it) << endl;
            cout << endl;
            cout << "HAD:" << endl;
            for(it2=had.begin(); it2!=had.end(); it2++) cout << *(it2) << endl;
            cout << endl;
            for(it=has.begin(); it!=has.end(); it++) has.erase(*(it));
            for(it2=had.begin(); it2!=had.end(); it2++) had.erase(*(it2));
            
        }
        else{it=has.find(n);
         if(it==has.end()){
         
            has.insert(n);
            had.erase(n);
            
        }
        else  {
           
           has.erase(n);
           had.insert(n);
            
        }
        
        }
        
        
    }
    cout << "GAME" << " #" << game << endl;
        
            cout << "HAS:" << endl;
            for(it=has.begin(); it!=has.end(); it++)cout << *(it) << endl;
            cout << endl;
            cout << "HAD:" << endl;
            for(it2=had.begin(); it2!=had.end(); it2++) cout << *(it2) << endl;
           
    
        
        
    
    
}
