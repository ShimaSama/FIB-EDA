#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v, int n, int t, vector<bool> b){
	
        if(t<n){
		int aux=t+1;
		for(int i=1; i<=n; i++){
			if(b[i-1]==false){

				b[i-1]=true;
                		v[t]=i;
                		print(v,n,aux,b);
				b[i-1]=false;
			}
		}
        }
        else{

                cout << '(' <<  v[0];
                for(int i=1; i<n; i++){

                        cout <<"," <<  v[i];

                }
                cout << ')' <<  endl;
        }
}


int main(){

        int n,m;

        cin >> n;

        vector<int> v(n);
	vector<bool> b(n,false);

        print(v,n,0,b);


}

