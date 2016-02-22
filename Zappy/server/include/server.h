#ifndef	_SERVER_H_
#define	_SERVER_H_

#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <sys/time.h>
#include        <unistd.h>
#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include	<netdb.h>
#include	<time.h>
#include	"parser.h"

#define UNUSED(x) (void)(x)

typedef				void(*fct)();
typedef	struct s_server t_server;

typedef enum VUE VUE;
enum    VUE
  {
    HAUT,
    BAS,
    GAUCHE,
    DROITE
  };

typedef struct			s_team
{
  char				*name;
  int				nb;
  struct s_team			*next;
}				t_team;

typedef	struct			s_list_team
{
  t_team			*begin;
  t_team			*end;
}				t_list_team;

typedef struct			s_list
{
  int				linemate;
  int				deraumere;
  int				sibur;
  int				mendiane;
  int				phiras;
  int				thystame;
  int				food;
  time_t			time_food;
}				t_list;

typedef	struct			s_cmd
{
  int				(*fptr)(t_server *, char **, int);
  time_t			time;
  char				**tab;
  int				sock;
  int				done;
  struct s_cmd			*next;
  struct s_cmd			*prev;
}				t_cmd;

typedef struct			s_client
{
  int				sock;
  fct				fct_read;
  int				type;
  int				nb;
  char				*team;
  int				lvl;
  int				haut;
  int				larg;
  VUE				orientation;
  t_list			*inventaire;
  t_cmd				*cmd;
  struct s_client		*next;
} 				t_client;

typedef struct			s_egg
{
  int				nb;
  int				type;
  int				haut;
  int				larg;
  int				father;
  int				time;
  char				*team;
  struct s_egg			*next;
}				t_egg;

typedef struct			s_map
{
  t_list			**map;
  int				haut;
  int				larg;
}				t_map;

struct				s_server
{
  t_client			*client;
  t_egg				*egg;
  int				port;
  fd_set			fd_write;
  fd_set			fd_read;
  int				fd_max;
  t_map				*map;
  t_arg				*arg;
  t_list_team			team;
  int				sock_graph;
};

typedef struct			s_cmd_tab
{
  char				*cmd;
  int				(*fptr)(t_server *, char **, int);
  int				time;
}				t_cmd_tab;

typedef	struct			s_norme_pute
{
  int				len;
  int				i;
  int				a;
  int				check;
}				t_norme_pute;

/*
** DIR -> CLIENT
*/

/*
** add_client.c
*/

int				check_client(t_client **, int);
void				add_client(t_client **, int, int, fct);

/*
** do_team.c
*/

void				check_position(t_server *);
void				init_p_team(t_server *, t_client *, char *);
void				set_team(t_server *, char *, int);
void				say_nb_team(int, int);
int				do_team(t_server *, char *, int, t_team *);

/*
** eggs.c
*/

t_egg				*get_dispo_egg(t_server *, char *);
void				egg_become_ia(t_server *, t_client *, char *);
void				egg_dead(t_egg *, t_server *);
void				add_egg(t_server *, t_client *);
void				init_egg(t_server *, t_client *);

/*
** eggs2.c
*/

int				check_egg(t_server *, char *);

/*
** get_client.c
*/

t_client			*get_client2(t_server *, int);

/*
** inventaire.c
*/

void				init_inventaire(t_client *);

/*
** map.c
*/

void				init_map(t_server *);
void				add_obj(t_map *);
void				add_food(t_map *);
void				create_map(t_server *, t_arg);

/*
** team.c
*/

void				init_team(t_server *, int);
void				check_team(t_server *);

/*
** DIR -> CMD
*/

/*
** com_avance.c
*/

void				avance(t_server *, t_client *);
int				com_avance(t_server *, char **, int);

/*
** com_broadcast.c
*/

int				get_direction(int, int);
int				get_direct(t_server *, t_client *, t_client *);
int				get_dir(t_server *, t_client *, t_client *);
void				broadcast(t_server *, t_client *, char *);
int				com_broadcast(t_server *, char **, int);

/*
** com_connect_nbr.c
*/

void				connect_nbr(t_server *, t_client *);
int				com_connect_nbr(t_server *, char **, int);

/*
** com_expulse.c
*/

int				get_deplacement(int, int);
int				get_orient(VUE);
void				do_expulse(t_server *, t_client *, VUE);
void				expulse(t_server *, t_client *);
int				com_expulse(t_server *, char **, int);

/*
** com_fork.c
*/

int				com_fork(t_server *, char **, int);

/*
** com_gauche_droite.c
*/

void				droite(t_client *);
void				gauche(t_client *);
int				com_droite(t_server *, char **, int);
int				com_gauche(t_server *, char **, int);

/*
** com_incantation.c
*/

