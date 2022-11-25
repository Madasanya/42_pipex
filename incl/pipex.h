/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mamuller <mamuller@student.42wolfsburg>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/02 14:38:59 by mamuller		  #+#	#+#			 */
/*   Updated: 2021/12/02 14:38:59 by mamuller		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/incl/libft.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_content
{
	char	**cmd_n_flags;
	char	*path;
	int		index;
}	t_content;

/*exit_handler.c*/
void	ft_close_fd(void);
void	ft_free_split(char **split);
void	ft_free_list(t_list *head);
void	ft_exit_on_error(t_list **cmd_list, char *error_msg);
void	ft_exit_on_invalid_cmd(char **path_list, t_list **cmd_list, \
		t_content *content, t_list *elem);

/*helper.c*/
void	ft_make_cmd_list(char **argv, char **envp, int argc, t_list **cmd_list);
char	*ft_get_cmd_path(const char *cmd, char **path_list);
char	**ft_split_path(char **env);
char	*ft_strjoin_with_free(char *s1, char const *s2);

/*piping.c*/
void	ft_pipex(int argc, char **argv, t_list *cmd_list, char **envp);
void	ft_initialize_fds(int *fd, int argc, char **argv, t_list *cmd_list);
void	ft_execute_child_process(t_list *cmd_list, char **envp, int *fd);
void	ft_execute_parent_process(int pid, int *fd, t_list **cmd_list);
void	ft_execute_last_cmd(pid_t pid, t_list *cmd_list, char **envp);

/*pipex.c*/
int		main(int argc, char **argv, char **envp);
void	ft_check_input_file(char *filename, char *outputfile);
void	ft_check_output_file(const char *filename);
char	*ft_check_cmd_path(char **path, char **split, int j, const char *cmd);

#endif