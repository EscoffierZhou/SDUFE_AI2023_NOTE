#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// 使用libcurl进行HTTP请求
size_t CurlWriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// 将文本进行翻译
std::string TranslateText(const std::string& text, const std::string& fromLang, const std::string& toLang)
{
    std::string translation;

    std::string url = "https://openapi.youdao.com/api";
    url += "?q=" + text;
    url += "&appKey=40dd5b5c5581ab83";  // 您的应用ID
    url += "&salt=1";
    url += "&signType=v3";
    url += "&curtime=0";
    url += "&from=" + fromLang;
    url += "&to=" + toLang;

    CURL* curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &translation);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            std::cerr << "Failed to perform curl request: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        std::cerr << "Failed to initialize curl." << std::endl;
    }

    return translation;
}

int main()
{
    // 输入日语文本
    std::vector<std::string> texts;
    std::string input;
    std::cout << "输入日语文本（输入over结束输入）：" << std::endl;
    while (std::getline(std::cin, input) && input != "over")
    {
        texts.push_back(input);
    }

    // 翻译文本并输出结果
    std::cout << "翻译结果：" << std::endl;
    for (const std::string& text : texts)
    {
        std::string translation = TranslateText(text, "ja", "zh-CHS");
        std::cout << text << " => " << translation << std::endl;
    }

    return 0;
}