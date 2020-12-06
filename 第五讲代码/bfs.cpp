#include <iostream>
#include <queue>

#define N 75

typedef struct _Node
{
	int row;
	int col;
	int dir;
	int len;
} Node;

int dir[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int bfs
(
	char maze[][N + 2], int len[][N + 2],
	int w, int h,
	int r1, int c1, int r2, int c2
)
{
	Node s = {r1, c1, -1, 0};
	len[r1][c1] = 0;
	std::queue<Node> q;
	q.push(s);
	while(!q.empty())
	{
		Node f = q.front();
		q.pop();
		if(f.row == r2 && f.col == c2)
		{
			return len[f.row][f.col];
		}
		for(int i = 0; i < 4; i++)
		{
			int newRow = f.row + dir[i][0];
			int newCol = f.col + dir[i][1];
			if(newRow >= 0 && newRow <= h + 1
				&& newCol >= 0 && newCol <= w + 1
				&& (maze[newRow][newCol] == ' ' || (newRow == r2 && newCol == c2))
				&& len[f.row][f.col] <= 10)
				{
					Node n = {newRow, newCol, i, f.len};
					if(n.dir != f.dir)
					{
						n.len++;
					}
					if(n.len <= len[newRow][newCol])
					{
						len[newRow][newCol] = n.len;
						q.push(n);
					}
				}
		}
	}
	return INT_MAX;
}


int main(int argc, char *argv[])
{
	int w, h;
	scanf("%d%d", &w, &h);
	char maze[N + 2][N + 2] = {0};
	int len[N + 2][N + 2] = {INT_MAX};
	for(int i = 0; i < h + 2; i++)
	{
		for(int j = 0; j < w + 2; j++)
		{
			maze[i][j] = ' ';
			len[i][j] = INT_MAX;
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
		
		int minLen = bfs(maze, len, w, h, y1, x1, y2, x2);
		for(int i = 0; i < h + 2; i++)
		{
			for(int j = 0; j < w + 2; j++)
			{
				len[i][j] = INT_MAX;
			}
		}
		if(minLen <= 10)
		{
			printf("%d\n", minLen);
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}