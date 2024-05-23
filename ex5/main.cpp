#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class myString {
private:
    string m_str;
public:
    myString(string s) {
        m_str = s;
    }
};

class ReadClass {
public:
    void showClass() {
        string content = readFile("main.cpp");
        if (content.empty()) {
            cout << "Error opening file." << endl;
            return;
        }
        int classCount = 0;
        size_t pos = 0;
        while ((pos = content.find("class", pos)) != string::npos) {
            size_t classNameStart = pos + 6;
            size_t classNameEnd = content.find("{", classNameStart);
            if (classNameEnd != string::npos) {
                string className = content.substr(classNameStart, classNameEnd - classNameStart);
                cout << "Class name: " << className << endl;
                classCount++;
                pos = classNameEnd;
            }
        }
        cout << "Total classes found: " << classCount << endl;
    }

private:
    string readFile(const string& filename) {
        FILE* file = fopen(filename.c_str(), "r");
        if (!file)
            return "";
        string content;
        char ch;
        while ((ch = fgetc(file)) != EOF)
            content += ch;
        fclose(file); // 關閉檔案
        return content;
    }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
