#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

// Helper functions (not defined in header file)

// new_node allocates memory for a new node, initializes it's fields to their
// default values, and returns it.
static node* new_node() {
    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->val = 0;
    return n;
}

// insert_node_after inserts newNode after the specified node in the linked
// list.
static void insert_node_after(node* n, node* newNode) {
        newNode->next = n->next;
        n->next->prev = newNode;
        n->next = newNode;
        newNode->prev = n;
        return;
}

// remove_node removes the specified node from the linked list, and frees the
// memory associated with it.
static void remove_node(node* n) {
    // TODO: Write code to remove newNode from the linked list
    // This will involve updating:
    //  - The next pointer of the node before it in the list
    //  - The prev pointer of the node after it in the list
    // You will also have to free the memory associated with the removed node
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    return;
}


// Public functions (defined in header file)

// new_linked_list allocates memory for a new linked list, initializes its
// fields, and returns it.
linked_list* new_linked_list() {
    // Allocate memory for a new linked list
    linked_list* l = (linked_list*) malloc(sizeof(linked_list));

    // Initialize fields. The sentinel node doesn't contain a value, and
    // therefore doesn't actually count towards the size of the linked list.
    // It's next and prev pointers point back to itself, at the start, since
    // it's a circular linked list
    l->sentinel = new_node();
    l->sentinel->next = l->sentinel;
    l->sentinel->prev = l->sentinel;
    l->size = 0;

    return l;
}

// linked_list_push_front inserts the given item at the front of the linked list.
void linked_list_push_front(linked_list* l, int i) {
    // TODO: Write code to insert an item at the front of the list.
    // This will involve:
    //  - Allocating memory for a new node
    //  - Setting the value of the new node to i
    //  - Calling insert_node_after to insert the new node after the sentinel node
    //  - Incrementing the size field of the linked list
    struct node* n = new_node();
    n->val = i;
    insert_node_after(l->sentinel, n);
    l->size++;
    return;

}

// linked_list_pop_front removes the item at the front of the list and returns it.
int linked_list_pop_front(linked_list* l) {
    // TODO: Write code to remove and return the item at the front of the list.
    // This will involve:
    //  - Returning -1 if the list is empty, otherwise:
    //  - Calling remove_node to remove the node at the front of the list
    //  - Freeing the memory associated with the removed node
    //  - Returning the value of the removed node (make sure to store the value
    //      before your free the node's memory!)
    //  - Decrementing the size field of the linked list

    if (l->size == 0) {
        return -1;
    }
    else {
        int i = l->sentinel->next->val;
        remove_node(l->sentinel->next);
        l->size--;
        return i;
    }

}

// linked_list_push_back inserts the given item at the back of the linked list.
void linked_list_push_back(linked_list* l, int i) {
    // TODO: Write code to insert an item at the back of the list.
    // This will involve:
    //  - Allocating memory for a new node
    //  - Setting the value of the new node to i
    //  - Calling insert_node_after to insert the new node before the sentinel
    //      node (i.e. after the node that is currently before the sentinel node)
    //  - Incrementing the size field of the linked list
    struct node* n = new_node();
    n->val = i;
    insert_node_after(l->sentinel->prev, n);
    l->size++;
    return;
}

// linked_list_pop_back removes the item at the back of the list and returns it.
int linked_list_pop_back(linked_list* l) {
    // TODO: Write code to remove and return the item at the back of the list.
    // This will involve:
    //  - Returning -1 if the list is empty, otherwise:
    //  - Calling remove_node to remove the node at the back of the list
    //  - Freeing the memory associated with the removed node
    //  - Returning the value of the removed node (make sure to store the value
    //      before your free the node's memory!)
    //  - Decrementing the size field of the linked list

    if (l->size == 0) {
        return -1;
    }
    else {
        int i = l->sentinel->prev->val;
        remove_node(l->sentinel->prev);
        l->size--;
        return i;
    }
}

// linked_list_remove removes the item out of the linked list, if it exists. If
// there are duplicate items in the linked list, it will only remove one of
// them. If the item does not exist in the linked list, it will silently do
// nothing.
void linked_list_remove(linked_list* l, int i) {
    // TODO: Iterate through the list (stopping when you get back to the
    // sentinel node). Remove the first node whose value is equal to the
    // specified int, or silently do nothing if that value doesn't exist in the
    // linked list.
    for (node* cur = l->sentinel->next; cur != l->sentinel; cur = cur->next) {
        if (cur->val == i) {
            remove_node(cur);
            l->size--;
            return;
        }
    }
    return;
}

// linked_list_contains returns true if the given item exists in the linked
// list, and false otherwise.
bool linked_list_contains(linked_list* l, int i) {
    // TODO: Iterate through the list (stopping when you get back to the
    // sentinel node). Return true if it contains the specified int, or false
    // otherwise

    for (node* cur = l->sentinel->next; cur != l->sentinel; cur = cur->next) {
        if (cur->val == i) {
            return true;
        }
    }
    return false;
}

// linked_list_size returns the number of items currently in the linked list.
int linked_list_size(linked_list* l) {
    // TODO: Return the current size of the list
    return l->size;
}

// free_linked_list frees the memory allocated for the linked list (the memory
// of any remaining nodes, as well as the linked list header struct itself).
void free_linked_list(linked_list* l) {
    // TODO: Free the memory associated with any nodes remaining in the list,
    // then free the memory associated with the linked_list struct itself
    node* n = l->sentinel;
    for (int i = 0; i < l->size; i++) {
        n = n->next;
        free(n->prev);
    }
    free(l);
}
