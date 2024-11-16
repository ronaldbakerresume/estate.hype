#include <iostream>
#include "api_integration.h"

int main() {
    APIIntegration api;

    // Zillow API Example: Fetch property data
    std::vector<std::string> zillowUrls = {
        "https://api.zillow.com/v1/property/12345",
        "https://api.zillow.com/v1/property/67890",
        "https://api.zillow.com/v1/property/24680"
    };
    std::string zillowApiKey = "your_zillow_api_key_here";

    std::cout << "Fetching Zillow API data...\n";
    api.fetchDataMultithreaded(zillowUrls, zillowApiKey);

    // Google Places API Example: Search for places
    std::vector<std::string> placesUrls = {
        "https://maps.googleapis.com/maps/api/place/textsearch/json?query=restaurant&location=37.7749,-122.4194",
        "https://maps.googleapis.com/maps/api/place/textsearch/json?query=hospital&location=37.7749,-122.4194",
        "https://maps.googleapis.com/maps/api/place/textsearch/json?query=park&location=37.7749,-122.4194"
    };
    std::string googleApiKey = "your_google_api_key_here";

    std::cout << "Fetching Google Places API data...\n";
    api.fetchDataMultithreaded(placesUrls, googleApiKey);

    std::cout << "Completed all API calls!" << std::endl;
    return 0;
}
