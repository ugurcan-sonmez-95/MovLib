#include "Movies.hpp"
#include <iostream>
#include <cctype>
#include <limits>

void display_menu() {
    std::cout << "\nWelcome to MovLib!" << "\n\n";
    std::cout << "Enter 'P' to see your movies in your list." << '\n';
    std::cout << "Enter 'A' for adding a movie to your list." << '\n';
    std::cout << "Enter 'R' for removing a movie from your list." << '\n';
    std::cout << "Enter 'I' to increase the watch count of a movie in your list." << '\n';
    std::cout << "Enter 'Q' to quit." << '\n';
}

int main() {
    char ans;
    Movies movie_list;
    do {
        display_menu();
        std::cout << "\nPlease choose what you want to do: ";
        std::cin >> ans;
        ans = std::toupper(ans);
        switch (ans) {
            case 'P':
                movie_list.display();
                break;
            case 'A':
            {
                std::string name;
                std::cout << "Enter the movie name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                int watch_count, rating;
                std::cout << "Enter the watch count and movie rating with spaces: ";
                std::cin >> watch_count >> rating;
                movie_list.add_movie(name, watch_count, rating);
                break;
            }
            case 'R':
            {
                std::string name;
                std::cout << "Enter the movie name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                movie_list.remove_movie(name);
                break;
            }
            case 'I':
            {
                std::string name;
                std::cout << "Enter the movie name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                movie_list.increase_watch_count(name);
                break;
            }
            case 'Q':
                std::cout << "Thank you for using MovLib!" << '\n';
                break;
            default:
                std::cout << "\nUnknown input. Please try again!" << '\n';
        }
    } while (ans != 'Q');

    return 0;
}