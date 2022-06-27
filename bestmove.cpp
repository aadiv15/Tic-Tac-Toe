_move bestmove(char grid[3][3])
{
	int bestval= -100000000;
	_move bestMove;
	bestMove.r = -1;
	bestMove.c = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(grid[i][j]=='_')
			{
				grid[i][j] = p;
				int tmp = minmax(grid , 0 , false);
				grid[i][j]='_';
				if(tmp>bestval)
				{
					bestMove.r=i;
					bestMove.c=j;
					bestval=tmp;
				}
			}
		}
	}
	return bestMove;
}
