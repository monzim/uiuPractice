
#include "url_gen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/log.h"

// Helper Function for generate the URL with the API key
void generateUrl(char* url, const char* location) {
  addLog("generateUrl: Generating URL for location: %s", location);
  snprintf(url, MAX_URL_LENGTH, "%s?key=%s&q=%s&aqi=no", BASE_URL, API_KEY, location);
}

char* getApiUrlWithLocation(const char* location) {
  addLog("getApiUrlWithLocation: Generating URL for location: %s", location);

  char* url = (char*)malloc(MAX_URL_LENGTH * sizeof(char));

  if (url == NULL) {
    printRed("Error: Failed to allocate memory for URL\n");
  }

  snprintf(url, MAX_URL_LENGTH, "%s?key=%s&q=%s&aqi=no", BASE_URL, API_KEY, location);

  return url;
}

char* getCurrentWeatherWithLocationUrl(const char* location) {
  addLog("getCurrentWeatherWithLocationUrl: Generating URL for location: %s", location);
  char* url = (char*)malloc(MAX_URL_LENGTH * sizeof(char));

  if (url == NULL) {
    printRed("Error: Failed to allocate memory for URL\n");
    return "http://api.weatherapi.com/v1/";
  }

  snprintf(url, MAX_URL_LENGTH, "%s%s?key=%s&q=%s&aqi=no", BASE_URL, CURENT_WEATHER_REQUEST, API_KEY, location);

  return url;
}
