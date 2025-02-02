# Database System Algorithms & Practice

> Databases and system design are foundational areas in computer science and software engineering. They play a critical role in building scalable, efficient, and reliable systems that can handle real-world demands. Mastering these areas requires a deep understanding of algorithms, data modeling, and architectural principles, combined with practical problem-solving skills.

This set of practice problems is designed to help you explore key concepts in database algorithms and system design. By working through these problems, you'll develop the skills needed to design robust systems and optimize database performance. These exercises are ideal for students preparing for interviews, developers enhancing their expertise, or anyone interested in mastering the art of system design and database management.

Algorithms:

- Query Optimization: Techniques to speed up database queries and reduce computational overhead.
- Indexing: Using structures like B-trees, hash indexes, and bitmap indexes to improve data retrieval.
- Transactions and ACID Properties: Ensuring data integrity and consistency in concurrent environments.
- Distributed Databases: Algorithms for partitioning, replication, and distributed consensus (e.g., Paxos, Raft).
- Search and Sorting in Databases: Efficiently handling large-scale datasets.
- HyperLogLog: Estimate cardinalities for large-scale datasets efficiently.
- Leader Election: Implement consensus algorithms like Paxos or Raft for leader election in distributed systems.
- Crash Recovery: Simulate recovery mechanisms, such as WAL (Write-Ahead Logging) or ARIES.
- Lock Management: Design lock-based concurrency control systems (e.g., two-phase locking).
- Isolation Levels: Simulate various isolation levels (e.g., Read Committed, Serializable) and analyze trade-offs.

## Information Retrieval

- ...
Information Retrieval (IR) is the science of finding, organizing, and ranking relevant information from large datasets, often in response to a query. From search engines to recommendation systems, IR is a cornerstone of modern computing, enabling users to access the information they need efficiently and accurately.

This set of practice problems is designed to give you hands-on experience with the foundational concepts, algorithms, and systems in information retrieval. By solving these problems, you'll gain a deeper understanding of how IR systems work and build the skills necessary to tackle challenges in search engines, document ranking, and personalized recommendations.

### Problems

Text Preprocessing:

- Tokenization, stemming, and lemmatization.
- Stopword removal and case normalization.
- Handling noisy or unstructured data.

Indexing:

- Implementing **inverted indexes** for fast retrieval.
- Exploring compressed and distributed indexing methods.
- Dealing with dynamic updates to indexes.

Search and Ranking:

- Implementing ranking algorithms like **TF-IDF** and **BM25**.
- Understanding vector space models and cosine similarity.
- Using language models for document ranking.

Query Processing:

- Designing systems to handle single-word, phrase, and Boolean queries.
- Expanding queries using synonyms or related terms.
- Processing queries in multi-lingual or cross-lingual contexts.

Evaluation of IR Systems:

- Measuring system performance using metrics like **precision**, **recall**, and **F1-score**.
- Implementing ranking-specific metrics such as **NDCG** (Normalized Discounted Cumulative Gain) and **MAP** (Mean Average Precision).
- Analyzing trade-offs between precision and recall for different use cases.

Clustering and Classification in IR:

- Using clustering algorithms to group similar documents (e.g., k-means, hierarchical clustering).
- Implementing classification for query intent or document categorization (e.g., Naive Bayes, SVM).

Relevance Feedback and Personalization:

- Implementing feedback mechanisms like Rocchio’s algorithm.
- Building personalized recommendation systems using collaborative and content-based filtering.

Advanced Topics:

- Implementing latent semantic analysis (LSA) or topic modeling (e.g., LDA).
- Exploring neural IR models like BERT for retrieval tasks.
- Handling large-scale IR tasks with distributed systems like Elasticsearch or Solr.

Domain-Specific IR:

- Searching in specialized domains like legal, medical, or academic corpora.
- Implementing faceted search and filtering.

IR at Scale:

- Using distributed frameworks like Hadoop and Spark for large-scale data processing.
- Building scalable IR systems using tools like Elasticsearch, Lucene, or Solr.


## References

- [simpledb](https://github.com/dbremont/simpledb)
- [Information Retrieval (IR)](https://en.wikipedia.org/wiki/Information_retrieval)
