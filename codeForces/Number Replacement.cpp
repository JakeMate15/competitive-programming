#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	while(a--)
	{
		int b;
		cin>>b;
		int c[b];
		for(int i=0;i<b;i++)
			cin>>c[i];
		string d;
		cout<<endl;
		cin>>d;
		int sum=0;
		for(int i=0;i<b;i++)
		{
			for(int j=0;j<b;j++)
			{
				if(c[i]==c[j]&&d[i]!=d[j])sum++;		
			}
		}
		if(sum)cout<<"no";
		else cout<<"yes";
	}	
return 0;
}