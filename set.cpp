#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s; // key값이 중복이 안되고 [] 로접근안된다. 
	int i;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	
	cout <<s.size() << '\n'; // 3 
	cout << *s.find(2) << '\n'; // 만약 없다면 0을 반환한다.  // 2
	s.erase(s.find(2)); // 2 지워졌음. 
		
	set<int>::iterator iter;
	
	cout << "----------------------" << '\n';
	for(iter = s.begin() ; iter != s.end(); ++iter){
		cout << *iter << '\n';		
	}
	
	s.clear();
	cout << s.size() << '\n';
	
	if(s.empty()){
		cout<<"비어있습니다" <<'\n';
	}

	return 0;
 } 
