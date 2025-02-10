 # http://bactra.org/notebooks/text-networks.html
import spacy
import networkx as nx
import matplotlib.pyplot as plt

# Load NLP model
nlp = spacy.load("en_core_web_sm")

# Sample text
text = "Elon Musk is the CEO of Tesla. Tesla acquired SolarCity. SpaceX was founded by Elon Musk."

# Process text
doc = nlp(text)

# Extract entities and relationships
edges = []
for ent1 in doc.ents:
    for ent2 in doc.ents:
        if ent1 != ent2:
            edges.append((ent1.text, ent2.text))

# Create graph
G = nx.Graph()
G.add_edges_from(edges)

# Draw network
plt.figure(figsize=(8, 6))
nx.draw(G, with_labels=True, node_color="lightblue", edge_color="gray", node_size=2000, font_size=10)
plt.show()
