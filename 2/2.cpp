#include <bits/stdc++.h> 
using namespace std;

void TestCase(int T)  {
    cout << "Case #" << T << ": ";
}

int main() {
    cout << fixed << setprecision(2);

    int Townships;
    cin >> Townships;

    for(int i=1; i<=Townships; i++) {
        int houses;
        cin >> houses;

        int total_roof_bed_rooms = 0;
        int total_standard_rooms = 0;
        int total_victorian_style_halls = 0;

        for(int j=1; j<=houses; j++) {
            string inputString;
            cin >> inputString;

            int idx = 0;

            while(inputString[idx] != ',') idx++;
            ++idx;

            string curr = "";
            while(inputString[idx] != ',') curr.push_back(inputString[idx++]);
            total_roof_bed_rooms += stoi(curr);

            curr = "";
            idx++;
            while(inputString[idx] != ',') curr.push_back(inputString[idx++]);
            total_standard_rooms += stoi(curr);

            curr = "";
            idx++;
            while(idx<inputString.size()) curr.push_back(inputString[idx++]);
            total_victorian_style_halls += stoi(curr);

        }
        
        int total_walls = 0;

        total_walls += (3 * total_roof_bed_rooms);
        total_walls += (4 * total_standard_rooms);
        total_walls += (6 * total_victorian_style_halls);

        double accent_walls = (total_walls / 3.00);
        double normal_walls = ((total_walls * 2.00) / 3.00);

        double total_accent_color = (1.50 * accent_walls);
        double total_normal_color = (2.25 * normal_walls);

        double total_accent_time = (2.50 * accent_walls);
        double total_normal_time = (3.25 * normal_walls);

        double total_time = (total_accent_time + total_normal_time);
        
        TestCase(i);
        cout << total_time;
        cout << ", ";
        cout << total_accent_color;
        cout << ", ";
        cout << total_normal_color;
        cout << "\n";
    }
    return 0;
}