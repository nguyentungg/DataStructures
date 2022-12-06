const CONSTANTS = {
    RED: 'RED',
    BLACK: 'BLACK',
};

class Node {
    constructor(param) {
        this.key = param.key || 0;
        this.color = param.color || CONSTANTS.RED;
        this.left = param.left || undefined;
        this.right = param.right || undefined;
        this.parent = param.parent || undefined;
    }
}

class RedBlackTree {
    constructor() {
        this.leaf = new Node({ key: 0, color: CONSTANTS.BLACK });
        this.root = this.leaf;
    }

    // Method to print all nodes from the tree by traverse in deep
    printTree() {
        const stack = [
            { node: this.root, str: '' },
        ];

        while (stack.length) {
            // Take last item from stack
            const item = stack.pop();
            // Don't print empty leaf
            if (item.node == this.leaf) {
                continue;
            }
            // Get position of node - left or right
            let position = '';
            if (item.node.parent) {
                position = item.node === item.node.parent.left ? 'L----' : 'R----';
            } else {
                position = 'ROOT-';
            }
            // Print info about node
            console.log(`${item.str}${position} ${item.node.key} (${item.node.color})`);

            // Add node children into stack
            stack.push({ node: item.node.right, str: item.str + '     ' });
            stack.push({ node: item.node.left, str: item.str + ' |   ' });
        }
    }

    // Method to change positions of nodes, the right child will be the new vertex, previous vertex became the left child
    /**
    * @param {Node} node - vertex for rotation
    */
    rotateLeft(node) {
        const vertex = node.right;

        // set new right child for node
        node.right = vertex.left;
        if (vertex.left != this.leaf) {
            vertex.left.parent = node;
        }

        // replace node by new vertex
        vertex.parent = node.parent;
        // if node is root, set new root
        if (!node.parent) {
            this.root = vertex;
        }
        // replace node for parent
        else if (node === node.parent.left) {
            node.parent.left = vertex;
        }
        else {
            node.parent.right = vertex;
        }

        // set left child for vertex - node
        vertex.left = node;
        node.parent = vertex;
    }

    // Method to change positions of nodes, the left child will be the new vertex, previous vertex became the right child
    /**
    * @param {Node} node - vertex for rotation
    */
    rotateRight(node) {
        // left child is new vertex
        const vertex = node.left;

        // node lose left child, we replace it with right child from new vertex
        node.left = vertex.right;
        if (vertex.right != this.leaf) {
            vertex.right.parent = node;
        }

        // new vertex replaces old node
        vertex.parent = node.parent;
        if (!node.parent) {
            this.root = vertex;
        } else if (node == node.parent.right) {
            node.parent.right = vertex;
        } else {
            node.parent.left = vertex;
        }

        // attach right child for new vertex - it is old node
        vertex.right = node;
        node.parent = vertex;
    }

    // Insertion in the binary tree - walk by tree in while cycle, if the key is less that the key of current node, 
    // need search in the left node, else in the right node. After insertion we should check balance into the tree.
    /**
    * @param {number} key - key for new node
    */
    insert({ key }) {
        const node = new Node({
            key,
            left: this.leaf,
            right: this.leaf,
        });

        let parent;
        let tmp = this.root;

        // Search of parent for new node
        // we check all nodes while not get an empty leaf
        while (tmp !== this.leaf) {
            parent = tmp;
            // key less that key of current node, we should search in left subtree
            if (node.key < tmp.key) {
                tmp = tmp.left;
            }
            // key bigger that key of current node, we should search in right subtree
            else {
                tmp = tmp.right;
            }
        }

        node.parent = parent;

        // insert node in left or right subtree
        if (!parent) {
            this.root = node;
        } else if (node.key < parent.key) {
            parent.left = node;
        } else {
            parent.right = node;
        }

        // tree has no vertex, node will be root
        if (!node.parent) {
            node.color = CONSTANTS.BLACK;
            return;
        }
        // node has no grandparent, so we have no to balance the tree
        if (!node.parent.parent) {
            return;
        }

        // balancing of tree
        this.balanceInsert(node);
    }

