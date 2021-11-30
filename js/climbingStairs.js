/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    if (n <= 0) {
        return 0;
    }
    if (n === 1) {
        return 1;
    }
    if (n === 2) {
        return 2;
    }

    let oneStepBefore = 2;
    let twoStepsBefore = 1;
    let allWays = 0;

    for (let i = 2; i < n; i++) {
        allWays = oneStepBefore + twoStepsBefore;
        twoStepsBefore = oneStepBefore;
        oneStepBefore = allWays;
    }
    return allWays;
};

console.log('result is', climbStairs(4));