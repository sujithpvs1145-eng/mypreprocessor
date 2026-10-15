#ifndef OPERATION_H
#define OPERATION_H

void *read_file(char *line, FILE *src);
void write_file(char ch, FILE *dest);
void comment_remove(FILE *src, FILE *dest);
void insert_header(char*name);
void macro_handling(char*name);

#endif
