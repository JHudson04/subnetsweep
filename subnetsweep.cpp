#include <iostream>
#include <string>
#include <cstdlib> // system()
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

bool is_host_alive(const std::string& ip)
{
    #ifdef _WIN32
        std::string cmd = "ping -n 1 -w 100 " + ip + " > nul";
    #else
        std::string cmd = "ping -c 1 -W 1 " + ip + " > /dev/null";
    #endif
        int result = system(cmd.c_str());
        return result == 0;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <subnet> <start> <end>\n";
        return 1;
    }

    std::string subnet = argv[1]; // e.g. "192.168.1"
    int start = std::stoi(argv[2]);
    int end = std::stoi(argv[3]);

    for (int i = start; i <= end; ++i)
    {
        std::string ip = subnet + "." + std::to_string(i);
        std::cout << "[*] Scanning " << ip << " ... ";
        if (is_host_alive(ip))
        {
            std::cout << "ONLINE #\n";
        }
        else
        {
            std::cout << "offline X\n";

        }
#ifdef _WIN32
        Sleep(50); // delay between pings
#else
        usleep(50000);
#endif
    }
    return 0;
}