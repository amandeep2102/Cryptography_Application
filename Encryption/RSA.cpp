#include <bits/stdc++.h>
using namespace std;

class RSA
{
    long long int n1, n2;
    long long int pkey;

public:
    // prime numbers for the main stuff
    void getprimes(long long int a, long long int b)
    {
        n1 = a;
        n2 = b;
    }

    // phi function value
    long long int phi()
    {
        return (n1 - 1) * (n2 - 1);
    }

    // passing two integers in the function to declare the public keys
    void publickeys(long long int *pkey1, long long int *pkey2)
    {
        *pkey1 = n1 * n2;
        *pkey2 = (phi() / 2) - 1;
        pkey = *pkey2;
    }

    void privatekeys(long long int *pkey1)
    {
        for (long long int i = 1;; i++)
        {
            long long int d = (i * phi() + 1);
            if (d % pkey == 0)
            {
                *pkey1 = d*pkey;
                cout << i << endl;
                break;
            }
        }
    }


};

int main()
{
    long long int prime1, prime2;
    cout << "Enter two prime numbers: ";
    cin >> prime1;
    cin >> prime2;

    RSA rsa;
    long long int pblc1, pblc2, prvt;

    rsa.getprimes(prime1, prime2);
    cout << "phi value " << rsa.phi() << endl;
    rsa.publickeys(&pblc1, &pblc2);
    cout << "public key1 " << pblc1 << endl;
    cout << "public key2 " << pblc2 << endl;

    rsa.privatekeys(&prvt);
    cout<<"private key "<< prvt<< endl;
}