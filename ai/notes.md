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

## Wed Sep 3

### Announcements
* We will not be doing the code demo today

### Tree vs Graph
* There can be duplicate states in a tree that are explored
* Graphs illiminate duplicates by remembering every state and pruning
  nodes if it is a duplicate

#### Pros and Cons
* Graphs have to remember all states or an identifier for all states
  thus they could potentially use more memory
* Trees have less memory requirements
* You might have to explore the same states multiple times in a tree.
  Think about a destination in a city. You can go down and turn or you
could turn and go down. Both ways you end up at the same state.

_Closed List_ is the list containing all the states when using a Graph.

### Evaluation Criteria
* _Completeness:_ Will it accomplish the goal?
* _Optimality:_ Will it find the shallowest goal?
* _Time complexity:_
  * BFS: b^d
  * DFS: b^m
  * DLS: b^l
  * IDS: b^d
  * UCS: probably b^d* where d* is some depth dependent on the cost
* _Space complexity:_
  * BFS: b^(d+1)
  * DFS: b * m
  * DLS: b^l
  * IDS: b * d
  * UCS: b^(d * + 1)

_Nice table summarizing the above is found in the notes._

### Bi-Directional Search
One step from initial step, then search backwards from goal state.
With BFS your big O might be b^d where with bi-directional you'd be at
b^(d/2) which is a big difference.

## Fri Sep 5

### Program Setup

mkdir AI
wget url-to-tgz-file
tar -zxf ai-release-y-.tgz
cd ai-release-y14m09d04

Editing happens in ai-agents directory

cd ai-agents/

build: where the stuff for compiling exists
prog: source code

cd build/linux/

**Need to do:**

`make configure` in ai-agents/build/linux
and then `make` again.

Hundreds of lines of text should scroll by.

`cd ../../../` back to top level.

Now run distributed software as it stands:

`cd ai/bin/00bin-o`

This is software that we get for free. Most of this we are not
worried about. The few we do care about:
* ScavengerServer
* ScavengerDisplay
* ScavengerAgent

How to run software for the first time ie launch the environment:

`./RunProg ./ScavengerServer -f
../../../ai-agents/prog/ScavengerWorld/y12m09p02_world.txt -O 1 -s 10000
-t 0 -S 30`

`-f` sets the file for the world
`-O` the world is _observable_
`-s 10000` give the agent up to 10,000 steps to finish. Illiminates
infinite loops. Default limit is 1,000 but scavenger worlds take a lot
of steps
`-t` turns on and off tracing. we turn it off for observable worlds.
`-S` view display at end of simulation?

`--help` will list the options.

In a new tab, launch the display.
`./RunProg ./ScavengerDisplay -d 0`

Another tab:
`./RunProg ./ScavengerAgent --help`
then,
`./RunProg ./ScavengerAgent -a ?` lists the available agents and their
keys.
So,
`./RunProg ./ScavengerAgent -a s` to run Snorlax.

When it finishes the server gives you some stats.

Agent lives in a grid world. Each cell is 1000x1000
One cell has the base. Use the base to drop off items, etc.
Terrain sits between cells:
* Plain: flat, normal
* Mud: requires more power
* Rock: charge cost is same as plain but takes damage
* Cliffs/wall: you will fall and you will die

First assignment objective:
Agent start at base and find a path to identified goal location, go
there, then find a path back to base and walk back.

The world file contains where the base and goal are.
Avoid rocks and cliffs.


#### Start writing code:
cd into ScavengerList inside of prog directory.

##### New agent
`cp Snorlax.h cglPinkiePie.h`
`cp Snorlax.cpp cglPinkiePie.cpp`

Note the namespace. Do it. For all of your files. All of them.

Edit header file first.
Change up the #define stuff to match.
Change the namespace.
Change `Snorlax` to new name.

Edit cpp file
Change include
Replace Snorlax with new name

Agent constructors can optionally take arguments from the command line.

The `Program` method receives the percepts and decides what to do with
them. Keep things modular by writing more methods.

An `ai::Scavenger::Action` has enough information for the agent to know
about what it can do. We return this action and never delete this
action. We instantiate it from the heap but we are not responsible for
deleting it.

You will notice that Snorlax randomly sets the direction on the action.

We don't care about the look actions for the first assignment.

Some percepts:
* `X_LOC`
* `Y_LOC`
* `X_LOC`

You can see how we acquire these percepts.
`x = atof(percept->GetAtom("X_LOC").GetValue().c_str());`

The base is the origin of our world (0000, 0000, 0000).

x and y will be nice increments but z will not.

#### How to observe the whole world:
There is a for loop in the cpp file that loops through every percept.
This for loop parses the cells. Create a cell class and load this data
into it.

### Objective:
1. Create a model that represents the world.
2. Search for goal and go and reverse.
3. Solve the problem, cache up actions and run them.

First week: duplicate Snorlax.

#### TODO:
Duplicate Snorlax.
Add him to AgentPrograms.pm
`make`
You should be able to run program with new agent.

## Fri Sep 5

He's playing with legos.

### Puzzle

*Goal:* Assemble the 12 pieces so that you have a rectangle with assembled pieces with no innies and no outies or spaces.

*Possible goal states:*
* 6x10
* 5x12
* 4x15
* 3x20

There are multiple solutions for each state.

#### Search Tree

*root:* initial state. Assuming we are working on the 6x10 problem, an initial state might be an empty 6x10 rectangle.
*branch:* some action. Placement of a piece.
* there are 32 branches for placing the cross (4x8)
* let's just say there are a crap ton of branches, ie: possible actions per piece.
* b <= 12 * 250 = 3000
* m = 12
* d = 12
* size of the tree = b ^ d which is 3000 ^ 12

##### Optimize!

If we assume we know the order ahead of time size of the tree becomes 250 ^ 12.
Because of this, there would be no benefit to using a graph instead of a tree.

#### Action
We need to know some things before we can take an action:
* piece
* flip
* rotation
* x, y

#### State
How to do we determine our state?
* pieces placed
* empty squares

#### Problem
Must be able to describe:
* initial state (all empty squares)
* legal actions
* results
* cost
* goal test (have all pieces been placed?)

Actions and results are normally rolled into a single method.

Determine which search you will use. *DFS would probabyl be the best search for this problem.*

### Rectangle Sample Code

There is code available to demonstrate this process. Look for the Rectangle directory.

#### Action
*We need to implement an Action class.* Refer to the RectAction class.

#### State
*Implement a State class*. Refer to RectState.
Required methods:
* Display
* IsEqual
* both constructors and destructor

##### IsEqual
_Looking at the cpp file._
* paramater must be a pointer to the base class but in practive will be actual class, hence the dynamic cast

#### Problem
Refer to RectProblem
Required methods:
* constructor: requires pointer to base class as param that has been allocated from the heap.
  * ie: new MyStateClass()
* deconstructor
* GoalTest
* FindSucessors -> actions and results rolled into one
  * record results in in-out vector passed in
  * an ActionStatePair contains a pointer to the state and the action that got us to that state
  * DO NOT destruct the action or the state from the ActionStatePair
  * this method is the meat and potatoes of this class
* StepCost
  * returns numerical value for how much it costs to go from state1 to state2 using given action
* Heuristic
  * return 0 for now

Problem class should delete the state that is passed in.

##### CPP File
FindSuccessors: note where he creates a new state and action, tests them then creates an ActionStatePair if it is legal.
Goal Test: find_all is not what you think it is.

#### RectangleSolver

This class wraps it all together.

_frontier:_ nodes that have not been explored yet.

We will look at this class more next time.
