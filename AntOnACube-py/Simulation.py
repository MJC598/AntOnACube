from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from Ant import Ant

class Simulation(object):
    num_sims = 100
    graph = None
    ant_list = None
    total_weight = 0

    def __init__(self, num_sims: int, graph: defaultdict):
        self.num_sims = num_sims
        self.graph = graph

    def run(self):
        ant_list = [Ant(self.graph, 0, 6) for _ in range(self.num_sims)]
        executer = ThreadPoolExecutor(max_workers = 15)
        future_list = []
        for i in range(self.num_sims):
            future_list.append(executer.submit(ant_list[i].move))

        true_sums = sum([i.done() for i in future_list])
        while(true_sums != self.num_sims):
            true_sums = sum([i.done() for i in future_list])

        self.total_weight = sum([a.weight for a in ant_list])

    def avg(self):
        return self.total_weight / self.num_sims




