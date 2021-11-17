// /**
//  * @param {number} x
//  * @return {boolean}
//  */
// // FIRST SOLUTION
//  var isPalindrome = function(x) {
//     xString = x.toString()
//     let lower = 0;
//     let upper = xString.length - 1
//     while (lower !== upper && lower < upper) {
//         if(xString[lower] !== xString[upper]) {
//             return false;
//         }
//         lower++;
//         upper--;
//     }
//     return true
// };

const given = 121;

var isPalindrom = function(x) {
    if (given < 0) {
        return false;
    }
    let digits = 0;
    if(x >= 1) {
        digits++;
    } else {
        return true;
    }

    let xClone = x
    while(xClone / 10 >= 1) {
        xClone /= 10
        digits++
    }

    for(let i = 0; i < digits; i++) {
        // TODO: Finish this thought
        // TODO: Find the most optimized method of handling this issue
    }
    
};

console.log(isPalindrom(given))