#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Letter {
   public:
    string name;
    string address;
    string province;
    string district;
    int zip;
    bool operator<(const Letter& other) const {
        //**Begin Insert**
        return tie(this->zip, this->address, this->name) < tie(other.zip, other.address, other.name);
        //**End Insert**
    }
};
class ZipInfo {
   public:
    int zip;
    string province;
    string district;
};
void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) {
    //**Begin Insert**
    map<string, int> zinfo_map;
    sort(zipinfo.begin(), zipinfo.end(), [](ZipInfo a, ZipInfo b) { return a.district < b.district; });
    for (auto& e : zipinfo) zinfo_map[e.district + e.province] = e.zip;
    // for (auto& e : zinfo_map) cout << e.first << ' ';
    // cout << endl;
    for (auto& e : letters) e.zip = zinfo_map[e.district + e.province];
    sort(letters.begin(), letters.end());
    //**End Insert**
}

int main() {
    int nzip;
    cin >> nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++) {
        ZipInfo z;
        cin >> z.zip >> z.district >> z.province;
        zipinfo.push_back(z);
    }
    int n;
    cin >> n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++) {
        Letter l;
        cin >> l.name >> l.address >> l.district >> l.province >> l.zip;
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    for (auto& l : letters) {
        cout << l.name << " " << l.address << " " << l.district << " " << l.province << " " << l.zip << endl;
    }
}