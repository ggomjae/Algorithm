#include <iostream>
#include <queue>
#define MAX 11
using namespace std;
char arr[MAX][MAX];
int n,m;
 
struct NODE {
    int br, bc;
    int rr, rc;
};
 
NODE node;
bool check[MAX][MAX][MAX][MAX];
 
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
 
int solution() {
	
    queue<NODE> q;
    check[node.br][node.bc][node.rr][node.rc] = true;
    int time = 0;
    bool escape = false;
 
    q.push(node);
 
    while(!q.empty()){
 		int cnt = q.size();
 		
        for(int index = 0 ; index < cnt ; ++index){
            
			NODE now = q.front();
            q.pop();
 
            if(arr[now.rr][now.rc] == 'O') { 
				escape = true;
				break; 
			}
 
            for(int d = 0; d < 4; d++) {
                bool out[2] = { false,false };
                int t[2] = {};
                int p[2][2] = { 
					{ now.br, now.bc },
					{ now.rr, now.rc } 
				};
 
                for (int i = 0; i < 2; i++) {
                    while(arr[p[i][0]+dx[d]][p[i][1]+dy[d]] !='#'){
                      
					    t[i]++;
                        p[i][0] = p[i][0] + dx[d];
                        p[i][1] = p[i][1] + dy[d];
                      
					    if (arr[p[i][0]][p[i][1]] == 'O')
							 break;
                    }
                    out[i] = arr[p[i][0]][p[i][1]] == 'O';
                }
 
                if (out[0])
					continue;
                
                if (p[0][0] == p[1][0] && p[0][1] == p[1][1]){
                    if (t[0] > t[1]) 
						p[0][0] -= dx[d], p[0][1] -= dy[d];
                    else 
						p[1][0] -= dx[d], p[1][1] -= dy[d];
                }
                
                if (check[p[0][0]][p[0][1]][p[1][0]][p[1][1]])
					continue;
					
                check[p[0][0]][p[0][1]][p[1][0]][p[1][1]] = true;
                
                NODE next = { p[0][0], p[0][1], p[1][0], p[1][1] };
                q.push(next);
            }
        }
        
		if (escape) 
			break;
        
		time++;
 		
        if (time > 10)
			break;
    }
    
    return escape ? time : -1;
}
 
int main() {
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') {
                node.rr = i;
                node.rc = j;
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'B') {
                node.br = i;
                node.bc = j;
                arr[i][j] = '.';
            }
        }
    }
 
    cout << solution();
 
    return 0;
}
