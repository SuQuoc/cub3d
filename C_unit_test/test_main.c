
# include "unit_tests.h"


void test_extension(char *testsuite, char testcases[][2][1000])
{
    int pid = fork();
    if (pid == 0)
    {
        printf("\n");
        printf("\033[1;34mTestsuite (folder_path): %s\033[0m\n", testsuite);
        int j = 0;
        while (strcmp("", testcases[j][0]) != 0)
        {   
            char *output = (char*)malloc(BUF_SIZE + 1);
            int tmp_fd = open("TEMP_FILE", O_CREAT | O_TRUNC | O_WRONLY, 0664);
            dup2(tmp_fd, STDERR_FILENO);
            check_extension(ft_strjoin(testsuite, testcases[j][0]));
            close(tmp_fd);
            tmp_fd = open("TEMP_FILE", O_RDONLY);
            read(tmp_fd, output, BUF_SIZE);
            printf("\033[1mTestname: %s\033[0m    ", testcases[j][0]);
            compare(output, testcases[j][1]);
            close(tmp_fd);
            free(output);
            j++;
        }
        exit(0);
    }
    waitpid(pid, NULL, WUNTRACED);
}


int main()
{  
    //extension_tests
    char extension [][2][1000] = 
    {
        {"double_extension.cub.cub"     , ""},
        {"./double_extension.cub.cub"   , ""},
        {"doesnt_exist.cub"             , "Wrong file type/extension!\n"},
        {"file_cub"                     , "Wrong file type/extension!\n"},
        {"invalid_extension_cub"        , "Wrong file type/extension!\n"},
        {"'dumb space.cub'"             , "Wrong file type/extension!\n"},
        {"invalid_extension.cu"         , "Wrong file type/extension!\n"},
        {"", ""}
    };
    test_extension("../maps/extension_tests/", extension);



    //identifier_tests
    char identifier_tests [][2][1000] = 
    {
        {"different_identifier_order.cub"           , ""},
        {"no_newline_between_identifiers.cub"       , ""},
        {"spaces_and_tabs_after_identifier.cub"     , ""},
        {"identifier_after_map_content.cub"         , "Invalid identifier!\n"},
        {"invalid_floor_identifier.cub"             , "Invalid identifier!\n"},
        {"invalid_orientation_identifier.cub"       , "Invalid identifier!\n"},
        {"missing_floor.cub"                        , "Invalid identifier!\n"},
        {"missing_west_identifier.cub"              , "Invalid identifier!\n"},
        {"no_ceiling_identifier.cub"                , "Invalid identifier!\n"},
        {"spaces_tabs_after_before_identifier.cub"  , "Invalid identifier!\n"},
        {"missing_west_texture.cub"                 , "Invalid identifier!\n"},
        {"double_identifier.cub"                    , "Each identifier only allowed once!\n"},
        {"three_floors.cub"                         , "Each identifier only allowed once!\n"},
        {"invalid_texture.cub"                      , "Invalid texture path or no rights!\n"},
        {"last_is_double_with_nl.cub"               , "Consecutive nl in map content! Map content begins when every IDF was found!\n"},
        {"", ""}
    };
    test_framework("../maps/identifier_tests/", identifier_tests);

    //rgb_tests
    char rgb [][2][1000] = 
    {
        {"incomplete_rgb.cub"           , "Invalid amount of rgb values!\n"},
        {"invalid_256_rgb_range.cub"    , "Invalid rgb range!\n"},
        {"invalid_rgb_range.cub"        , "Invalid rgb range!\n"},
        {"negative_rgb_range.cub"       , "Invalid rgb range!\n"},
        {"valid_rgb_range.cub"          , ""},
        {"", ""},
    };
    test_framework("../maps/rgb_tests/", rgb);



    
    
    return 0;
}
