#include "naiveCrumbyColouring.h"

int main() {
    auto t_start = std::chrono::high_resolution_clock::now();
    std::vector<std::bitset<MAX_VERTICES>> adjacencyList;


    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    long long numberOfGraphsRead = 0;
    int number_of_crumby_colourable_graphs = 0;

    while (getline(std::cin, line)) {
        std::bitset<MAX_VERTICES> blueVertices, redVertices = std::bitset<MAX_VERTICES>();
        numberOfGraphsRead++;
        int n = getNumberOfVertices(line);
        loadGraph(line, n, adjacencyList);
        auto t1 = std::chrono::high_resolution_clock::now();
        int num_of_colourings = countNaiveCrumbyColourings(n, adjacencyList, 0, blueVertices, redVertices);
        if (num_of_colourings)
        {
            number_of_crumby_colourable_graphs++;
        } else {
            std::cout << line << std::endl;
        }

    }

    std::cerr << number_of_crumby_colourable_graphs << "/" << numberOfGraphsRead << " Graphs admit a crumby colouring in "
    << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-t_start).count()
    << "ms" << std::endl;

    return 0;
}