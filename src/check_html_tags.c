
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    char *items[MAX];
    int top;
} Stack;

// Initialize the stack
static void initStack(Stack *s) { s->top = -1; }

// Check if the stack is empty
static int isEmpty(Stack *s) { return s->top == -1; }

// Push an element onto the stack
static void push(Stack *s, char *item) {
    if (s->top == MAX - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Pop an element from the stack
static char *pop(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->items[(s->top)--];
}

// Get the top element of the stack
static char *peek(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->items[s->top];
}

// Extract just the tag name (up to space or end). Modifies in place.
static void stripToTagName(char *tag) {
    for (char *p = tag; *p; ++p) {
        if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '/') {
            *p = '\0';
            break;
        }
    }
}

// Check if the opening and closing tags match
static int isMatchingTag(char *openTag, char *closeTag) {
    // closeTag is expected like "/div" or "/p ..."
    if (closeTag[0] != '/') return 0;
    char buf[128];
    strncpy(buf, closeTag + 1, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    stripToTagName(buf);
    return strcmp(openTag, buf) == 0;
}

// Check if HTML tags are balanced
static int checkHTMLTags(const char *html) {
    Stack stack;
    initStack(&stack);

    char tag[256];
    size_t i = 0, j, n = strlen(html);

    while (i < n) {
        if (html[i] == '<') {  // Found a tag
            j = 0;
            i++;
            while (i < n && html[i] != '>' && j + 1 < sizeof(tag)) {
                tag[j++] = html[i++];
            }
            tag[j] = '\0';

            if (tag[0] == '\0') { i++; continue; }

            if (tag[0] != '/') {  // Opening tag
                stripToTagName(tag);
                // strdup is POSIX; on MSVC use _strdup
                #ifdef _MSC_VER
                char *dup = _strdup(tag);
                #else
                char *dup = strdup(tag);
                #endif
                if (!dup) { fprintf(stderr, "Out of memory\n"); return 0; }
                push(&stack, dup);
            } else {  // Closing tag
                char *topTag = pop(&stack);
                if (topTag == NULL || !isMatchingTag(topTag, tag)) {
                    if (topTag) free(topTag);
                    return 0;  // Tags are not balanced
                }
                free(topTag);  // Free memory allocated by strdup
            }
        }
        i++;
    }

    // If any unclosed tags remain, not balanced
    int balanced = isEmpty(&stack);
    // Free any leftovers to be tidy
    while (!isEmpty(&stack)) {
        free(pop(&stack));
    }
    return balanced;
}

int main(void) {
    // Read entire stdin into a buffer
    char *buf = NULL;
    size_t cap = 0, len = 0;
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        if (len + 1 >= cap) {
            size_t newcap = cap ? cap * 2 : 4096;
            char *tmp = (char *)realloc(buf, newcap);
            if (!tmp) { fprintf(stderr, "Out of memory\n"); free(buf); return 1; }
            buf = tmp; cap = newcap;
        }
        buf[len++] = (char)c;
    }
    if (!buf) {
        fprintf(stderr, "No input provided. Paste HTML or redirect a file.\n");
        return 1;
    }
    buf[len] = '\0';

    if (checkHTMLTags(buf)) {
        printf("HTML tags are balanced!\\n");
    } else {
        printf("HTML tags are not balanced!\\n");
    }

    free(buf);
    return 0;
}
