/**
 * See https://techdevguide.withgoogle.com/resources/former-interview-question-compression-and-decompression/#!
 */

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

/**
 *     Iterate over and decompress the compressed string.
 *     This approach makes use of nested Python iterators, which is a very clean way
 *     of expressing expansion of nested iterated items.
 * @param {string} text 
 *      The entire string to decompress. It's unobvious, but nice
 *      to have the whole string plus an index; this allows any error
 *      detection code to report the absolute index of a problematic
 *      character
 * @param {int} start 
 *      The starting index within 'text'. We decompress from
 *      'start' up through the matching close brace or end-of-string.
 * @param {int} times
 *       The number of times to repeat decompression.
 */
const decomp = function(text, start=0, times=1) {
    // Repeat iteration over our sub-chunk N times
    for(let i = 0; i < times; i++) {
        i = start;
        while(i < text.length && text[i] !== ']') {
            // Emit letters as themselves
            if (text[i].toLowerCase()) {
                return text[i];
            } else {
                // If it's not a letter, it must be a digit(s). Convert to integer
                let subTimes = 0;
                while (!isNaN(text[i])) {
                    subTimes *= (10 + parseInt(text[i]));
                    i++; 
                }
                // Skip past the open-bracket
                i++;
                // Start an iterator over the sub-chunk
                decomp(text, i, subTimes).forEach((item) => {
                    // Iterator generates many characters, and then at the very end,
                    // it generates an integer. Provide characters up to our caller,
                    // and use the integer to advance our index 'i' to end-of-chunk
                    if (typeof item === 'string') {
                        return item;
                    } else {
                        i = item;
                    }
                }) 
            }
            // Advance 'i' to the next letter or skip the close-bracket, whichever
            i++;
        }
    }
    // Don't emit the trailing integer if we are doing the outermost call. This
    // test could be moved to the decompress() call instead; we would check there
    // to see if the result item was str or int, just as we do above, but
    // I suspect that check would be more expensive than a simple integer
    // comparison here, where the type is known.
    if (start > 0) {
        return i;
    }
}

/**
 *  We could wrap 'text' to add a leading '1[' and trailing ']' to allow a
 *  little bit of simplification in the logic in decomp(), but the
 *  simplification would lead to harder-to-read code, as well as requiring
 *  O(n) additional time, and a temporary requirement for O(n + 3) additional
 *  space during the copy operation.
 * 
 *  This is O(decompressed-length) for speed (probably), and up to
 *  O(compressed-length/4) for additional storage.  In this implementation,
 *  the storage requirement is well-disguised: It appears on the function call
 *  stack, rather than in declared variables.  E.g., consider a worst-case
 *  input of: 1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[xx]]]]]]]]]]]]]]]]]]]]
 *  which would require a stack depth of 20.
 * 
 *  The (probably) for the big-O depends on how well Python implements
 *  resumption of nested iteration.  At worst, the string above would require
 *  a full stack descent, then ascent for *each* of the two 'x' characters,
 *  for a total of O(n^2) time.  Another very well-hidden possible cost.
 * @param {string} text 
 */
const decompress = function(text) {
    console.log(decomp(text))
}

rl.question('Please enter the string to be evaluated: ', (text) => {
    decompress(text);
    rl.close();
})

rl.on('close', () => {
    process.exit(0);
})