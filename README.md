# Ant on A Cube Problem
#### Background
Consider an ant crawling along the edges of a cube. The ant traverses a single edge in one second. At each corner it randomly
selects one of the three possible directions and then moves to the next corner. Each of the three directions that the ant can
take are equally probable. What is the mean time taken by the ant to traverse the cube from the starting corner to the opposite
corner? An example pathway, from the figure below, which would take three seconds is the path 1 → 5 → 8 → 7.

#### Expectations
Your task is to build a program using C, C++, or Java that investigates this problem using simulation techniques. The program
should meet the following criteria:
1. Runs on a *nix machine, please provide a makefile and/or build instructions.
2. Provides prompts that enable the user to interact or interface with the simulation at runtime.
3. Simulates on multiple threads simultaneously.
4. Uses caching techniques, if applicable.
Besides the mean time, any additional statistical information reported by the program is a plus.
Provide details on how you verified the results of your simulation.

#### To Build
This C++ project utilizes a very simple CMakeLists.txt to generate it's makefile. In order to build it, make sure you have CMake and g++ installed on your computer. Then on a terminal navigate to the build directory. From here enter the following two commands to make the executable project:
```bash
$ cmake ../AntOnACube/
$ cmake --build .
```
Once here you can run the project now located in the build directory via:
```bash
./AntOnACube
```

#### Design Choices
A number of design choices were made in this project, the big ones are outlined below.
* C++ - This project was done in C++ primarily because in simulation models speed and space is important. Because of this choice I decided to stay away from any GUI design, whereas with Java it would've been considered. The cross compatibility of the code was very important as I was developing on a Windows machine and testing on an Ubuntu machine. However, if I had wanted to focus instead on prototyping or quick modifications I would've chosen Python because of it's compilation down to C and its syntax that can be very easily converted to mathematical symbols.
* Docker - I considered Dockerizing this project to ensure the build can be run in isolation, but given the small size of the project and the specific mention of a makefile (or build instructions) I decided it was not worth the time.
* Thread Pool - Originally I designed the project to create a bunch of threads based on the number of ants walking. However, I began testing with large numbers of simulations and it quickly became a memory problem. To combat this I introduced a thread pool to pull from to combat memory issues and still maintain as many threads as possible.
* Graph Structure - This problem is easily adapted to an octagonal prism, pyramids, etc. as well as other pathways (Bridges of Koenigsberg problem). Because of this, I didn't want the cube to be a big challenge to overcome in the entire design so instead I made it a flexible graph. It also stuck out because it was similar to a problem I dealt with a little over a year ago during a combinatorics class.

#### Math Verification of Results
In order to verify our average we can simply use mathematics of random walks on a graph. The cube outlined above is just an undirected, unweighted graph with each vertex having 3 edges. Because all rules still hold regardless of where the ant is initially dropped (it is still trying to get to the opposite vertex) we can name the starting vertex $v_s$ and the end vertex $v_e$. Subsequently, each other vertex in the cube is at least 1 step away but no more than 2 steps away from $v_e$. They will be denoted $v_1$ and $v_2$ respectively. We can use this with the probability of repeating steps to determine an expected result.

A few important observations:
1. At the initial position, we know that $v_s$ will always have a 100% probability of being 3 units away from $v_e$ and any step the ant takes will move it to a $v_2$. 
2. If the ant is at a $v_2$ vertex \frac{2}{3} of the possible paths leads to a $v_1$ and \frac{1}{3} chance of going back to $v_s$.
3. If the ant is at a $v_1$ vertex \frac{1}{3} of the paths lead to $v_e$ and \frac{2}{3} of the paths lead to $v_2$.
4. $v_e$ always has a distance of 0 from $v_e$.

These 4 observations can be transformed into a system of linear equations to be solved. Given observation one, we can say that $v_s = v_2 + 1$. Given observation two, we can say $v_2 = \frac{2}{3}v_1 + \frac{1}{3}v_s + 1$. Finally, given observation three, we can say $v_1 = \frac{1}{3}v_e + \frac{2}{3}v_2 + 1$. After seeing these equations we simply use substitution to solve for $v_s$.

```math
v_s = (\frac{2}{3}v_1 + \frac{1}{3}v_s + 1) + 1 \\

= v_1 + 3 \\

v_1 = 0 + \frac{2}{3}(\frac{2}{3}v_1 + \frac{1}{3}v_s + 1) + 1 \\

= \frac{18}{45}v_s + 3 \\

v_s = ()\frac{18}{45}v_s + 3) + 3 \\

v_s = 10 \\
```

Therefore we would expect an average of around 10 steps.