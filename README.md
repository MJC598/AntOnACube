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