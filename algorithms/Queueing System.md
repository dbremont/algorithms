### Queueing System

**Description:**
A service center has three states: 0, 1, and 2. These states represent the number of customers in the queue. The transitions between states are based on the arrival and service rates. The transition probabilities are:

- From state 0 to state 1 with a probability of 0.8 (arrival) and to state 0 with a probability of 0.2 (no arrival).
- From state 1 to state 2 with a probability of 0.5 (arrival), to state 0 with a probability of 0.3 (service completion), and to state 1 with a probability of 0.2 (no arrival or service).
- From state 2 to state 1 with a probability of 0.7 (service completion) and to state 2 with a probability of 0.3 (no arrival or service).

**Tasks:**

1. Formulate the transition matrix for this Markov chain.
2. Find the stationary distribution of the number of customers in the queue.
3. What is the long-term average number of customers in the queue?
