#ifndef API_INTEGRATION_H
#define API_INTEGRATION_H

#include <string>
#include <vector>
#include <mutex>

class APIIntegration {
public:
    std::string fetchData(const std::string& url, const std::string& apiKey);
    void fetchDataMultithreaded(const std::vector<std::string>& urls, const std::string& apiKey);

private:
    std::mutex outputMutex;
};

#endif // API_INTEGRATION_H
