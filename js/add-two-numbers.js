/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

// I made this function to make it easier to test locally
var arrayToLinkedList = function (l1Array, l2Array) {
    let l1 = new ListNode(l1Array[0], null);
    if (l1Array.length > 1) {
        let currentNode = new ListNode(l1Array[1], null);
        l1.next = currentNode;
        for (let i = 2; i < l1Array.length; i++) {
            let nextNode = new ListNode(l1Array[i], null);
            currentNode.next = nextNode;
            currentNode = nextNode;
        }
    }
    let l2 = new ListNode(l2Array[0], null);
    if (l2Array.length > 1) {
        let currentNode = new ListNode(l2Array[1], null)
        l2.next = currentNode;
        for (let i = 2; i < l2Array.length; i++) {
            let nextNode = new ListNode(l2Array[i], null);
            currentNode.next = nextNode;
            currentNode = nextNode;
        }
    }
    return {
        l1: l1,
        l2: l2
    };
}

// I also made this function to make it easier to test locally
var linkedListToArray = function (linkedList) {
    let convertedArray = [];
    while(linkedList) {
        convertedArray.push(linkedList.val);
        linkedList = linkedList.next;
    }
    return convertedArray;
}

// FIRST ITERATION
var addTwoNumbers = function (l1, l2) {
    if (!l1.next && !l2.next) {
        if (l1.val + l2.val > 9) {
            return new ListNode(l1.val + l2.val - 10, new ListNode(1, null));
        } else {
            return new ListNode(l1.val + l2.val, null);
        }
    }

};

const l1 = [5];
const l2 = [0];

// console.log(arrayToLinkedList(l1, l2));
const linkedList = arrayToLinkedList(l1, l2);
const result = addTwoNumbers(linkedList.l1, linkedList.l2);
const resultAsArray = linkedListToArray(result);

console.log(resultAsArray);