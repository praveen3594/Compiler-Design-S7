#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void input();
void output();
void change(int p, char *res);
void constant();

struct expr {
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];

int n;

int main() {
    input();
    constant();
    output();
    return 0;
}

void input() {
    int i;
    printf("\n\nEnter the maximum number of expressions: ");
    scanf("%d", &n);
    printf("\nEnter the input (operator operand1 operand2 result): \n");
    for (i = 0; i < n; i++) {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;
    }
}

void constant() {
    int i;
    int op1, op2, res;
    char op, res1[5];

    for (i = 0; i < n; i++) {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0) {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];

            switch (op) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    if (op2 != 0) {
                        res = op1 / op2;
                    } else {
                        printf("Division by zero error in expression %s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
                        continue; // Skip this expression
                    }
                    break;
                case '=':
                    res = op1;
                    break;
                default:
                    continue; // Invalid operator
            }
            sprintf(res1, "%d", res);
            arr[i].flag = 1; 
            change(i, res1);
        }
    }
}

void output() {
    int i = 0;
    printf("\nOptimized code is: ");
    int hasOutput = 0;

    for (i = 0; i < n; i++) {
        if (!arr[i].flag) {
            printf("\n%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
            hasOutput = 1;
        }
    }
    if (!hasOutput) {
        printf("No expressions remaining after optimization.\n");
    }
}

void change(int p, char *res) {
    int i;
    for (i = p + 1; i < n; i++) {
        if (strcmp(arr[p].res, arr[i].op1) == 0) {
            strcpy(arr[i].op1, res);
        } else if (strcmp(arr[p].res, arr[i].op2) == 0) {
            strcpy(arr[i].op2, res);
        }
    }
}

