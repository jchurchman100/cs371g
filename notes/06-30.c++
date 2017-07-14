// -----------
// Fri, 30 Jun
// -----------

/*
workhorse containers:
    vector
    list
    deque

container adapters:
    stack
    queue
    priority_queue
*/

/*
stack
    push -> push_back
    pop -> pop_back
    size
    empty
    top -> back, two of them, one const, one not

    LIFO

    vector
    list
    deque  (default)
*/

/*
class relationships:
    inheritance
    containment
*/

/*
queue
    push  -> push_back
    pop   -> pop_front
    size
    empty
    back  -> back, two of them, one const, one not
    front -> front, two of them, one const, one not

    FIFO

    NOT vector
    list
    deque      (default)
*/

/*
priority_queue
    push  -> push_back
    pop   -> pop_heap, pop_back
    size
    empty
    top -> front, one of them, const

    highest or lowest priority pop

    vector   (default)
    NOT list
    deque
*/

int  i = 2;
int& r = i;

template <typename T, typename C = deque<T>>
class stack {
    private:
        C _c;
    public:
        stack (const C& c = C()) :
            _c (c)
            {}

        void push (const T& v) {
            _c.push_back(v);}

        const T& top () const {
            return _c.back();}

        T& top () {
            return _c.back();}

        void pop () {
            _c.pop_back();}

// ---------
// Questions
// ---------

/*
Which backing container can not be used with queue? Why not?
Which backing container can not be used with priority_queue? Why not?
Why is deque the default backing container for stack and queue?
Why is vector the default backing container for priority_queue?
What can vector do faster than deque? Why?
What can deque do faster than vector? Why?
Instead of having one constructor for stack with the backing container argument defaulted, it's better to have two constructors. See posted solution. Why?
Why is stack's one-argument constructor marked explicit?
*/
