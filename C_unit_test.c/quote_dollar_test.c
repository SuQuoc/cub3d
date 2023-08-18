	
#include "../cubed.h"

t_data *data;

typedef struct s_test
{
	char				*test;
    char                *bash;
    char                *mini;
	struct s_test		*next;
}						t_test;

t_test	*lstlast_test(t_test *lst)
{
	t_test	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}


void	add_test_back(t_test **lst, char *test, char *bash)
{
	t_test	*last;
    t_test	*new;
    new = malloc(sizeof(t_test));
    if (new == NULL)
	    return ;
    t_node *node = create_node(test);
    char *str = ft_strdup(test);
    dollar_and_s_quotes(&str, node, data);
    //printf("%s\n", test);
    new->next = NULL;
    new->test = test;
	new->bash = bash;
    new->mini = str;
    
    if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = lstlast_test(*lst);
	last->next = new;
}

void print_test(t_test node)
{
    if (strcmp(node.bash, node.mini) == 0)
    {
        //printf("Test: %s\n", node.test);
        //printf("bash: %s\n", node.bash);
        //printf("mini: %s\n", node.mini);
        //printf("Success\n");
        return ;
    }
    else
    {
        printf("Test: %s\n", node.test);
        printf("bash: %s\n", node.bash);
        printf("mini: %s\n", node.mini);
        printf("Fail 🥲\n");
        ft_printf("-------------------------------------------\n\n");
    }

}

void	print_test_list(t_test *head)
{
	t_test	*print;

	if (!head)
		return ;
	print = head;
	
	while (print)
	{
		print_test(*print);
        print = print->next;
	}
}


int g_ex_status = 0;

void	init_data(t_data *data, char **env)
{
	data->line_read = NULL;
	data->env_copy = dup_str_arr(env);
	data->cmd_line = NULL;
	data->fd_infile = -1;
	data->fd_outfile = -1;
	data->fd_heredoc = -1;
	data->fd_pipe[0] = -1;
	data->fd_pipe[1] = -1;
	data->children = 0;
	g_ex_status = 0;
	data->red_status = 0;
	data->problem = 0;
	signal_set_up(data);
}


void test_framwork(char *testsuite, char *testpath)
{
   



}

int main(int argc, char **argv, char **env)
{
    if (argc != 1 || argv[0] == NULL)
	    return (1);
    data = malloc(sizeof(t_data));
    init_data(data, env);
    t_test *head = NULL;
    


     int tmp_fd = open(O_RDONLY)) 

    //string array test
    char test [][2][1000] = 
    {
        {"filename" , "Error message"},

    };

    printf("Core dump?\n");

    unsigned long j = 0;
    while (j < sizeof(test) / sizeof(test[0]))
    {        
        add_test_back
        (   &head, 
            test[j][0],
            test[j][1]
        );
        j++;
    }

    //Quotes
    add_test_back
    (   &head, 
        "\"$'user\"",
        "$'user"   
    );
    
    add_test_back
    (   &head, 
        "\"01'$USER'SHIT $USER$USER'''$'user\"",
        "01'qtran'SHIT qtranqtran'''$'user"   
    );

    add_test_back
    (   &head, 
        "\"text$\"text",
        "text$text"
    );
    

    //
    add_test_back
    (   &head, 
        "text'$'",
        "text$"   
    );
    
    add_test_back
    (   &head, 
        "text$",
        "text$"   
    );

    add_test_back
    (   &head, 
        "$USER'$' space",
        "qtran$ space"   
    );

    //closed quotes directly after
    add_test_back
    (   &head, 
        "(text$\"USER\")",
        "(textUSER)"   
    );

    add_test_back
    (   &head, 
        "(text$'USER')",
        "(textUSER)"   
    );

    add_test_back
    (   &head, 
        "(\"text$'USER\")",
        "(text$'USER)"   
    );
    
    add_test_back
    (   &head, 
        "(\"text$USER'USER'\")",
        "(textqtran'USER')"   
    );

    
    
    
   
    //closed single quotes directly after but in double quotes
    add_test_back
    (   &head,
        "(\"text$'USER'\")",
        "(text$'USER')"
    );

    //closed double quotes in $ sign 
    add_test_back
    (   &head,
        "(\"text$\"USER)",
        "(text$USER)"
    );

    //unclosed quotes
    add_test_back
    (   &head, 
        "text$USER\"",
        "text"
    );
    add_test_back
    (   &head,
        "text$USER\"three\"quo\"tes",
        "textqtranthreequo\"tes"
    );

    add_test_back
    (   &head,
        "text$USER\"NAME\"",
        "textqtranNAME"  
    );

    add_test_back
    (   &head,
        "text$USER>name",
        "textqtran>name"
    );

     add_test_back
    (   &head,
        "text$USER name",
        "textqtran name"
    );

    add_test_back
    (   &head,
        "text\"$USER\"",
        "textqtran"
    );

    add_test_back
    (   &head,
        "text$USER\"NAME\"",
        "textqtranNAME"
    );

    add_test_back
    (   &head,
        "text\"$USER",
        "text\"qtran"
    );

    add_test_back
    (   &head,
        "$USER\"",
        ""
    );

    //$ sign and special instant afterwards
    add_test_back
    (   &head,
        "$\"\"",
        ""
    );

    add_test_back
    (   &head,
        "text$|text",
        "text$|text"
    );

    add_test_back
    (   &head,
        "text$<text",
        "text$<text"
    );

    add_test_back
    (   &head,
        "text$>>text",
        "text$>>text"
    );
    //special not instant afterwards
    add_test_back
    (   &head,
        "(text$USER|xt)",
        "(textqtran|xt)"
    );

    add_test_back
    (   &head,
        "(text$USER>>xt)",
        "(textqtran>>xt)"
    );
    
    //EXIT STATUS AKA $?
    add_test_back
    (   &head,
        "text$?\"exit-status",
        "text1234\"exit-status"
    );
    
    add_test_back
    (   &head,
        "(text$USER?text\")",
        "(textqtran?text\")"
    );

    add_test_back
    (   &head,
        "text$'?text",
        "text?text"
    );
    add_test_back
    (   &head,
        "text$non?text",
        "text?text"
    );

    add_test_back
    (   &head,
        "'text$?text'",
        "text$?text"
    );

    add_test_back
    (   &head,
        "(\"text$?text\")",
        "(text1234text)"
    );

    //print_test_list(head);
    return 0;
}
