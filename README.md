# DAA_Repo README
This is a Repo Made for submissions for the course CS2004-Design and Analysis of Algorithms in Shiv Nadar University, Chennai

Consists of the following:

1. Needleman-Wunsch Algorithm in C
2. Artificial Neural Network Implementation
3. ANN using Genetic Algorithm Optimization
4. ANN using Cultural Algorithm Optimization
5. ANN using Particle Swarm Optimization
6. ANN using Ant Colony Optimizatoin


## Needleman-Wunsch Algorithm [ CIA -1 ]

### Needleman-Wunsch Algorithm Program
This program takes in two DNA sequences of equal length and performs the Needleman-Wunsch algorithm to align the sequences and calculate the matching score. The program reads the sequences and their length from standard input and uses a scoring matrix to calculate the optimal alignment.

The program uses a dynamic programming approach to calculate the alignment matrix, score matrix, and trace matrix. It then traces back the optimal alignment using the traceback matrix and outputs the aligned sequences and matching score.

### Scoring Matrix
The scoring matrix used in this program gives a score of +2 for a match and -1 for a gap (insertion or deletion). The program initializes the score matrix with gap penalties for the first row and column and zeroes for the rest of the matrix.

### Usage
To run the program, compile the source code using a C compiler such as GCC:
`gcc needleman_wunsch.c -o needleman_wunsch`

Then, run the program and enter the two DNA sequences when prompted:
`./needleman_wunsch
Enter sequence 1: ATCG
Enter sequence 2: ACGT`

The program will output the matching score and the two aligned sequences.

Kindly Note - The Max Seq Length is a Defined Variable of Length 10, Which you can change within the code.

