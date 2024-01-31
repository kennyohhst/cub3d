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













		// if (fabs(dda.radian - 0) < EPS || fabs(dda.radian - PI) < EPS)
		// 	handle_east_west(game, &dda);	
		// else if (fabs(dda.radian - 0.5 * PI) < EPS || fabs(dda.radian - 1.5 * PI) < EPS)
   		// 	handle_north_south(game, &dda);
		// else
		// {

			void handle_north_south(t_render *game, t_dda *dda)
{
    if (fabs(dda->radian - 0.5 * PI) < EPS)
    {
        while (game->map[(int)(dda->mapy)][(int)(dda->mapx)] != '1')
            dda->mapy++;
        dda->wall_side = NORTH;
		game->cast.distance[dda->cast_n] = fabs(game->player.py - dda->mapy);
    }
    else
    {
        while (game->map[(int)(dda->mapy)][(int)(dda->mapx)] != '1')
            dda->mapy--;
        dda->wall_side = SOUTH;
		game->cast.distance[dda->cast_n] = fabs(game->player.py - dda->mapy);
    }
    dda->wall_h = game->player.py - (int)game->player.py;;
}

void handle_east_west(t_render *game, t_dda *dda)
{
    if (fabs(dda->radian - 0 * PI) < EPS)
    {
        while (game->map[(int)(dda->mapy)][(int)(dda->mapx)] != '1')
            dda->mapx++;
        dda->wall_side = WEST;
		game->cast.distance[dda->cast_n] = fabs(game->player.px - dda->mapx);
    }
    else
    {
        while (game->map[(int)(dda->mapy)][(int)(dda->mapx)] != '1')
            dda->mapx--;
        dda->wall_side = EAST;
		game->cast.distance[dda->cast_n] = fabs(game->player.px - dda->mapx);
    }
    dda->wall_h = game->player.px - (int)game->player.px;
}


		printf("ray[%zu] = %f, wall = %i\n", dda.cast_n, game->cast.distance[dda.cast_n], dda.wall_side);
		printf("ray[%zu] rad: %f, stepx: %d, stepy: %d\n", dda.cast_n, dda .radian, dda.stepx, dda.stepy);
		printf("ray[%zu] sidedistY: %f, deltaY %f\n", dda.cast_n, dda.sidedisty, dda.deltaY);
		printf("ray[%zu] sidedistX: %f, deltaX %f\n", dda.cast_n, dda.sidedistx, dda.deltaX);


				if (dda->cast_n > 120 && dda->cast_n < 134)
			printf("mapx: %f, mapy: %f\n", dda->mapx, dda->mapy);










void	set_values(t_dda *dda)
{
	if (dda->sidedistx < dda->sidedisty)
	{
		if (dda->stepy == -1)
			dda->wall_side = SOUTH;
		else
			dda->wall_side = NORTH;
	}
	else
	{
		if (dda->stepx == -1)
			dda->wall_side = EAST;
		else
			dda->wall_side = WEST;
	}
}

/**
 * @brief calculates the distance from the player to the wall && sets wall_h
 * if wall_h has not yet been set
 * 
*/
void	set_dist_wallh(t_render *game, t_dda *dda)
{
	double	perpendicular_dist;
	// double	corrected_dist;
	double	wall_hit;

	if (dda->wall_side == NORTH || dda->wall_side == SOUTH)
		perpendicular_dist = dda->sidedisty - dda->deltaY;
	else
		perpendicular_dist = dda->sidedistx - dda->deltaX;
	// corrected_dist = perpendicular_dist * cos(dda->radian - game->player.rad);
	game->cast.distance[dda->cast_n] = fabs(perpendicular_dist);
	if (dda->wall_side == NORTH || dda->wall_side == SOUTH)
		wall_hit = game->player.px + perpendicular_dist * sin(dda->radian); // change to  cirrected dist
	else
		wall_hit = game->player.py - perpendicular_dist * cos(dda->radian); // change to corrected dist
	dda->wall_h = wall_hit - (int)wall_hit;
}