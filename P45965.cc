#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v, int n, int t, int sum, int m){

        if(t<n){
                int aux=t+1;
		if(t<(n-(m-sum))){
			v[t]=0;
        	        print(v,n,aux,sum,m);
		}
		if(sum<m){
             		v[t]=1;
			sum++;
      			print(v,n,aux,sum,m);
		}
        }
        else{

                cout << v[0];
                for(int i=1; i<n; i++){

                        cout <<" " <<  v[i];

                }
                cout << endl;
        }
}


int main(){

        int n,m;

        cin >> n >> m;

        vector<int> v(n);

	int sum=0;

        print(v,n,0,sum,m);


}
 
