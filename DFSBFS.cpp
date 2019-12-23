#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

bool check[1001];

void orderInit(int n,vector<int> v[])
{
	for(int index = 1 ; index <= n ; ++index)
	{
		sort(v[index].begin() , v[index].end());	
	}
	
	return ;
}

void dfs(vector<int> v[] , int start_node)
{
	cout << start_node << " ";
	check[start_node] = true;
	
	for(int index = 0 ; index < v[start_node].size(); ++index)
	{
		if(check[v[start_node][index]] != true)
		{
			dfs(v, v[start_node][index]);
		}
	}
	
	return ;
}

void bfs(vector<int> v[] , int start_node)
{
	queue<int> q;
	q.push(start_node);
	check[start_node] = true;
	
	while(!q.empty())
	{
		int node = q.front();
		cout << node << " ";
		q.pop();		
		
		for(int index = 0 ; index < v[node].size() ; ++index)
		{
			if(check[v[node][index]] != true)
			{
				check[v[node][index]] = true;
				q.push(v[node][index]);	
			}
		}
	}
	
	return ;	
}

int main()
{
	int n,edge,start_node;
	cin >> n >> edge >> start_node;
	vector<int> v[1001];
	
	memset(check, false , sizeof(check));
	
	for(int index = 0 ; index < edge ; ++index)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	orderInit(n,v);
	
	dfs(v,start_node);
	
	memset(check, false , sizeof(check));
	cout << '\n';
	
	bfs(v,start_node);

	return 0;
}
