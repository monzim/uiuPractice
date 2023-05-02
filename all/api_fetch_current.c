#include "api_fetch_current.h"

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/fetch_write_callback.h"
#include "../helper/file_writer.h"
#include "../helper/json_parser.h"
#include "../helper/log.h"
#include "../helper/print_helper.h"
#include "../helper/url_gen.h"

// Function to fetch current weather data with a given location using libcurl
WeatherData fetchCurrentWeatherWithLocation(const char *location, const char *filename, bool saveToFile, bool print) {
  char id[256];
  sprintf(id, "%ld", time(NULL));

  addLog("GetCurrentWeatherWith: %s Location: %s, File: %s, Print: %s, Name: %s", id, location,
         saveToFile ? "true" : "false", print ? "true" : "false", filename);

  CURL *http;
  CURLcode response;
  char buffer[2024];

  WeatherData weatherData;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  http = curl_easy_init();

  if (http) {
    char *url = getCurrentWeatherWithLocationUrl(location);
    addLog("GetCurrentWeatherWith: %s URL: %s", id, &url);

    curl_easy_setopt(http, CURLOPT_URL, url);

    curl_easy_setopt(http, CURLOPT_WRITEFUNCTION, fetchWriteCallback);

    curl_easy_setopt(http, CURLOPT_WRITEDATA, buffer);

    response = curl_easy_perform(http);

    if (response != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
      addLog("GetCurrentWeatherWith: %s Curl error: %s", id, curl_easy_strerror(response));
      curl_easy_cleanup(http);
      curl_global_cleanup();
      printRed("\n( ´･･)Unable to fetch weather data for location: %s\n", location);
      printRed("Curl error: %s\n", curl_easy_strerror(response));
      printRed("Location: %s\n", location);

      // return weatherData;
      exit(EXIT_FAILURE);
    }

    long http_code = 0;
    curl_easy_getinfo(http, CURLINFO_RESPONSE_CODE, &http_code);

    if (http_code != 200) {
      addLog("GetCurrentWeatherWith: %s, HTTP Code: %ld, Location: %s", id, http_code, location);
      curl_easy_cleanup(http);
      curl_global_cleanup();
      printRed("\n( ´･･)Unable to fetch weather data for location: %s\n", location);
      printRed("HTTP Code: %ld\n", http_code);
      printRed("Location: %s\n", location);
      printYellow(
          "Maybe you have wrong location or you have exceeded the limit of free API calls. Or invalid API key.\n");
      printGray("____________________________________________________________\n");
      exit(EXIT_FAILURE);
    }

    json_object *json = json_tokener_parse(buffer);

    Location weatherLocation;
    Current current;

    parseLocation(json_object_object_get(json, "location"), &weatherLocation);
    parseCurrent(json_object_object_get(json, "current"), &current);

    weatherData.location = weatherLocation;
    weatherData.current = current;

    if (saveToFile) writeBufferToFile(filename, buffer, strlen(buffer), false);
    if (print) printWeatherData(&weatherData);

    curl_easy_cleanup(http);
  }

  addLog("GetCurrentWeatherWith: %s Finished", id);
  curl_global_cleanup();

  addLog("GetCurrentWeatherWith: %s Returning, WeatherData: %s", id, &weatherData);
  return weatherData;
}
