#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s; // key���� �ߺ��� �ȵǰ� [] �����پȵȴ�. 
	int i;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	
	cout <<s.size() << '\n'; // 3 
	cout << *s.find(2) << '\n'; // ���� ���ٸ� 0�� ��ȯ�Ѵ�.  // 2
	s.erase(s.find(2)); // 2 ��������. 
		
	set<int>::iterator iter;
	
	cout << "----------------------" << '\n';
	for(iter = s.begin() ; iter != s.end(); ++iter){
		cout << *iter << '\n';		
	}
	
	s.clear();
	cout << s.size() << '\n';
	
	if(s.empty()){
		cout<<"����ֽ��ϴ�" <<'\n';
	}

	return 0;
 } 
