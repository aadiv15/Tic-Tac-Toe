int eval(char grid[3][3])
{
	//row victory
	for (int i = 0; i < 3; i++)
	{
		if(grid[i][0]==grid[i][1] and grid[i][1]==grid[i][2] and grid[i][1]=='X')
			return 10;
		if(grid[i][0]==grid[i][1] and grid[i][1]==grid[i][2] and grid[i][1]=='O')
			return -10;
	}
	//column victory
	for (int i = 0; i < 3; i++)
	{
		if(grid[0][i]==grid[1][i] and grid[1][i]==grid[2][i] and grid[2][i]=='X')
			return 10;
		if(grid[0][i]==grid[1][i] and grid[1][i]==grid[2][i] and grid[2][i]=='O')
			return -10;
	}
	//diagonal victory
	if(grid[0][0]==grid[1][1] and grid[1][1]==grid[2][2] and grid[2][2]=='X')
		return 10;
	if(grid[0][0]==grid[1][1] and grid[1][1]==grid[2][2] and grid[2][2]=='O')
		return -10;
	if(grid[2][0]==grid[1][1] and grid[1][1]==grid[0][2] and grid[2][0]=='X')
		return 10;
	if(grid[2][0]==grid[1][1] and grid[1][1]==grid[0][2] and grid[2][0]=='O')
		return -10;

	return 0;
}