#include <stdio.h>
#include <stdbool.h>
#define N 75

int h, w;

int dir[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int minLen = 20;

void dfs(
	char maze[][N + 2], bool visited[][N + 2], 
	int prevDir, int pathLen,
	int r1, int c1, int r2, int c2
)
{
	visited[r1][c1] = true;
	
	// 到达终点
	if(r1 == r2 && c1 == c2)
	{
		visited[r1][c1] = false;
		if(pathLen < minLen)
		{
			minLen = pathLen;
		}
		return;
	}
		
	for(int i = 0; i < 4; i++)
	{
		int newRow = r1 + dir[i][0];
		int newCol = c1 + dir[i][1];
		
		if(newRow >= 0 && newRow <= h + 1
			&& newCol >= 0 && newCol <= w + 1
			&& (maze[newRow][newCol] == ' ' || (newRow == r2 && newCol == c2))
			&& !visited[newRow][newCol]
			&& pathLen <= 10)
		{
			if(prevDir != i)
			{
				dfs(maze, visited, i, pathLen + 1, newRow, newCol, r2, c2);
			}
			else {
				dfs(maze, visited, i, pathLen, newRow, newCol, r2, c2);
			}
		}
	}
	visited[r1][c1] = false;
}

int main(int argc, char *argv[])
{
	scanf("%d%d", &w, &h);
	char maze[N + 2][N + 2] = {0};
	bool visited[N + 2][N + 2] = {false};
	for(int i = 0; i < h + 2; i++)
	{
		for(int j = 0; j < w + 2; j++)
		{
			maze[i][j] = ' ';
		}
	}
	getchar();
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			scanf("%c", &maze[i][j]);
		}
		getchar();
	}
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		
		dfs(maze, visited, -1, 0, y1, x1, y2, x2);
		
		if(minLen <= 10)
		{
			printf("%d\n", minLen);
		}
		else printf("impossible\n");
		
		minLen = 20;
	}
	return 0;
}