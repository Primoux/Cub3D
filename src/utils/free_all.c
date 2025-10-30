/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:31 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:39:07 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "memory.h"

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_images(data);
	free_structs(data);
	free_mlx(data);
}
