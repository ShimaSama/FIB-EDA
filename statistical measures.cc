#include <iostream>
#include <map>
#include <string>
using namespace std;




int main(){
    
 map<int,int> s;
 string what;
 int n;
 double total= 0.0;
 double ave;
 int aux;
 int size=0;
 bool yes;
  map<int,int>::iterator it;
   cout.setf(ios::fixed);
    cout.precision(4);
 
 while(cin >> what){
     
     if(what == "number"){
        
        cin >> n;
        total= total + n; 
        it=s.find(n);
       if(it==s.end()) s.insert(pair<int,int>(n,1));
       else{
           it->second= it->second +1;
           
       }
    
        yes = false;
        size++;
    }
    else if (what=="delete") {
        if(s.empty()) yes=true;
        
        else{
            
            cout.setf(ios::fixed);
            cout.precision(4);
            
            yes=false;
            it=s.begin();
            aux= it->first;
            if(it->second==1) s.erase(s.begin());
            else it->second= it->second-1;
            if(s.empty()) yes = true;
            total= total - aux;
            size--;
            
        }
         
     }
     if(yes==true) cout << "no elements" << endl;
     else {
         it=s.end();
         it--;
        
         ave= total/size;
         cout << "minimum: " << (s.begin())->first  << ", maximum: " << it->first << ", average: " << ave << endl;
         
     }
        
        
    }
     
 }
    
    
    
    
