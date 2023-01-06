// Question #13 of Challange 1
// Question Name:-
// seating arrangement in a jet plane with n passangers....
// Leetcode #1227

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};
