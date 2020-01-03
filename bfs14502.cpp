#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 8

int N, M;
int result_count = 0;
int arr[MAX][MAX];
int arr_copy[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector <pair<int, int> > v;

void BFS() {
	queue <pair <int, int> > q;
	for (int i = 0; i < v.size(); i++){
		 q.push(make_pair(v[i].first, v[i].second));
    }
    
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) 
				continue;
			if (arr_copy[nx][ny] == 0) {
				arr_copy[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int size = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr_copy[i][j] == 0) 
				size++;

	result_count = max(size, result_count);
}

void wall(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++)
				arr_copy[i][j] = arr[i][j];
		}
			
		BFS();
		return ;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}


int main() {

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) 
				v.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}	
		}
	}

	cout << result_count;
	return 0;
}
