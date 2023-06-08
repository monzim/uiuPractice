#include "discord.h"

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

// Manually added libraries
#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/log.h"
#include "/Users/monzim/Developer/vcpkg/packages/json-c_arm64-osx/include/json-c/json.h"

// Function to send a Discord webhook message using curl
void sendWebhookMessage(const char *url, const char *jsonPayload) {
  CURL *curl;
  CURLcode res;
  struct curl_slist *headers = NULL;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload);

    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      addLog("Sending Discord message failed, curl error: %s", curl_easy_strerror(res));
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
  }
}

// Function to send a Discord message
void sendMessageToDiscord(const char *url, const struct DiscordMessage *message) {
  struct json_object *embedObj = json_object_new_object();
  struct json_object *footerObj = json_object_new_object();
  struct json_object *thumbnailObj = json_object_new_object();

  json_object_object_add(embedObj, "title", json_object_new_string(message->embeds[0].title));
  json_object_object_add(embedObj, "description", json_object_new_string(message->embeds[0].description));
  json_object_object_add(embedObj, "color", json_object_new_int(message->embeds[0].color));
  json_object_object_add(embedObj, "timestamp", json_object_new_string(message->embeds[0].timestamp));

  json_object_object_add(footerObj, "text", json_object_new_string(message->embeds[0].footer.text));
  json_object_object_add(embedObj, "footer", footerObj);

  json_object_object_add(thumbnailObj, "url", json_object_new_string(message->embeds[0].thumbnail.url));
  json_object_object_add(embedObj, "thumbnail", thumbnailObj);

  // Create main JSON object and add embeds array
  struct json_object *jsonObj = json_object_new_object();
  struct json_object *embedArray = json_object_new_array();
  json_object_array_add(embedArray, embedObj);
  json_object_object_add(jsonObj, "content", json_object_new_null());
  json_object_object_add(jsonObj, "embeds", embedArray);
  json_object_object_add(jsonObj, "username", json_object_new_string(message->username));
  json_object_object_add(jsonObj, "avatar_url", json_object_new_string(message->avatar_url));
  json_object_object_add(jsonObj, "attachments", json_object_new_array());

  const char *jsonPayload = json_object_to_json_string(jsonObj);

  // Send the message
  sendWebhookMessage(url, jsonPayload);
  addLog("Discord message sent successfully");
}

// Function to generate Discord message from weather data
DiscordMessage generateDiscordMessage(WeatherData weatherData) {
  DiscordMessage discordMessage;

  discordMessage.content[0] = '\0';

  sprintf(discordMessage.embeds[0].title, "Weather update for %s, %s", weatherData.location.name,
          weatherData.location.country);

  sprintf(discordMessage.embeds[0].description,
          "Current Weather:  **%s**\nTemperature: %.1f°C \nFeels Like: %.1f°C\n\nWind: %.1f mph from %s\nPressure: "
          "%.1f mb \nHumidity: %d%%\nVisibility: %.1f km\n\nUV Index: %.1f\nGusts: %.1f mph\nLocation: "
          "[%s](https://www.google.com/maps?q=%.6f,%.6f)",
          weatherData.current.condition.text, weatherData.current.temp_c, weatherData.current.feelslike_c,
          weatherData.current.wind_mph, weatherData.current.wind_dir, weatherData.current.pressure_mb,
          weatherData.current.humidity, weatherData.current.vis_km, weatherData.current.uv,
          weatherData.current.gust_mph, weatherData.location.name, weatherData.location.lat, weatherData.location.lon);

  discordMessage.embeds[0].color = 4512659;

  sprintf(discordMessage.embeds[0].footer.text, "Last Updated: %s (local time)", weatherData.current.last_updated);

  strncpy(discordMessage.embeds[0].timestamp, weatherData.current.last_updated,
          sizeof(discordMessage.embeds[0].timestamp) - 1);

  discordMessage.embeds[0].timestamp[sizeof(discordMessage.embeds[0].timestamp) - 1] = '\0';

  sprintf(discordMessage.embeds[0].thumbnail.url, "http:%s", weatherData.current.condition.icon);

  sprintf(discordMessage.username, "%s", BOT_NAME);
  strcpy(discordMessage.avatar_url, BOT_AVATAR_URL);

  addLog("Discord message generated successfully");

  return discordMessage;
}
