#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// ʹ��libcurl����HTTP����
size_t CurlWriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// ���ı����з���
std::string TranslateText(const std::string& text, const std::string& fromLang, const std::string& toLang)
{
    std::string translation;

    std::string url = "https://openapi.youdao.com/api";
    url += "?q=" + text;
    url += "&appKey=40dd5b5c5581ab83";  // ����Ӧ��ID
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
    // ���������ı�
    std::vector<std::string> texts;
    std::string input;
    std::cout << "���������ı�������over�������룩��" << std::endl;
    while (std::getline(std::cin, input) && input != "over")
    {
        texts.push_back(input);
    }

    // �����ı���������
    std::cout << "��������" << std::endl;
    for (const std::string& text : texts)
    {
        std::string translation = TranslateText(text, "ja", "zh-CHS");
        std::cout << text << " => " << translation << std::endl;
    }

    return 0;
}