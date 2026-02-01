#include "../includes/cube.h"

int	rgb_error(int r, int g, int b, char **nums)
{
	int i;

	i = 0;
	printf("%d\n%d\n%d\n", r, g, b);
	if (r > 255 || r < 0)
		return (1);
	if (g > 255 || g < 0)
		return (1);
	if (b > 255 || b < 0)
		return (1);
	while (i < 3)
	{
		if (nums[0][i] && (nums[0][i] > '9' || nums[0][i] < '0'))
			return (1);
		if (nums[1][i] && (nums[1][i] > '9' || nums[1][i] < '0'))
			return (1);
		if (nums[2][i] && (nums[2][i] > '9' || nums[2][i] < '0'))
			return (1);
		i++;
	}
	return (0);
}

void	error_and_exit(int i, t_data *data)
{
	free_everything(data);
	if (i == INCORRECT_CHAR)
		write(2, "INCORRECT CHAR\n", 15);
	else if (i == MALLOC_ERROR)
		write(2, "MALLOC ERROR\n", 14);
	else if (i == TOO_MANY_PLRS)
		write(2, "WRONG AMOUNT OF PLAYERS\n", 25);
	else if (i == MAP_ERROR)
		write(2, "MAP UNCLOSED\n", 13);
	else if (i == FILE_OPEN_FAILURE)
		write(2, "ERROR WHILE OPENING FILE\n", 25);
	else if (i == WRONG_ARG_NUM)
		write(2, "WRONG NUMBER OF ARGUMENTS\n", 26);
	else if (i == WRONG_EXTENTION)
		write(2, "WRONG EXTENTION\n", 16);
	else if (i == WRONG_TEXTURE)
		write(2, "SAME TEXTURES\n", 16);
	else if (i == WRONG_RGB)
		write(2, "WRONG RGB\n", 11);
	exit(-1);
}

int	rgb_connect_and_errors(char **nums, t_data *data)
{
	int r;
	int g;
	int b;
	int result;

	r = ft_atoi(nums[0]);
	g = ft_atoi(nums[1]);
	b = ft_atoi(nums[2]);
	if (rgb_error(r, g, b, nums))
	{
		free_double_arr(nums);
		error_and_exit(WRONG_RGB, data);
	}
	result = (r << 16) | (g << 8) | b;
	free_double_arr(nums);
	return (result);
}
