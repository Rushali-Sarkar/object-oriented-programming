#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Range {

    private:
        int start;
        int end;

        void reset() {
           this -> start = 0;
           this -> end = 0;

            return;
        }

    public:

        Range() {
            this -> start = 0;
            this -> end = 0;
        }

        Range(int end) {
            this -> start = 0;
            this -> end = end;
        }

        Range(int start, int end) {
            this -> start = start;
            this -> end = end;
        }

        void rStretch(int stretch_by = 1) {
          this -> end += stretch_by;
          return;
        }  

        void lStretch(int stretch_by = 1) {
            this -> start -= stretch_by;
            return;
        }

        void stretch(int stretch_by = 1) {
            this -> start -= stretch_by;
            this -> end += stretch_by;
            return;
        }

        void squeeze(int squeeze_by = 1) {
            this -> start += squeeze_by;
            this -> end -= squeeze_by;

            if (this -> start > this -> end)
                this -> reset();

            return;
        }

        void shift(int shift_by = 1) {
            this -> start += shift_by;
            this -> end += shift_by;
            return;
        }

        int length() {
            return this -> end - this -> start + 1;
        }

        bool contains(int item) {
            return item >= this -> start && item <= this -> end;
        }

        bool equals(Range n) {
            return n.start == this -> start && n.end == this -> end;
        }

        bool isDisjoint(Range n) {

            bool isStartBetween = n.start >= this -> start && n.start <= this -> end;
            bool isEndBetween = n.end >= this -> end && n.end <= this -> end;

            return (!isStartBetween) && (!isEndBetween);
        }

        bool isOverlapping(Range n) {
            return (!this -> isDisjoint(n));
        }

        bool isTouching(Range n) {
            return this -> end + 1 == n.start || this -> start == n.end + 1;
        } 

        bool lessThan(Range n) {
            return this -> start < n.start;
        }

        bool greaterThan(Range n) {
            return this -> start > n.start;
        }

        bool isSubset(Range n) {
            return this -> start >= n.start && this -> end <= n.end;
        }

        bool isSuperset(Range n) {
            return n.start >= this -> start && n.end <= this -> end;
        }

        Range merge(Range n) {

            if (this -> isDisjoint(n) && !this -> isTouching(n))
                return Range();

            int new_start = this -> start < n.start ? this -> start : n.start;
            int new_end = this -> end > n.end ? this -> end : n.end;

            return Range(new_start, new_end);
        }

        Range common(Range n) {

            if (this -> isDisjoint(n))
                return Range();

            int common_start = this -> start > n.start ? this -> start : n.start;
            int common_end = this -> end < n.end ? this -> end : n.end;

            return Range(common_start, common_end);
        }

        vector<int> elements() {

            vector<int> allInRange;

            for (int element = this -> start; element <= this -> end; element++) 
                allInRange.push_back(element);

            return allInRange;
        }
};

class ClosedRange: public Range {

    private:

        int start;
        int end;

    public:

        ClosedRange() {
            this -> start = 0;
            this -> end = 0;
        }

        ClosedRange(int end) {
            this -> start = 0;
            this -> end = end;
        }

        ClosedRange(int start, int end) {
            this -> start = start;
            this -> end = end;
        }

        string toString() {
            return "[" + to_string(this -> start) + ", " + to_string(this -> end) + "]";
        }
};

class OpenRange: public Range {

    private:

        int start;
        int end;

    public:

        OpenRange() {
            this -> start = 0;
            this -> end = 0;
        }

        OpenRange(int end) {
            this -> start = 0;
            this -> end = end - 1;
        }

        OpenRange(int start, int end) {
            this -> start = start + 1;
            this -> end = end - 1;
        }

        string toString() {
            return "(" + to_string(this -> start - 1) + ", " + to_string(this -> end + 1) + ")";
        }
};

class SemiOpenBegin: public Range {

    private:

        int start;
        int end;

    public:

        SemiOpenBegin() {
            this -> start = 0;
            this -> end = 0;
        }

        SemiOpenBegin(int end) {
            this -> start = 0;
            this -> end = end;
        }

        SemiOpenBegin(int start, int end) {
            this -> start = start + 1;
            this -> end = end;
        }

        string toString() {
            return "(" + to_string(this -> start - 1) + ", " + to_string(this -> end) + "]";
        }
};

class SemiOpenEnd: public Range {

    private:
        
        int start;
        int end;

    public:

        SemiOpenEnd() {
            this -> start = 0;
            this -> end = 0;
        }

        SemiOpenEnd(int end) {
            this -> start = 0;
            this -> end = end - 1;
        }

        SemiOpenEnd(int start, int end) {
            this -> start = start;
            this -> end = end - 1;
        }

        string toString() {
            return "[" + to_string(this -> start) + ", " + to_string(this -> end + 1) + ")";
        }
};


