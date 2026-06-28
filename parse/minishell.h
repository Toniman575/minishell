#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_redir_type
{
	redir_none,
	redir_input,	// '<'
	redir_output,	// '>'
	redir_append,	// '>>'
	redir_heredoc,	// '<<'
} t_redir_type;

typedef enum e_operator
{
	op_none,
	op_pipe		// '|'
}	t_operator;

typedef struct s_redir
{
	t_redir_type	type;		// 
	char			*filename;  // File to open/read/write
	struct s_redir	*next;		// Next redirection, if any
}	t_redir;

typedef struct	s_cmd
{
	char		**argv;		// Args for execve
	t_redir		*redirs;	// How this cmd redirects
	t_operator	op;			// None or pipe
	t_cmd		*next;		// Next cmd
} t_cmd;
