#!/bin/bash

# Number of tests to run for each N
NUM_TESTS=5

# Run tests for each N from 1 to 100
for N in {1..1000}; do
  for TEST_NUM in $(seq 1 $NUM_TESTS); do
    # Generate N random numbers
    RANDOM_NUMBERS=$(shuf -i 1-10000 -n $N | tr "\n" " ")
    
    # Run the PmergeMe program with the generated random numbers
    ./PmergeMe "$RANDOM_NUMBERS"
    
  done
done
