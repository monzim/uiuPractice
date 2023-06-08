#include <stdio.h>

#include "../helper/color_print.h"
#include "../models/models.h"

void printLocation(const Location* location) {
  printMagenta("Local Time: %s\n", location->localtime);

  printMagenta("Location: %s, %s, %s\n", location->name, location->region, location->country);

  printMagenta("Google Maps: ");
  printBlue("https:
}

void printCurrent(const Current* current) {
  printGray("Weather Condition: ");
  printBoldRed("%s\n", current->condition.text);

  printf("Temperature (C): ");
  printf("%.1f\n", current->temp_c);

  printf("Temperature (F): ");
  printf("%.1f\n", current->temp_f);

  printf("Feels Like (C): ");
  printf("%.1f\n", current->feelslike_c);

  printf("Feels Like (F): ");
  printf("%.1f\n", current->feelslike_f);

  printf("Wind Speed (mph): ");
  printf("%.1f\n", current->wind_mph);

  printf("Wind Speed (kph): ");
  printf("%.1f\n", current->wind_kph);

  printf("Wind Degree: ");
  printf("%d\n", current->wind_degree);

  printf("Wind Direction: ");
  printf("%s\n", current->wind_dir);

  printf("Pressure (mb): ");
  printf("%.1f\n", current->pressure_mb);

  printf("Pressure (in): ");
  printf("%.2f\n", current->pressure_in);

  printf("Precipitation (mm): ");
  printf("%.1f\n", current->precip_mm);

  printf("Precipitation (in): ");
  printf("%.2f\n", current->precip_in);

  printf("Humidity: ");
  printf("%d\n", current->humidity);

  printf("Cloud: ");
  printf("%d\n", current->cloud);

  printYellow("\nLast Updated: ");
  printYellow("%s\n", current->last_updated);
}

void printWeatherData(const WeatherData* weatherData) {
  printGreen("\nWeather Data\n");
  printRed("========================================\n");

  printLocation(&weatherData->location);
  printf("\n");
  printCurrent(&weatherData->current);
}
