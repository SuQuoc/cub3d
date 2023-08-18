#pragma once

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <string>
# include <mlx.h>



///////testfiles///////////////////////////////////////////
//check_extentions_tests.cpp
void	check_extension_error_tests();
void	check_extension_tests();

////////////other functions////////////////////////////////
//compare_functions.cpp
void		compare(const char *test, const int my_output, const int right_output, const char last);
void		compare(const char *test, const std::string my_output, const std::string right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf, \
					const char *test, const int my_output, const int right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf, \
					const char *test, const std::string my_output, const std::string right_output, const char last);

//tests_utils.cpp
void	    ok();
void	    fail();
std::string	get_file_content(const char *right_output_file);
void		error_tests_framework(void (*error_tests)(/* std::streambuf*, std::streambuf* */), \
				const char *my_outfile_name, const char *right_outfile_name, const char *compare_prompt);
