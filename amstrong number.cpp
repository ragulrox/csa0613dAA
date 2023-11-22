#include <iostream>
using namespace std;
int main()
{
    int num,Num,rem,res=0;
    cout << "Enter a integer:";
    cin>>num;
    Num = num;
    while(Num!=0)
	{
        rem=Num%10;
        res+=rem*rem*rem;
        Num/=10;
    }
    if (res==num)
        cout<<"true";
    else
        cout<<"false";

    return 0;
}
