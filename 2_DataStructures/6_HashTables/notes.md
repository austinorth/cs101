## Associative Array
- Also known as a map
- can contain arbitrary key-value pairs
- Each key can exist at most once

### Operations
- Insert(key, value)
- Delete(key)
- Get(key)

### How is it different from a struct?
- Structs
  - Fields must be specified at compile time
  - Laid out in a contiguous block of memory
  - Field are accessed by calculating offest from struct's location in
    memory
  - Does not support arbitrary keys at runtime

- Associative Array
  - Keys are not necessarily known at compile time
  - Implemented via some underlying data structure like a binary search
    tree.
  - Supports arbitrary keys at runtime

## Hash Table
- Implements an associative array
- Uses a hash function to compute a hash code from a key
- Hash code is used to index into an array of buckets or slots
- The value associated with the key can be found in that backet
- Indexing into an array is O(1)
- Performance depends largely on the hash function

## Hash Functions
### Responsibilities
- Convert variable length keys to fixed length values.
- Ensure that the resulting hash codes/indexes are uniformly distributed
  over the key space
- Maps keys to indices less than or equal to hash table.

### Properties of a Good Hash Function
- Uniformity
  - Every output in the range should be generated with rougly equal
    probability.
  - If more than one key hashes to the same index, we get a collision.
  - Perfect hash function has no collisions
  - Minimal perfect hash function is perfect and maps N keys to N
    consecutive integers.
- Efficiency
- Universality
- Deterministic
- Defined range

## Collision Resolution
### Load Factor
- Load factor = n/k
  - n = number of entries in the hash table
  - k = number of buckets
- Represents avg number of elements per bucket
- Collisions become more likely as load factor increases
- Often hash table is dynamically resized

### Separate Chaining
- If I have two things hashed to the same bucket, store both to the same
  bucket.
- In bucket head of linked list is stored.
- Have to store key _with_ value in bucket.
- Could also be binary search tree.
- When all keys hash to the same bucket = worst case

### Open Addressing
- All entries stored in bucket array
- If bucket is occupied, examine more buckets according to "probe
  sequence"
- Has to minimize clustering

