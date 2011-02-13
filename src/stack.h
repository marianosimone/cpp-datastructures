#ifndef CPPDATASTRUCTURES_STACK_H_
#define CPPDATASTRUCTURES_STACK_H_

/**
 * A stack is a data structure that represents a pile
 * This is just an interface for all stacks implementations, thus
 * it can not be instantiated
**/
class Stack {
  public:
    /**
     * Adds value to the top of the stack
    **/
    virtual void push(int value) = 0;

    /**
     * Returns the current top value, without removing it
     * from the stack
     * TODO: Define what happens when it's empty
    **/
    virtual int top() const = 0;

    /**
     * Returns and removes the current top value
     * After invoking, the value is not longer a member of the stack
     * TODO: Define what happens when it's empty
    **/
    virtual int pop() = 0;

    /**
     * Returns true if the are values in the stack,
     * false otherwise
    **/
    virtual bool isEmpty() const = 0;

    /**
     * Removes all elements from the stack
    **/
    virtual void clear() = 0;

    virtual ~Stack() {}
};

#endif
