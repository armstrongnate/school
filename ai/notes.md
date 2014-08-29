# AI Notes
## Wed Aug 27
### Get the Book
DJ says the book is effective. Buy it. Read it. Live it.

### Types of agents
* reflex: 1 percept becomes 1 action
  - model based reflex agent: pays more attention
* goal: has a destination in mind
* utility: goal based with a happiness factor
  - _happy_ means how the agent thinks it is doing
  - utility functions tries to determine _how well am i doing?_ or, how
    happy am I?
  - competitive agents are happy when its competitors are not happy

### Environments
Attributes of what an environment might be.
* Fully-oversvable vs partially
  - fully example: chess board
  - partially example: earth
* Single-agent vs multi-agent
  - single: crossword puzzle
  - multi: chinese checkers
  - something thats performance effects your performance constitutes
    another agent
* Deterministic vs stocastic
  - deterministic: i can predict what will happen to the environment
    based on my action eg chinese checkers
  - stocastic: example is real world. complex environments
  - **You can have a partially observable deterministic environment.**
* Episodic vs sequential
  - episodic: one percept then one action. rinse and repeat, eg picking
    cherries
  - sequential: percepts and actions build on each other, eg board game
* Static vs dynamic
  - static: environment does not change while you think
  - dynamic: environment can change while you think
* Discrete vs continuous
  - discrete: something about the world is discrete. _Im either standing
    here or there. not inbetween_.
  - continuous: real world. you can stand anywhere.
* Known vs unknown
  - known: has an idea of what is going to happen
  - unknown: agent is handed an xbox remote but has never played halo.
    No idea what is going to happen

### Homework
* Study and learn these environments.

## Wed Aug 29

Announcements:
* Homework assignments are being pushed back a week
* Need Ubuntu 14.04

_Slides from this lecture are available [here](http://cit.dixie.edu/cs/4300/examples.examples/Lecture-y14m08d29-uninformed-search.pdf)_

### Searching for Solutions
_Atomic state_: The state of the world. Think of a ball holding the
state. The state might be x, y, z coordintates. If its atomic you don't
break it apart. It's a bit.

_Uninformed_: No idea where the goal is
_Informed_: Has an idea

_Solution_: fixed sequences

### Goal Forumlation
* There could be a large number of goal states
  * Example: rubick's cube blue side is up vs down

### Problem Formulation
* What actions are possible?
* What does the state look like?
* Reduce state to as simple as possible
* Don't omit details that solution relies on

### Search Algorithm
1. Know where we start from (current state)
2. If I haven't found a goal, keep looking
3. Consider all actions given the state
4. Repeat for newlly found state

### Tree Search
Tree Root: initial state
b: branching factor
d: depth of shallowest goal
m: maximum depth of tree
total nodes: b^m

#### Search Options

##### BFS
* breadth first search
* _one level at a time_
* only has to search `b^d`
* **memory intensive** because you have to remember stuff

##### DFS
* depth first search
* finds first leaf then goes all the way down then works its way up
* must search `b^m` in worst case, therefore
* if `m` is infinity then this is a poor choice. example: rubicks cube.
* if m is limited:
  * must remember current branch and its siblings `b*m`
  * worst case runtime is `b^m`

##### Uniform Cost Search
* much like BFS but only takes the path with the least cost

##### DLS
* depth limited search
* much like dfs but sets a cutoff level
* only finds goal if it is within limit
* doesn't always find goal
* only use if you know the goal is within a limit

##### IDS
* interitive deepening search
* much like DLS except that it tries it with a limit and then increases
  the limit if it is unsuccessful and tries again

### Problem Definition
This is important since it models the structure of the methods we will
write for our programs. _See link to notes above_.
