
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
            int bytes = read(tmp_fd, output, BUF_SIZE);
            output[bytes] = '\0';
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
        {"cub.cub"                      , "Valid"},
        {".cub"                         , "No hidden files or 'rel-rel-paths'\n"},
        {"cu"                           , "Wrong file type/extension!\n"},
        {"valid.cub"                    , "Valid"},
        {"double_extension.cub.cub"     , "Valid"},
        {"./double_extension.cub.cub"   , "No hidden files or 'rel-rel-paths'\n"},
        {"doesnt_exist.cub"             , "U have to CHECK OPEN ALSO! Tomorrow\n"},
        {"file_cub"                     , "Wrong file type/extension!\n"},
        {"invalid_extension_cub"        , "Wrong file type/extension!\n"},
        {"'dumb space.cub'"             , "Wrong file type/extension!\n"},
        {"invalid_extension.cu"         , "Wrong file type/extension!\n"},
        {"", ""}
    };
    test_extension("", extension);

    //identifier_tests
    char identifier_tests [][2][1000] = 
    {
        {"different_identifier_order.cub"           , "Valid"},
        {"no_newline_between_identifiers.cub"       , "Valid"},
        {"spaces_before_identifier.cub"             , "Invalid identifier!\n"},
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
        {"last_is_double_with_nl.cub"               , "Invalid map_content!\n"},
        {"", ""}
    };
    test_framework("../maps/identifier_tests/", identifier_tests);

    //rgb_tests
    char rgb [][2][1000] = 
    {
        {"valid_rgb_range.cub"          , "Valid"},
        {"incomplete_rgb.cub"           , "Invalid amount of rgb values!\n"},
        {"invalid_256_rgb_range.cub"    , "Invalid rgb range!\n"},
        {"overflow_rgb_range.cub"       , "Invalid rgb range!\n"},
        {"negative_rgb_range.cub"       , "Invalid rgb format! Example: C 10,20,30"},
        {"iv_rgb_input.cub"             , "Invalid rgb format! Example: C 10,20,30"},
        {"rgb_format.cub"               , "Invalid rgb format! Example: C 10,20,30"},
        {"rgb_format2.cub"              , "Invalid rgb format! Example: C 10,20,30"},
        {"", ""},
    };
    test_framework("../maps/rgb_tests/", rgb);


    //map_test
    char map_test [][2][1000] = 
    {
		{"diagonals.cub"                            	, "Valid"},
		{"inner_circle_with_space_and_pillar.cub"		, "Make sure theres only 1 map and no 'flying' walls!\n"},
        {"inner_circle_with_space_and_pillar2.cub"		, "Make sure theres only 1 map and no 'flying' walls!\n"},	
        {"inner_circle_with_space_and_pillar3.cub"		, "Make sure theres only 1 map and no 'flying' walls!\n"},
        {"inner_circle_with_zero_and_pillar.cub"		, "Valid"},	
        {"inner_pillar_axis_connected.cub"		        , "Valid"},
		{"inner_pillar_diagonal_connected.cub"		    , "Make sure theres only 1 map and no 'flying' walls!\n"},
        {"inner_unlcosed_edges_spaces.cub"				, "map not closed by walls!\n"},
		{"inner_unlcosed_edges_zero.cub"				, "Valid"},
		{"inner_walls_disconnected_from_outer.cub"		, "Valid"},
		{"nl_in_map_content.cub"						, "Consecutive nl in map! Map begins when all IDF were found!\n"},
		{"no_map_content_except_player.cub"             , "Invalid map_content!\n"},
        {"no_map_content.cub"							, "Invalid map_content!\n"},
		{"no_newline_between_identifier_and_map.cub"	, "Valid"},
		{"only_space_line.cub"							, "Make sure theres only 1 map and no 'flying' walls!\n"},
        {"player_in_corner_wout_edge.cub"				, "Invalid player position!\n"},
        {"player_in_corner_wout_edge2.cub"				, "Invalid player position!\n"},
        {"player_in_outer_wall.cub" 					, "Invalid player position!\n"},
        {"player_touches_space.cub" 					, "Invalid player position!\n"},
        {"separated_map_vertically.cub"					, "Make sure theres only 1 map and no 'flying' walls!\n"},
		{"spaces_left_from_map.cub"						, "Valid"},
		{"text_after_map_content_wi_nl.cub"				, "Consecutive nl in map! Map begins when all IDF were found!\n"},	
		{"text_after_map_content_wout_nl.cub"			, "Invalid map_content!\n"},	
		{"unclosed_wall2.cub"							, "map not closed by walls!\n"},
		{"unclosed_wall.cub"							, "map not closed by walls!\n"},
		{"unknown_char_x_in_map_content.cub"			, "Invalid map_content!\n"},		
		{"unlcosed_edges_space.cub"						, "map not closed by walls!\n"},
		{"unlcosed_edges_zero.cub"						, "map not closed by walls!"},	
		{"wall_outside_map.cub"							, "Make sure theres only 1 map and no 'flying' walls!\n"},
		{"zero_in_bot_line.cub"							, "map not closed by walls!\n"},
		{"zero_in_top_line.cub"							, "map not closed by walls!\n"},
		{"zero_left_side.cub"							, "map not closed by walls!\n"},
        {"zero_right_of_outer_wall.cub"					, "map not closed by walls!\n"},
        {"zero_right_side.cub"							, "map not closed by walls!\n"},
        {"", ""},
    };
    test_framework("../maps/map_content_tests/", map_test);
    
    
    return 0;
}



















