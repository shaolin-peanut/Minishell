cmake_minimum_required(VERSION 3.16)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell_main
        src/main.c
        src/built_in/built_in.c
        src/built_in/built_in_exe.c
        src/built_in/export.c
        src/execution/access.c
        src/execution/bin_exe.c
        src/execution/execution.c
        src/execution/get.c
        src/execution/status.c
        src/execution/variable.c
        src/is/is_redirection.c
        src/is/is_token.c
        src/parser/basic_char_checks.c
        src/parser/cmd_path_check.c
        src/parser/compound_char_checks.c
        src/parser/create_tokens.c
        src/parser/heredoc.c
        src/parser/operators_checks.c
        src/parser/parser.c
        src/parser/processing.c
        src/parser/prompt.c
        src/parser/quotes.c
        src/parser/testing.c
        src/parser/token_init.c
        src/parser/tokenizer.c
        src/parser/variables.c
        src/parser/word_processing.c
        src/processing/bin_processing.c
        src/processing/processing_built.c
        src/processing/processing_cmd.c
        src/processing/processing_redirection.c
        src/processing/variable_value.c
        src/redirection/close.c
        src/redirection/heredoc.c
        src/redirection/manage_redirection.c
        src/redirection/redirect.c
        src/shell_subsystems/environment_variables.c
        src/utils/build_argv.c
        src/utils/error.c
        src/utils/init_structs.c
        src/utils/list_utils.c
        src/utils/memory.c
        src/utils/parser_utils.c)

target_include_directories(minishell_main PRIVATE include)
target_include_directories(minishell_main PRIVATE libft/inc)

target_link_libraries(minishell_main ${CMAKE_SOURCE_DIR}/libft/libft.a)

target_link_libraries(minishell_main readline)
