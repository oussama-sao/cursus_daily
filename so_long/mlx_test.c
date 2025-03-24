/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:28:24 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/24 01:58:01 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void    *mlx;
    void    *img;

    mlx = mlx_init();
    if (!mlx) {
        write(2, "MLX initialization failed\n", 26);
        return (1); // Exit if initialization fails
    }

    img = mlx_new_image(mlx, 1920, 1080);
    if (!img) {
        write(2, "Image creation failed\n", 22);
        return (1); // Exit if image creation fails
    }

    // Add more code to test the rest of the MLX functionality
    mlx_destroy_image(mlx, img);  // Clean up resources

    return (0);
}
