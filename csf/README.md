# Classical Algorithms

> The computational units behind computational systems.

## Guide

| **Algorithm**                         | **Domain**                   | **Primary Use Case**                                                                 |
|----------------------------------------|------------------------------|--------------------------------------------------------------------------------------|
| **Quicksort**                          | Sorting                      | Efficient sorting algorithm based on the divide-and-conquer principle.               |
| **Merge Sort**                         | Sorting                      | Stable, divide-and-conquer sorting algorithm that divides the list and merges.       |
| **Dijkstra's Algorithm**               | Graph Theory                 | Finds the shortest path between nodes in a graph, commonly used in routing.          |
| **A* (A-star) Algorithm**              | Pathfinding/Graphs           | Pathfinding algorithm that finds the shortest path using heuristics.                |
| **K-means Clustering**                 | Machine Learning             | A clustering algorithm used to partition data into K clusters.                       |
| **Support Vector Machines (SVM)**      | Machine Learning             | Supervised learning algorithm for classification and regression tasks.               |
| **Decision Trees**                     | Machine Learning             | A supervised learning algorithm for classification and regression tasks.             |
| **Backpropagation (Neural Networks)**  | Machine Learning             | Used for training neural networks through gradient descent.                          |
| **Naive Bayes**                        | Machine Learning             | Classification algorithm based on Bayes' Theorem, commonly used for text analysis.   |
| **PageRank**                           | Web/Search Algorithms        | Algorithm used by Google to rank web pages in search results based on links.         |
| **Bellman-Ford Algorithm**             | Graph Theory                 | Finds the shortest paths from a single source node to all other nodes in a graph.     |
| **K-nearest Neighbors (K-NN)**         | Machine Learning             | Classification algorithm based on the closest training examples.                      |
| **Huffman Coding**                     | Data Compression             | Algorithm used for lossless data compression based on frequency of occurrence.       |
| **Prims Algorithm**                    | Graph Theory                 | Finds the minimum spanning tree for a weighted undirected graph.                     |
| **Floyd-Warshall Algorithm**           | Graph Theory                 | Computes shortest paths between all pairs of nodes in a weighted graph.              |
| **Genetic Algorithms**                 | Optimization/AI              | Evolution-inspired algorithm for optimization problems, used in AI and machine learning.|
| **Bloom Filter**                       | Data Structures              | Space-efficient probabilistic data structure used to test if an element is a member of a set. |
| **RSA Algorithm**                      | Cryptography                 | Public-key encryption algorithm for secure data transmission.                       |
| **SHA-256**                            | Cryptography                 | A cryptographic hash function used to securely generate hash values.                 |
| **Monte Carlo Simulation**             | Statistics/Mathematics       | A probabilistic algorithm for solving mathematical problems through random sampling. |
| **Apriori Algorithm**                  | Data Mining                  | Algorithm used to mine frequent itemsets in transactional databases.                 |
| **Fisher-Yates Shuffle**               | Randomization                | Algorithm for generating a random permutation of a finite sequence.                  |
| **Lamport's Bakery Algorithm**         | Concurrency                  | Algorithm for mutual exclusion in concurrent programming to prevent race conditions.  |
| **Peterson's Algorithm**               | Concurrency                  | Algorithm for achieving mutual exclusion in a system with two processes.             |
| **Paxos Algorithm**                    | Distributed Computation       | Consensus algorithm used to achieve agreement in a distributed system.               |
| **MapReduce**                          | Distributed Computation       | Framework for processing and generating large data sets using a distributed algorithm. |
| **Raft Algorithm**                     | Distributed Computation       | Consensus algorithm that ensures distributed systems agree on a state in the presence of failures. |
| **Quorum-based Replication**           | Distributed Computation       | Method for ensuring fault tolerance in distributed databases through consensus.      |
| **Vector Clocks**                      | Distributed Computation       | Used to capture causality and synchronize clocks in distributed systems.             |
| **Red-Black Tree**                     | Data Structures              | A self-balancing binary search tree to maintain balanced tree heights.               |
| **AVL Tree**                           | Data Structures              | A self-balancing binary search tree that maintains strict balancing criteria.        |
| **Trie**                               | Data Structures              | A tree-like data structure for storing strings in an efficient manner.               |
| **Hash Table**                         | Data Structures              | A data structure that allows for fast retrieval using a hash function.              |
| **LR Parser**                          | Compiler/Interpreter         | A bottom-up parser used in compilers to analyze context-free grammars.               |
| **Top-Down Parsing (Recursive Descent)**| Compiler/Interpreter         | A recursive method used in parsing in compilers, often with context-free grammars.   |
| **SIFT (Scale-Invariant Feature Transform)**| Computer Vision           | Algorithm for detecting and describing local features in images, invariant to scale and rotation. |
| **First-Fit Algorithm**                | Memory Management (OS)       | Memory allocation strategy where the first available memory block that fits is used. |
| **Round-Robin Scheduling**             | Operating Systems            | Scheduling algorithm that allocates time slices for processes in a cyclic order.     |
| **Banker's Algorithm**                 | Operating Systems            | Safety algorithm used in resource allocation to avoid deadlock in an operating system. |
| **LRU (Least Recently Used)**          | Caching (OS)                 | Algorithm used to manage cache by evicting the least recently used item.            |
| **Semaphore**                          | Concurrency                  | Synchronization mechanism used to control access to a shared resource in concurrent programming. |
| **Fork-Join Model**                    | Concurrency                  | Used for parallel execution, splitting tasks into smaller sub-tasks that can be executed concurrently. |
| **Two-Phase Commit Protocol**          | Distributed Computation      | Ensures atomicity of transactions in distributed systems by having a commit and abort phase. |
| **Graph Coloring**                     | Graph Theory                 | Algorithm used to assign colors to vertices in a graph, ensuring adjacent vertices have different colors. |
| **Kruskal’s Algorithm**                | Graph Theory                 | Finds the minimum spanning tree for a weighted graph by adding edges in order of increasing weight. |
| **Geohash**                            |                              | Used to build location-based services. |
| **HyperLogLog**                        |                              | Counting unique queries performed by users in a search. |
| **Consistent Hashing**                 |                              | Used for efficient data distribution between the cluster’s nodes.|
| **Merkle Tree**                        |                              | Used to detect inconsistencies between data replicas across multiple nodes.|
| **Raft Algorithm**                         |                              | Used to achieve consensus on log replication. |
| **Lossy Count**                            |                              | Network traffic analysis, web analytics, and identifying heavy hitters.|
| **QuadTree**                               |                              | Used to build location-based services.|
| **Operational Transformation**             |                              | Used to support collaborative editing systems.|
| **Leaky Bucket**                           |                              | Used for rate limiting |
| **Rsync**                                  |                              | Synchronizing files and directories between two different systems.|
| **Ray Casting**                            |                              | Used for geospatial analysis, collision detection in video games, and computer graphics.|


