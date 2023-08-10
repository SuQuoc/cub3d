#include "tests.hpp"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ok()
{
	std::cout << "\033[0;92m OK\033[0m";
}

void	fail()
{
	std::cout << "\033[0;91m FAIL\033[0m";
}

std::string	get_file_content(const char *right_output_file)
{
	std::ifstream	infile(right_output_file, std::ios::in);
	std::string		right_output;
	std::string		buf;

	if (!infile.is_open())
	{
		std::cerr << "Error: file '" << right_output_file << "' could not be opened" << std::endl;
		infile.close();
		std::exit (1);
	}
	while (getline(infile, buf))
	{
		right_output += buf + "\n";
	}
	infile.close();
	return (right_output);
}

void	error_tests_framework(void (*error_tests)(/* std::streambuf*, std::streambuf* */), \
			const char *my_outfile_name, const char *right_outfile_name, const char *compare_prompt)
{
	std::string		right_output;
	std::string		my_output;
	int				cerrbuf;
	int				filebuf;
	
	filebuf = open(my_outfile_name, O_RDONLY | O_CREAT);
	if (!filebuf)
	{
		std::cerr << "Error: could not open file '" << my_outfile_name << \
			"'. Please check if there is a 'my_output' folder in tests. If not, create one" << std::endl;
		std::exit (1);
	}
	
	cerrbuf = dup(2);
	dup2(filebuf, 2);
	close(filebuf);

	error_tests(/* filebuf, cerrbuf */);
	
	close(2);
	dup2(2, cerrbuf);

	right_output = get_file_content(right_outfile_name);
	my_output = get_file_content(my_outfile_name);
	compare(compare_prompt, my_output, right_output, 'y');
}
/* 
void	error_tests_framework(void (*error_tests)( std::streambuf*, std::streambuf* ), \
			const char *my_outfile_name, const char *right_outfile_name, const char *compare_prompt)
{
	std::streambuf	*filebuf;
	std::streambuf	*cerrbuf;
	std::ofstream	outfile;
	std::string		right_output;
	std::string		my_output;
	
	outfile.open(my_outfile_name, std::ofstream::out);
	if (!outfile)
	{
		std::cerr << "Error: could not open file '" << my_outfile_name << \
			"'. Please check if there is a 'my_output' folder in tests. If not, create one" << std::endl;
		std::exit (1);
	}
	cerrbuf = std::cerr.rdbuf();
	filebuf = outfile.rdbuf();
 
	std::cerr.rdbuf(filebuf);
	error_tests( filebuf, cerrbuf );
	std::cerr.rdbuf(cerrbuf);
	outfile.close();

	right_output = get_file_content(right_outfile_name);
	my_output = get_file_content(my_outfile_name);
	compare(compare_prompt, my_output, right_output, 'y');
} */
