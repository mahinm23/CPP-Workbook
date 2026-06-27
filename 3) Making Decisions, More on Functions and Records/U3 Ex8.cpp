#include <iostream>

struct Student { 
    std::string name; 
    std::string id; 
    int total_mark; 
    int cw_mark;
    int exam_mark;
};

std::string getName(Student s) { 
    return s.name; 
}

Student setName(Student s, std::string n) { 
    s.name = n; 
    return s; 
}

Student setExam(Student s, int mark) {
    s.exam_mark = mark;
    return s;
}

Student setCW(Student s, int mark) {
    s.cw_mark = mark;
    return s;
}

int getMark(Student s) {
    s.total_mark = s.cw_mark + s.exam_mark;
}
