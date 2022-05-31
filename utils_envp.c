#include "minishell.h"

size_t  size_list(void)
{
    t_envp  *lst;
    size_t  count;

    count = 0;
    lst = info.envp;
    while (lst->next)
    {
        count++;
        lst = lst->next;
    }
    return (count);
}

t_envp  list_new_envp(char *envp)
{
    t_envp  *list;

    list = malloc(sizeof(t_envp));
    if (!list)
        return (NULL);
    list->order = size_list() + 1;
    list->variable = get_var_envp(envp);
    if (!ft_strcmp(list->variable, 'SHLVL'))
        list->val = get_val_shlvl(envp);
    else
        list->val = get_val_envp(envp);
    list->next = NULL;
    return (list);
}

void  list_add_back_envp(t_envp *envp, t_envp *new)
{
    t_envp  *list;
    if (!new)
        return (0);
    if (!envp)
    {
        envp = new;
        return (0);
    }
    while (list)
        list = list->next;
    list->next = new;
}