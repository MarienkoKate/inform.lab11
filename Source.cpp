
#define _CRT_SECURE_NO_WARNINGS
#include < stdio.h >
#include < string.h > 
#include < stdlib.h >
#include "Header.h"       


void copy_word(char* dst, char* src, int start, int end) {

    int j = 0, k = 0;

    for (j = start; j < end; j++) {
        dst[k] = src[j];
        k++;
    }

    dst[k] = '\0';
}

void init(head* l) {
    l->head = NULL;
    l->size = 0;
}

void push_back(head* l, int val, int words_count) {

    node* n, * cur;

    n = (node*)malloc(sizeof(node));
    if (n == NULL) exit(-2);
    n->len = val; n->next = NULL; n->quantity = 0;
    n->start = 0;

    if (l->head == NULL) {

        n->prev = NULL;
        l->head = n;
        n->quantity++;
        l->size++;
        if (n->start == 0) n->start = words_count;

    }
    else {

        cur = l->head;

            while (cur->next != NULL && cur->len != val) {
                cur = cur->next;
            }
            if (cur->next == NULL && cur->len != val) {

                cur->next = n;
                n->prev = cur;
                l->size++;
                n->quantity++;
                if (n->start == 0) n->start = words_count;
                
            }
            else if (cur->len == val) {
                cur->quantity++;
            }
    }

}
void print(head* h) {

    node* n = h->head;

    while (n) {
        printf(" len %d q %d start %d\n", n->len, n->quantity, n->start);
        n = n->next;
    }

}

node* search_max_val(head* h) {

    node* cur = h->head;
    node* max_node = (node*)malloc(sizeof(node));
    node* pre_max_node = (node*)malloc(sizeof(node));
    int max = 0;
    int i = 0, q;

    while (i != h->size && cur) {

        if (cur->quantity > max) {

            max = cur->quantity;
            max_node = cur;
            cur = cur->next;
           
        }
        else if (cur->next != NULL) {
            cur = cur->next;            
        }
        i++;
    }
    q = max;
     max = -1;
     i = 0;

    //printf("max %d\n", max_node->quantity);
     cur = h->head;
    while (i != h->size && cur) {

       // printf("n\n");

        if (cur->quantity > max && cur->quantity < q) {

            max = cur->quantity;
            pre_max_node = cur;
            //pre_max_node->quantity = cur->quantity;
            cur = cur->next;
            //printf("%d \n", max);

        }
        else if (cur->next != NULL) {
            cur = cur->next;
            //printf("%d \n", pre_max_node->quantity);
        }
        i++;
    }
  
    return pre_max_node;
}


void my_swap(char** s1, char** s2) {
    char* tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int my_strcmp(int len1, int len2) {
    if (len1 > len2) return 1;
    else return -1;
}

void sort(int word_count, char** words) {

    int i = 0, j = 0, min_idx = 0;
    int n = word_count;

    for (i = 0; i < word_count; i++) {
        min_idx = i;

        for (j = i; j < n; j++) {
            if (my_strcmp(strlen(words[j]), strlen(words[min_idx])) < 0)
                min_idx = j;
        }
        my_swap(&words[i], &words[min_idx]);
    }

}

int copy_words_to_array(char* w, FILE* f, char** words, head* h) {
    int start_w = 0, i = 0, end_w = 0, in_word = 0, word_count = 0, len_word = 0, len;

    while (w[i] != 0) {

       if (fscanf(f, "%c", &w[i]) ==NULL) return -1;

        if ((w[i] >= 'a' && w[i] <= 'z') || (w[i] >= 'A' && w[i] <= 'Z')) {
            if (in_word == 0) start_w = i;
            in_word = 1;
        }
        else {
            if (in_word == 1) {

                end_w = i;
                len_word = end_w - start_w;
                words[word_count] = (char*)malloc((len_word + 1) * sizeof(char));
                copy_word(words[word_count], w, start_w, end_w);
                word_count++;

            }
            in_word = 0;
        }
        i++;
    }
    if (in_word == 1) {

        words[word_count] = (char*)malloc((end_w - start_w + 1) * sizeof(char));
        copy_word(words[word_count], w, start_w, end_w);
        len_word = end_w - start_w;
        word_count++;
    }
    return word_count;
}

void destroy(head* l) {
    node* cur = l -> head;
    node* prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur -> next;
        free(prev);
    }
}
















