int				nb_clt_case(t_server *, t_client *, int, int);
int				incantation(t_server *, t_client *, int, int);
void				send_incantation(t_server *, t_client *, int, int);
void				do_incantation(t_server *, t_client *, int, int);
int				com_incantation(t_server *, char **, int);

/*
** com_incantation2.c
*/

int				need_incant(int, int);

/*
** com_inventaire.c
*/

void				inventaire(t_client *);
int				com_inventaire(t_server *, char **, int);

/*
** com_pose.c
*/

int				get_nb_inv(t_client *, int);
void				sup_inventaire(t_client *, int);
void				add_ressource(t_server *, int, int, int);
int				pose(t_server *, t_client *, char **);
int				com_pose(t_server *, char **, int);

/*
** com_prend.c
*/

int				get_nb_res(t_server *, int, int, int);
void				add_inventaire(t_client *, int);
void				sup_ressource(t_server *, int, int, int);
int				prend(t_server *, t_client *, char **);
int				com_prend(t_server *, char **, int);

/*
** com_voir.c
*/

void				voir_left(t_server *, int *, int *, VUE);
void				voir_line(t_server *, int *, int *, VUE);
char				*do_voir(t_server *, t_client *, char *, int);
void				fct_voir(t_server *, t_client *);
int				com_voir(t_server *, char **, int);

/*
** com_voir2.c
*/

void				voir_front(t_server *, int *, int *, VUE);

/*
** do_commande.c
*/

void				add_cmd_time(t_server *, t_cmd_tab, t_client *, char **);
int				do_commande(t_server *, char *, int);

/*
** get_case2.c
*/

char				*get_food_case(t_server *, int, int, char *);
char				*get_linemate_case(t_server *, int, int, char *);
char				*get_deraumere_case(t_server *, int, int, char *);
char				*get_sibur_case(t_server *, int, int, char *);
char				*get_mendiane_case(t_server *, int, int, char *);

/*
** get_case3.c
*/

char				*get_phiras_case(t_server *, int, int, char *);
char				*get_thystame_case(t_server *, int, int, char *);
char				*my_strcat(char *, char *);

/*
** get_case.c
*/

int				get_nb_player(t_server *, int, int);
char				*get_player_case(t_server *, int, int, char *);
int				get_eggs_nb(t_server *, int, int);
char				*get_eggs_case(t_server *, int, int, char *);
char				*get_case(t_server *, int, int, char *);

/*
** utils.c
*/

int				my_min(int, int);

/*
** DIR -> GRAPHIC
*/

/*
** check_win.c
*/

int				nb_player_win(t_server *, char *);
void				check_win(t_server *);

/*
** graphic2.c
*/

int				get_orientation(VUE);
void				send_new_player(t_client *, int);
void				send_inventaire(t_client *, int);
void				send_position(t_client *, int);

/*
** graphic_broadcast.c
*/

void				pbc(t_server *, char *, int);

/*
** graphic.c
*/

int				set_client_graphic(t_client **, int);
void				send_init_map(t_server *, int);
void				send_map(t_server *, int);
void				send_team(t_server *, int);
int				do_graphic(t_server *, char *, int);

/*
** graphic_egg.c
*/

void				enw(t_server *, t_egg *);
void				ebo(t_server *, t_egg *);
void				eht(t_server *, int);

/*
** graphic_fork.c
*/

void				pfk(t_server *, int);
void				pex(t_server *, int);

/*
** graphic_incantation.c
*/

void				pic(t_server *, int, int, int);
void				pie(t_server *, int, int);
void				plv(t_server *, int, int, int);

/*
** graphic_mort.c
*/

void				pdi(t_server *, int);
void				seg(t_server *, char *);
void				edi(t_server *, int);

/*
** graphic_prend_pose.c
*/

void				pgt(t_server *, int, int);
void				pdr(t_server *, int, int);
void				bct(t_server *, int, int);

/*
** DIR -> OTHER
*/

/*
** my_str_to_wordtab.c
*/

int				tablen(char **);
void				free_tab(char **);
int				count_word(char *, char);
char				**my_str_to_wordtab(char *, char);

/*
** return.c
*/

int				return_ok(int);
int				return_ko(int);

/*
** DIR -> SERVER
*/

/*
** init_server.c
*/

int				init_proto_sock(int *, struct sockaddr_in *, struct protoent *, int);
int				init_bind_listen(int, struct sockaddr_in);
int				init_server(t_server *);

/*
** loop.c
*/

void				check_event(t_server *);
void				del_food(t_server *);
void				check_eggs(t_server *);
int				do_select(t_server *);
void				loop_end(t_server *, t_client *);
int				loop(t_server *);

/*
** my_read.c
*/

void				my_read_s(t_server *, int);
t_client			*get_client(t_client *, int);
void				my_deconnexion(t_server *, int);
void				send_msg_c(int, char [1024], t_server *, int);
void				my_read_c(t_server *, int);

/*
** server.c
*/

int				main(int, char**);

#endif
