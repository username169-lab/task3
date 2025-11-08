# task3

## Using L-graph technique to implement reading from input file and transforming the data.
File main.c defines interface for walking through an L-graph.
File list.c defines structures and functions to work with a list.
File get.c defines functions to read from input file.
File func.h declares functions from list.c andd get.c.

##task3.c
void *start(); - start node
void *word(); - word node
void *pipe1(); - node with symbol '|'
void *aper1(); - node with symbol '&'
void *greater1(); - node with symbol '>'
void *spec(); - node with special word
void *newline(); - newline node
void *stop(); - stop node

int c - global variable.

##list.c
The list is implemented through array structure.
void init_list() - initializes a list
void clear_list() - clears the list
void term_list() - terminates the list
void init_buf() - initializes a buffer word
void add_sym(int c) - adds a symbol to the buffer word
void add_word() - adds a word to the list
void print_list() - prints the list
int sym_set(int c) - check if c is a special symbol
void sort() - insertion sort

##get.c
get_sym() - returns read symbol

##func.h
int get_sym();
void init_list();
void clear_list();
void term_list();
void init_buf();
void add_sym(int);
void add_word();
void print_list();
int sym_set(int);
void sort();
