#include <iostream>
#include <math.h>  
using namespace std;

int blabla(int l, int ri,double m, double f, double r){
	
	if(l>ri) return l;
	
	else{
		
		int mid= (ri+l)/2;
		double ojisan = mid*f +m; //cada dia +f
		double ginko = pow(r,mid)*m;
		if(ojisan<ginko) return blabla(l,mid-1,m,f,r);
		else if(ginko==ojisan) return mid;
		else return blabla(mid+1, ri,m,f,r);
		
	}

	
	
}

int main(){
	
	double m,f,r;
	while( cin >> m >> f >> r){
		
		r= r/100 + 1; 
		
		cout << blabla(1,10000000,m,f,r) << endl; 
		
		
		
	}
	
	
}
