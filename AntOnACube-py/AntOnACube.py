from Graph import Graph
from Simulation import Simulation

if __name__ == '__main__':
    graph = Graph()
    sim = Simulation(100, graph.build_cube())
    sim.run()
    print(sim.avg())
