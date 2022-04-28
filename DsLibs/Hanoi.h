#include<string>
#include<iostream>

namespace eds {
	namespace algorithm {
        using namespace std;

        string a = "towerA";
        string b = "towerB";
        string c = "towerC";

        unsigned long counta = 0;

        void Hanoi(unsigned num, string x, string y, string z) {
            if (num == 1) {
                counta++;
                cout << "move from " << x << " to " << z << " count = " << counta << endl;
            }
            else {
                Hanoi(num - 1, x, z, y);
                counta++;
                cout << "move from " << x << " to " << z << " count = " << counta << endl;
                Hanoi(num - 1, y, x, z);
            }
        }
	}
}