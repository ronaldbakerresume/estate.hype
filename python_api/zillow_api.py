import requests

class ZillowAPI:
    def __init__(self, api_key):
        self.api_key = api_key

    def fetch_property_details(self, property_id):
        url = f"https://api.zillow.com/v1/property/{property_id}"
        headers = {"Authorization": f"Bearer {self.api_key}"}
        response = requests.get(url, headers=headers)
        return response.json() if response.status_code == 200 else {"error": response.json()}
