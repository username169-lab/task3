#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <func.h>

static char **lst;
static int sizelist;
static int curlist;

static char *buf;
static int sizebuf;
static int maxlen;
static int curbuf;

void init_list() {
    sizelist = 0;
    curlist = 0;
    lst = NULL;
}

void clear_list() {
    int i;
    sizelist = 0;
    curlist = 0;
    if (lst == NULL) return;
    for (i = 0; lst[i] != NULL; i++)
        free(lst[i]);
    free(lst);
    lst = NULL;
}

void term_list() {
    if (lst == NULL) return;

    char **tmp;
    if (curlist > sizelist - 1) {
        tmp = realloc(lst, (sizelist + 1)*sizeof(*lst));
        if (tmp != NULL)
            lst = tmp;
        else
            /* ERROR */;
    }

    lst[curlist] = NULL;

    tmp = realloc(lst, (sizelist = curlist + 1)*sizeof(*lst));
    if (tmp != NULL)
        lst = tmp;
    else
        /* ERROR */;
}

void init_buf() {
    buf = NULL;
    sizebuf = 0;
    curbuf = 0;
}

void add_sym(int c) {
    char *tmp;
    if (curbuf > sizebuf - 1) {
        tmp = realloc(buf, (sizebuf += SIZE)*sizeof(char));
        if (tmp != NULL)
            buf = tmp;
        else
            /* ERROR */;
    }

    buf[curbuf++] = c;
}

void add_word() {
    char *tmp;
    if (curbuf > sizebuf - 1) {
        tmp = realloc(buf, (sizebuf + 1)*sizeof(char));
        if (tmp != NULL)
            buf = tmp;
        else
            /* ERROR */;
    }

    buf[curbuf] = '\0';

    tmp = realloc(buf, (sizebuf = curbuf + 1)*sizeof(char));
    if (tmp != NULL)
        buf = tmp;
    else
        /* ERROR */;
    if (sizebuf > maxlen)
        maxlen = sizebuf;
    
    char **ptr;
    if (curlist > sizelist - 1) {
        ptr = realloc(lst, (sizelist += SIZE)*sizeof(*lst));
        if (ptr != NULL)
            lst = ptr;
        else
            /* ERROR */;
    }
    lst[curlist++] = buf;
}

void print_list() {
    if (lst == NULL) return;

    int i;
    printf("%d\n", sizelist - 1);
    for (i = 0; i < sizelist - 1; i++)
        printf("%s\n", lst[i]);
}

int sym_set(int c) {
    return c != '\n' && c != ' ' && c != '\t' && c != EOF &&
        c != ';' && c != '<' && c != '(' && c != ')' && 
        c != '|' && c != '&' && c != '>';
}

void sort() {
    if (lst == NULL) return;
    
    printf("Sorting...\n");
    int i, j;
    char *tmp;
    for (i = 1; i < sizelist - 1; i++) {
        tmp = lst[i];
        for (j = i; j > 0 && strncmp(lst[j - 1], tmp, maxlen) > 0; j--)
            lst[j] = lst[j - 1];
        lst[j] = tmp;
    }
}





















