/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:02:38 by chillion          #+#    #+#             */
/*   Updated: 2022/08/30 16:38:19 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

void	*ft_zalloc(size_t nmemb, size_t size);
char	*ft_free_strjoin(char *s1, char *s2);
int		ft_schr(char *s);
char	*get_next_line(int fd);
char	*rest_line(char *str);
char	*keep_line(char *str);
char	*get_read_fd(int fd, char *str);
void	ft_free(char **str);

#endif