    // Method to balance the tree after inserting.
    // 1) Make the balancing of the tree while the parent of the node is red.
    // 2) If the parent of the node is the left child of his grandparent:
    // a) if the uncle and the parent are red, we can change colors of the parent and the uncle to black, make the grandparent red, 
    // and apply balancing for the grandparent to solve rule 4.
    // b) if the parent is red and the uncle is black. If the node is the right child, apply balancing to the parent and rotate left.
    // After make the parent black and the grandparent red. Apply rotate right for the grandparent.
    // 3) If the parent of the node is the right child:
    // a) If the parent and the uncle is red, we should make them black and make the grandparent red. After will apply balancing to 
    // the grandparent.
    // b) Else, if the node is the left child, we continue balancing from the parent and make left rotation. After set color of the 
    // parent as black, make the grandparent red and apply right rotation for the grandparent.
    // 4) Set black color for the root.
    /**
    * @param {Node} node - node for balancing
    */
    balanceInsert(node) {
        // while parent is red
        while (node.parent.color === CONSTANTS.RED) {
            // node parent is left child of grandparent
            if (node.parent === node.parent.parent.left) {
                const uncle = node.parent.parent.right;
                // if uncle and parent are red, need make these black and grandparent red
                if (uncle.color === CONSTANTS.RED) {
                    uncle.color = CONSTANTS.BLACK;
                    node.parent.color = CONSTANTS.BLACK;
                    node.parent.parent.color = CONSTANTS.RED;
                    node = node.parent.parent;
                }
                // if parent is red and uncle is black
                else {
                    // if node is right child
                    if (node === node.parent.right) {
                        node = node.parent;
                        this.rotateLeft(node);
                    }
                    node.parent.color = CONSTANTS.BLACK;
                    node.parent.parent.color = CONSTANTS.RED;
                    this.rotateRight(node.parent.parent);
                }
            } else {
                const uncle = node.parent.parent.left;
                if (uncle.color === CONSTANTS.RED) {
                    uncle.color = CONSTANTS.BLACK;
                    node.parent.color = CONSTANTS.BLACK;
                    node.parent.parent.color = CONSTANTS.RED;
                    node = node.parent.parent;
                } else {
                    if (node == node.parent.left) {
                        node = node.parent;
                        this.rotateRight(node);
                    }
                    node.parent.color = CONSTANTS.BLACK;
                    node.parent.parent.color = CONSTANTS.RED;
                    this.rotateLeft(node.parent.parent);
                }
            }

            if (node == this.root) {
                break;
            }
        }

        this.root.color = CONSTANTS.BLACK;
    }

    // Method to find the minimum value for the subtree
    /**
    * @param {Node} node - node of the tree where we should search the minimum value
    */
    minimum(node) {
        while (node.left != this.leaf) {
            node = node.left;
        }
        return node;
    }

    // Method to replace oldNode by newNode
    /**
    * @param {Node} oldNode - node that should be replaced
    * @param {Node} newNode - node that value will be used instead the old node
    */
    replace(oldNode, newNode) {
        if (!oldNode.parent) {
            this.root = newNode;
        } else if (oldNode == oldNode.parent.left) {
            oldNode.parent.left = newNode;
        } else {
            oldNode.parent.right = newNode;
        }
        newNode.parent = oldNode.parent;
    }

    // Method to delete the node by key. If the node that we should remove has only one child, we replace the node by his child. 
    // If the node has both children, we should find the minimum child in the right subtree, and use that to replace the node.
    /**
    * @param {number} key - key for node that should be removed
    */
    deleteNode(key) {
        let forRemove = this.leaf;
        let tmp = this.root;

        // searching the node for removing
        while (tmp != this.leaf) {
            if (tmp.key === key) {
                forRemove = tmp;
                break;
            }

            if (tmp.key > key) {
                tmp = tmp.left;
            } else {
                tmp = tmp.right;
            }
        }

        // node is not found
        if (forRemove == this.leaf) {
            console.log('node not found');
            return;
        }

        let minRight = forRemove;
        let minRightColor = minRight.color;
        let newMinRight;

        /*
        if the node for removing has no left child,
        we replace this by its right child
        */
        if (forRemove.left == this.leaf) {
            newMinRight = forRemove.right;
            this.replace(forRemove, forRemove.right);
        }
        /*
        if the node for removing has no right child,
        we replace this by its left child
        */
        else if (forRemove.right == this.leaf) {
            newMinRight = forRemove.left;
            this.replace(forRemove, forRemove.left);
        }
        // if the node for removing have both children
        else {
            minRight = this.minimum(forRemove.right);
            minRightColor = minRight.color;
            newMinRight = minRight.right;

            if (minRight.parent === forRemove) {
                newMinRight.parent = minRight;
            }
            /*
            replace minimum of the right subtree by its right child,
            attach right children from node for removing into the minimum of right subtree
            */
            else {
                this.replace(minRight, minRight.right);
                minRight.right = forRemove.right;
                minRight.right.parent = minRight;
            }

            // attach left children from node for removing into the minimum of right subtree
            this.replace(forRemove, minRight);
            minRight.left = forRemove.left;
            minRight.left.parent = minRight;
            minRight.color = forRemove.color;
        }

        if (minRightColor === CONSTANTS.BLACK) {
            this.balanceDelete(newMinRight);
        }
    }

