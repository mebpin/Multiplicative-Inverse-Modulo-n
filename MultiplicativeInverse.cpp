//Calculating Multiplicative Inverse of a number in given modulo using Extended Euclidean Algorithm (recursive) 
// Idea: in  "ax+by=gcd(a,b)" compute the value of  y in mod b  which is the inverse of a in modulo b.
//code by Bipin Timalsina
#include<iostream>
using namespace std;
class InverseModulo{
private:
	int mod(int a, int b) {
  		int	c = a % b;
  		return (c < 0) ? c + b : c;
	}
	
public:
	int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
	}
	int computeInverse(int a, int b){
		int n=a;
		int old_x = 1, x = 0;
	    int old_y = 0, y = 1;
	    int q, r;
	    while (b!=0){
	        q = a / b;//quotient 
	        r = a % b;//remainder
	        int temp = x;
	        x = old_x - q * x;
	        old_x = temp;
	        temp = y;
	        y = old_y - q * y;
	        old_y = temp;
	        a = b;
	        b = r;
    	}
    	int inverse = mod(old_y,n);
    	return  inverse;
	}
	
};

int main(){
	InverseModulo obj;
	int a,n,i;
	cout<<"		====	Multipicative Inverse of a number in given modulo  ====";
	cout<<"\nEnter a number of which you want to find inverse\n";
	cin>>a;
	cout<<"\nEnter the modulo in which you want to find inverse of "<<a <<"\n";
	cin>>n;
	cout<<"------------RESULT-------------\n";
	if(obj.gcd(a,n)==1){
		i = obj.computeInverse(n,a);
		cout<<"Inverse of " <<a <<" is "<<i <<" in mod "<<n <<endl;
	}else{
		cout<<"Inverse of " <<a <<" does not exist in mod "<<n <<endl;	
	}
	
	return 0;
}
