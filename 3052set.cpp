#include <iostream>
#include <set>

using namespace std;

int main()
{
	int a[10] = {0,};
	int i ;
	set<int> s;
	
	for( i = 0 ; i < 10 ; ++i){
		cin >> a[i] ;
		s.insert(a[i]%42);
	}
	
	cout << s.size() << '\n';
	
	return 0;
}
