#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <thread>
#include <mutex>
#include <iostream>
using namespace std;
map<string, string> g_pages;
mutex g_pages_mutex;
void save_page(const string &url) {
    //simulate a long page fetch
    this_thread::sleep_for(chrono::seconds(2));
    string result = "fake content";

    lock_guard<mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}
int main() {
    thread t1(save_page, "http://foo");
    thread t2(save_page, "http://bar");

    for(const auto &it : g_pages) {
        cout << it.first << " => " << it.second << "\n";
    }

    return 0;
}
