package bag

// Bag is a simple abstract data type (ADT) for storing items. It has methods
// for adding and removing items, checking if a given item exists in the bag,
// and getting the number of items stored in the bag.
type Bag struct {
	Contents []int
	// TODO: Add fields here for storing items. You can use any data structure
	// you want (there is no "right" answer). The fields you add here will be
	// accessible in the methods below. See: https://gobyexample.com/methods
}

// NewBag is used to create an instance of a Bag.
func NewBag() *Bag {
	return &Bag{nil}
}

// Add inserts an item into the bag. The bag should accept and store duplicate
// items (i.e. it is not a set).
func (b *Bag) Add(i int) {
	b.Contents = append(b.Contents, i)
	return
}

// Remove takes an item out of the bag, if it exists. If there are duplicate
// items in the bag, it should only remove one of them. If the item does not
// exist in the bag, it should silently do nothing.
func (b *Bag) Remove(i int) {
	// TODO: Implement the Remove method.
	c := b.Contents
	for index, item := range c {
		if item == i {
			c[index] = c[len(c)-1]
			c[len(c)-1] = 0
			c = c[:len(c)-1]
			b.Contents = c
			return
		}
	}
	return
}

// Contains returns true if the given item exists in the bag, and false
// otherwise.
func (b *Bag) Contains(i int) bool {
	c := b.Contents
	for _, item := range c {
		if item == i {
			return true
		}
	}
	return false
}

// Size returns the number of items in the bag.
func (b *Bag) Size() int {
	return len(b.Contents)
}
