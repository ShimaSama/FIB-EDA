#include <iostream>
#include <map>
using namespace std;


int main(){

	int x,y,n;
    
	while(cin >> x >> y >> n){

		map<int,int> m;
        map<int,int>:: iterator it;
        int pos = 1;
        m.insert(pair<int,int>(n,pos));
        
        bool find = false;
		while(n<=100000000 and not find){


			if( n%2==0) n=(n/2) + x;
			else n = 3*n +y;
             ++pos;
              it= m.find(n);
            m.insert(pair<int,int>(n,pos));
           
            
          
            if( it!=m.end() and n<=100000000){
                
                find=true;
               
                cout << pos- (it->second) << endl;
                
            }
	

        
        }
        if(not find) cout << n << endl;

    }
}

