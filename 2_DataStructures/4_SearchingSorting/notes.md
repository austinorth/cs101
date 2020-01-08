# Searching and Sorting

## Sequential Search
- Both our dynamic array as well as our linked list have a O(n)
  Contains() operation.

## Binary Search
- Prequisite: the array is sorted.
- Analogous to searching through a phone book.
- Does not work for linked lists (no random access!)
- Algorithm
  - Find the item in the middle of the list
  - Check if it's the item you're searching for - if so, return true
  - if greater, discard the left half of the list
  - repeat using the remaining half of the list
  - if you get down to a single element and it's not the one you're
    looking for, return false.
### What is the Big O?
- log(n) base2
- log is inverse of exponent. Tells you the number of times you have to
  multiply 2 by itself to get n.
- 2^3 = 8, so log(base2)(8) = 3

### Cool Stuff
- The longer your array gets, the less adding a single item affects the
  overall search complexity.
- If you double the number of items in your array, it will only add one
  operation to your search, no matter how large the array.

## Selection Sort
- Builds the final sorted array one item at a time
- Sorted portion is stored on the left of the array, unsorted on the
  right.
- For each item, it has to check all remaining items to find the
  minimum.

## Insertion Sort
- Builds the final sorted array one item at a time
- Iterates over the input data, and for each item, iterates backwards
  through the sorted portion to find the location where it belongs and
  inserts it there.
- Must shift items to make room in the sorted portion of the array.
- O(n) is best case, but can only happen with an already-sorted array.
- O(n^2) is worst case, happens when passed a reverse-sorted array.
- O(n^2) or O(kn) is avg, wheen each element in the input is no more
  than k places away from its sorted position.

## Merge Sort
- Insight: You can merge two sorted arrays in O(n) time and O(n) space.
- Divide and Conquer
- An array with a single item in it is sorted.
- Breaks into single item arrays, then recursively merges back into
  single sorted array.
- Time O(n log(n))
- Space O(n)

## Quick Sort
- Divide and Conquer
- Randomly chooses a pivot
- Reorder array so that everything less than the pivot comes before it,
  and everything greater comes after it.
- Pivot is now in final location.
- Recursively apply operation to sub-arrays on either side.
- Best Case Time O(n log(n)), Worst is O(n^2)
- Average Case O(n log(n))
- O(log n)

## Should We Always Use Bisection Search?
- No, cuz array sometimes needs sorted. If you have an unsorted array,
  just do a linear sort.
- Linear search is cheaper if array is unsorted and we only need to
  search once.
- 
