class Solution {
public:


    // Have 2 closed parentheses for every 1 open to make it balanced, return required insertions to make the string 'balanced'
    int minInsertions(string s) {

        int opens = 0;  // Check how many is currently opened
        int sum = 0;    // Sum of insertions required
        int closedTotal = 0;    // Track if there's any current closed that doesn't have a second one.

        // loop through string
        for (char c : s) {
            // Open
            if (c == '(') {

                if (closedTotal & 1 == 1) {
                    
                    // Premature closing, set closed back to 0 and add 1 to int as need one to finish the double close parenthese req
                    closedTotal++;
                    if (opens > 0) {
                        
                        opens--;    // So we don't recount later.
                        sum++;

                    } else {

                        // No open? Need to add two to sum then to compensate
                        sum += 2;

                    }


                }
         
                opens++;    // Open ++ after the prev if to compensate for the opens check

            // Closed
            } else {
                
                // Second closed parenthese
                if (closedTotal & 1 == 1) {
                    
                    // No opens, need a +1
                    if (opens == 0) {
                        
                        sum++;

                    // Open that's unclosed, resolved so give it a --
                    } else {

                        opens--;

                    }
                }

                closedTotal++;

            } // End of If

        } // End of For loop

        if (closedTotal & 1 == 1) {
            
            // For loop ended, no need to modify closed Total

            if (opens > 0) {

                opens--;
                sum++;
                // Resolution of an unresolved closed

            } else {

                // No Remaining open requires a +2
                sum += 2;

            }

        }

        // Need 2 more for every open
        sum += opens * 2;
        return sum;

    }
};