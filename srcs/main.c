/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:35:20 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:03:19 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int c, char **v)
{
	struct s_so_long	game;

	map_parse(&game, get_file(c, v));
	ff_check(&game);
	init_enemies(&game);
	init_game(&game);
	gen_weightmap(&game);
	s_hook_register(game.mlx, s_hook_create(E_DESTROY_NOTIFY, M_NONE,
			mlx_loop_end, game.mlx.ctx));
	s_hook_register(game.mlx, s_hook_create(E_KEY_PRESSED, M_KEY_PRESSED,
			key_pressed, &game));
	render_map(&game);
	refresh_numbers(&game);
	refresh_score(&game);
	mlx_loop_hook(game.mlx.ctx, f_loop, &game);
	mlx_loop(game.mlx.ctx);
	so_long_unleak(game);
}
