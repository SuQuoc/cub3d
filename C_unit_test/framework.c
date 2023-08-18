
# include "unit_tests.h"

int compare(char *output, char *expected)
{
    if (ft_strncmp(output, expected, ft_strlen(expected)) == 0)
        return (printf ("OK\n"), 1);
    else if (ft_strncmp("Valid", expected, ft_strlen(expected)) == 0) 
        return (printf ("OK\n"), 1);
    else  
        return (printf ("FAIL\n"), 0);
}

void test_framework(char *testsuite, char ***testcases, t_data *g_data)
{
    int pid = fork();
    if (pid == 0)
    {
        char output[2000];
        int tmp_fd = open("TEMP_FILE", O_CREAT | O_WRONLY | O_RDONLY, 0664);
        dup2(tmp_fd, STDERR_FILENO);
        printf("Testite (folder_path): %s\n", testsuite);

        int j = 0;
        while (testcases[j] != NULL)
        {   
            printf("Test nbr\n");
            int fd = open(ft_strjoin(testsuite, testcases[j][0]), O_RDONLY);
            if (fork() == 0)
                loop_file(fd, g_data);
            read(tmp_fd, output, 2000);
            printf("Testname: %s\n", testcases[j][0]);
            compare(output, ft_strjoin("Error\n", testcases[j][1]));
            j++;
        }
        close(tmp_fd);
        exit(0);
    }
}