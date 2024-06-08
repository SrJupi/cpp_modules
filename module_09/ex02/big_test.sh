#!/bin/bash

# Number of simulations to run
NUM_SIMULATIONS=1000

# Range for the number of random numbers (N)
MIN_N=1
MAX_N=20000

# Run simulations
for SIMULATION in $(seq 1 $NUM_SIMULATIONS); do
  # Generate a random N between MIN_N and MAX_N
  N=$(shuf -i $MIN_N-$MAX_N -n 1)
  
  # Generate N random numbers
  RANDOM_NUMBERS=$(shuf -i 1-30000 -n $N | tr "\n" " ")
  
  # Run the PmergeMe program with the generated random numbers
  ./PmergeMe $RANDOM_NUMBERS
done
