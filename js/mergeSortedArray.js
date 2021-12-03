/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
    if (m === 0) {
        for (let i = 0; i < nums1.length; i++) {
            nums1[i] = nums2[i];
        }
        return nums1;
    }
    if (n === 0) {
        return nums1;
    }
    let n1 = 0;
    let n2 = 0;
    while (n1 < nums1.length) {
        console.log('n1 is', n1)
        while (n > 0 && nums2[n2] <= nums1[n1]) {
            console.log('n2 is', n2)
            nums1.splice(n1, 0, nums2[n2])
            nums1.pop()
            n2++;
            n1++;
            n--;
        }
        n1++;
        m--;
    }
    if (n > 0) {
        for (let i = n2; i < nums2.length; i++) {
            nums1.splice(nums1.length - n, 0, nums2[i])
            nums1.pop()
            n--;
        }
    }
    return nums1;
};

var mergeSolution = function (nums1, m, nums2, n) {
    while (n > 0) {
        if (m >= 0 && nums1[m - 1] > nums2[n - 1]) {
            nums1[m + n - 1] = nums1[--m]
        } else {
            nums1[m + n - 1] = nums2[--n]
        }
    }
    return nums1;
}

let nums1 = [1, 2, 3, 0, 0, 0]
let m = 3
let nums2 = [2, 5, 6]
let n = 3

console.log('\nExample 1:\n', merge(nums1, m, nums2, n))
console.log('Answer:', mergeSolution(nums1, m, nums2, n))

nums1 = [1]
m = 1
nums2 = []
n = 0

console.log('\nExample 2:\n', merge(nums1, m, nums2, n))
console.log('Answer:', mergeSolution(nums1, m, nums2, n))

nums1 = [0]
m = 0
nums2 = [1]
n = 1

console.log('\nExample 3:\n', merge(nums1, m, nums2, n))
console.log('Answer:', mergeSolution(nums1, m, nums2, n))
