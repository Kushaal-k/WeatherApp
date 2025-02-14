# Weather App

A C++ command-line weather application that fetches real-time weather data using the OpenWeatherMap API. The app provides current weather conditions, temperature, humidity, and sunrise/sunset times for any city.

## Features

- **Real-time Weather Data**
  - Current temperature (Celsius and Fahrenheit)
  - Humidity levels
  - Weather description
  - Sunrise and sunset times

- **User-friendly Interface**
  - Simple command-line input
  - Formatted time display
  - Clear data presentation

- **Error Handling**
  - Input validation
  - API connection error handling
  - JSON parsing error management

## Technical Stack

- **Language:** C++
- **Libraries Required:**
  - `libcurl` - For HTTP requests
  - `nlohmann/json` - For JSON parsing
  - Standard C++ libraries

## Prerequisites

1. C++ compiler (supporting C++11 or later)
2. libcurl library
3. nlohmann/json library
4. OpenWeatherMap API key

## Setup

1. **Install Required Libraries**
   ```bash
   # On Ubuntu/Debian
   sudo apt-get install libcurl4-openssl-dev
   sudo apt-get install nlohmann-json3-dev

   # On Windows with vcpkg
   vcpkg install curl:x64-windows
   vcpkg install nlohmann-json:x64-windows
   ```

2. **API Key Configuration**
   - Sign up at [OpenWeatherMap](https://openweathermap.org/api)
   - Get your API key
   - Replace `"YOUR_API_KEY"` in the code with your actual API key

## Usage

1. Compile the program:
   ```bash
   g++ weather_app.cpp -lcurl -o weather_app
   ```

2. Run the program:
   ```bash
   ./weather_app
   ```

3. Enter the city name when prompted

## Code Structure

### Main Components

1. **WriteCallback Function**
   - Handles the API response data
   - Accumulates received data into a string

2. **printReadableTime Function**
   - Converts UNIX timestamps to readable datetime format
   - Formats sunrise and sunset times

3. **fetchWeather Function**
   - Makes API calls to OpenWeatherMap
   - Parses JSON response
   - Displays formatted weather information

## API Response Handling

The app processes the following JSON data:
- Temperature (converted from Kelvin to Celsius and Fahrenheit)
- Humidity percentage
- Weather description
- Sunrise and sunset times (converted from UNIX timestamp)

## Error Handling

- Empty city name validation
- cURL error handling
- JSON parsing error handling
- Network connection error handling

## Output Format

```
Enter city name: London
City: London
Temperature: 18 C or 64.4 F
Humidity: 72%
Weather: partly cloudy
Sunrise: 2024-02-15 06:45:23
Sunset: 2024-02-15 17:15:45
```

## Future Improvements

1. Add support for:
   - Weather forecasts
   - Multiple cities at once
   - Additional weather metrics (wind speed, pressure)
2. Implement configuration file for API key
3. Add historical weather data
4. Include weather alerts and warnings
5. Add graphical visualization of weather data

## Security Note

- The API key is currently hardcoded in the source. For production use, consider:
  - Using environment variables
  - Implementing a configuration file
  - Using secure key management

## Contributing

Feel free to fork this project and submit pull requests for any improvements.

## License

This project is open source and available under the MIT License.