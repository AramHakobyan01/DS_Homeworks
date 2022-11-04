#include <iostream>
#include <stack>

std::string SimplyPath(std::string path) {
    std::string currentPath = "";
    std::stack<std::string> pathStack;
    std::string temp = "";
    if (path[path.size() - 1] != '/') {
        path += "/";
    }
    for (int i = 1; i < path.size(); i++) {
        if (path[i] != '/') {
            temp += path[i];
            continue;
        }
        if (temp != ".") {
            if (temp != ".." && temp != "") {
                pathStack.push(temp);
            }
        }
        if (temp == ".") {
            temp = "";
            continue;
        }
        if (temp == "..") {
            if (currentPath.empty()) {
                temp = "";
                continue;
            } else {
                currentPath.resize(currentPath.size() - pathStack.top().size() - 1);
                temp = "";
                pathStack.pop();
                continue;
            }
        }
        if (temp == "/") {
            temp = "";
            continue;
        }
        if (!currentPath.empty() && currentPath[currentPath.size() - 1] == '/') {
            currentPath.resize(currentPath.size() - 1);
        }
        if (!temp.empty()) {
            currentPath += "/";
            currentPath += temp;
            temp = "";
        }
    }
    if (currentPath.empty()) {
        currentPath += "/";
    } else if (currentPath[currentPath.size() - 1] == '/') {
        currentPath.resize(currentPath.size() - 1);
    }
    return currentPath;
}

int main() {
    std::string path = "/Hhp/..///f/R///FM/DPPv///..//";
    std::string currentPath = SimplyPath(path);
    std::cout << currentPath << std::endl;
    return 0;
}
