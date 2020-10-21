#include "Movies.hpp"
#include <iostream>

Movies::Movies() {}

Movies::Movies(std::string name, int watch_count, int rating) 
    : name{name}, watch_count{watch_count}, rating{rating} {}

Movies::Movies(const Movies &source)
    : Movies{source.name, source.watch_count, source.rating} {}

Movies::~Movies() {}

void Movies::add_movie(const std::string &name, const int watch_count, const int rating) {
    for (const auto &movie: movies) {
        if (movie.get_name() == name) {
            std::cout << "The movie already exists!" << '\n';
            return;
        }
    }
    Movies new_movie {name, watch_count, rating};
    movies.push_back(new_movie);
    std::cout << "The movie has been successfully added!" << '\n';
}

void Movies::remove_movie(const std::string &name) {
    for (int i{}; i < movies.size(); i++) {
        if (movies[i].get_name() == name) { 
            movies.erase(movies.begin()+i);
            std::cout << "The movie has been successfully removed!" << '\n';
            return;
        }
    }
    std::cout << "There is no such movie in the library." << '\n';
}

std::string Movies::get_name() const { return name; }

void Movies::increase_watch_count(const std::string &name) {
    for (auto &movie: movies) {
        if (movie.get_name() == name) {
            movie.watch_count++;
            std::cout << "The watch count has been updated." << '\n';
            return;
        }
    }
    std::cout << "There is no such movie in the library." << '\n';    
}

void Movies::display() const {
    if (movies.empty()) {
        std::cout << "\nYour movie list is empty." << '\n';
        return;
    }
    std::cout << '\n';
    for (const auto &movie: movies) 
        std::cout << "[ " << movie.name << " - " << movie.watch_count << " times watched - " << movie.rating << "-star rating" << " ]" << '\n';
}