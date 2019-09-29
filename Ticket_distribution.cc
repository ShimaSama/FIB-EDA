#include <iostream>
#include <queue>
#include <string>
using namespace std;

string prim;

class comp{
	public:
		bool operator()(string n1,string n2){
			if(n1.size() == n2.size()){
				
				string s = prim.substr(0,  n1.size());
				if(n1 == s) return false;
				if(n2 == s) return true;
				if( n1 < n2){
					
					if(s>n1 and s<n2) return true;
					else return false;
							
				}		
				else{
					
					if(s<n1 and s>n2) return false;
					else return true;
					
				}
			
			}
			else return n1.size() > n2.size();
			
		}
};

int main(){
	
	 
	
	
	char what;
	string nom;
	
	while (cin >> prim){
		
		priority_queue<string,vector<string>,comp> per; //cola de personas
	
		int n=0; //num tiquets
		
		while(cin >> what and what!='E'){
			
			if (what== 'S'){
				
				cin >> nom;
				
				if(n==0)	per.push(nom);
				
				else {
					cout << nom << endl;
					n--;
				}
			}
			
			else if(what== 'T'){
				
				if(not per.empty()) {
					
					cout << per.top() << endl;
					per.pop();
					
				}
				else n++;
				
			}
		}
		
		cout << n << " ticket(s) left" << endl;
		cout << per.size() <<  " supporter(s) with no ticket" << endl;
		cout << endl;
		

	}
	
}

