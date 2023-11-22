#include <iostream>
using namespace std;
int binomialCoefficients(int n,int k) 
{
   if (k==0||k==n)
   return 1;
   return binomialCoefficients(n-1,k-1)+binomialCoefficients(n-1,k);
}
int main()
{
int n,k;
cout<<"enter the value of n:";
cin>>n;
cout<<"enter the value of k:";
cin>>k;
cout<<"The value of C("<<n<<","<<k<<") is"<<binomialCoefficients(n,k);
return 0;
}
