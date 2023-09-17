#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>

void clearConsole() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void pingIP(const std::string& ipAddress) {
    std::string command = "start cmd /c ping " + ipAddress;
    std::system(command.c_str());
}

int main() {
    clearConsole();
    std::cout << "Warning: Your IP address is sensitive information. Keep it private and don't share it with unauthorized parties.\n";
    std::string ipAddress;
    std::cout << "Please enter the IP address you want to ping: ";
    std::cin >> ipAddress;
    int numTabs;
    std::cout << "Please enter the number of CMD tabs you want to open: ";
    std::cin >> numTabs;

    std::vector<std::thread> threads;

    for (int i = 0; i < numTabs; ++i) {
        threads.push_back(std::thread(pingIP, ipAddress));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Pinging " << ipAddress << " in " << numTabs << " separate CMD tabs.\n";
    return 0;
}