    // Method to balance the tree after deleting.
    // 1) Make balancing of the tree while the node isn't root of the tree and color of the node is black
    // 2) If the node is the left child of his parent
    // a) If the brother of the node is red: set color of the brother as black, set color of the parent as red. Apply left rotation to 
    // the parent of the node. Set the right child of the parent as the brother.
    // b) If children of the brother are black: set color of the brother as red and apply balancing to the parent of the node.
    // c) If color of one child of the brother is red. If color of the right child of the brother is black: set color of the left 
    // child as black, set color of the brother as red, apply right rotation to the brother, set the right child of the parent as brother. 
    // After, set color of the brother equal to the parent color, set color of the parent as black, set color for the right child of the 
    // brother as black. Apply left rotation to the parent of the node. Set the root of the tree as the node.
    // 3) If node is the right child and his brother is the left child.
    // a) If color of the brother is red. Set color of the brother as black, set color of the parent as red, apply right rotation for 
    // the parent of the node, and assign the left child of the parent as brother.
    // b) If both children of the brother is black. Set color of the brother as red and apply balancing to the parent.
    // c) If one of child of the brother is red. If the left child of the brother is black, set color of the right child of the brother 
    // as black, set color of the brother as red, apply left rotation to the brother, set the left child of the parent as brother. 
    // After, set color of the brother as color of the parent. Set color og the parent as black, set color of the left child of the brother as black, Apply right rotation to the parent. Set the root as the node.
    /**
    * @param {Node} node - node for balancing
    */
    balanceDelete(node) {
        while (node != this.root && node.color == CONSTANTS.BLACK) {
            if (node == node.parent.left) {
                let brother = node.parent.right;

                if (brother.color == CONSTANTS.RED) {
                    brother.color = CONSTANTS.BLACK;
                    node.parent.color = CONSTANTS.RED;
                    this.rotateLeft(node.parent);
                    brother = node.parent.right;
                }

                if (
                    brother.left.color == CONSTANTS.BLACK &&
                    brother.right.color == CONSTANTS.BLACK
                ) {
                    brother.color = CONSTANTS.RED;
                    node = node.parent;
                } else {
                    if (brother.right.color == CONSTANTS.BLACK) {
                        brother.left.color = CONSTANTS.BLACK;
                        brother.color = CONSTANTS.RED;
                        this.rotateRight(brother);
                        brother = node.parent.right;
                    }

                    brother.color = node.parent.color;
                    node.parent.color = CONSTANTS.BLACK;
                    brother.right.color = CONSTANTS.BLACK;
                    this.rotateLeft(node.parent);
                    node = this.root;
                }
            } else {
                let brother = node.parent.left
                if (brother.color == CONSTANTS.RED) {
                    brother.color = CONSTANTS.BLACK;
                    node.parent.color = CONSTANTS.RED;
                    this.rotateRight(node.parent);
                    brother = node.parent.left;
                }

                if (
                    brother.left.color == CONSTANTS.BLACK &&
                    brother.right.color == CONSTANTS.BLACK
                ) {
                    brother.color = CONSTANTS.RED;
                    node = node.parent;
                } else {
                    if (brother.left.color == CONSTANTS.BLACK) {
                        brother.right.color = CONSTANTS.BLACK;
                        brother.color = CONSTANTS.RED;
                        this.rotateLeft(brother);
                        brother = node.parent.left;
                    }

                    brother.color = node.parent.color;
                    node.parent.color = CONSTANTS.BLACK;
                    brother.left.color = CONSTANTS.BLACK;
                    this.rotateRight(node.parent);
                    node = this.root;
                }
            }
        }

        node.color = CONSTANTS.BLACK;
    }



}
const t = new RedBlackTree();

for (let i = 1; i < 20; i++) {
    t.insert({ key: i });
}
t.printTree();

for (let i = 1; i < 20; i++) {
    if (i % 3 === 0) {
        t.deleteNode(i);
    }
}
t.printTree();
