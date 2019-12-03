#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(vector<int>& v, int n, int t, vector<bool> b, map<int,string>& form){

        if(t<n){
                int aux=t+1;
                for(int i=0; i<n; i++){
                        if(b[i]==false){

                                b[i]=true;
                                v[t]=i;
                                print(v,n,aux,b,form);
                                b[i]=false;
                        }
                }
        }
        else{

                cout << '(' << form[ v[0]];
                for(int i=1; i<n; i++){

                        cout <<"," << form[v[i]];

                }
                cout << ')' <<  endl;
        }
}


int main(){

        int n,m;

        cin >> n;

        vector<int> v(n);
        vector<bool> b(n,false);
	map<int,string> form;
	string tina;
	for(int i=0; i<n; i++){
		cin >> tina;
		form[i]=tina;
	}

        print(v,n,0,b,form);


}

