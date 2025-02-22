#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

map <string, double> grades;

struct Students {
    string first, last;
    double gpa;

    Students(string s1, string s2, double gpa) {
        this->last = s1;
        this->first = s2;
        this->gpa = gpa;
    }

    bool check(Students other) {
        if (this->gpa > other.gpa)
            return true;
        else if (this->gpa == other.gpa && this->last > other.last)
            return true;
        else if (this->gpa == other.gpa && this->last == other.last && this->first > other.first)
            return true;
        return false;
    }
};

void heapdown(vector <Students> &a, int n, int i) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int min = i;
    if (l < n && a[l].check(a[min])) {
        min = l;
    }
    if (r < n && a[r].check(a[min])) {
        min = r;
    }
    if (min != i) {
        swap(a[i], a[min]);
        heapdown(a, n, min);
    }
}

void heapS(vector <Students> &a, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapdown(a, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapdown(a, i, 0);
    }
}
// int partition(pair < pair<string, string>, double> a[], int left, int right) {
//     int pivot = right;
//     int i = left - 1;
//     for (int j = left; j <= right - 1; j++) {
//         if (check(a[j], a[pivot])) {
//             i++;
//             swap(a[j], a[i]);
//         }
//     }
//     swap(a[i + 1], a[pivot]);
//     return i + 1;
// }

// int partition2(pair < pair<string, string>, double> a[], int left, int right) {
//     int pivot = (left + right)/2;
//     while(left <= right) {
//         while(check(a[left], a[pivot])) {
//             left++;
//         }
//         while(check(a[pivot], a[right])) {
//             right--;
//         }
//         if (left <= right) {
//             swap(a[left], a[right]);
//             left++;
//             right--;
//         }
//     }
//     return left;
// }

// void QuickS (pair < pair<string, string>, double> a[], int left, int right) {
//     if (left < right) {
//         int index = partition2(a, left, right);
//         QuickS(a, left, index - 1);
//         QuickS(a, index, right);
//     }
// }

double gpa(pair<string, int> a[], int num) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < num; i++) {
        sum1 += grades[a[i].first] * a[i].second;
        sum2 += a[i].second;
    }
    return sum1/sum2;
}

int main() {
    int n; cin >> n;
    grades.insert(make_pair("A+", 4.0));
    grades.insert(make_pair("A", 3.75));
    grades.insert(make_pair("B+", 3.5));
    grades.insert(make_pair("B", 3.0));
    grades.insert(make_pair("C+", 2.5));
    grades.insert(make_pair("C", 2.0));
    grades.insert(make_pair("D+", 1.5));
    grades.insert(make_pair("D", 1.0));
    grades.insert(make_pair("F", 0));
    vector <Students> students;
    for (int i = 0; i < n; i++) {
        int num; string s1, s2;
        cin >> s1 >> s2 >> num;
        pair <string, int> subjects[num];
        for (int j = 0; j < num; j++) {
            cin >> subjects[j].first >> subjects[j].second;
        }
        students.push_back(Students(s1, s2, gpa(subjects, num)));
    }
    heapS(students, n);
    for (int i = 0; i < n; i++) {
        cout << students[i].last << " " << students[i].first << " ";
        cout << setprecision(3) << fixed << students[i].gpa << "\n";
    }
}