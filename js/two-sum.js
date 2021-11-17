// /**
//  * @param {number[]} nums
//  * @param {number} target
//  * @return {number[]}
//  */
// FIRST ITERATION
//  var twoSum = function(nums, target) {
//     for (let i = 0; i < nums.length - 1; i++) {
//         for (let j = i + 1; j < nums.length; j++) {
//             if(nums[i] + nums[j] === target) {
//                 return [i, j]
//             }
//         }
//     }
// };

let nums = [3, 2, 4]
let target = 6

// let nums = [2, 7, 11, 15]
// let target = 9

// let nums = [3,3]
// let target = 6

var twoSum = function (nums, target) {
    let hashmap = {}
    for(let i = 0; i < nums.length; i++) {
        const diff = target - nums[i]
        if(hashmap[diff.toString()] !== undefined) {
            return [i, hashmap[diff.toString()]]
        } else {
            hashmap[nums[i].toString()] = i
        }
    }
};

console.log(twoSum(nums, target))