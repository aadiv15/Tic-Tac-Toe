int minmax(char grid[3][3], int d, bool im)
{
	int score = eval(grid);
	if(score == 10)
		return 10;
	if(score == -10)
		return -10;

	if(gridnotfull(grid)==0)
		return 0;

	if(im)
	{
		int b= -100000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(grid[i][j]=='_')
				{
					grid[i][j]=p;
					b=max(b,minmax(grid,d+1, !im));
					grid[i][j]='_';
				}				
			}
		}
		return b;
	}
	else
	{
		int b= 100000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(grid[i][j]=='_')
				{
					grid[i][j]=o;
					b=min(b,minmax(grid,d+1, !im));
					grid[i][j]='_';
				}				
			}
		}
		return b;	
	}
}