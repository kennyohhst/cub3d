/**
 *
1. It calculates the x-coordinate of the pixel in the texture (img_x) based on the height of the wall hit (game->cast.wall_h[cast_n]).

2. It then enters a loop that runs for the height of the wall in pixels (pixel_h).

3. In each iteration of the loop, it calculates the y-coordinate of the pixel in the texture (img_y) based on the current pixel height and the multiplication factor (mult_factor).

4. It retrieves two texels (texel0 and texel1) from the texture. These are the texels at the calculated y-coordinate and the one just below it.

5. It calculates a fractional y-coordinate (fractional_y) which represents the exact position of the pixel within the two texels.

6. It then calls the get_texel function to interpolate between the two texels based on the fractional y-coordinate. This results in a combined texel (combined_texel).

7. Finally, it places the combined texel into the pixels_buffer at the correct position.
*/
void place_combined_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, size_t pixel_h, float mult_factor)
{
	size_t	i;
	size_t	img_x;
	size_t	img_y;
	uint8_t	texel0;
	uint8_t	texel1;
	uint8_t	combined_texel;
	float	fractional_y;

	i = 0;
	img_x = (int)(game->cast.wall_h[cast_n] * PIXEL) % PIXEL;
	while (i < pixel_h)
	{
		img_y = (int)(i * mult_factor);
		texel0 = wall.pixels[img_y * PIXEL + img_x];
		texel1 = wall.pixels[(img_y + 1) * PIXEL + img_x];
		fractional_y = (i * mult_factor) - img_y;
		combined_texel = get_texel(texel0, texel1, fractional_y);
		game->cast.pixels_buffer[cast_n * HEIGHT + i] = combined_texel;
		i++;
	}
}

uint8_t	get_texel(uint8_t a, uint8_t b, float t);




void	fuck_some_shit_up(t_render *game)
{
	uint32_t	x;
	uint32_t	y;

	mlx_texture_t *wall = game->text.t_wall_e;
	int index = (32 * PIXEL + 0) * 4;
	uint8_t alpha = wall->pixels[index];
	uint8_t blue = wall->pixels[index + 1];
	uint8_t green = wall->pixels[index + 2];
	uint8_t red = wall->pixels[index + 3];
	uint32_t colour = get_RGB(alpha, red, green, blue);

	x = 0;
	while (x < WIDTH / 2)
	{
		y = 0;
		while (y < HEIGHT)
		{
			game->cast.pixels_buffer[y * WIDTH + x] = colour;
			y++;
		}
		x++;
	}

	 index = (6 * PIXEL + 32) * 4;
	 alpha = wall->pixels[index];
	 blue = wall->pixels[index + 1];
	 green = wall->pixels[index + 2];
	 red = wall->pixels[index + 3];
	 colour = get_RGB(alpha, red, green, blue);


	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			game->cast.pixels_buffer[y * WIDTH + x] = colour;
			y++;
		}
		x++;
	}


	//colour = get_RGB(255, 255, 0, 0);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(game->text.img_walls, x, y, game->cast.pixels_buffer[y * WIDTH + x]);
			y++;
		}
		x++;
	}
}













		// if (fabs(calc.radian - 0) < EPS || fabs(calc.radian - PI) < EPS)
		// 	handle_east_west(game, &calc);	
		// else if (fabs(calc.radian - 0.5 * PI) < EPS || fabs(calc.radian - 1.5 * PI) < EPS)
   		// 	handle_north_south(game, &calc);
		// else
		// {

			void handle_north_south(t_render *game, t_calc *calc)
{
    if (fabs(calc->radian - 0.5 * PI) < EPS)
    {
        while (game->map[(int)(calc->mapy)][(int)(calc->mapx)] != '1')
            calc->mapy++;
        calc->wall_side = NORTH;
		game->cast.distance[calc->cast_n] = fabs(game->player.py - calc->mapy);
    }
    else
    {
        while (game->map[(int)(calc->mapy)][(int)(calc->mapx)] != '1')
            calc->mapy--;
        calc->wall_side = SOUTH;
		game->cast.distance[calc->cast_n] = fabs(game->player.py - calc->mapy);
    }
    calc->wall_h = game->player.py - (int)game->player.py;;
}

