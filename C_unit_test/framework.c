
# include "unit_tests.h"

void ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_data(data);
}


int compare(char *output, char *expected)
{
    if (ft_strncmp(&output[6], expected, ft_strlen(expected)) == 0)
        return (printf ("\033[0;92m OK\033[0m\n"), 1);
    else 
    {
        printf ("\033[0;91m FAIL\033[0m\n"),
        printf("Output: %s\n", &output[6]);
        printf("Expect: %s\n", expected);
        return (0);
    }
}

void test_framework(char *testsuite, char testcases[][2][1000])
{
    int pid = fork();
    if (pid == 0)
    {
        printf("\n");
        printf("\033[1;34mTestsuite (folder_path): %s\033[0m\n", testsuite);
        int j = 0;
        while (strcmp("", testcases[j][0]) != 0)
        {   
            char *output = (char*)malloc(BUF_SIZE + 1);;
            int fd = open(ft_strjoin(testsuite, testcases[j][0]), O_RDONLY);
            int cpid = fork();
            int tmp_fd = open("TEMP_FILE", O_CREAT | O_TRUNC | O_WRONLY, 0664);
            if (cpid == 0)
            {
                t_data *g_data = init_data();
                ft_mlx_init(g_data);
                dup2(tmp_fd, STDERR_FILENO);
                loop_file(fd, g_data);
                exit(0);
            }
            waitpid(cpid, NULL, WUNTRACED);
            close(fd);
            tmp_fd = open("TEMP_FILE", O_RDONLY);
            read(tmp_fd, output, BUF_SIZE);
            //printf("OUTPUT: %s\n", output);
            printf("\033[1mTestname: %s\033[0m    ", testcases[j][0]);
            compare(output, testcases[j][1]);
            close(tmp_fd);
            close(fd);
            free(output);
            j++;
        }
        exit(0);
    }
    waitpid(pid, NULL, WUNTRACED);
}
