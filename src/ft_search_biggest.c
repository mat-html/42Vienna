#include "../include/f.h"

void	**ft_search_biggest(char **map, int row, int col)
{
	int dp[row][col];
	int i;
	int j;

	i = 0;
	j = 0;

	max_sqr max;
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
				if(dp[i][j] > max[0].size)
				{
					max[0].size = dp[i][j];
					max[0].i = i;-
					max[0].j = j;
				}
			}
			else
			{
				dp[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}
