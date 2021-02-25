/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:12:33 by tchiba            #+#    #+#             */
/*   Updated: 2020/12/04 22:08:42 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>

typedef	struct	s_info
{
	char		*name;
	time_t		time;
}				t_info;

int				ft_count_dir(void);
void			ft_strcmp_sort(t_info *info, int d_cnt);
void			ft_timecmp_sort(t_info *info, int d_cnt);
int				ft_info_pack(DIR *dir, struct dirent *dp, t_info *info);
void			ft_putstr(char *s);
int				ft_strcmp(char *s1, char *s2);
int				put_error(int n);

#endif
