#include "gtest/gtest.h"
#include "../Game.h"

TEST(gameTest, assignmentTest){
    Game game;
    ASSERT_EQ(game.intRect, (sf::IntRect{0,0,72,36}));
}