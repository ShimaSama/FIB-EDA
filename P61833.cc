#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<int> > Matrix;

Matrix mult(const Matrix &a, const Matrix &b, int m){
	
	Matrix aux(2,vector<int> (2));
	
    aux[0][0] = ((a[0][0]%m*b[0][0])%m + (a[0][1]%m*b[1][0]))%m;
    aux[0][1] = ((a[0][0]%m*b[0][1])%m + (a[0][1]%m*b[1][1]))%m;
    aux[1][0] = ((a[1][0]%m*b[0][0])%m + (a[1][1]%m*b[1][0]))%m;
    aux[1][1] = ((a[1][0]%m*b[0][1])%m + (a[1][1]%m*b[1][1]))%m;
	
	return aux;
}

int main(){
	
	int n,mt;
	Matrix m(2,vector<int> (2));
	
	while( cin >> m[0][0]){
		
		cin >> m[0][1] >> m[1][0] >> m[1][1] >> n >> mt;
				Matrix id(2,vector<int> (2))  ;
				id[0][0] = id[1][1] = 1; //matriu identitat
				id[1][0] = id[0][1] = 0;
		
			if( n==0){
				
				m[0][0] = m[1][1] = 1; //matriu identitat
				m[1][0] = m[0][1] = 0;
				
			}
			
			else{
			
			
				while(n>0){
					if(n%2 == 1){
					//	Matrix aux;
						id=mult(m,id,mt);
						
					}
					
					    //Matrix aux= m;
						 m=mult(m,m,mt);
						n=n/2;
					}
				
				
			}
		
		
		//print
		
		cout << id[0][0] << ' ' << id[0][1] << endl; 
		cout << id[1][0] << ' ' << id[1][1] << endl;
		cout << "----------" << endl;		
		
	}
	
	
}
