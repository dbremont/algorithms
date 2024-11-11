### Speech Recognition

**Objective:** Build a simple Markov chain model for recognizing spoken words or phonemes.

**Description:** Use a Markov model to recognize sequences of phonemes or words in spoken language. Each state represents a phoneme or a word, and transitions between states are based on observed phoneme or word sequences.

**Steps:**

1. **Training Data:** Collect a corpus of spoken language data, including phoneme or word sequences.
2. **Model Training:** Create a Markov model where each state is a phoneme or word, and transition probabilities are learned from the training data.
3. **Recognition:** Given a sequence of observed phonemes or words, use the Viterbi algorithm to determine the most likely sequence of states.

**Example:**
Recognize the spoken word "hello" from a sequence of phonemes: [h, e, l, o].
