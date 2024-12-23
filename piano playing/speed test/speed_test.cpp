#include <iostream>
#include <curl/curl.h>
#include <chrono>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb; // We don't need to store the downloaded data
}

double performSpeedTest(const std::string& url) {
    CURL* curl;
    CURLcode res;
    long response_code;
    double downloadSpeed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        
        // Start measuring time
        auto start = std::chrono::high_resolution_clock::now();
        
        res = curl_easy_perform(curl);
        
        // Stop measuring time
        auto end = std::chrono::high_resolution_clock::now();
        
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return 0.0;
        }

        // Get the response code and download speed
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &downloadSpeed);

        // Calculate time taken
        std::chrono::duration<double> duration = end - start;
        
        std::cout << "Response Code: " << response_code << std::endl;
        std::cout << "Download Speed: " << downloadSpeed << " bytes/sec" << std::endl;
        std::cout << "Time Taken: " << duration.count() << " seconds" << std::endl;

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return downloadSpeed;
}

int main() {
    std::string url = "http://ipv4.download.thinkbroadband.com/10MB.zip"; // A sample file for testing
    performSpeedTest(url);
    return 0;
}