## Data Structures

> Study and application of essential data structures such as arrays, linked lists, stacks, queues, trees, graphs, and hash tables, focusing on their properties, operations, and use cases in solving computational problems.

| **Data Structure**       | **Description**                                                                 | **Key Use Cases**                                                                 |
|---------------------------|---------------------------------------------------------------------------------|-----------------------------------------------------------------------------------|
| **Set**                   | A collection of unique elements.                                               | Removing duplicates, membership testing, and mathematical operations.            |
| **Trie**                  | A tree-like structure for storing strings, where each node represents a character. | Autocomplete, spell checking, and IP routing.                                   |
| **Heap**                  | A specialized tree-based structure where the parent node is ordered relative to its children. | Priority queues, scheduling, and algorithms like Dijkstra's.                    |
| **Tree**                  | A hierarchical structure with a root node and child nodes.                     | Representing hierarchical data (e.g., file systems, organization charts).         |
| **Stack**                 | A Last-In-First-Out (LIFO) data structure.                                     | Function call management, undo/redo operations, parsing expressions.             |
| **Queue**                 | A First-In-First-Out (FIFO) data structure.                                    | Task scheduling, buffering, breadth-first search (BFS).                          |
| **Graph**                 | A collection of nodes (vertices) connected by edges.                           | Modeling networks (e.g., social networks, maps, dependencies).                   |
| **Array**                 | A fixed-size collection of elements, stored contiguously in memory.            | Storing and accessing sequential data (e.g., lists, matrices).                   |
| **Map/Dictionary**        | A collection of key-value pairs, where keys are unique.                        | Storing and retrieving data by key (e.g., configurations, caches).               |
| **Skip List**             | A probabilistic alternative to balanced trees with layered linked lists.        | Implementing ordered sets and maps with simpler balancing than trees.            |
| **AVL Tree**              | A self-balancing binary search tree with strict height balancing.               | Applications requiring frequent lookups, insertions, and deletions.              |
| **B-Tree**                | A self-balancing tree structure optimized for disk access.                      | Database indexing (e.g., SQL databases, file systems).                           |
| **Octree**                | A tree structure for partitioning 3D space into regions.                        | 3D graphics, volumetric data, and physics simulations.                           |
| **R-Tree**                | A tree structure for spatial indexing of multi-dimensional data.                | Geographic information systems (GIS), spatial databases, and nearest-neighbor search. |
| **Quadtree**              | A tree structure for partitioning 2D space into regions.                        | Image processing, collision detection, and game development.                     |
| **Suffix Tree**           | A compressed trie containing all suffixes of a string.                          | Substring search, longest common substring, and DNA sequence analysis.           |
| **Suffix Array**          | An array of all suffixes of a string, sorted lexicographically.                 | String matching, bioinformatics, and text compression.                           |
| **Bloom Filter**          | A probabilistic data structure for testing set membership.                     | Spell checkers, network routers, and database query optimization.                |
| **Linked List**           | A collection of nodes, each containing data and a reference to the next node.  | Dynamic memory allocation, implementing stacks, queues, and adjacency lists.     |
| **Hash Table**            | A collection of key-value pairs, using a hash function for fast lookups.       | Implementing dictionaries, caches, and database indexing.                        |
| **Fenwick Tree (BIT)**    | A tree-like structure for efficient prefix sum calculations.                    | Dynamic frequency counting, range sum queries, and financial applications.       |
| **Red-Black Tree**        | A self-balancing binary search tree with colored nodes.                         | Implementing ordered maps (e.g., C++ `std::map`, Java `TreeMap`).                |
| **Circular Buffer**       | A fixed-size buffer that wraps around when full.                                | Real-time data streaming, audio processing, and producer-consumer problems.      |
| **Segment Tree**          | A tree structure for efficient range queries and updates.                       | Range minimum/maximum queries, interval scheduling, and computational geometry.  |
| **Binary Search Tree (BST)** | A tree where each node has at most two children, with left < root < right.   | Efficient searching, sorting, and range queries.                                 |
| **Disjoint Set (Union-Find)** | A structure for managing partitions of a set with efficient union and find operations. | Kruskal’s algorithm, image processing, and network connectivity.                |
| **Trie with Suffix Compression** | A compressed trie for efficient storage of strings.                          | Autocomplete, spell checking, and IP routing with reduced memory usage.          |
| **Persistent Data Structures** | Immutable data structures that preserve previous versions.                   | Functional programming, version control, and undo/redo systems.                  |

## References

- [List of algorithms](https://en.wikipedia.org/wiki/List_of_algorithms)
- [Outline of computer science](https://en.wikipedia.org/wiki/Outline_of_computer_science)
- [Combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization)
- ...
