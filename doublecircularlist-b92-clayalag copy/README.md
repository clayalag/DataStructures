# List ADT using a Circular Doubly-Linked List  

In this mini-project you will implement a List ADT using yet another underlying data structure: the circular doubly-linked list. The following figures illustrate what we are aiming for. We shall call the class `DoubleCircularList`. 

An object of the `DoubleCircularList` class consists of just one data member: a pointer to a DNode (where a *DNode* is a node that contains data, a next pointer, and a prev pointer). For this assignment, the *data* that will be held by each DNode is an object of class Job, where the class Job is defined as:

```c++
class Job {
private:
    int start;
    int duration;
    int running;
public:    
    Job(int s, int d, int r) start(s), duration(d), running(r){}
}
```

Say that L is an empty `DoubleCircularList` object. It would have a state like this:

<img src="https://i.imgur.com/8lxgvpJ.png" width = 150>

For this List, nodes will always be added at the end. If we add a Job(10, 30, 0) to L.  (`L.add(Job(10,30,0))`)

<img src="https://i.imgur.com/cb9kx82.png" width=350>

Notice the state of the next and prev pointer of the only node.

If we add another Job(50, 80, 0) to L.  (`L.add(Job(50,80,0))`). 

<img src="https://i.imgur.com/nba5V1U.png" width=600>

If we add another Job(120, 40, 0) to L.  (`L.add(Job(120,40,0))`)

<img src="https://i.imgur.com/UUwFTGp.png">

Notice how the next pointer of the last node points to the first node. Similarly, the prev pointer of the first node points to the last node. 



One of the member functions that you will provide to the `DoubleCircularList` is `next()`, this simply moves the head pointer to the next object in the list. If there is only one item in the list or the list is empty, nothing happens. For example, L.next() would have this effect:

You are provided with the declaration of the `Job` and `DoubleCircularList` classes.  You will implement the functions of the `DoubleCircularList` see the `DoubleCircularList.h` for documentation on how the classes should work.

In `main.cpp`, please implement the necessary tests to demonstrate that your ADT is working correctly.







