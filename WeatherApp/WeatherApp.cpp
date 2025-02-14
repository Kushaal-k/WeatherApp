#include <iostream>
#include <iomanip>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;

void printReadableTime(time_t timestamp)
{
	struct tm timeInfo;
	localtime_s(&timeInfo, &timestamp);

	cout << put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << endl;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* response)
{
	size_t totalSize = size * nmemb;
	response->append((char*)contents, totalSize);
	return totalSize;
}

void fetchWeather(const std::string& city, const std::string& apiKey)
{
	CURL* curl;
	CURLcode res;
	string responseString;

	curl = curl_easy_init();
	if (curl)
	{
		string url = "https://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey;

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
		{
			std::cerr << "cURL Error!!" << curl_easy_strerror(res) << std::endl;
		}
		else
		{
			auto jsonResponse = nlohmann::json::parse(responseString);

			std::cout << "City: " << jsonResponse["name"] << std::endl;

			long temperature = jsonResponse["main"]["temp"];
			long tempCelsius = temperature - 273.15;
			double tempFahrenheit = (tempCelsius * 9 / 5) + 32;
			std::cout << "Temperature : " << tempCelsius << " C or " << tempFahrenheit << " F" << std::endl;

			std::cout << "Humidity : " << jsonResponse["main"]["humidity"] << "%" << std::endl;
			std::cout << "Weather: " << jsonResponse["weather"][0]["description"] << std::endl;

			time_t sunrise = jsonResponse["sys"]["sunrise"];
			time_t sunset = jsonResponse["sys"]["sunset"];

			std::cout << "Sunrise: ";
			printReadableTime(sunrise);
			std::cout << "Sunset: ";
			printReadableTime(sunset);
 		}
			
		curl_easy_cleanup(curl);

	}
}

int main()
{
	string city;
	std::cout << "Enter city name: ";
	std::cin >> city;

	if (city.empty()) {
		std::cout << "Error : City name cannot be empty!!" << std::endl;
		return 0;
	}

	fetchWeather(city, "YOUR_API_KEY");

	return 0;
}