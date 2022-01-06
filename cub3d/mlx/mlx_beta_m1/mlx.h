/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@42.fr>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue Oct 14 16:23:28 2019 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/


/*
**
** This library is a simple framework to help 42 students
** create simple graphical apps.
** It only provides the minimum functions, it's students' job
** to create the missing pieces for their own project :)
**
** The MinilibX can load XPM and PNG images.
** Please note that both image loaders are incomplete, some
** image may not load.
**
** For historical reasons, the alpha byte represent transparency
** instead of opacity.
** Also, for compatibility reasons, prototypes may show inconsistant
** types.
**
** Only the dynamic library is available. It must be placed in an appropriate path.
** ./ is one of them. You can also use DYLD_LIBRARY_PATH
**
*/


#ifndef MLX_BETA_H

#define	MLX_BETA_H


/*
**  needed before everything else.
**  return (void *)0 if failed
*/


/*
** Basic actions
*/

/*
**  return void *0 if failed
*/
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0xAARRGGBB format
**  x and y must fit into the size of the window, no control is done on the values
*/


/*
** Image stuff
*/

/*
**  return void *0 if failed
*/
/*
**  endian : 0 = graphical sever is little endian, 1 = big endian
**  usefull in a network environment where graphical app show on a remote monitor that can have a different endian
*/


/*
** dealing with Events
*/


/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
**   mlx_string_put display may vary in size between OS and between mlx implementations
*/

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/
#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
/*
** image_writable can loop forever if no flush occurred. Flush is always done by mlx_loop.
** cmd_completed first flush then wait for completion.
** mlx_do_sync equals cmd_completed for all windows.
** cmd is one of the define, param will be img_ptr or win_ptr accordingly
*/

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif /* MLX_BETA_H */
