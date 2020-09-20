#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"

#include <queue>
#include <stack>

using namespace std;

RecipeBook recipes = {
    {
        {"SmallDrink", 
                    {
                        {"SmallCup", 1}
                    }
        },
        {"MediumDrink", 
                    {
                        {"MediumCup", 1}
                    }
        },
        {"LargeDrink", 
                    {
                        {"LargeCup", 1}
                    }
        },
        {"Fries", 
                    {
                        {"Potato", 1},
                        {"CanolaOil", 1}
                    }
        },
        {"Burger", 
                    {
                        {"WheatBun", 2},
                        {"BeefPatty", 1},
                        {"Cheese", 1},
                        {"Lettuce", 1},
                        {"Tomato", 1}
                    }
        },
        {"DoubleBurger", 
                    {
                        {"WheatBun", 3},
                        {"BeefPatty", 2},
                        {"Cheese", 2},
                        {"Lettuce", 3},
                        {"Tomato", 1}

                    }
        },
        {"Salad", 
                    {
                        {"Lettuce", 1},
                        {"Tomato", 1},
                        {"SaladDressing", 1},
                        {"Fork", 1}
                    }
        },
        {"IceCreamCone", 
                    {
                        {"SugarCone", 1},
                        {"VanillaCream", 1}
                    }
        },
        {"#1", {
                   {"MediumCup", 1},
                   {"Potato", 1},
                   {"CanolaOil", 1},
                   {"WheatBun", 2},
                   {"BeefPatty", 1},
                   {"Cheese", 1},
                   {"Lettuce", 1},
                   {"Tomato", 1}

               }
        },
        {"#2", {
                   {"MediumCup", 1},
                   {"Potato", 1},
                   {"CanolaOil", 1},
                   {"WheatBun", 3},
                   {"BeefPatty", 2},
                   {"Cheese", 2},
                   {"Lettuce", 3},
                   {"Tomato", 1}
               }
        },
        {"#3", {
                   {"MediumCup", 1},
                   {"Potato", 1},
                   {"CanolaOil", 1},
                   {"WheatBun", 4},
                   {"BeefPatty", 2},
                   {"Cheese", 2},
                   {"Lettuce", 2},
                   {"Tomato", 2}
               }
        }
    }
};

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) :
    runner(runner_),
    kitchen(kitchen_) {}

void Cook::prepare_dish( std::stack<Order>& orders, std::queue<std::pair<std::size_t, Dish>>& finished_dishes) {
    if(orders.empty()) {
        return;
    }

    Order order = orders.top();
    orders.pop();

    vector<string> orderItems = order.get_items();

    for(int i = 0; i < orderItems.size(); i++) {
        IngredientMap ingredientList = recipes[orderItems[i]];

        vector<Ingredient> usedIngredients = runner.get_ingredients(ingredientList);

        pair<size_t, Dish> dish( order.get_id(), kitchen.prepare_dish(move(ingredientList)) );

        finished_dishes.push(dish);
    }

}