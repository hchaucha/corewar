/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:42:01 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 15:42:02 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../inc/corewar.h"

void	verif_size_champs(t_champ *champ, int ret, int fd)
{
	int		len;
	int		tmp;
	char	*str[BUFF_SIZE + 1];

	len = 0;
	lseek(fd, 2192, SEEK_SET);
	while ((tmp = read(fd, str, BUFF_SIZE)))
		len += tmp;
	while (champ->next)
		champ = champ->next;
	if (champ->nb_octet > CHAMP_MAX_SIZE)
	{
		ret = champ->nb_octet - CHAMP_MAX_SIZE;
		ft_printf(C_RED"Error: Le joueur %d(%s) est trop grand de %d octets.\n"
			C_NONE, champ->id_champ, champ->name, ret);
		exit(1);
	}
	if (len != champ->nb_octet)
		ft_error(
			"Error: File has a code size differ from what its header says");
}

void	read_file(int fd, t_champ **champ, int id_champ)
{
	int		ret;
	int		champ_len;
	char	*file;
	char	*buffer[BUFF_SIZE + 1];

	file = NULL;
	champ_len = 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
		champ_len += ret;
	file = (char *)malloc(sizeof(char) * (champ_len + 1));
	lseek(fd, 0, SEEK_SET);
	read(fd, file, champ_len);
	file[champ_len] = '\0';
	if (file[0] != (char)0x00 || file[1] != (char)0xea || file[2] != (char)0x83
			|| file[3] != (char)0xf3)
		ft_error("Error: Wrong magic number");
	if (file[2188] != 0 || file[2189] != 0 ||
		file[2190] != 0 || file[2191] != 0)
		ft_error("Error : Wrong .cor");
	get_champion_header(file, champ_len, champ, id_champ);
	free(file);
	verif_size_champs(*champ, ret, fd);
}

char	*get_champion_file(char *file, int nb_octet, int i, int champ_len)
{
	int		n;
	char	*new;

	new = ft_strnew(nb_octet);
	n = 0;
	while (n < (champ_len - 2192))
	{
		new[n] = file[i];
		i++;
		n++;
	}
	return (new);
}

int		get_nb_octet(char *file, int i)
{
	int		n;
	int		nb;
	int		ret;
	int		power;
	int		tmp;

	n = 132;
	nb = 0;
	ret = 0;
	while (file[n++] == 0)
		nb++;
	if (n < 138 || (nb = 8 - nb) < 0 || nb > 6)
		ft_error("Error : Wrong .cor");
	nb = 8 - nb;
	power = 0;
	while (nb--)
	{
		if (file[i] < 0)
			tmp = 256 + file[i--];
		else
			tmp = file[i--];
		ret += tmp * ft_pow(16, power);
		power += 2;
	}
	return (ret);
}

void	get_champion_header(char *file, int champ_len, t_champ **champ, int id)
{
	int		i;
	int		n;
	t_trash	t;

	t.name = ft_strnew(1);
	t.comment = ft_strnew(1);
	i = -1;
	n = 0;
	t.nb_octet = 0;
	while (++i < champ_len)
	{
		if (i >= 132)
		{
			if (i == 132 && (t.nb_octet = get_nb_octet(file, 139)))
				i = 140;
			while (i++ < 2188 && i < champ_len)
				t.comment = ft_straddnchar(t.comment, 1, 1, file[i - 1]);
		}
		else if (file[i] == -13 && file[i - 1] == -125 && file[i - 2] == -22)
			while (i++ < 128 && i < champ_len)
				t.name = ft_straddnchar(t.name, 1, 1, file[i]);
	}
	t.file = get_champion_file(file, t.nb_octet, 2192, champ_len);
	t.id_champ = id;
	add_to_champlst(champ, &t);
}
