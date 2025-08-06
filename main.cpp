#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct GuestEntry
{
    std::string name;
    uint32_t checkInTime = 0;
    uint32_t checkOutTime = 0;
};

static std::string::const_iterator findComma(std::string::const_iterator begin, std::string::const_iterator end)
{
    constexpr char comma = ',';

    std::string::const_iterator it = std::find(begin, end, comma);
    if (it == end)
    {
        throw std::runtime_error("Comma was not found");
    }

    return it;
}

static std::vector<GuestEntry> parseEntries(const char *fileName)
{
    std::vector<GuestEntry> entries;

    std::ifstream stream(fileName);
    if (!stream)
    {
        throw std::runtime_error("Input file was not found");
    }

    std::string line;

    // Skip the header
    std::getline(stream, line);
    while (std::getline(stream, line))
    {
        GuestEntry currentEntry;

        auto firstCommaIt = findComma(line.cbegin(), line.cend());
        currentEntry.name = std::string(line.cbegin(), firstCommaIt);
        firstCommaIt++;

        auto secondCommaIt = findComma(firstCommaIt, line.cend());
        currentEntry.checkInTime = std::stoi(std::string(firstCommaIt, secondCommaIt));
        secondCommaIt++;

        currentEntry.checkOutTime = std::stoi(std::string(secondCommaIt, line.cend()));

        if (currentEntry.checkInTime > currentEntry.checkOutTime)
        {
            throw std::runtime_error("checkInTime is larger then checkOutTime ");
        }

        entries.push_back(currentEntry);
    }

    return entries;
}

static void printTheMostPopulatedPeriod(const std::vector<GuestEntry> &entries)
{
    // Put solution in here
}

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        return 1;
    }

    try
    {
        const char *fileName = argv[1];
        std::vector<GuestEntry> entries = parseEntries(fileName);
        printTheMostPopulatedPeriod(entries);

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 1;
}
