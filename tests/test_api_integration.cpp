#include <gtest/gtest.h>
#include "api_integration.h"

TEST(APIIntegrationTest, MultithreadedFetch) {
    APIIntegration api;

    std::vector<std::string> urls = {
        "https://api.zillow.com/v1/property/12345",
        "https://api.zillow.com/v1/property/67890",
        "https://api.zillow.com/v1/property/24680"
    };

    std::string apiKey = "your_zillow_api_key_here";
    api.fetchDataMultithreaded(urls, apiKey);

    SUCCEED();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
