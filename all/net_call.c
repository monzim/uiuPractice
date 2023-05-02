#include <curl/curl.h>
#include <stdio.h>

#include "/Users/monzim/Developer/vcpkg/packages/json-c_arm64-osx/include/json-c/json.h"

// Define a struct for the "location" field
struct Location {
  char name[50];
  char region[50];
  char country[50];

  double lat;
  double lon;

  char tz_id[50];
  long localtime_epoch;
  char localtime[20];
} location;

// Define a struct for the "condition" field within the "current" field
struct Condition {
  char text[50];
  char icon[200];

  int code;
};

// Define a struct for the "current" field
struct Current {
  long last_updated_epoch;
  char last_updated[20];

  float temp_c;
  float temp_f;

  int is_day;
  struct Condition condition;

  float wind_mph;
  float wind_kph;
  int wind_degree;
  char wind_dir[5];

  float pressure_mb;
  float pressure_in;

  float precip_mm;
  float precip_in;

  int humidity;
  int cloud;
  float feelslike_c;
  float feelslike_f;

  float vis_km;
  float vis_miles;
  float uv;
  float gust_mph;
  float gust_kph;
};

// Define a struct to store the entire JSON response
struct WeatherData {
  struct Location location;
  struct Current current;
};

// // Callback function to write fetched data to buffer
// size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
//   size_t real_size = size * nmemb;
//   char *buffer = (char *)userp;

//   for (size_t i = 0; i < real_size; i++) {
//     buffer[i] = ((char *)contents)[i];
//   }

//   return real_size;
// }

int main() {
  CURL *curl;
  CURLcode res;

  // Initialize libcurl
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl) {
    // Set URL to fetch weather data from
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.weatherapi.com/v1/current.json?key=&q=Dhaka&aqi=no");

    // Set callback function to write fetched data to buffer
    // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Buffer to store fetched data
    char buffer[2024];

    // Set buffer as user data
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

    // Perform the HTTP GET request
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      curl_easy_cleanup(curl);
      curl_global_cleanup();
      return 1;
    }

    // Print the fetched data
    printf("%s ", buffer);

    // Clean up
    curl_easy_cleanup(curl);
  }

  // Clean up libcurl
  curl_global_cleanup();

  return 0;
}
