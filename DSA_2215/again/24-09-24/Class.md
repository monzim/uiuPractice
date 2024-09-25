# Problem

## construct a BST putting the following key one after another: 22, 15, 25, 31, 19, 20, 10, 17, 24, 21

# Solution

## Construct the tree

```mermaid
graph TD
    22 --> 15
    22 --> 25
    25 --> 31
    15 --> 19
    19 --> 20
    15 --> 10
    19 --> 17
    25 --> 24
    24 --> 21
```

## Now From the constructed tree, delete the following element one after another: 10, 19, 15, 22

```mermaid
graph TD
    22 --> 25
    25 --> 31
    25 --> 24
    24 --> 21
    25 --> 17
    25 --> 20
```