void handle_east_west(t_render *game, t_calc *calc)
{
    if (fabs(calc->radian - 0 * PI) < EPS)
    {
        while (game->map[(int)(calc->mapy)][(int)(calc->mapx)] != '1')
            calc->mapx++;
        calc->wall_side = WEST;
		game->cast.distance[calc->cast_n] = fabs(game->player.px - calc->mapx);
    }
    else
    {
        while (game->map[(int)(calc->mapy)][(int)(calc->mapx)] != '1')
            calc->mapx--;
        calc->wall_side = EAST;
		game->cast.distance[calc->cast_n] = fabs(game->player.px - calc->mapx);
    }
    calc->wall_h = game->player.px - (int)game->player.px;
}


		printf("ray[%zu] = %f, wall = %i\n", calc.cast_n, game->cast.distance[calc.cast_n], calc.wall_side);
		printf("ray[%zu] rad: %f, stepx: %d, stepy: %d\n", calc.cast_n, calc .radian, calc.stepx, calc.stepy);
		printf("ray[%zu] sidedistY: %f, deltaY %f\n", calc.cast_n, calc.sidedisty, calc.deltaY);
		printf("ray[%zu] sidedistX: %f, deltaX %f\n", calc.cast_n, calc.sidedistx, calc.deltaX);


				if (calc->cast_n > 120 && calc->cast_n < 134)
			printf("mapx: %f, mapy: %f\n", calc->mapx, calc->mapy);










void	set_values(t_calc *calc)
{
	if (calc->sidedistx < calc->sidedisty)
	{
		if (calc->stepy == -1)
			calc->wall_side = SOUTH;
		else
			calc->wall_side = NORTH;
	}
	else
	{
		if (calc->stepx == -1)
			calc->wall_side = EAST;
		else
			calc->wall_side = WEST;
	}
}

/**
 * @brief calculates the distance from the player to the wall && sets wall_h
 * if wall_h has not yet been set
 * 
*/
void	set_dist_wallh(t_render *game, t_calc *calc)
{
	double	perpendicular_dist;
	// double	corrected_dist;
	double	wall_hit;

	if (calc->wall_side == NORTH || calc->wall_side == SOUTH)
		perpendicular_dist = calc->sidedisty - calc->deltaY;
	else
		perpendicular_dist = calc->sidedistx - calc->deltaX;
	// corrected_dist = perpendicular_dist * cos(calc->radian - game->player.rad);
	game->cast.distance[calc->cast_n] = fabs(perpendicular_dist);
	if (calc->wall_side == NORTH || calc->wall_side == SOUTH)
		wall_hit = game->player.px + perpendicular_dist * sin(calc->radian); // change to  cirrected dist
	else
		wall_hit = game->player.py - perpendicular_dist * cos(calc->radian); // change to corrected dist
	calc->wall_h = wall_hit - (int)wall_hit;
}



	while (1)
	{
		disH = get_dist(game->player.px, game->player.py, calc->hor_ray_x, calc->hor_ray_y);
		disV = get_dist(game->player.px, game->player.py, calc->ver_ray_x, calc->ver_ray_y);
		if (disV < disH)
		{
			calc->mapx = (int)(calc->ver_ray_x);
			calc->mapy = (int)(calc->ver_ray_y);
		}
		else
		{
			calc->mapx = (int)(calc->hor_ray_x);
			calc->mapy = (int)(calc->hor_ray_y);
		}
		if (game->map[calc->mapy][calc->mapx] == '1')
			return (set_values(game, calc, disH, disV));
		else
		{
			if (disV > disH)
			{
				calc->hor_ray_x += calc->hor_stepx;
				calc->hor_ray_y += calc->hor_stepy;
			}
			else
			{
				calc->ver_ray_x += calc->ver_stepx;
				calc->ver_ray_y += calc->ver_stepy;
			}	
		}
	}