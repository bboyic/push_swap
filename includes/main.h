/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:54:45 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/13 03:39:18 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define	MAIN_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_ab
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_ab;

int		ft_freeAv(char **av);
size_t	ft_strlen(const char *s);
void	ft_free(t_ab *anb, int *a, int ac, char **av);
int		*ft_sortACreate(t_ab *anb, int argc);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_pars(int ac, char **av);
int		ft_strIsNum(char *av);
int		ft_pars_repeat(int ac, char **av);
t_ab	*ft_push_a(t_ab *anb);
t_ab	*ft_push_b(t_ab *anb, int *sort_a, int md);
t_ab	*ft_move(t_ab *anb, int md, int len, int max);
t_ab	*ft_find_point(t_ab *anb, int size);
t_ab	*ft_min(t_ab *anb, int max);
int		ft_sort_len(int *sort_a, int md);
int		*ft_copy_a(int *a, t_ab *anb);
int		ft_check_sort(int *a, int len);
int		*ft_sort(int *a, int len);
int		ft_size_split(char **av);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_points(t_ab *anb, int ev, int index);
int		ft_rpoints(t_ab *anb, int size);
int		ft_rrpoints(t_ab *anb, int size);
t_ab	*ft_push_r(t_ab *anb, int r_points, int size);
t_ab	*ft_push_rr(t_ab *anb, int r_points, int size);
t_ab	*ft_sa(t_ab *anb);
t_ab	*ft_sb(t_ab *anb);
t_ab	*ft_pa(t_ab *anb);
t_ab	*ft_pb(t_ab *anb);
t_ab	*ft_ra(t_ab *anb);
t_ab	*ft_rb(t_ab *anb);
t_ab	*ft_rra(t_ab *anb);
t_ab	*ft_rrb(t_ab *anb);
t_ab	*ft_ss(t_ab *anb);
t_ab	*ft_rr(t_ab *anb);
t_ab	*ft_rrr(t_ab *anb);
void	ft_ab_clear(t_ab *anb);
t_ab	*ft_new_anb(t_ab *anb);

#endif