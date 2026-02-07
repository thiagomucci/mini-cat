# mini-cat

A minimal implementation of the Unix cat utility, writted in C using
low-level POSIX system calls

This project is part of a personal study of the book Advanced Programming in the UNIX Environment (APUE),
focusing on file descriptors, openat, read, write, and proper error handling

## Features
- Opens directories and files using open and openat
- Reads files using read
- Writes output using write
- Proper error handling with perror
- No use of stdio (fopen, fgets, etc)

## Build

Compile using a POSIX-compliant C compiler: cc -Wall -Wextra -pedantic mini-cat.c -o mini-cat

## Usage
./mini-cat directory file

Example: ./mini-cat . README.md

## References
W. Richard Stevens, Advanced Programming in the UNIX Environment
