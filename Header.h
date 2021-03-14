#ifndef C_H
#define C_H

typedef struct node {
    int quantity;
    int len;
    int start;
    struct node* next;
    struct node* prev;
} node;


typedef struct head {
    node* head;
    size_t size;
} head;

void copy_word(char* dst, char* src, int start, int end);
void init(head* l);
void push_back(head* l, int val, int words_count);
void print(head* h);
node* search_max_val(head* h);
void my_swap(char** s1, char** s2);
int my_strcmp(int len1, int len2);
void sort(int word_count, char** words);
int copy_words_to_array(char* w, FILE* f, char** words, head* h);
void destroy(head* l);

#endif