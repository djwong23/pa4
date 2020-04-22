#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {
    AND, OR, NAND, NOR, XOR, NOT, PASS, DECODER, MULTIPLEXER
} kind_t;
struct gate {
    kind_t kind; // indicates size of DECODER and MULTIPLEXER
    int size;// length determined by kind and size;
    int *params; // includes inputs and outputs, indicated by variable numbers

};
struct circuit {
    int *values;
    struct gate *gates;
};

struct varNode {
    char name[10];
    int id;
    struct varNode *next;
};

int findIndex(struct varNode *root, char *name) {
    while (root != NULL) {
        if (strcmp(root->name, name) == 0) {
            return root->id;
        }
        root = root->next;
    }
    return -1;
}

int createNewIndex(struct varNode *root, char *name, int varNum) {
    while (root->next != NULL) {
        root = root->next;
    }
    root->next = malloc(sizeof(struct varNode));
    root = root->next;
    strcpy(root->name, name);
    root->id = varNum++;
    root->next = NULL;
    return root->id;
}

int main(int argc, char **argv) {
    FILE *f = fopen("C:\\Users\\djwon\\Desktop\\CS\\PA4\\src\\test.txt", "r");
    char *input = malloc(sizeof(char) * 20);
    struct circuit *c = malloc(sizeof(struct circuit));
    c->gates = malloc(sizeof(struct gate));
    fscanf(f, "%s", input);
    int varNum = 2;
    struct varNode *root = malloc(sizeof(struct varNode));
    struct varNode *ptr = root;
    int totalVariables = 2;
    int numInputs = 0;
    int numOutputs = 0;
    int numGates = 0;
    int i = 0;
    if (strcmp(input, "INPUT") == 0) { //puts all the inputs into the circuit's input array and linked list
        int num = 0;
        fscanf(f, "%d", &num);
        totalVariables += num;
        numInputs = num;
        fscanf(f, "%s", root->name);
        root->id = varNum++;
        for (i = 1; i < num; i++) {
            ptr->next = malloc(sizeof(struct varNode));
            ptr = ptr->next;
            fscanf(f, "%s", ptr->name);
            ptr->id = varNum++;
            ptr->next = NULL;
        }
    }
    fscanf(f, "%s", input);
    if (strcmp(input, "OUTPUT") == 0) { //puts all the outputs into the circuit's output array and linked list
        int num = 0;
        fscanf(f, "%d", &num);
        numOutputs = num;
        totalVariables += num;
        ptr->next = malloc(sizeof(struct varNode));
        ptr = ptr->next;
        fscanf(f, "%s", ptr->name);
        ptr->id = varNum++;
        for (i = 1; i < num; i++) {
            ptr->next = malloc(sizeof(struct varNode));
            ptr = ptr->next;
            fscanf(f, "%s", ptr->name);
            ptr->id = varNum++;

        }
        ptr->next = NULL;
        ptr = root;


    }
    c->values = (int *) malloc(totalVariables * sizeof(int));
    c->values[0] = 0;
    c->values[1] = 1;
    for (i = 2; i < totalVariables; i++) {
        c->values[i] = 0;
    }
    while (fscanf(f, "%s", input) != EOF) { //creating and gate
        if (strcmp(input, "AND") == 0) {
            numGates++;
            struct gate *temp =  malloc(sizeof(struct gate)*numGates);
            for (i = 0; i < numGates - 1; i++)
                temp[i] = c->gates[i];
            c->gates = temp;
            c->gates[numGates - 1].kind = AND;
            c->gates[numGates - 1].size = 0;
            c->gates[numGates - 1].params = malloc(sizeof(int) * 3);
            int index = 0;
            for (int i = 0; i < 3; i++) {
                fscanf(f, "%s", input);
                if (strcmp(input, "0") == 0)
                    index = 0;
                else if (strcmp(input, "1") == 0)
                    index = 1;
                else {
                    index = findIndex(root, input);
                    if (index == -1) {
                        index = createNewIndex(root, input, varNum);
                        varNum++;
                        totalVariables++;
                    }

                }
                c->gates[numGates - 1].params[i] = index;
            }
        } else if (strcmp(input, "OR") == 0) {
            numGates++;
            struct gate *temp =  malloc(sizeof(struct gate)*numGates);
            for (i = 0; i < numGates - 1; i++)
                temp[i] = c->gates[i];
            c->gates = temp;
            c->gates[numGates - 1].kind = OR;
            c->gates[numGates - 1].size = 0;
            c->gates[numGates - 1].params = malloc(sizeof(int) * 3);
            int index = 0;
            for (int i = 0; i < 3; i++) {
                fscanf(f, "%s", input);
                if (strcmp(input, "0") == 0)
                    index = 0;
                else if (strcmp(input, "1") == 0)
                    index = 1;
                else {
                    index = findIndex(root, input);
                    if (index == -1) {
                        index = createNewIndex(root, input, varNum);
                        varNum++;
                        totalVariables++;
                    }

                }
                c->gates[numGates - 1].params[i] = index;
            }

        } else if (strcmp(input, "XOR") == 0) {
            numGates++;
            struct gate *temp =  malloc(sizeof(struct gate)*numGates);
            for (i = 0; i < numGates - 1; i++)
                temp[i] = c->gates[i];
            c->gates = temp;
            c->gates[numGates - 1].kind = XOR;
            c->gates[numGates - 1].size = 0;
            c->gates[numGates - 1].params = malloc(sizeof(int) * 3);
            int index = 0;
            for (int i = 0; i < 3; i++) {
                fscanf(f, "%s", input);
                if (strcmp(input, "0") == 0)
                    index = 0;
                else if (strcmp(input, "1") == 0)
                    index = 1;
                else {
                    index = findIndex(root, input);
                    if (index == -1) {
                        index = createNewIndex(root, input, varNum);
                        varNum++;
                        totalVariables++;
                    }

                }
                c->gates[numGates - 1].params[i] = index;
            }
        } else if (strcmp(input, "NAND") == 0) {
            numGates++;
            struct gate *temp =  malloc(sizeof(struct gate)*numGates);
            for (i = 0; i < numGates - 1; i++)
                temp[i] = c->gates[i];
            c->gates = temp;
            c->gates[numGates - 1].kind = NAND;
            c->gates[numGates - 1].size = 0;
            c->gates[numGates - 1].params = malloc(sizeof(int) * 3);
            int index = 0;
            for (int i = 0; i < 3; i++) {
                fscanf(f, "%s", input);
                if (strcmp(input, "0") == 0)
                    index = 0;
                else if (strcmp(input, "1") == 0)
                    index = 1;
                else {
                    index = findIndex(root, input);
                    if (index == -1) {
                        index = createNewIndex(root, input, varNum);
                        varNum++;
                        totalVariables++;
                    }

                }
                c->gates[numGates - 1].params[i] = index;
            }
        }

    }
    int n = pow(2, numInputs);
    int j = 0;
    for (j = 0; j < n; j++) {
        int num = j;
        for (i = numInputs + 1; i >=2; i--) {
            if (num != 0) {
                c->values[i] = num % 2;
                num /= 2;
            } else
                c->values[i] = 0;



        }
        for (i = 2; i<numInputs+2;i++) {
            printf("%d ", c->values[i]);
        }
        printf("|");
        for (i = 0; i < numGates; i++) {
            struct gate g = c->gates[i];
            if (g.kind == AND) {
                c->values[g.params[2]] = (c->values[g.params[0]] == 1 && c->values[g.params[1]] == 1);
               //printf("The result of %d AND %d is %d\n", c->values[g.params[0]], c->values[g.params[1]], c->values[g.params[2]]);
            } else if (g.kind == OR) {
                c->values[g.params[2]] = (c->values[g.params[0]] == 1 || c->values[g.params[1]] == 1);
              //printf("The result of %d OR %d is %d\n", c->values[g.params[0]], c->values[g.params[1]], c->values[g.params[2]]);
            } else if (g.kind == XOR) {
                c->values[g.params[2]] = (c->values[g.params[0]] != c->values[g.params[1]]);
              //printf("The result of %d XOR %d is %d\n", c->values[g.params[0]], c->values[g.params[1]], c->values[g.params[2]]);
            } else if (g.kind == NAND) {
                c->values[g.params[2]] = !((c->values[g.params[0]] == c->values[g.params[1]]) && (c->values[g.params[0]] == 1));
             //printf("The result of %d NAND %d is %d\n", c->values[g.params[0]], c->values[g.params[1]], c->values[g.params[2]]);
            }

        }

        for (i = numInputs + 2; i < numInputs + 2 + numOutputs; i++) {
            printf(" %d", c->values[i]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}


