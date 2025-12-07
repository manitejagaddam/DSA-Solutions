class Solution {
public:
    int countOdds(int low, int high) {
        
        /*
        
        case1 ->
            staring = odd
            ending = odd

            3 - 7 -> middle = 5
            3 - 11 -> middle = 5 7 9 
        
        case 2 -> 
            starging = even
            ending = even

            4 - 10 -> middle = 5 7 9

            4 - 16 -> middle = 5 7 9 11 13 15

        case 3 -> 
            starting = odd
            ending = even

            3 - 10 -> middle = 5 7 9

            1 - 10 -> middle = 3 5 7 9
        */
        
        return (high + 1) / 2 - low / 2;
    }
};