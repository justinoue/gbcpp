#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp){
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

int main(int argc, char* argv[]){
  std::cout << "Bootin up..." << std::endl;

  std::string api_key = std::string("api_key=") + std::string(argv[1]);
  std::string format = "format=json";
  std::string endpoint = "http://www.giantbomb.com/api/";

  CURL *curl = curl_easy_init();
  if(curl){
    CURLcode res;
    std::string read_buffer;

    std::string full_uri = endpoint + "videos" + "/?" + api_key + "&" + format;
    curl_easy_setopt(curl, CURLOPT_URL, full_uri.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
      std::cout << "i dunno lol ¯\\(°_o)/¯" << std::endl;
    }
    else{
      rapidjson::Document d;
      d.Parse(read_buffer.c_str());

      const rapidjson::Value& r = d["results"];
      assert(r.IsArray());
      int i = 1;
      for(rapidjson::Value::ConstValueIterator itr = r.Begin(); itr != r.End(); ++itr){
        std::cout << i <<": " << itr[0]["name"].GetString() << std::endl;
        std::cout << itr[0]["site_detail_url"].GetString() << std::endl << std::endl;
        i++;
      }

    }

    curl_easy_cleanup(curl);
  }


  return 0;
}
