#!/bin/bash

echo ""
echo "==========================================" 
echo "=========== STDIN & LEAK TEST ============" 
echo "==========================================" 
echo ""
echo "Type a long line (more than 42 char), type ENTER, type a short line, type ENTER"
echo "Open an other terminal page and type the command 'leaks a.out'"
echo "The last line should say '0 leaks for 0 total leaked bytes.'"
echo "Come back to this terminal and type Ctrl + D"
echo "This should close the test"
echo ""
gcc -Wall -Werror -Wextra ./gnl_tester_stdin.c ./get_next_line_2.c -I ./ && ./a.out
