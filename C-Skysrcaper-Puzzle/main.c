/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:46:11 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/02 17:14:29 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	solve(int arr[4][4]);
void	print_criteria(int arr[4][4]);


void	initialize(char *str, int *attr, int arr[4][4]) //attr'de 3 tane integerlik bir array, 1. 2. cli argumaninda kacinci charda oldugumuz, 2.column, 3.row
{
	if (attr[1] == 4)
	{
		attr[1] = 0;
		attr[2] += 1;
	}
	arr[attr[2]][attr[1]] = str[attr[0]] - 48; // convert char to int by substracting 48 from chars integer value (ASCII value)
	attr[1]++;
	attr[0]++; //ilerlemesi icin
}

int	input_to_arr(char *str, int *attr, int arr[4][4])
{
	while (str[attr[0]] != '\0')
	{
		if (str[attr[0]] >= '1' && str[attr[0]] <= '4') //input check // 1,2,3,4
			initialize(str, attr, arr);
		else if (str[attr[0]] == ' ') // check spaces
			++attr[0];
		else
		{
			write(1, "Error", 5);
			return (1);
		}
	}

	if (attr[0] >= 32)
	{
		write(1, "Error", 5);
		return (1);
	}
	return (0);
}

// i j z
int	main(int argc, char **argv)
{
	int	i;
	int	arr[4][4]; //inputlarimi tutatcagim bir 4x4 matrix, 1.row -> coluplar icin, 2.row -> coldownlar icin, 3. -> rowleft ..., kac tan bina goruldu bilgileri
	int	attr[3]; //buffer 3 tane integer deger tutan
	
	if (argc == 2)
	{
		i = -1;


		while (i++ < 3) // buffer = {0,0,0}
			attr[i] = 0; 


		arr[3][3] = -1;

	
		if (input_to_arr(argv[1], attr, arr) == 1) // function call and condition check
			return (0);



		if (arr[3][3] == -1) // hala -1 olamaz bir sorun var
		{
			write(1, "Error", 5);
			return (0);
		}
			
		
		solve(arr);
	}
	else
		write(1, "Error", 5);
	return (0);
}
