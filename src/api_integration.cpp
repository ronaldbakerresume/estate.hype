#include "api_integration.h"
#include <iostream>
#include <curl/curl.h>
#include <thread>
#include <vector>
#include <mutex>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    size_t totalSize = size * nmemb;
    out->append((char*)contents, totalSize);
    return totalSize;
}

std::string APIIntegration::fetchData(const std::string& url, const std::string& apiKey) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize cURL!" << std::endl;
        return "";
    }

    std::string response;
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    return response;
}

void APIIntegration::fetchDataMultithreaded(const std::vector<std::string>& urls, const std::string& apiKey) {
    std::vector<std::thread> threads;
    for (size_t i = 0; i < urls.size(); ++i) {
        threads.emplace_back([&, i]() {
            std::string result = fetchData(urls[i], apiKey);
            std::lock_guard<std::mutex> lock(outputMutex);
            std::cout << "Thread " << i << " fetched: " << result.substr(0, 100) << "...\n";
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}
