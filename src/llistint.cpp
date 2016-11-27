#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
  * Copy constructor (deep copy)
  */
LListInt::LListInt(const LListInt& other) {
  // construct this
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  // traverse through other and copy each element into this
  if (!other.empty()) {
    Item* temp = other.getNodeAt(0); 
    int i = 0;
    while (temp != NULL) {
      this->insert(i, temp->val);
      temp = temp->next;
      i++;
    }
  }
}

/**
  * Assignment Operator (deep copy)
  */
LListInt& LListInt::operator=(const LListInt& other) {
  // check if linked lists are equal
  if(this == &other) {
    return *this;
  }
  // initialize this LListInt
  this->clear();
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
  // insert new elements in this from copy 
  if (!other.empty()) {
    Item* temp = other.getNodeAt(0);
    int i = 0;
    while (temp != NULL) {
      this->insert(i, temp->val);
      temp = temp->next;
      i++;
    }
  }

  return *this;

}

/**
  * Concatenation Operator (other should be appended to the end of this)
  */
LListInt LListInt::operator+(const LListInt& other) const {
  // Copy constructor 
  LListInt lhs(*this);

  if (!other.empty()) {
    Item* temp = other.getNodeAt(0);
    int i = this->size(); // set i to end of the list 
    // insert all other values into this list
    while (temp != NULL) {
      lhs.insert(i, temp->val);
      temp = temp->next;
      i++;
    }
  }

  return lhs;
}

/**
  * Access Operator
  */
int const & LListInt::operator[](int position) const {
  return this->get(position);
}


/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  Item* newItem = new Item;
  newItem->val = val;

  if (loc < 0 || loc > size_) {
    return;
  }
  // empty list
  if (head_== NULL) {
    // add a newItem node in between head and tail
    if (loc == 0) {
      newItem->prev = NULL;
      newItem->next = NULL;
      head_ = newItem;
      tail_ = newItem;
      size_++;
    } 
    // out of bounds
    else {
      return;
    }
  }
  // insert into the first position
  else if (head_ != NULL && loc == 0) {
    // link the new item to head and 1st item
    newItem->prev = NULL;
    newItem->next = head_;
    if (head_->next) {
      head_->next->prev = newItem;
    }
    head_ = newItem;
    size_++;
  }
  else {
    Item* temp = head_;
    // go to one item before the insertion
    for (int i = 0; i < loc-1; i++) {
      temp = temp->next;
    } 
    newItem->prev = temp;
    // insert in the middle of the list
    if (temp->next != NULL) {
      newItem->next = temp->next;
      temp->next->prev = newItem;
    }
    // insert into the end of the list
    else {
      newItem->next = NULL;
      tail_ = newItem;
    }
    temp->next = newItem;
    size_++;
  }

}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  // invalid bounds
  if (loc < 0 || loc >= size_) {
    return;
  }
  // empty list
  if (head_== NULL) {
    return;
  }
  // remove first value
  else if (head_ != NULL && loc == 0) {
    // points head to one item after the first
    Item* oldFirst = head_;
    head_ = head_->next;
    // test if list is greater than one item
    if (head_) {
      head_->prev = NULL;
      delete oldFirst;
    }
    else {
      delete oldFirst;
    }
    size_--;
  }
  else {
    Item* temp = head_;
    for (int i = 0; i < loc-1; i++) {
      temp = temp->next;
    }
    temp = temp->next;
    // remove last item of the list
    if (temp->next == NULL) {
      temp->prev->next = NULL;
      tail_ = temp->prev;
      delete temp;
    }
    // remove random item in the middle of the list
    else {
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      delete temp;
    }
    size_--;
  }
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_) {
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item* temp = head_;
  // out of bounds
  if(loc < 0 || loc >= size_) {
    throw std::invalid_argument("Bad location");
  }
  // iterate through each item until getting to the location
  else {
    for (int i = 0; i < loc; i++) {
      temp = temp->next;
    }
    return temp;
  }

}
