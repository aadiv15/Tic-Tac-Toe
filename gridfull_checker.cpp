bool gridnotfull(char grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(grid[i][j]=='_')
				return 1;
		}
	}
	return 0;
}