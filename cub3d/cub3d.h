/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:35:35 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/22 03:42:29 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx_beta/mlx.h"
# include "mlx/mlx.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define TEXTURES 5

# define ERROR_INF -1
# define ERROR 0
# define SUCCES 1
# define NEXT 2

# define OPEN_MAX 256
# define BUFFER_SIZE 128

typedef struct			s_sprite
{
	int					x;
	int					y;
}						t_sprite;

typedef struct			s_sprites
{
	int					x;
	int					y;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_draw_sprite
{
	t_sprite			*sprites;
	int					i;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_width;
	int					draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					y;
	int					d;
	int					tex_x;
	int					tex_y;
	int					color;
	int					total_color;
}						t_draw_sprite;

typedef struct			s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

typedef struct			s_ray
{
	int					x;
	int					mapx;
	int					mapy;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				*z_buffer;
}						t_ray;

typedef struct			s_image
{
	void				*img_ptr;
	char				*data;
	int					width;
	int					height;
	int					size_l;
	int					bpp;
	int					endian;
}						t_image;

typedef struct			s_keys
{
	int					key_w;
	int					key_s;
	int					key_a;
	int					key_d;
	int					key_left;
	int					key_right;
}						t_keys;

typedef struct			s_map
{
	char				**map;
	char				*map_name;
	int					width;
	int					height;
}						t_map;

typedef	struct			s_player
{
	double				posx;
	double				posy;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				move_speed;
	double				rotate_speed;
	int					set_player;
}						t_player;

typedef struct			s_identifier
{
	int					resolution;
	int					path[TEXTURES];
	int					color_floor;
	int					color_ceiling;
}						t_identifier;

typedef	struct			s_info
{
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	int					color_floor;
	int					color_ceiling;
	int					save_option;
	t_map				*map;
	t_keys				*keys;
	t_player			*player;
	t_image				*img;
	t_image				**textures;
	t_image				*sprite;
	t_sprites			*sprites_on_screen;
	t_identifier		*identifier;
	int					gnl_return;
}						t_info;

typedef	struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

void					clear_structs(t_info *info);
int						print_error(char *message);
void					exit_error(char *message);
int						exit_game(t_info *info);
int						init_player(t_info *info);
int						init_keys(t_info *info);
int						init_map(t_info *info, char *map_name);
int						init_textures(t_info *info);
int						init_sprite(t_info *info);
int						key_press(int key, t_info *info);
int						key_release(int key, t_info *info);
int						key_update(t_info *info);
int						main_loop(t_info *info);
int						config_resolution(char *line, int i, t_info *info);
int						config_path(int index, char *line, int i, t_info *info);
int						config_color(char *line, int i, char location, \
		t_info *info);
char					*treat_description(char *map_name, t_info *info);
char					**treat_map(char *str, t_info *info);
int						check_map_validation(t_info *info, char **map);
void					set_player_position(t_info *info, char direction, \
		int x, int y);
void					move_forward(t_map *map, t_player *player);
void					move_backward(t_map *map, t_player *player);
void					move_left(t_map *map, t_player *player);
void					move_right(t_map *map, t_player *player);
void					set_camera_position(t_info *info, double dirx, \
		double planex, double planey);
void					turn_left(t_player *player);
void					turn_right(t_player *player);
void					put_pixel_on_image(int color, int x, int y, \
		t_image *img);
void					vertical_line_color(t_line *line, t_info *info, \
		int color);
void					vertical_line_texture(t_line *line, t_info *info, \
		t_image *texture, t_ray *ray);
t_image					*new_image(t_info *info);
int						raycasting(t_info *info);
void					hit(t_ray *ray, t_info *info);
void					get_line_height(t_ray *ray, t_player *player, \
		t_info *info);
void					get_draw_start_end(t_ray *ray, t_info *info);
void					texturize(t_ray *ray, t_info *info);
int						set_texture(t_info *info, char *path, int i);
int						stock_sprite(char *path, t_info *info);
void					put_pixel_on_sprite_image(t_draw_sprite *s, \
		t_info *info);
int						draw_sprite(t_ray *ray, t_info *info);
t_sprite				*list_to_tab(t_info *info);
void					sort_sprite(t_info *info, t_sprite *sprites, \
		int nbr_sprites);
void					is_sprite(t_ray *ray, t_info *info);
int						create_bitmap(t_image *mlx_img, char *name);

int						ft_isspace(int c);
int						ft_isprint(int c);
int						ft_isdigit(char c);
int						ft_putstr(char *str);
void					ft_bzero(void *p, size_t len);
int						ft_strlen(char *str);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strdup(char *s1);
char					*ft_substr(char *str, int start, int len);
char					*ft_strjoin(char *s1, char *s2);
int						ft_lstsize(t_list *list);
int						ft_atoi(char *str);
int						get_next_line(int fd, char **line);

#endif
