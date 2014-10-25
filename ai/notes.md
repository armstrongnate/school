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

## Wed Sep 10

### Announcements
*Submit Search Part 1 ASAP.* What to submit:
* AgentPrograms.pm
* new .h and .cpp files

`CELL_124: 7000,-5000,242.6400,cliff,plain,rocks,mud`
percept name: x,y,z,north,south,east,west

### Search Part 1

For this part we don't have to worry about all the percepts. We only have to worry about our current state and whether it's safe to go north.

1. Move the `#if 0` block to the top to get our current location.
2. Next would be the for loop already written for us to get all the cells. Edit this loop to set a flag for north being a wall
3. Use the data from the above for loop to determine if we can move north
4. If we can move north, move north. Otherwise, quit

#### Sudo code:
```
get my loc
find current cell
flag if north is safe
if safe
  go north
else
  quit
```

#### Note on compares
<pre>x1 == x2</pre>

This does a bit comparison in `c++`. So if you are comparing doubles or floats, do:
```fabs(x2 - x1) < .500```

#### depend errors
1. fix AgentPrograms.pm
2. ai-agents/build/linux/prog/ScavengerWorld/
3. `rm .depend* Makefile.agents`

### Search Part 2
For this assignment refer to the previous day's notes. We will be creating Problem, Action
and State classes. Refer to the Rect examples.

### Informed Search
_Total path cost so far:_ `g(n)`
_Heuristic (estimated cost from state in `n` to a goal):_ `h(n)`
_Greedy Search:_ runs right at the goal given a `h(n)` or `g(n)`
  * Strengths:
    * doesn't waste time expanding nodes on opposite side of the world
    * relies on some kind of indicator of where the goal is
  * Weaknesses:
    * totally dependent up your _guess_, ie
    * if your heuristic is bad, your Greedy Search is bad

## Wed Sep 12

### Announcements
Michael made _PerceptsandActions.pdf_ which has some helpful info for the
ScavengerWorld assignments. It is on the downloads page.

### Search Part 2
Objectives:
* Create a model
* State
* Action
* Problem
* Find steps to goal

#### Creating our model
**Purpose:** contain information about our search tree.

The search tree is made up of nodes that each represent a _state_.

A state would consist of:
* x, y, z
* charge
* ~~hit points~~

Don't keep a separate copy of your map in your state.

Inital state would be represented by something like: `0, 0, 0, 100` (x, y, z, charge).

Legal actions from the given state are _GO NORTH_, _GO SOUTH_, etc.

Each action has:
* action code

If, from the initial state, I go north, what will the state be? `0, 1000, ?, 99.5`.
The model will tell us what our `charge`, `z`, etc will be if we perform an action.
Basically it will give us a state given an action.

Therefore, a model would consist of:
* (x, y, z, N, S, E, W) * full map

#### Problem class
##### FindSuccessors
What it does:
1. enumerating all possible actions
2. determine which are legal (_prunes_, if you will)
3. generate resulting state

How it does it:
* must have model data available while finding successors (pass by pointer)
* instantiates new `actions` and `states` off the heap
* generates a list of `ActionStatePairs` which is an in-out variable

