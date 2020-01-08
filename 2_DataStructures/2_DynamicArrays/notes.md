# Class 2

### Big O Notation
- Big O notation is used to classify algorithms according to their
  running times or space requirementsi.
- Ignore constants.
- Ignore lesser powers.
- Amortized complexity = average complexity

### Abstract Data Types
#### Stack
- Last in First Out (LIFO)
- Can only add or remove items from the "top"
- push
- pop

### Queue
- First in First Out (FIFO)
- Enqueue
- Dequeue
- Peek

### Deque
- Queue and Stack Combined
- Push and Pop from back _and_ front
- 
# Class 3

### Linked Lists
#### Traversal
- Set current pointer to first node (head)
- Check if node is not NULL
- Print node's value
- Update current pointer to next node
- Repeat from step 2
- Stop when you encounter NULL

### Adding an Element after a Node
- Create a new node, set its value
- Set "next" pointer of new node to current "next" pointer of existing
  node
- Set "next" pointer of existing node to address of new node

### Removing an Element after a Node
- Check if node's next pointer is NULL
- Assuming there is something to remove, store value of node's next
  pointer in temporary variable.
- Update the node's next pointer to point to the node after the next
  node
- Free memory of temporary variable.

### Variations
- Use a linked list as a queue with a tail pointer!
  - Makes insert at back O(1)
- Circular Linked List
  - Tail points back to start
  - Tail pointer = head pointer
  - Simplifies operations like removing a node.
- Create a list struct that stores head pointer and size.
- Sentinel Node
  - Makes adding and removing from beginning of list easier
  - Stores no data, is just a placeholder
  - Ensures all nodes can be safely dereferenced.
- Doubly Linked List
  - Makes push and pop on both ends O(1)
- 
