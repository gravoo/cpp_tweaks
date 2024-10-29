# SIGSEGV ISSUE
## Root cause
- In adaptive_huffman_code I have detected SIGSEGV on first run of compiled binary
- After gdb investigation dereferencing argv[1] was causing fault

## NOTES
- SIGSEGV is a signal sended by kernel into process
- envp yet another tab that can be passes in main function for accessing shell variables

## HOW TO GENERATE SIGSEGV
- by dereferencing NULL pointer
- by dereferencing deleted pointer(may generate) 
- by double deleting pointer
- by accessing tab out of range(may generate)

## HOW TO PREVENT SIGSEGV
- add -fsanitize=address into compile option to detect double delete problem
- use valgrind --tool=memcheck to detect double delete problem
- add -fsanitize=bound into compile option to detect out of bound access
- use cppcheck -enable=all to detect out of bound 
- use RAII and remember to implement copy constructor/assignemnt for dynamic memory

## HOW TO HANDLE SIGSEGV
- easy gdb step by step with g++ -g option
- analize coredump in gdb 
- for ubuntu cool tool is coredumpctl(systemd-coredump)
- SIGSEGV can be handled by adding signal handler

## Summarry
- argc is tab for argument count passing into program, default is 1 as first element is name of binary
- argv tab is having all arguments that are passed into program, ended up by 0
- accessing argv[1] with no argument passing is causing SIGSEGV