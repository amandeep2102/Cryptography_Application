#include<bits/stdc++.h>
using namespace std;

class RSA{
    int n1,n2;

    public: 
    //prime numbers for the main stuff
    void getprimes( int a , int b){
        n1 = a;
        n2 = b;
    }

    //phi fucntion value
    int phi(){
        return (n1-1)*(n2-1);
    }

    //passing two integers in the function to declare the public keys
    void publickeys(int *pkey1, int *pkey2){
        *pkey1 = n1*n2;
        *pkey2 = (phi()/2)-1;
    }

    void privatekeys(int *pkey1, int *pkey2){
        

    }
};


int main(){
    long long int prime1,prime2;
    cout<<"Enter two prime numbers: ";
    cin>>prime1;
    cin>>prime2;

    RSA rsa;
    int pblc1,pblc2;

    rsa.getprimes(prime1, prime2);
    cout<<rsa.phi()<<endl;
    rsa.publickeys(&pblc1, &pblc2);
    cout<<pblc1<<endl;
    cout<<pblc2<<endl;
    

}