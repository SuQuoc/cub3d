#include "tests.hpp"
#include "../cubed.h"

void	check_extension_tests()
{
	compare("check_extension_tests:", check_extension("abc.cub"), 0, 'n');
	compare(NULL, check_extension((char*)".cub"), 1, 'n');
	compare(NULL, check_extension((char*)"cub"), 1, 'n');
	compare(NULL, check_extension((char*)"cub.cub"), 0, 'y');
}


void	check_extension_error_tests()
{
	error_tests_framework(&check_extension_tests, "my_output/check_extension.txt", \
									"right_output/check_extension.txt", "error-messages:");
}