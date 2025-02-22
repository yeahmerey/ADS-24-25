#include<bits/stdc++.h>

using namespace std;

struct Student{
    string name;
    string surname;
    double overall;
};

bool cmp(Student s1, Student s2){
    if(s1.overall == s2.overall){
        if(s1.surname == s2.surname){
            return s1.name < s2.name;
        }
        return s1.surname < s2.surname;
    }
    return s1.overall < s2.overall;
}

int partition(vector <Student> &st, int low, int high){
    Student pivot = st[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(cmp(st[j], pivot)){
            i++;
            swap(st[j],st[i]);
        }   
    }
    swap(st[i+1], st[high]);
    return i + 1;
}

void quickSort(vector <Student> &st, int low, int high){
    if(low < high){
        int pivot = partition(st,low, high);
        quickSort(st, low, pivot - 1);
        quickSort(st, pivot + 1, high);
    }
}

int main(){
    int n; cin >> n;
    vector<Student> st(n);
    map<string, double> mp;
    mp["A+"] = 4.0;
    mp["A"] = 3.75;
    mp["B+"] = 3.5;
    mp["B"] = 3.0;
    mp["C+"] = 2.5;
    mp["C"] = 2.0;
    mp["D+"] = 1.5;
    mp["D"] = 1.0;
    mp["F"] = 0;

    for(auto &student : st){
        cin >> student.surname; 
        cin >> student.name;
        int m; 
        cin >> m;
        double sum = 0, sum2 = 0;
        while(m--){
            string mark; int credits;
            cin >> mark >> credits;
            sum += mp[mark] * credits;
            sum2 += credits;
        }
        student.overall = sum / sum2;
    }
    quickSort(st, 0, st.size() - 1);
    for(auto i : st){
        cout << i.surname << " " << i.name << " " << fixed << setprecision(3) << i.overall << endl;
    }
}