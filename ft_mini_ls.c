/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:29:56 by tchiba            #+#    #+#             */
/*   Updated: 2020/12/04 23:21:03 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int			ft_count_dir(void)
{
	DIR				*dir;
	struct dirent	*dp;
	int				len;

	dir = opendir("./");
	if (dir == NULL)
		return (put_error(0));
	len = 0;
	while ((dp = readdir(dir)) != NULL)
		if (dp->d_name[0] != '.')
			len++;
	closedir(dir);
	return (len);
}

void		ft_strcmp_sort(t_info *info, int d_cnt)
{
	int			i;
	int			j;
	t_info		tmp;

	i = 0;
	while (i < d_cnt)
	{
		j = i + 1;
		while (j < d_cnt)
		{
			if ((ft_strcmp(info[i].name, info[j].name) < 0))
			{
				tmp.name = info[i].name;
				tmp.time = info[i].time;
				info[i].name = info[j].name;
				info[i].time = info[j].time;
				info[j].name = tmp.name;
				info[j].time = tmp.time;
			}
			j++;
		}
		i++;
	}
}

void		ft_timecmp_sort(t_info *info, int d_cnt)
{
	int		i;
	int		j;
	t_info	tmp;

	i = 0;
	while (i < d_cnt)
	{
		j = i + 1;
		while (j < d_cnt)
		{
			if (info[i].time > info[j].time)
			{
				tmp.name = info[i].name;
				tmp.time = info[i].time;
				info[i].name = info[j].name;
				info[i].time = info[j].time;
				info[j].name = tmp.name;
				info[j].time = tmp.time;
			}
			j++;
		}
		i++;
	}
}

int			ft_info_pack(DIR *dir, struct dirent *dp, t_info *info)
{
	struct stat		buf;
	int				i;

	i = 0;
	dir = opendir("./");
	if (dir == NULL)
		return (put_error(0));
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.')
		{
			if (stat(dp->d_name, &buf) == 0)
			{
				info[i].time = buf.st_mtime;
				info[i].name = dp->d_name;
				i++;
			}
		}
	}
	closedir(dir);
	return (0);
}

int			main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*dp;
	t_info			*info;
	int				d_cnt;
	int				i;

	dir = NULL;
	dp = NULL;
	if (argc > 1 && argv)
		return (put_error(EINVAL));
	d_cnt = (ft_count_dir());
	if (!(info = malloc(sizeof(t_info) * d_cnt)))
		return (put_error(ENOMEM));
	if (ft_info_pack(dir, dp, info) == 1)
		return (1);
	ft_strcmp_sort(info, d_cnt);
	ft_timecmp_sort(info, d_cnt);
	i = 0;
	while (i < d_cnt)
		ft_putstr(info[i++].name);
	free(info);
	return (0);
}
