# ID3 Implementation in Vanilla Python

import  json
from rich import print

# Sample dataset (Play Tennis)
# Each row is a sample: [Outlook, Temperature, Humidity, Wind, PlayTennis]
dataset = [
    ['Sunny', 'Hot', 'High', 'Weak', 'No'],
    ['Sunny', 'Hot', 'High', 'Strong', 'No'],
    ['Overcast', 'Hot', 'High', 'Weak', 'Yes'],
    ['Rain', 'Mild', 'High', 'Weak', 'Yes'],
    ['Rain', 'Cool', 'Normal', 'Weak', 'Yes'],
    ['Rain', 'Cool', 'Normal', 'Strong', 'No'],
    ['Overcast', 'Cool', 'Normal', 'Strong', 'Yes'],
    ['Sunny', 'Mild', 'High', 'Weak', 'No'],
    ['Sunny', 'Cool', 'Normal', 'Weak', 'Yes'],
    ['Rain', 'Mild', 'Normal', 'Weak', 'Yes'],
    ['Sunny', 'Mild', 'Normal', 'Strong', 'Yes'],
    ['Overcast', 'Mild', 'High', 'Strong', 'Yes'],
    ['Overcast', 'Hot', 'Normal', 'Weak', 'Yes'],
    ['Rain', 'Mild', 'High', 'Strong', 'No']
]

# Feature names
features = ['Outlook', 'Temperature', 'Humidity', 'Wind']

from collections import Counter
import math

# Function to compute entropy of a set of labels
def entropy(labels):
    total = len(labels)
    counts = Counter(labels)
    ent = 0.0
    for count in counts.values():
        p = count / total
        ent -= p * math.log2(p)
    return ent

# Function to compute information gain for a feature
def info_gain(dataset, feature_index):
    total_entropy = entropy([row[-1] for row in dataset])
    values = [row[feature_index] for row in dataset]
    unique_values = set(values)
    
    weighted_entropy = 0.0
    for val in unique_values:
        subset = [row for row in dataset if row[feature_index] == val]
        weighted_entropy += (len(subset) / len(dataset)) * entropy([row[-1] for row in subset])
    
    gain = total_entropy - weighted_entropy
    return gain

# ID3 Algorithm
def id3(dataset, features):
    labels = [row[-1] for row in dataset]
    
    # If all labels are the same, return the label
    if labels.count(labels[0]) == len(labels):
        return labels[0]
    
    # If no features left, return the majority label
    if not features:
        return Counter(labels).most_common(1)[0][0]
    
    # Find the best feature to split on
    gains = [info_gain(dataset, i) for i in range(len(features))]
    best_feature_index = gains.index(max(gains))
    best_feature = features[best_feature_index]
    
    tree = {best_feature: {}}
    
    # Get unique values of the best feature
    values = set([row[best_feature_index] for row in dataset])
    
    # Split dataset and recurse
    for val in values:
        subset = [row[:best_feature_index] + row[best_feature_index+1:] for row in dataset if row[best_feature_index] == val]
        subtree = id3(subset, features[:best_feature_index] + features[best_feature_index+1:])
        tree[best_feature][val] = subtree
    
    return tree

# Build the tree
decision_tree = id3(dataset, features)

# Function to print the tree nicely
# def print_tree(tree, indent=''):
#     if not isinstance(tree, dict):
#         print(indent + str(tree))
#         return
#     for feature, branches in tree.items():
#         for value, subtree in branches.items():
#             print(f"{indent}{feature} = {value} ->")
#             print_tree(subtree, indent + "  ")

def print_tree(tree, indent="", is_last=True, key_name=""):
    """Beautifully prints a nested dictionary as a tree."""
    
    # Decide the branch symbol
    if indent == "":
        # Root node
        branch = ""
    else:
        branch = "└── " if is_last else "├── "
    
    # Print the current key or leaf value
    if isinstance(tree, dict):
        if key_name:
            print(f"{indent}{branch}{key_name}")
            indent += "    " if is_last else "│   "
        for i, (key, value) in enumerate(tree.items()):
            is_last_item = i == len(tree) - 1
            print_tree(value, indent, is_last_item, key)
    else:
        print(f"{indent}{branch}{key_name}: {tree}")

# Print the resulting decision tree
# print_tree(decision_tree)

print(json.dumps(decision_tree, indent=4))

# print(decision_tree)