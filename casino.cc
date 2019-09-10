#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

	map<string,int> casino;
	string x;
	string what;
	map<string,int>::iterator it;
	
	while(cin >> x and cin >>what){

		it=casino.find(x);
		if(what == "enters"){
				
			if(it!= casino.end()) cout << x << " is already in the casino" << endl;
			else casino.insert(pair<string,int> (x,0));

		}
		else if(what == "leaves"){

			if(it==casino.end()) cout << x << " is not in the casino" << endl;
			else{
				cout << x << " has won " << it->second << endl;
				 casino.erase(it);
			}
		}	
		else {
			
			int money;
			cin >> money;
			if(it == casino.end()) cout << x << " is not in the casino" << endl;
			else{
				
				it->second = it->second + money;
			
			}

		}

	}
	cout << "----------" << endl;
	for(it = casino.begin(); it != casino.end(); ++it) {
		cout << it->first << " is winning " << it->second << endl;
} 
	

}
