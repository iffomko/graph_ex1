#include <iostream>
#include <fstream>
#include "list/list.h"

int main() {
    std::ifstream fin("C:\\Users\\Iluha\\Documents\\github_repos\\28.04.2022-ex1--classwork-\\input.txt");

    list* graph = nullptr;
    int n;

    if (fin) {
        fin >> n;

        graph = new list[n];

        for (int i = 0; i < n; i++) {
            int count, index;
            fin >> count;

            for (int j = 0; j < count; j++) {
                fin >> index;
                graph[i].push(index);
            }
        }
    } else {
        std::cout << "Can't read file..." << std::endl;
    }

    if (graph != nullptr) {
        for (int i = 0; i < n; i++) {
            std::cout << i + 1 << ": ";
            graph[i].print();
            std::cout << std::endl;
        }
    }

    fin.close();

    return 0;
}
