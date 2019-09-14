#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(){

	map <string,int> bag;

	string what;
	string wor;
	map<string,int>::iterator it;
	while(cin >> what){

		if(what=="store"){
           
			cin >> wor;
			it = bag.find(wor);
			if (it==bag.end()) 	bag.insert(pair<string,int>(wor,1));
			else it->second +=1;

					
		}
		else if(what=="delete"){
            

			cin >> wor;
			it= bag.find(wor);
			if( it!= bag.end()){
                


				if(it->second==1) bag.erase(wor);
				else it->second=it->second-1;

			}


		}
		else if(what=="minimum?"){
            

			if (bag.empty()) cout << "indefinite minimum" << endl;
			else {

				 it=bag.begin();
				cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
               

			}
		}
		else if(what=="maximum?"){

			if (bag.empty()) cout << "indefinite maximum" << endl;
			else {
                
                it=bag.end();
				it--;
                
				
	
				cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;


			}
		}


}


	


}
