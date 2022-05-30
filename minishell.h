#ifndef MINISHELL_H
#define MINISHELL_H

//################# INC #################

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

//########### Global_variable ###########

t_info  info;

//################# STR #################

typedef struct s_info
{
	char    **av;
    t_envp  *envp;
}t_info;

typedef struct s_envp
{
    size_t          order;
    char            *variable;
    char            *val;
    struct s_envp   *next;
}t_envp;

//################# FUN #################

/*~~~~~~~~~~~ pars_envp ~~~~~~~~~~~*/
int     envp_to_lst(char **envp);
void    list_add_back_envp(t_envp *envp, t_envp *new);
t_envp  list_new_envp(char *envp);
size_t  size_list(void);
char    *get_var_envp(char *envp);
char    *get_val_envp(char *envp);
char    *get_val_shlvl(char *envp);
// drop in Libft from ..\minishell\utils_envp.c
int     ft_strcmp(char *s1, char *s2);
//





#endif