// * Problem: Implement an algorithm to delete a node in the middle (i.e., any
//  * node but the first and last node, not necessarily the exact middle) of a
//  * singly linked list, given only access to that node.
//  * 
//  * EXAMPLE lnput:the node c from the linked list a->b->c->d->e->f Result:
//  * nothing is returned, but the new linked list looks like a->b->d->e->f



//basically if i have to del mid node, nd i have not been given access to head i'll just copy the data and link of the next node to the current node to be del and free the next node.
//but if its first node or last node to be del then scenario becomes different.