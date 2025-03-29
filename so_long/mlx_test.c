/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:28:24 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/28 04:40:39 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <math.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// 	time_t	key_press_time;
// 	int		key_held;
// }				t_vars;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// //esc pressed should close window :

// int	button_pressed(int keycode, void *param)
// {
// 	t_vars *vars = (t_vars *)param;
// 	// if (keycode == 65307)
// 	// {
// 		mlx_destroy_window(vars->mlx,vars->win);
// 		exit(0);
// 	// }
// 	return (0);
// }

// //put message if window resized:

// int	resized(int keycode, void *param)
// {
// 	(void)param;
// 	(void)keycode;
// 	printf("the window is resized \n");
// 	return (0);
// }

// //close when red x pressed :
// int pressx(void *param)
// {
// 	t_vars *vars = (t_vars *)param;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit (0);
// }

// //mouse in :
// int mousein(int x, int y, void *param)
// {
// 	(void)x;
// 	(void)y;
// 	(void)param;
// 	printf("hellowww\n");
// 	return (0);
// }
// //mouse out :
// int mouseout(int x, int y, void *param)
// {
// 	(void)x;
// 	(void)y;
// 	(void)param;
// 	printf("byeeeeee\n");
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data img;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 500, 400, "Hello world!");
// 	// mlx_hook(vars.win, 3, 1L<<1, button_pressed, &vars);//esc close window
// 	// mlx_hook(vars.win, 25, 1L<<18, resized, &vars);//resize put message
// 	// mlx_hook(vars.win, 17, 1L<<17, pressx, &vars);//close when x pressed
// 	// mlx_hook(vars.win, 7, 1L<<4, mousein, &vars);//mouse in
// 	// mlx_hook(vars.win, 8, 1L<<5, mouseout, &vars);//mouse out
// 	// mlx_loop(vars.mlx);
// 	img.img = mlx_new_image(vars.mlx, 500, 400);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	int x, y, distance;

//     for (x = -30; x <= 30; x++)
//     {
//         for (y = -30; y <= 30; y++)
//         {
//             distance = x * x + y * y;
//             if (distance <= 30 * 30)
//                 my_mlx_pixel_put(&img, 250 + x, 200 + y, 0xFFFF00);
//         }
//     }
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_loop(vars.mlx);
// }
#define WIDTH 800
#define HEIGHT 600
#define CIRCLE_RADIUS 30
typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_data  img;
    int     hue;
    int     circle_x;
    int     circle_y;
}   t_game;

// Function to put a pixel in an image
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

// Function to convert HSV to RGB (approximated)
int hsv_to_rgb(int hue)
{
    float r, g, b;
    int i = hue / 60;
    float f = (hue / 60.0) - i;
    float q = 1 - f;

    if (i == 0) { r = 1; g = f; b = 0; }
    else if (i == 1) { r = q; g = 1; b = 0; }
    else if (i == 2) { r = 0; g = 1; b = f; }
    else if (i == 3) { r = 0; g = q; b = 1; }
    else if (i == 4) { r = f; g = 0; b = 1; }
    else { r = 1; g = 0; b = q; }

    return ((int)(r * 255) << 16) | ((int)(g * 255) << 8) | (int)(b * 255);
}

// Function to render the background
void render_background(t_game *game)
{
    int x, y;
    int color = hsv_to_rgb(game->hue % 360);
    
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
            my_mlx_pixel_put(&game->img, x, y, color);
    }
}

// Function to render a circle
void render_circle(t_game *game)
{
    int x, y, distance;

    for (x = -CIRCLE_RADIUS; x <= CIRCLE_RADIUS; x++)
    {
        for (y = -CIRCLE_RADIUS; y <= CIRCLE_RADIUS; y++)
        {
            distance = x * x + y * y;
            if (distance <= CIRCLE_RADIUS * CIRCLE_RADIUS)
                my_mlx_pixel_put(&game->img, game->circle_x + x, game->circle_y + y, 0xFFFFFF);
        }
    }
}

// Function that updates the frame
int update_frame(t_game *game)
{
    game->hue += 2;
    render_background(game);
    render_circle(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
    return (0);
}

// Handle key press events
int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC key
        exit(0);
    if (keycode == 119 && game->circle_y > CIRCLE_RADIUS) // W key
        game->circle_y -= 10;
    if (keycode == 115 && game->circle_y < HEIGHT - CIRCLE_RADIUS) // S key
        game->circle_y += 10;
    if (keycode == 97 && game->circle_x > CIRCLE_RADIUS) // A key
        game->circle_x -= 10;
    if (keycode == 100 && game->circle_x < WIDTH - CIRCLE_RADIUS) // D key
        game->circle_x += 10;
    return (0);
}

// Main function
// int main(void)
// {
//     t_game game;

//     game.mlx = mlx_init();
//     game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Rainbow & Circle");
//     game.img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
//     game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
    
//     game.hue = 0;
//     game.circle_x = WIDTH / 2;
//     game.circle_y = HEIGHT / 2;

//     mlx_loop_hook(game.mlx, update_frame, &game);
//     mlx_hook(game.win, 2, 1L << 0, key_press, &game);
//     mlx_loop(game.mlx);

//     return (0);
// }


#include "mlx.h"
#include <stdio.h>

int main(void)
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width, img_height;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "XPM Image Example");

    img = mlx_xpm_file_to_image(mlx, "./assets/goku2.xpm", &img_width, &img_height);
    if (!img)
    {
        printf("Error: Failed to load XPM image\n");
        return (1);
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0); // Display image at (100,100)
    mlx_loop(mlx);
    
    return (0);
}

// Render a moving rainbow that shifts through all colors (screen turns red, becomes green and then becomes blue, then starts all over again).
// Create a circle that you can move accross your screen using your WASD keys.