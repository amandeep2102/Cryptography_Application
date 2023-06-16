//#include<bits/stdc++.h>
#include<iostream>
#include<ctime>
#include<sstream>
using namespace std;

class RSA
{
    long long int n1, n2, n12;
    long long int e=2;

public:
    long long int phi=-1;
    // prime numbers for the main stuff
    void getprimes(long long int a, long long int b)
    {
        n1 = a;
        n2 = b;
        n12 = n1*n2;
        // phi function value
        phi = (n1 - 1) * (n2 - 1);
    }

    long long int gcd(long long int a, long long int b){
        long long int c;
        while(true){
            c = a%b;
            if (c==0)
                return b;
            a=b;
            b=c;
        }
    }

    // passing two integers in the function to declare the public keys
    void publickeys(long long int *pkey1, long long int *pkey2)
    {
        *pkey2 = n1 * n2;
        while(e<phi){
            if (gcd(e,phi)==1)
                break;
            else
                e++;
        }
        *pkey1 = e;
    }

    void privatekeys(long long int *pkey1)
    {
        long long int d=2;
        while (true) {
            if ((d * e) % phi == 1)
                break;
            d++;
        }
        *pkey1 = d;
    }

    long long int modular(long long int base, long long int exp, long long int mod)
    {
        long long int x = 1;
        while(exp>0){
            if (exp & 1)
                x = (x * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return x;
    }

    string encrypt(char mes, long long int pkey1, long long int pkey2){
        long long int enc;
        string str;
        int m = (int) mes;
        enc = modular(m, pkey1, pkey2);
        str = to_string(enc);
        str = make_five_bit_string(str);
        return str;
    }

    char decrypt(string enc, long long int prvt){
        stringstream ss;
        ss << enc;
        long long int encrypt;
        ss >> encrypt;
//        cout<<" for decryption inside decryption func "<<encrypt<<endl;
        long long int dec;
        dec = modular(encrypt, prvt, n12);
        char decrypted;
        decrypted = char(dec);
        return decrypted;
    }

    string make_five_bit_string(string str){
        int length = str.length();
        string in((5-length), '0');
//        cout<<"string in " << in<<endl;
        str.insert(0, in);
//        cout<<"str "<<str<<endl;
        return str;
    }
};

int main()
{
    srand(time(0));
    long long int prime_array[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    long long int prime1, prime2;
    prime1 = prime_array[rand()%25];
    prime2 = prime_array[rand()%25];
//    prime1 = 61;
//    prime2 = 61;
    cout << "Enter two prime numbers: ";
    cout<< "prime number 1: "<<prime1;
    cout<< "   prime number 2: "<< prime2<<endl;

    RSA rsa{};
    long long int pblc1, pblc2, prvt;

    rsa.getprimes(prime1, prime2);
    cout << "phi value " << rsa.phi << endl;
    rsa.publickeys(&pblc1, &pblc2);
    cout << "public key1 " << pblc1 << endl;
    cout << "public key2 " << pblc2 << endl;

    rsa.privatekeys(&prvt);
    cout<<"private key "<< prvt<< endl;

    string message = "amandeep";
    string encrypted;
    string decrypted;
    char d;
    for (int i = 0; i < message.length(); ++i) {
        string en = rsa.encrypt(message[i], pblc1, pblc2);
        encrypted.append(en);
    }
    cout<<"encrypted "<< encrypted <<endl;

    for (int i = 0; i < encrypted.length(); i=i+5) {
        string str = encrypted.substr(i, 5);
        cout<<"string for encryption " << str<<endl;
        d = rsa.decrypt(encrypted.substr(i, 5), prvt);
        decrypted.push_back(d);
    }
    cout<<"decrypted "<<decrypted<<endl;


}