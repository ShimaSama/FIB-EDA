#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(){
    
        string line;
        while(getline(cin,line)){
                                //leer hasta el enter
                istringstream in(line);
                int n;
                set<int> se;
                while(in >> n) se.insert(n); //pasar del string a int y ponerlo en set
                
                set<int>::iterator it = se.begin();
                int total=0;
                int bef;
                if(not se.empty()){
                        ++total;
                        bef = *it;
                        ++it;
                }
                for(;it!=se.end();it++){
                    
                        if((bef%2==0 and *it%2!=0) or (bef%2!=0 and *it%2==0) and bef<*it) ++total;
                        bef=*it;
                    
            
                    
                }
                cout << total << endl;
        }
}

