#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Odometer {

    private:
        
        int size;
        int start;
        int end;
        int length;
        vector<int> readings;
        int index;

        bool isAscending(int value) {
            

            if (value < 10) 
                return true;

            if (value % 10 <= (value / 10) % 10)
                return false;

            return isAscending(value / 10);
        }

    public:

        Odometer() {
            size = 0;
            start = 0;
            end = 0;
            length = 0;
            index = 0;
        }

        Odometer(int value) {
            size = value;
            length = 0;

            start = pow(10, size - 1);
            end = start * 10;
            

            for (int i = start; i < end; i++) {
                if (isAscending(i)) {
                    readings.push_back(i);
                    length++;
                }

            }
            start = readings[0];
            end = readings[length - 1];
            index = 0;
        }

        int currentReading() {

            if (index == length)
                index = 0;
            if (index < 0)
                index = length - 1;
      
            return readings[index];
        }

        vector<int> nextReadings(int value = 1) {

            vector<int> next_readings;
            for (int i = 0; i < value; i++) {
                if (index == length - 1)
                    index = 0;
                next_readings.push_back(readings[++index]);
            }
            return next_readings;
        }

        vector<int> previousReadings(int value = 1) {

            vector<int> previous_readings;
            for (int i = 0; i < value; i++) {

                if (index < 1)
                    index = length;
                previous_readings.push_back(readings[--index]);
            }
            return previous_readings;
        }


        int difference(int reading1, int reading2) {

            if (!isAscending(reading1) || !isAscending(reading2))
                return -1;

            if (reading1 > reading2) {
                int temp = reading1;
                reading1 = reading2;
                reading2 = reading1;
            }

            int counter = 0;

            for (int i = 0; i < length; i++) {

                while (readings[i] > reading1 && readings[i] < reading2)
                    counter++;

                if (readings[i] >= reading2)
                    break;

            }

            return counter;
        }

        void print() {

            cout << "Start: " << start << endl;
            cout << "End: " << end << endl;
            cout << "Current Reading: " << currentReading() << endl;
            cout << endl <<  "All Readings : " << endl;
            for (int i = 0; i < length; i++) {

                cout << readings[i] << '\t';
                if ( (i + 1) % 10 == 0)
                    cout << endl;
            }
            cout << endl << endl;
        
            return;
        }
};

int main(int argc, char* argv[]) {

    Odometer o1(5);
    o1.print(); 
    vector<int> nexto1 = o1.nextReadings(4);
    cout << "4 next readings " << endl;
    for (int i = 0; i < 4; i++)
        cout << nexto1[i] << " ";
    cout << endl;
    cout << "Current Reading : " << o1.currentReading() << endl;
    vector<int> prevo1 = o1.previousReadings(8);
    cout << "8 previous reading " << endl;
    for (int i = 0; i < 8; i++)
        cout << prevo1[i] << " ";
    cout << endl;
    cout << "Current Reading : " << o1.currentReading() << endl;
    return 0;
}

    

    






















            
        

       




