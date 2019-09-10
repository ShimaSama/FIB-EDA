 #include <iostream>
#include <queue>
using namespace std;


int main(){

	priority_queue <int>num;

	char what;
	int x;
	int aux;

	while (cin >> what){

		 if(what=='S') {
			
			cin >> x;
			num.push(x);

		}

		else if(what=='A'){
		       if(num.empty())cout << "error!" << endl;
  
			else cout << num.top() << endl;
		}
		else if(what=='R'){
			if(num.empty())cout << "error!" << endl;
			else num.pop();
		}
		else if(what=='I'){
	
			cin >> x;
			if(num.empty())cout << "error!" << endl;
			else{
				aux=num.top();
				num.pop();
				aux=aux+x;
				num.push(aux);	
				
			}
		}
		else if(what=='D'){
		
			cin >> x;
			if(num.empty())cout << "error!" << endl;
			else{
				aux=num.top();
				num.pop();
				aux=aux-x;
				num.push(aux);
			}

		}


	}

}




