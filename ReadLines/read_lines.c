
#include "read_lines.h"

void read_lines(FILE *fp, char ***lines, int *num_lines) {
    char* line = read_line(fp);
    while(!feof(fp)){
        *num_lines += 1;
        push_back(lines, num_lines, &line);
        line = read_line(fp);

    }

}

void push_back(char*** lines, const int* len, char** line){
    *lines  = realloc(*lines, (*len) * sizeof(**lines));
    (*lines)[*len-1] = *line;
}

void push_back_C(char** array, const int* len, char val){
    *array = realloc(*array, (*len) * sizeof(**array));

(*array)[*len-1] = val;
}


char *read_line(FILE *fp) {
    char cur_char;
    int size = 1;
    char* line = NULL;
    fscanf(fp, "%c", &cur_char);

    while(!feof(fp)){

        push_back_C(&line, &size, cur_char);
        size++;

        if(cur_char == '\n'){
            break;
        }
        fscanf(fp, "%c", &cur_char);

    }
    if(line){
        push_back_C(&line, &size, '\0');

    }

    return line;
}
