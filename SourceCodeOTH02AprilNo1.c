#include <stdio.h>
#include <stdlib.h>

// Struktur data untuk node dalam stack
struct Node {
    char data;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(struct Node** top, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Fungsi untuk menghapus elemen dari stack
char pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Fungsi untuk mengecek apakah tanda kurung berpasangan
int isBalanced(char expr[]) {
    struct Node* stack = NULL;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(&stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (isEmpty(stack)) {
                return 0;
            }
            char popped = pop(&stack);
            if ((expr[i] == ')' && popped != '(') ||
                (expr[i] == ']' && popped != '[') ||
                (expr[i] == '}' && popped != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(stack);
}

int main() {
    char expr[100];
    printf("Masukkan urutan tanda kurung: ");
    scanf("%s", expr);
    
    if (isBalanced(expr)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
