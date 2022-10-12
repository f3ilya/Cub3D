/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:14:41 by                   #+#    #+#             */
/*   Updated: 2021/12/23 13:56:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*a;

	i = 0;
	while (s[i] != '\0')
		i++;
	a = malloc(sizeof(*s) * i + 1);
	if (a == NULL)
		return (a);
	i = 0;
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0') && (i < n - 1) && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i])
			free(str[i]);
	}
	free(str);
}

int	free_and_return(char **str_arr, int return_val)
{
	clear(str_arr);
	return (return_val);
}
