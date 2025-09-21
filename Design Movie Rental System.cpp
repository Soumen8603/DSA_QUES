class MovieRentingSystem {
    map < int, set<pair<int, int>>> movies;
    map < int, set<pair<int, int>>> rented_price;
    map<int, map<int, int>> rented_movies;
    map<int, map<int, int>> prices;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i < entries.size(); i++) {

            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];

            movies[movie].insert({price, shop});
            prices[movie][shop] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        if (movies.find(movie) == movies.end()) {
            return result;
        }
        const auto& shops_for_movie = movies.at(movie);
        int count = 0;
        for (const auto& entry : shops_for_movie) {
            if (count >= 5) {
                break;
            }
            int shop_id = entry.second;
            result.push_back(shop_id);
            count++;
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = prices[movie][shop];
        auto it = movies.find(movie);
        if (it != movies.end()) {
            auto& shop_set = it->second;
            auto shop_it = shop_set.find({price, shop});

            if (shop_it != shop_set.end()) {
                // delete from the movies
                shop_set.erase(shop_it);

                if (shop_set.empty()) {
                    movies.erase(it);
                }
                rented_price[price].insert({shop, movie});
                rented_movies[movie][shop] = price;
            }
        }
    }

    void drop(int shop, int movie) {
        auto movie_it = rented_movies.find(movie);
        if (movie_it != rented_movies.end()) {
            auto& shop_map = movie_it->second;
            auto shop_it = shop_map.find(shop);
            if (shop_it != shop_map.end()) {
                int price = rented_movies[movie][shop];
                shop_map.erase(shop_it);
                if (shop_map.empty()) {
                    rented_movies.erase(movie_it);
                }

                rented_price[price].erase({shop, movie});
                if (rented_price[price].empty()) {
                    rented_price.erase(price);
                }

                movies[movie].insert({price, shop});
                prices[movie][shop] = price;
            }
        }
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        if (rented_price.empty()) {
            return result;
        }
        int count = 0;

        // Iterate through the map, which is sorted by price (the key).
        for (const auto& price_entry : rented_price) {
            const auto& shop_movie_set = price_entry.second;

            // Iterate through the set for each price.
            for (const auto& entry : shop_movie_set) {
                if (count >= 5) {
                    // Stop after collecting 5 movies.
                    return result;
                }

                int shop_id = entry.first;
                int movie_id = entry.second;

                // Push back only the shop_id and movie_id.
                result.push_back({shop_id, movie_id});
                count++;
            }
        }

        return result;
    }
};