#### Code demo
See [curtis's model header](cgla2Model.h)

## Mon Sep 15

### Announcements
* Keep pushing forward on search stuff
* Should be searching for goal
* `ai_search.h` must be imported to get at search libraries
* added InterfaceStringToInt method to model header
* implement model cpp file

### AddCell
```
std::pair<int, int> key(DoubleToInt(x1), DoubeToInt(y1));
Cell c(id1, x1, y1, z1, n, s, e, w);
cells[key] = c;
return true;
```

### ParsePercepts
Inside of `for` loop, use the `Model::InterfaceStringToInt` method to convert the
strings to integers before passing them to `AddCell` (ie "wall").

### Lecture

**Informed vs Uninformed Search:** informed has a guess of where the goal is.

**Uniform vs Greedy:** greedy uses `h(n)` and ignored `g(n)`.

#### A * Search
* Uses `f(n)` which is `g(n) + h(n)`
* result is we get fatter than a greedy search
* but, we could find a path that is of lower cost because we care about that `g(n)`

#### Heuristics
Why and when they _can be_ useful for `A * Search`
* Admissible (does not over estimate the cost)
* Consistent ( `h(n) <= c(n,a,n1) + (h(n1)` )
  * estimate goal from current state (`h(n)`) and from state after action (`h(n1)`),
  then the difference of those two heuristics should be less than the cost in order
  to take the action
* Larger values better (if admissable)
  * becuase large values mean we are well informed, which allows us to avoid
  uninformed searching which means we will expand less nodes
  * delay the non-fruitful nodes as long as possible
* Fast to calculate
  * if it is not fast you defeat the purpose of speeding things up

### Homework
* Finish part 2

## Wed Sep 17

### Announcements
* We are going to look at the search library code _again_
* Maze solver is an example that uses the search library code

### Maze Solver
  * `ai-agents/prog/Maze`
  * `maze1.txt` has the map where `s` is _start_ and `g` is _goal_

#### Action
Purpose is to store the `int` that represents a single action type as defined
by the `enum`.

* Overloads `=` and `==` to make life easier. The `State` class must implement
an `isEqual method.

#### State
* Tracks an `x` and `y` position
* must implement an `IsEqual` method
  * we must convert the passed in pointer to a real object. we do that by
  doing a dynamic cast
  * use the `==` operator to de-reference and compare the two objects

#### Problem
Purpose: expand `state` into possible other states.

* define FindSucessors
* is a state the goal state?
* give the cost between two states
* you only need to override Heuristic if you're using greedy or a * search
* StepCost will just return 1 if we're not worried about cost
* constructor should take an initial state
* destructor should delete the initial state

The maze problem class does use a model that stores the grid.

##### StepCost
* Demos the dynamic casting (useful!)

##### FindSuccessors
* `dx` and `dy` represent up, down, left, right
  * that way we get the `x` and `y` if we traveled in any of those directions
  * create a new state and action based on the state and the action to get to that state
* returns true if there were any legal actions added to `results_out`

The maze includes two versions of _bringing it all together_. See below:

#### MazeDriver
This code would be inside our Agent.

In order to call the search method in the algorithm:
1. create an algorithm (either a tree or a graph)
  * you must pass it a `problem` and `frontier` pointer
  * see where `the_algorithm` is initialized
  * there are several different fringe options (BFFringe, etc)
  * `the_frontier` must be allocated off the heap and DO NOT FREE IT
  * `the_problem` must also be allocated off the heap and DO NOT FREE IT
  * `the_problem` requires an initial state
2. `Search` method returns a `boolean` representing the goal test
3. call `GetSolution()`
4. iterate over the solution asking for action and state along the way
  * _i have a solution, what are the steps?_
5. delete the_algorithm

See MazeSolver for more flexible options.

#### MazeSolver
More complicated `main` because it supports command line options.

* BuildSearchAux selects the fringe

### Examples
`cgla2Demo.tgz` demonstrates using the search.

## Mon Sep 19

### Announcements
None

### Calculating charge cost
```
h = (1000 * 0.001) + interfacePenalty
v = dz * 0.001
```
* `h` is horizontal cost
* `interfacePenalty` is 1 if terrain is mud, otherwise it is 0
* `v` is vertical (or elevation) cost
* you gain change by going down hill though it's never actually profitable

### Search Part 3
* not just find path but execute path to goal
* then find and execute path from goal to base
* agent must know that it completed the task

#### CGLA3DEMO
Look for this code on the downloads.

##### State machine
He has an `enum` for _modes_ to keep track of what the agent is doing.

The Agent starts out in the `FIND_GOAL` state or mode. This is his _state machine_.

* if in FIND_BASE mode and doesn't have any actions in its queue, then do a search
for the base
* then executes the actions and goes into the 'QUIT' mode
* executes 'QUIT' action

Agent can jump from state to state in any order. For example, if he is in 'FIND_GOAL'
mode and can't find a goal it can jump straigh to 'QUIT' mode.

See the `Problem` method in his cgla3Demo.cpp for examples of changing his mode.

##### FindPathToGoal
Sends the SearchProblem the mode so it knows to look for the goal vs the base.

Loops over the solution list looking for a pointer to a search action. Pushes the
de-referenced search action.

##### FindPathToBase
Major difference is that the search problem is trying to find the base.
The meat is identical to `FindPathToGoal` because of how we store the goal in
the `model`.

### Heuristics
Remember larger heuristics are better.

### Homeworkd
* Ponder the slider problem

## Mon Sep 22

### Heuristics (again)
Heuristic must be:
* Admissible _(never over estimates)_ `h(n) <= c(n, g)`
  * `c(n, g)` = the `cost` of going from `n` to the `goal`
* Consistent `h(n) <= c(n,n') + h(n')`
* Dominate `h1(n) >= h2(n)`

## Wed Sep 24

* We are starting on the next assignment

### Assignment 2

* we will be using the `LOOK` command
  * agent needs to remember which direction it looked when it looks
* we add cells as we discover them
  * at first we only know the `x` and `y` of the cell until we go there
* do all of this assignment in a separate branch, preserving the first assignment

1. Look north, south, east and west to discover interfaces for base and
record them in the model
  * if we look north and see plain, we know that the cell to the north has `plain`
  to its south. fill everything else in later

#### Online search purpose
Physically moving when it knows it can move somewhere and learn more information.
Once it gets there it decides should I go up, down, etc.

**Goal:** get to somewhere it hasn't been before. Discover!
  * if the cell i'm standing in has an unknown interface to the north, `LOOK` north.

1. Do a search from current cell to nearest unexplored cell (use uniform cost)
2. do a separate search from unexplored cell to home (use A * )
3. make sure we have enough charge to go from current cell to unexplored cell
then to home.
4. go home either now or from unexplored cell depending on charge

**Explore the map and find as many cells as possible.** Oh, and pick up interesting
objects. And make it fast so you can get bonus points.

## Fri Sep 26

## MiniMax
* See the tic tac toe code example
* `ply_data` is a struct for housing our multiple return values

## Mon Sep 29

### Announcements
* We are sticking with tic tac toe to learn MiniMax and to get excited about
the algortithm

### Searching with opponents
First let's talk about the scenario where you can't search for an end game.

#### Cutoff layer
_When you can't search to the end of the game so you set a limit_
* Use an `Evaluation(state, player)` function to pick from the cutoff layer

##### Evaluation function
Takes a state and a player
* An `Oracle` could, given a state, tell you exactly how far away you are from
the goal which would result in a perfect `heuristic`
* The point of a cutoff layer is to not use an oracle
* An evaluation function that tries to be an oracle defeats the purpose of a
cutoff layer
* So, the purpose of an Evaluation function is to estimate and not try to be perfect
* the player that is passed is always the player whose turn it is regardless of
min or max

Ask: _how many turns am I away from a win and how many turns is my opponent away
from a win?_ Take the difference and return it.

### Homework
* it costs .25 to charge. So to get back to the base you have to have at least
.25 when you get there.
* worlds 1 and 2 can't be solved for part 2

## Wed Oct 01

### Alpha-Beta pruning
In `b^d` we cut down on `d` with a cutoff. To cut down on `b` we need to prune
some branches, ie _limit the amount of legal actions_ or ignore moves that are
obviously bad.

Example: if we are looking for a max node and we've found a 1 and come across a
-1 we can ignore it because 1 is greater than -1 so it is obviously not a winner.

Remember: MiniMax is just a breadth-first search.

For a max node:
<pre>alpha = MAX(alpha_in, child_in)</pre>
<pre>beta = beta_in</pre>

At a min node:
1. keep if greater than or equal to `alpha_in`
  * this will not prune as many branches but it makes a better agent (the equal
  to part)

## Fri Oct 03

### Mancala
* demonstrates benefits of an evaluation function
* contains example code for AlphaBeta

## Mon Oct 06

### Announcements
* Written exam will be in the testing center right after fall break
* Quizes: go to downloads page and review the quizzes as prep for the exam
* come back with questions from quizzes
* should be progressing with scavenger agents

### Propositional Logic
Definitions:

_Making known statements and then inferring truths from known statements._

_Derive knowledge that wasn't originally told._

1. agent keeps a knowledge base of facts it knows are true
  * _north of 0,0 is a plain_
2. percepts are used to generate facts for our knowledge base
3. decisions are made by asking questions of the facts
  * _is it safe for me to move north?_
4. background knowledge (or physics) are things that are true regardless of the
problem.
  * _fact: plain interfaces are ALWAYS safe._

#### Evaluation:
1. Physics knowledge (Background)
2. Instance knowledge (Tell)
3. Questions (Theorems, Ask)

#### Grammar
_see download notes for this slide_

`=>` | implies | one fact implies another fact will be true
`<=>` | bidirectional implication | if one is true the other will also be true
`⋁` | or | this or that
`⋀` | and | this and that
`¬` | not | not this

**See the truth table in the download notes**

#### Entailment
> if beta is true everywhere alpha is true then alpha entails beta

Given everything we know about the world, is it safe for us to move north?

## Wed Oct 08

### Announcements
* GET YOUR ASS IN GEAR
* Curtis will be available to help Thur Oct 9 from 8-9am in Hazy 119
* Chinese checkers assignment will be posted by Friday

### Propositional Logic
* Literals: single symbol or a negated symbol
* Clause: disjunction of literals (only `or`s and `not`s)
* Inference algorithm: process to check for entailment
* Sound: never a false positive
* Complete: never a false negative

### Proof by contradiction
alpha entails beta if `alpha AND NOT beta` is false everywhere.
> Assume the opposite and prove that it can't happen.
Basically solidifies the entailment.

### DPLL
Prunes the tree.
* Early termination
* Pure symbol heuristic
* Unit clause heuristic

# Midterm Review

## Adversarial Search

### Which move will be selected by Minimax? Assume left to right processing
* You can shuffle the tree
* sort the min row in desc order
* sort the max row in asc order

Just give the leaf nodes in the correct order:

**[6, 2, 3], [9, 7, 4], [1000, 9, 1] which would be C**

### Define the following agent terms
Print out and use the book then study

* Performance measure: measure overall activity of agent over its lifetime
* Utility: measure happiness of a state
* Deterministic: you can predict the result for any action
* Stochastic: your agent might take an action without knowing the result
* Static: unless an agent takes an action, nothing changes
* Dynamic: the environment can change the world
* Fully observable vs Partially ovservable: Does your agent know _everything_?
* Known vs unknown: Does your agent know what will happen if?
* Continuous: you end up with infinite branching factor

### What assumptions did we make for minimax to work?
* Episodic from a search standpoint because each turn we make one decision.

I missed the rest. Consult the book.

### What environments are searches in chapter 3 restricted to?
* Fully observable for the searchable part
* Single Agent
* Deterministic
* Sequential
* Static
* Discrete
* Known

### In vacuum example, how would you classify a world where the suck action pics up all the dirt 85% of the time?
Stocastic

What if the dust settles? Dynamic


### Define again
* State space: collection of all positions on the map. Might include charge if charge counts
* Optimal solution: solution of the lowest cost
* Explored set: closed list; nodes you've already seen and expanded and found their successors
  * used primarily in graph search
* Successor: one of the states branched from a previous state given an action
* Expanding a node: finding all successors
* completeness: if there is a solution it will find it
* optimality: it will find the optimal solution
* space complexity: the big O of memory consumption
* time complexity: big O of time (how many must be examined before we run out of time)
* repeated state: state we have been to before. detected by the _explored set_
* branching factor: number of children

### More Search Terms
Separate slide from above

### Game Search Tree
Examine the minimax game search tree shown in the diagram.

First row chooses the MAX

a) B would be chosen

b) max nodes update alpha, min nodes update beta.
  * start with alpha = -inifinity, beta = infinity on every node

## Propositional Logic

### Terms
* Knowledge base: all sentences that are currently known about that world
* Entailment: the question is true because the knowledge base is true; something
that can be inferred
* Sound: no false positives
* Complete: no false negatives
* Valid: a valid sentence is always true
* Satisfiable: one more values make it true
* Unsatisfiable: fewer than one values make it true
* Proof by contradiction: alpha and not beta is satisfiable `SAT(alpha && !beta)`
* Truth table entailment: beta is true everywhere alpha is true
* Conjunction: `and` of things
* Disjunction: `or` of things

### Truth tables
`A <=> B`: where A is true, B must be true. Both A and B have to be the same.
`A => B`: `false => B` is always `true`. But `true => false` is false.

Entailment probably won't be on the test.

Break the sentence up and solve.

### Sample Search Strategy Exam Question

### a)
Search    Time    Space
BFS       O(b^d)  O(b^d)
          O(30^6) O(30^6)

DFS       O(b^m)  O(b * m)
          O(30^infinity)  O(30 * infinity)

#### b)
Use ID starting at 6 or DL(6) # depth limited with a limit of 6
Go with depth limited using a tree search.

### c)
```
`f=g+h` and `f` is what we sort by.
`g` is cost
Put `A` in the priority queue and pop it out and expand its children.
B: 6
C: 8
```

#### Which got expanded?
A, B, D, E, I, J, K

#### Is it admissable?
Admissable means it does not overestimate. Work backwards from the goal and make
sure the path cost is greater than the node's value. Leaf nodes get infinity and
are never an overestimate.

### Puzzle story
Don't solve just translate into propositional logic ie physics, glossary, etc.

## Singood

### Dictionary
```
SinA: singood is A
1stB: First mate is B
... 9 symbols total
```

### Physics
```
SinA => !SinB && !SinC
.
.
.
SinA || SinB || SinC
// singood must be one and only one of A, B, or C
```
