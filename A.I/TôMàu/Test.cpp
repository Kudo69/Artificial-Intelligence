#include<iostream>
using namespace std;

void I_Want_To_Be_A_Coder(long long n)
{
	for (long long i=1; i<=n; i++)
		cout<<i<<". "<<"I'm Sory!"<<endl;
}

int main()
{
	long long n;
	cout<<"Enter the number of your say sory: ";
	cin>>n;
	I_Want_To_Be_A_Coder(n);
	return 0;
}