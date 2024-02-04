/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:17:55 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/02 17:15:27 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pointers: 8 bytes
// 0: row, 1: column

#include <stdio.h>

void	print_criteria(int arr[4][4]);

void	inc_asign(int grid[4][4], int constant, int roworcolumn, int inc_or_dec) // if "roworcolumn" == o -> row, == 1 -> column, 
{
	int	z;

	if (inc_or_dec == 0)
	{
		z = -1;
		while (++z < 4)
		{
			if (roworcolumn == 0)
				grid[constant][z] = z + 1;
			else
				grid[z][constant] = z + 1;
		}
	}
	else
	{
		z = 4;
		while (--z > -1)
		{
			if (roworcolumn == 0)
				grid[constant][z] = 4 - z;
			else
				grid[z][constant] = 4 - z;
		}
	}
}

void	asign_one(int grid[4][4], int i, int j) // put highest skyscraper to the correct place
{
	
	if (i == 0) //colup
		grid[0][j] = 4;
	else if (i == 1) //coldown
		grid[3][j] = 4;
	else if (i == 2) //rowleft
		grid[j][0] = 4;
	else //i = 3 rowright
		grid[j][3] = 4;
	
}

void	asign(int grid[4][4], int *i, int *j, int arr[4][4])
{
	//int	z;

	//z = -1;
	if (arr[*i][*j] == 1) // if i see only 1 skyscraper
		asign_one(grid, *i, *j);
	else if (*i == 0)  //i see 4 
		inc_asign(grid, *j, 1, 0);
	else if (*i == 1) //i see 4 
		inc_asign(grid, *j, 1, 1);
	else if (*i == 2) //i see 4 
		inc_asign(grid, *j, 0, 0);
	else //i see 4 
		inc_asign(grid, *j, 0, 1);
}

void	init_grid(int arr[4][4], int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == 4 || arr[i][j] == 1) //if i see 4 or 1 skyscraper
			{
				asign(grid, &i, &j, arr); 
			}
			print_criteria(grid);
		}
	}
}

// int	main()
// {
// 	int arr[4][4] = {{1,2,3,3},{3,3,1,2},{1,2,2,2},{4,3,1,2}};
// 	int grid[4][4] = { -1 };
// 	init_grid(arr, grid);
//     print_criteria(grid);
// 	return 0;
// }
