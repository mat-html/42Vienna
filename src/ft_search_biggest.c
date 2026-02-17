int	**ft_search_biggest(char **map, int row, int col)
{
	int dp[row][col];
	int max_size;
	int i;
	int j;

	i = 0;
	j = 0;
	max_size = 0;
	while (i < row)
	{
		while (j < col)
		{
			if(dp[i][j] == 1)
			{
				if(i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				}
			}
			max_size = max(max_size, dp[i][j]);
			j++;
		}
		i++;
	}
}
