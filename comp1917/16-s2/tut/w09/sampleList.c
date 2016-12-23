/*
 * List.c
 *
 * Implementation of List ADT
 *
 * Author:  Curtis Millar
 */

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

static Lnode destroyNode(Lnode head, Lnode prev, Lnode curr);

struct node {
    int val;
    Lnode next;
};

Lnode newNode(int value) {
    Lnode new = malloc(sizeof(struct node));

    if (new != NULL) {
        new->next = NULL;
        new->val = value;
    }

    return new;
}

Lnode prepend(Lnode head, Lnode new) {

    if (new != NULL) {
        new->next = head;
        head = new;
    }

    return head;
}

Lnode append(Lnode head, Lnode new) {
    Lnode curr = NULL;

    if (new != NULL) {
        if (head == NULL) {
            head = new;
        } else {
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }

            curr->next = new;
        }
    }

    return head;
}

void printList(Lnode head) {
    Lnode curr = head;

    if (curr != NULL) {
        while (curr->next != NULL) {
            printf("%d, ", curr->val);
            curr = curr->next;
        }

        // Last element
        printf("%d\n", curr->val);
    }

    return;
}

Lnode deleteNode(Lnode head, int val) {
    Lnode curr = NULL;
    Lnode prev = NULL;

    if (head != NULL) {
        // Find match
        curr = head;
        while (curr != NULL && curr->val != val) {
            prev = curr;
            curr = curr->next;
        }


        // Delete match
        if (curr != NULL) {
            // We found one!
            head = destroyNode(head, prev, curr);
        }
    }

    return head;
}

static Lnode destroyNode(Lnode head, Lnode prev, Lnode curr) {

    if (head != NULL) {
        // There needs to actually be a list

        // Pull the node from the list
        if (prev == NULL) {
            // Node was at the start
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
    }

    // Freeeeedooommmm!!!!
    free(curr);

    return head;
}