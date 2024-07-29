#ifndef STRUCTS_H 
# define STRUCTS_H

typedef struct s_pixel
{
	int x;
	int y;
	int color;
}	t_pixel;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_screen
{	
	float	im_x;
	float	fi_x;
	float	im_y;
	float	fi_y;
} t_screen;

typedef struct s_position
{
	double	real;
	double	im;
}	t_position;

typedef struct s_fract
{
	char 		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	int			iter;
	t_screen	matrix;
	t_position	c;
	t_position	z;
	float		real_julia;
	float		im_julia;
	double		button_x;
	double		button_y;
}	t_fract;	

/*my structs out of fractol*/
typedef struct s_var
{
	int i;
	int j;
}	t_var;
#endif
