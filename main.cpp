#define _CRT_SECURE_NO_WARNINGS
#include < stdio.h >
#include < string.h > 
#include < stdlib.h >
#include "Header.h"  


int main() {
    char w[256];

    head h;
    init(&h);

    int i = 0, in_word = 0, start_w = 0, end_w = 0, word_count = 0;
    char* words[256];

    FILE* f = fopen("file.txt", "rt");
    if (f == NULL) { return -3; }

    while (!feof(f)) {

        word_count = copy_words_to_array(w, f, words, &h);

    }

    sort(word_count, words);

    for (i = 0; i != word_count; i++) {
        push_back(&h, strlen(words[i]), i);

    }


    node* n = search_max_val(&h);


    for (i = n->start; i != n->start + n->quantity; i++) {
        printf("%s\n", words[i]);
    }
    print(&h);
    destroy(&h);
    free(*words);
}