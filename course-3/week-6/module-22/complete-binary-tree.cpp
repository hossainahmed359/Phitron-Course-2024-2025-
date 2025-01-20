

// Last Nodes filled up from left
// Height : h = log(n) n = nodes


// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. Here are some examples of complete binary trees:

/* 
            1
         /     \
        2       3
       / \     / \
      4   5   6   7


            1
         /     \
        2       3
       / \     / 
      4   5   6  

               1
           /       \
         2           3
       /   \       /   \
      4     5     6     7
     / \   /
    8   9 10


 */

// arr = [1, 2, 3, 4, 5, 6]
// parent node index * 2 + 1 = left node index
// parent node index * 2 + 2 = right node index
// (child node index - 1) / 2 = parent node index

// NOT A COMPLETE BINARY TREE
/* 

            1
         /     \
        2       3
       / \        \
      4   5        6


 */