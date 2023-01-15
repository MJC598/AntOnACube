import random
from collections import defaultdict

class Ant(object):
    path = []
    weight = 0
    graph = None
    location = None
    goal = None

    def __init__(self, graph: defaultdict, location: int, goal: int):
        self.graph = graph
        self.location = location
        self.goal = goal
        self.path.append(self.location)

    def move(self):
        choice = random.randint(0,2)
        self.location = self.graph[self.location][choice]
        self.path.append(self.location)
        self.weight += 1
        if self.location != self.goal:
            self.move()





