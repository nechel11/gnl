/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:17:08 by nbyrd             #+#    #+#             */
/*   Updated: 2021/12/03 13:26:25 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_read_remainder(int fd, char *temp_line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*gnl_enter(char *temp_line, char *buffer);
char	*gnl_liner(char *temp_line);
char	*gnl_reading(char	*temp_line);
#endif
