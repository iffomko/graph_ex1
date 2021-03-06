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

        std::cout << "\n\n";

        bool isCheck = true;

        for (int i = 0; i < n; i++)
            for (int j = 1; j <= n; j++)
                if (i + 1 != j && !graph[i].check(j)) {
                    isCheck = false;
                    break;
                }

        if (isCheck)
            std::cout << "Graph is full..." << std::endl;
        else
            std::cout << "Graph isn't full..." << std::endl;

        if (!isCheck) {
            list* graphAddition = new list[n];

            for (int i = 0; i < n; i++)
                for (int j = 1; j <= n; j++)
                    if (i + 1 != j && !graph[i].check(j)) {
                        graphAddition[i].push(j);
                    }

            for (int i = 0; i < n; i++) {
                std::cout << i + 1 << ": ";
                graphAddition[i].print();
                std::cout << std::endl;
            }
        }
    }

    fin.close();

    return 0;
}
