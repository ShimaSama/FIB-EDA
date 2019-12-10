#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> T;
vector<bool> mc;
vector<bool> md1;
vector<bool> md2;

int diag1(int i, int j){

	return n-j-1+i;
}
int diag2(int i, int j){
	
	return i+j;

}
void recursiu(int i,int& tina){
	
	if(i==n) tina++;
	else{
		
		for(int j=0; j<n; ++j){
			
			if(not mc[j] and not md1[diag1(i,j)] and not md2[diag2(i,j)]){

				T[i] = j;
				mc[j] = true;
				md1[diag1(i,j)] = true;
				md2[diag2(i,j)] = true;
				recursiu(i+1,tina);
				mc[j] = false;
				md1[diag1(i,j)] = false;
				md2[diag2(i,j)] = false; 
			}
		}		
	}
}

int main(){


	cin >> n;
	T = vector<int>(n);
	mc = vector<bool> (n,false);
	md1 = vector<bool> (2*n-1, false);
	md2 = vector<bool> (2*n-1, false);
	int tina =0;
	recursiu(0,tina);
	cout << tina << endl;
	


}
