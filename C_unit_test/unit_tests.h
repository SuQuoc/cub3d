# ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#include "../cubed.h"

int compare(char *output, char *expected);
void test_framework(char *testsuite, char testcases[][2][1000]);

#define TMPFILE "tmpfile"
#define BUF_SIZE 2000


# endif
