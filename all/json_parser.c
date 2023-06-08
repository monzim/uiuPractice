
#include "json_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../helper/log.h"

// Function implementations
void parseLocation(json_object *json, Location *location) {
  addLog("Parsing location from json, json: %p, location: %p", json, location);

  json_object *name, *region, *country, *lat, *lon, *jtz_id, *localtime_epoch, *localtime;

  json_object_object_get_ex(json, "name", &name);
  json_object_object_get_ex(json, "region", &region);
  json_object_object_get_ex(json, "country", &country);

  json_object_object_get_ex(json, "lat", &lat);
  json_object_object_get_ex(json, "lon", &lon);
  json_object_object_get_ex(json, "tz_id", &jtz_id);

  json_object_object_get_ex(json, "localtime_epoch", &localtime_epoch);
  json_object_object_get_ex(json, "localtime", &localtime);

  strncpy(location->name, json_object_get_string(name), sizeof(location->name));
  strncpy(location->region, json_object_get_string(region), sizeof(location->region));
  strncpy(location->country, json_object_get_string(country), sizeof(location->country));

  location->lat = json_object_get_double(lat);
  location->lon = json_object_get_double(lon);

  strncpy(location->tz_id, json_object_get_string(jtz_id), sizeof(location->tz_id));
  location->localtime_epoch = json_object_get_int64(localtime_epoch);
  strncpy(location->localtime, json_object_get_string(localtime), sizeof(location->localtime));
}

void parseCondition(json_object *json, Condition *condition) {
  addLog("Parsing condition from json, json: %p, condition: %p", json, condition);

  json_object *text, *icon, *code;

  json_object_object_get_ex(json, "text", &text);
  json_object_object_get_ex(json, "icon", &icon);
  json_object_object_get_ex(json, "code", &code);

  strncpy(condition->text, json_object_get_string(text), sizeof(condition->text));
  strncpy(condition->icon, json_object_get_string(icon), sizeof(condition->icon));
  condition->code = json_object_get_int(code);
}

void parseCurrent(json_object *json, Current *current) {
  addLog("Parsing current from json, json: %p, current: %p", json, current);

  json_object *last_updated_epoch, *last_updated, *temp_c, *temp_f, *jis_day, *condition, *wind_mph, *wind_kph,
      *wind_degree, *wind_dir, *pressure_mb, *pressure_in, *precip_mm, *precip_in, *humidity, *cloud, *feelslike_c,
      *feelslike_f, *vis_km, *vis_miles, *juv, *gust_mph, *gust_kph;

  json_object_object_get_ex(json, "last_updated_epoch", &last_updated_epoch);
  json_object_object_get_ex(json, "last_updated", &last_updated);

  json_object_object_get_ex(json, "temp_c", &temp_c);
  json_object_object_get_ex(json, "temp_f", &temp_f);
  json_object_object_get_ex(json, "is_day", &jis_day);

  json_object_object_get_ex(json, "condition", &condition);
  json_object_object_get_ex(json, "wind_mph", &wind_mph);
  json_object_object_get_ex(json, "wind_kph", &wind_kph);

  json_object_object_get_ex(json, "wind_degree", &wind_degree);
  json_object_object_get_ex(json, "wind_dir", &wind_dir);

  json_object_object_get_ex(json, "pressure_mb", &pressure_mb);
  json_object_object_get_ex(json, "pressure_in", &pressure_in);
  json_object_object_get_ex(json, "precip_mm", &precip_mm);
  json_object_object_get_ex(json, "precip_in", &precip_in);
  json_object_object_get_ex(json, "humidity", &humidity);
  json_object_object_get_ex(json, "cloud", &cloud);

  json_object_object_get_ex(json, "feelslike_c", &feelslike_c);
  json_object_object_get_ex(json, "feelslike_f", &feelslike_f);

  json_object_object_get_ex(json, "vis_km", &vis_km);
  json_object_object_get_ex(json, "vis_miles", &vis_miles);
  json_object_object_get_ex(json, "uv", &juv);

  json_object_object_get_ex(json, "gust_mph", &gust_mph);
  json_object_object_get_ex(json, "gust_kph", &gust_kph);

  // Parse the extracted JSON values into the Current struct
  current->last_updated_epoch = json_object_get_int64(last_updated_epoch);

  strncpy(current->last_updated, json_object_get_string(last_updated), sizeof(current->last_updated));

  current->temp_c = (float)json_object_get_double(temp_c);
  current->temp_f = (float)json_object_get_double(temp_f);
  current->is_day = json_object_get_int(jis_day);

  parseCondition(condition, &current->condition);
  current->wind_mph = (float)json_object_get_double(wind_mph);
  current->wind_kph = (float)json_object_get_double(wind_kph);
  current->wind_degree = json_object_get_int(wind_degree);

  strncpy(current->wind_dir, json_object_get_string(wind_dir), sizeof(current->wind_dir));

  current->pressure_mb = (float)json_object_get_double(pressure_mb);
  current->pressure_in = (float)json_object_get_double(pressure_in);

  current->precip_mm = (float)json_object_get_double(precip_mm);
  current->precip_in = (float)json_object_get_double(precip_in);

  current->humidity = json_object_get_int(humidity);
  current->cloud = json_object_get_int(cloud);

  current->feelslike_c = (float)json_object_get_double(feelslike_c);
  current->feelslike_f = (float)json_object_get_double(feelslike_f);

  current->vis_km = (float)json_object_get_double(vis_km);
  current->vis_miles = (float)json_object_get_double(vis_miles);

  current->uv = json_object_get_int(juv);
  current->gust_mph = (float)json_object_get_double(gust_mph);
  current->gust_kph = (float)json_object_get_double(gust_kph);
}