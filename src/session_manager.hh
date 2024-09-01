#pragma once

#include <chrono>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <cstdio>
#include <iostream>

class SessionManager
{
public:
    SessionManager(int expected_users = 100);
    ~SessionManager();
    void update_session(const std::string &session_id);

private:
    void monitor_sessions();

private:
    std::mutex session_mutex;
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> session_durations;
};

SessionManager::SessionManager(int expected_users)
{
    session_durations.reserve(expected_users);
    std::thread(&SessionManager::monitor_sessions,this).detach();
}

SessionManager::~SessionManager()
{
}

void SessionManager::update_session(const std::string &session_id)
{
    std::lock_guard<std::mutex> lock(session_mutex);
    session_durations[session_id] = std::chrono::steady_clock::now();
}

void SessionManager::monitor_sessions()
{
    while (true)
    {
        std::cout << "executing background job!!\n";
        
        std::this_thread::sleep_for(std::chrono::seconds(10)); // Check every minute
        auto now = std::chrono::steady_clock::now();

        std::lock_guard<std::mutex> lock(session_mutex);
        for (auto it = session_durations.begin(); it != session_durations.end();)
        {
            if (std::chrono::duration_cast<std::chrono::seconds>(now - it->second).count() >= 10)
            { 
                std::system((std::string{"rm ./workplace/"} + it->first + "*").c_str());
                it = session_durations.erase(it); 
            }
            else
            {
                ++it;
            }
        }
        std::cout << "execution done!!\n";
    }
}
