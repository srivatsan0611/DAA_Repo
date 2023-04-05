# DAA_Repo README
This is a Repo Made for submissions for the course CS2004-Design and Analysis of Algorithms in Shiv Nadar University, Chennai

Consists of the following:

1. Needleman-Wunsch Algorithm in C
2. Artificial Neural Network Implementation
3. ANN using Genetic Algorithm Optimization
4. ANN using Cultural Algorithm Optimization
5. ANN using Particle Swarm Optimization
6. ANN using Ant Colony Optimizatoin


## 1. Needleman-Wunsch Algorithm [ CIA -1 ]

### Needleman-Wunsch Algorithm Program
This program takes in two DNA sequences of equal length and performs the Needleman-Wunsch algorithm to align the sequences and calculate the matching score. The program reads the sequences and their length from standard input and uses a scoring matrix to calculate the optimal alignment.

The program uses a dynamic programming approach to calculate the alignment matrix, score matrix, and trace matrix. It then traces back the optimal alignment using the traceback matrix and outputs the aligned sequences and matching score.

### Scoring Matrix
The scoring matrix used in this program gives a score of +2 for a match and -1 for a gap (insertion or deletion). The program initializes the score matrix with gap penalties for the first row and column and zeroes for the rest of the matrix.

### Usage
To run the program, compile the source code using a C compiler such as GCC:

```gcc needleman_wunsch.c -o needleman_wunsch```

Then, run the program and enter the two DNA sequences when prompted:
`./needleman_wunsch
Enter sequence 1: ATCG
Enter sequence 2: ACGT`

The program will output the matching score and the two aligned sequences.

Kindly Note - The Max Seq Length is a Defined Variable of Length 10, Which you can change within the code.


## 2. Artifician Neural Networks and Optimization Algorithms [ CIA -2 ]

The dataset used here is the Bank-Personal-Loan-Modelling Dataset which has a target variable 'personal loan'

The general steps followed here are:

1. Design a neural network architecture appropriate for the given dataset.
2. Initialize the weights of the neural network.
3. Choose an optimization algorithm (Genetic Algorithm, Cultural Algorithm, Particle Swarm Optimization, or Ant Colony Optimization).
4. Train the neural network using the chosen optimization algorithm to find the weights that minimize the loss function.
5. Evaluate the accuracy of the trained neural network on a validation dataset to determine how well it generalizes to new data.

##### General Preprocessing
Was done by simply dropping the columns "ID" and "ZIP Code" as they provide no mathematical information and simply isn't a factor.
This is applied throughout the 5 ANN variations.

### GA vs CA vs PSO vs ACO

#### Genetic Algorithm 

This genetic algorithm is designed to optimize the weights of a neural network model using a fitness function. The goal is to find the set of weights that maximizes the model's performance on a given dataset.

The genetic algorithm follows these steps:

1. Initialize a population of random weight vectors.
2. Evaluate the fitness of each weight vector in the population using the fitness function.
3. Select the two weight vectors with the highest fitness scores as parents.
4. Generate new offspring weight vectors by performing crossover and mutation on the parents.
5. Evaluate the fitness of the offspring weight vectors using the fitness function.
6. Combine the parents and offspring to form a new population.
7. Iterate over a specified number of generations.


The fitness function used in this genetic algorithm is defined as the negative of the loss of the model, which is calculated using the given dataset and the weights of the model.

To set the weights of the model for each weight vector, the weights are first reshaped to the appropriate shape for the neural network layers. Then, the weights are set for the layers of the model, and the model is compiled using the specified optimizer and loss function. The loss of the model is then evaluated using the training dataset, and the negative of the loss is returned as the fitness score for that weight vector.

After a specified number of generations, the genetic algorithm returns the weight vector with the highest fitness score, which represents the set of weights that achieved the best performance on the given dataset.


### Cultural Algorithm

This implementation uses a belief space in addition to the population to guide the search process.
Can be considered like GA + Belief Space [Guided Search Space]

Steps:
1. Initialize the population and belief space with random weights.
2. For each generation, evaluate the fitness of each individual in the population.
3. Select the top two individuals in the population as parents.
4. Generate offspring by performing crossover and mutation on the parents and randomly selecting a parent from the belief space.
5. Combine the parents and offspring to form the new population.
6. Update the belief space by adding the parents and selecting the top individuals.
7. Iterate over a specified number of generations.
8. Return the weights of the individual with the highest fitness score.


Parameters:
- population_size: The size of the population.
- generations: The number of generations to run the algorithm.
- mutation_rate: The probability of mutating an individual.
- belief_space_size: The size of the belief space.

### Particle Swarm Optimization

Particle Swarm Optimization (PSO) is a population-based stochastic optimization algorithm that was inspired by the social behavior of bird flocking or fish schooling. 

Steps: 

1. Initialize a swarm of particles with random positions and velocities.
2. Evaluate the fitness of each particle.
3. Update the personal best-known position and fitness for each particle based on their current position and fitness.
4. Update the global best-known position and fitness based on the personal best-known positions and fitnesses of all particles.
5. Adjust the velocity and position of each particle based on their personal best-known position and the global best-known position, using the following equation:

velocity(t+1) = w * velocity(t) + c1 * r1 * (personal_best_position - current_position) + c2 * r2 * (global_best_position - current_position)

position(t+1) = current_position + velocity(t+1)

where w is the inertia weight, c1 and c2 are the cognitive and social learning coefficients, and r1 and r2 are random values between 0 and 1.

6. Clip the particle's position to the search space boundaries if necessary.
7. Repeat for a fixed number of iterations or until a convergence criterion is met.
8. Return the global best-known position as the optimal solution.

### Ant Colony Optimization

Ant Colony Optimization (ACO) is a metaheuristic algorithm that is inspired by the foraging behavior of ants. The algorithm is used for optimization problems and is particularly suited to problems that can be modeled as a graph.

The ACO algorithm starts by initializing a population of ants with random solutions to the problem. The ants then follow pheromone trails left by other ants as they search for food. In the ACO algorithm, the pheromone trails are represented as a matrix. Each ant constructs a solution to the problem by probabilistically selecting the next component of the solution based on the pheromone level of that component.

1. Initialize the pheromone matrix with a value of 1 for each element.
2. Initialize the best weights and the best loss to None and 99, respectively.
3. For each iteration:
  1. Initialize an ant population and ant accuracies.
  2. For each ant:
    1. Create a weight matrix with dimensions (12,6).
  3. For each element of the weight matrix:
    - If a randomly generated value is less than the corresponding element in the pheromone matrix, set the value of the element to a random number drawn from a normal distribution with mean 0 and standard deviation 1.
  4. Evaluate the loss of the weight matrix using the fitness function.
  5.. Add the weight matrix and its corresponding loss to the ant population and ant accuracies, respectively.
3. If the loss of the weight matrix is better than the current best loss, update the best weights and the best loss.
4. Update the pheromone matrix:
  1. For each element of the pheromone matrix, reduce its value by a factor of the evaporation rate.
  2. For each ant in the population:
    1. For each element of the weight matrix of the ant:
      1. If the value of the element is not equal to 0, increase the value of the corresponding element in the pheromone matrix by Q divided by the loss of the ant multiplied by the value of the element in the weight matrix.
  3. If the current iteration is a multiple of 10, print the current iteration and the current best loss.
5. Return the best weights.
