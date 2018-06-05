
#ifndef LIBLEM_H
# define LIBLEM_H
# include "../libft/libft.h"

typedef struct	s_id
{
	char		*n;
	int		id;
	int		x;
	int		y;
	struct s_id	*next;
}		t_id;

typedef struct	s_map
{
	int		**map;
	int		w;
}		t_map;

typedef struct s_path
{
	int		cost;
	int		ants;
	char		**path;
	int		*a;
	int		w;
	struct s_path	*next;
}		t_path;

typedef	struct	s_hex
{
	int	ants;
	t_map	*map;
	t_id	*id;
	int	**path;
	int	w;
}		t_hex;

t_path	*lem_in(char **s, int i);
char	**getord();
t_hex	*getstruct(char **map);
t_hex   *getlinks(t_hex *h, char **map);
t_hex   *getpaths(t_hex *h);
t_path	*translate(t_hex *h);
t_path  *antdist(t_hex *h, t_path *p);
void	printres(t_path *p, t_hex *h, char **map, int v);

//STRUCT
t_hex	*ft_newhex(int a, t_map *m, t_id *id);
t_map	*ft_newmap(int w);
t_id	*ft_newid(char *id, int i);
t_path	*ft_newpath(int cost);
void    ft_deletemap(t_map *m);
void    ft_deleteid(t_id *id);
void    ft_deletepath(t_path *p);
void	ft_deletehex(t_hex *h);
void	ft_deletedstr(char **s);

//FUNC
void    ft_exit(void);
t_id		*ft_idgenerator(char **map);
t_map		*ft_mindistance(t_map *m);
void		ft_read_nd_clear(void);
t_id		*ft_getaxis(t_hex *h, char **m);
char		**ft_insertlink(t_hex *h, char **map, char **m);
char    **linktoup(t_id *down, t_id *up, char **m);
char    **linktodown(t_id *down, t_id *up, char **m);

//PRINT
void    ft_putres(t_path *p);
void	ft_putinstruct(char **m);
void    ft_putbanner(void);
int     ft_visual(t_path *p, t_hex *h, char **m);
void	ft_staticpath(t_path *p);
char	**ft_statichex(t_path *p, t_hex *h, char **map);
void	ft_dynamicpath(t_path *p, int m);
void    ft_putdstr(char **s);
void    ft_putdmap(char **s);

void	ft_puttmap(t_map *m);
void    ft_putid(t_id *id);
void    ft_putpath(t_hex *m);
void    ft_putfinal(t_path *p);

#endif
