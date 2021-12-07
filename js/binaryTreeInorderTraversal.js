/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    let result = [];
    inorderTraversalHelper(root, result);
    return result;

};

var inorderTraversalHelper = function (root, result) {
    if (root) {
        inorderTraversalHelper(root.left, result);
        result.push(root.val);
        inorderTraversalHelper(root.right, result);
    }
};

class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

let end = new TreeNode(3, undefined, undefined)
let right = new TreeNode(2, end, undefined);
let first = new TreeNode(1, undefined, right);

console.log(inorderTraversal(first))

var iterativeInorderTraversal = function (root) {
    let result = [];
    let stack = [];
    while (true) {
        while (root) {
            stack.push(root);
            root = root.left;
        }
        if (stack.length === 0) {
            return result;
        }
        let node = stack.pop();
        result.push(node.val);
        root = node.right;
    }
}

console.log(iterativeInorderTraversal(first))