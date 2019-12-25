#include <iostream>

using namespace std;

int main(){
	
	char a[100];
	char temp1[100];
	char temp2[100];
	
	cin >> temp1 >> temp2 ;
	
	// 11718  
	for (int index = 0; index < 100; index++)
	{ 
		cin.getline(a, 101);  
		cout << a << endl;
	}
	
	// 11719 
	string str;

	for(int index = 0 ; index < 100 ; ++index)
	{
		getline(cin,str);
		cout << str << '\n';
	}

	// 11720  
	int n;
	string number;
	int sum = 0;
	
	cin >> n >> number;
	 
	for(int index = 0 ; index < n ; ++index)
	{
		sum += number[index] - '0';
	}
	
	cout << sum;
	
	// 11721 
	string str;
	cin >> str;
	
	for(int index = 0 ; index < str.size() ; ++index)
	{
		if(index%10 == 0 && index != 0)
		{
			cout << '\n';
		}
		cout << str[index];
	}
	
	return 0;
}
