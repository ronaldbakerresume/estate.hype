import requests

class GooglePlacesAPI:
    def __init__(self, api_key):
        self.api_key = api_key

    def search_places(self, query, location, radius=1000):
        url = f"https://maps.googleapis.com/maps/api/place/textsearch/json"
        params = {
            "query": query,
            "location": f"{location[0]},{location[1]}",
            "radius": radius,
            "key": self.api_key,
        }
        response = requests.get(url, params=params)
        return response.json() if response.status_code == 200 else {"error": response.json()}
