#ifndef MOVIES_HPP
#define MOVIES_HPP

#include <vector>
#include <string>

class Movies {
    private:
        std::vector<Movies> movies;
        std::string name;
        int watch_count, rating;
    public:
        Movies();
        Movies(std::string name, int watch_count, int rating);
        Movies(const Movies &source);
        ~Movies();
        std::string get_name() const;
        void add_movie(const std::string &name, const int watch_count, const int rating);
        void remove_movie(const std::string &name);
        void increase_watch_count(const std::string &name);
        void display() const;
};

#endif 