from pprint import pprint
import numpy as np
import matplotlib.pyplot as plt

# full graph generation
def get_full_graph(N=25):
    matrix = np.ones((N,N), int)
    np.fill_diagonal(matrix, 0)
    return matrix

# random graph generation
def get_random_graph(N=25, remove_coef=0.6):
    matrix = get_full_graph(N)
    k = int((len(matrix)**2-len(matrix))*remove_coef) // 2
    for t in range(k):
        x = np.random.randint(len(matrix), size=2)
        matrix[x[0]][x[1]] = 0
        matrix[x[1]][x[0]] = 0
    return matrix

def get_bipartite_graph(N=25):
    matrix = np.zeros((N,N), int)
    for i in range(0, N):
        for j in range(0, N):
            if j == (i+1) and i<N-1:
                matrix[i][j] = 1
#            elif j == (i-1) and i>0:
#                matrix[i][j] = 1
    return matrix

def get_max_colors(graph):
    return graph[graph.sum(axis=1).argmax()].sum()+1

def generate_population(population_size, individual_size, max_colors):
    return np.random.randint(max_colors+1, size=(population_size, individual_size))

def fines(individual, graph):
    fine = 0
    for i in range(len(individual)-1):
        for j in range(i+1, len(individual)):
            if individual[i] == individual[j] and graph[i][j] == 1:
                fine += 1
    return fine

def tournament_selection(population, graph, k=2):
    new_population = [] #np.array((0,0), int)
    for t in range(k):
        np.random.shuffle(population)
        for i in range(len(population)//k):
            x = np.array([fines(ind, graph) for ind in population[i*k: k*(i+1)] ])
            new_population.append(population[i*k: k*(i+1)][x.argmin()])
    return np.array(new_population[:len(population)+1])

def mutation(population, max_colors, probability=0.3):
    mutations = np.random.rand(len(population))
    count = 0
    for i in range(len(mutations)):
        if mutations[i] > probability:
            count += 1
            index = np.random.randint(len(population[i]))
            population[i][index] = np.random.randint(max_colors)
    return population, count

def draw(population, graph, max_colors):
    x = np.array([fines(ind, graph) for ind in population])
    uniques, counts = np.unique(x, return_counts=True)
    fitnes = [[len(graph)-t[0], t[1]] for t in zip(uniques, counts)]
    fitnes.sort()
    to_show = [0 for i in range(len(graph)+1)]
    for obj in fitnes:
        to_show[obj[0]] = obj[1]
#    plt.hist(to_show, weights=(to_show), range=(0,max_colors+1), bins=max_colors+1)
#    plt.show()

def evoluate(graphtype, budget=20):
    def avg_fitnes(population, graph):
        x = np.array([fines(ind, graph) for ind in population])
        uniques, counts = np.unique(x, return_counts=True)
        fitnes = [(len(graph)-t[0])*t[1] for t in zip(uniques,counts)]
        avg = 1
        for i in fitnes:
            avg += i
        return avg/len(population)

    solution = None
    fine = None
    if graphtype == 'full':
        graph = get_full_graph(25)
    elif graphtype == 'random':
        graph = get_random_graph(25)
    elif graphtype == 'bipartite':
        graph = get_bipartite_graph(25)
    max_colors = get_max_colors(graph)
    population_size = 50 + np.random.randint(200)
    population = generate_population(population_size, 25, max_colors)
    generation = 0
    start_avg_fitnes = avg_fitnes(population, graph)
    draw(population, graph, max_colors)
    while generation < budget:
        population = tournament_selection(population, graph, k=4)
        population, count = mutation(population, max_colors)
        generation += 1
        draw(population, graph, max_colors)
        x = np.array([fines(ind, graph) for ind in population])
        if x.min() == 0:
            solution = population[x.argmin()]
            fine = 0
            break
    if solution is None:
        x = np.array([fines(ind, graph) for ind in population])
        solution = population[x.argmin()]
        fine = x.min()
    result_avg_fitnes = avg_fitnes(population, graph)
    return solution, fine, generation, population_size, start_avg_fitnes, result_avg_fitnes, max_colors

if __name__ == '__main__':
    np.random.seed(100)

    for i in range(10):
        solution, fine, generation, population_size, start_avg_fitnes, result_avg_fitnes, max_colors = evoluate('full')
        uniques = np.unique(solution)
        print(i, max_colors, fine, generation, population_size, start_avg_fitnes, result_avg_fitnes)


    for i in range(10):
        solution, fine, generation, population_size, start_avg_fitnes, result_avg_fitnes, max_colors = evoluate('random')
        uniques = np.unique(solution)
        print(i, max_colors, fine, generation, population_size, tart_avg_fitnes, result_avg_fitnes)

    for i in range(10):
        solution, fine, generation, population_size, start_avg_fitnes, result_avg_fitnes, max_colors = evoluate('bipartite')
        uniques = np.unique(solution)
        print(i, max_colors, fine, generation, population_size, start_avg_fitnes, result_avg_fitnes)
