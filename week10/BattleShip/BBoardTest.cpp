#include <iostream>
#include "BBoard.hpp"
#include <gtest/gtest.h>

namespace
{
class BBoardTest : public ::testing::Test
    {
    protected:
        Ship destroyer1;
        Ship destroyer2;
        Ship carrier1;
        Ship carrier2;
        Ship battleship1;
        Ship battleship2;

        BBoard board;
        BBoardTest(): 
            destroyer1("destroyer", 2),
            destroyer2("destroyer", 2),
            carrier1("carrier", 5),
            carrier2("carrier", 5),
            battleship1("battleship", 4),
            battleship2("battleship", 4)
        {
        }  
    };

TEST_F(BBoardTest, ShipPlacementRowNEdge)
{
    EXPECT_EQ(true, board.placeShip(destroyer1, 1, 1, 'R'))
              << "failure to place ship in row orientation"
              << ", not edge of board";
    EXPECT_EQ(1, board.getNumShipsRemaining())
              << "Ships counted incorrectly when added to board.";
    EXPECT_EQ(&destroyer1, board.getShipsArrayElement(1, 1));
    EXPECT_EQ(&destroyer1, board.getShipsArrayElement(1, 2))
              << "failure to place ship in correct orientation";
}

TEST_F(BBoardTest, ShipPlacementColNEdge)
{
    EXPECT_EQ(true, board.placeShip(carrier1, 1, 1, 'C'))
              << "failure to place ship in col orientation, "
              << "not edge of board.";
    for(int i = 0; i < carrier1.getLength(); i++)
    {
        EXPECT_EQ(&carrier1, board.getShipsArrayElement(1 + i, 1))
                  << "failure to place ship in correct orientation, "
                  << "not at edge of board.";
    }
}

TEST_F(BBoardTest, ShipPlacementRowEdge)
{
    EXPECT_EQ(true, board.placeShip(destroyer1, 1, 8, 'R'))
              << "failure to place ship in row orientation"
              << ", not edge of board";

    for(int i = 0; i < destroyer1.getLength(); i++)
    {
        EXPECT_EQ(&destroyer1, board.getShipsArrayElement(1, 8 + i))
              << "failure to place ship in correct orientation";
    }
    EXPECT_EQ(false, board.placeShip(destroyer1, 2, 9, 'R'))
              << "Placed ship out of bounds.";
}

TEST_F(BBoardTest, ShipPlacementColEdge)
{
    EXPECT_EQ(true, board.placeShip(carrier1, 5, 1, 'C'))
              << "failure to place ship in col orientation, "
              << "not edge of board.";
    for(int i = 0; i < carrier1.getLength(); i++)
    {
        EXPECT_EQ(&carrier1, board.getShipsArrayElement(5 + i, 1))
                  << "failure to place ship in correct orientation, "
                  << "not at edge of board.";
    }
    EXPECT_EQ(false, board.placeShip(carrier1, 6, 1, 'C'))
              << "Placed ship out of bounds.";
}

TEST_F(BBoardTest, ShipPlacementOverlap)
{
    board.placeShip(battleship1, 2, 2, 'R');
    for(int i = 0; i < battleship1.getLength(); i++)
    {
        EXPECT_EQ(false, board.placeShip(battleship2, 2, 2 + i, 'C'))
                  << "Placed ship on top of another.";
    }
}

TEST_F(BBoardTest, AttackFunctional)
{
    board.placeShip(battleship1, 2, 2, 'R');
    EXPECT_EQ(1, board.getNumShipsRemaining())
              << "Incorrect number ships recorded.";    
    EXPECT_EQ(0, battleship1.getDamage())
              << "Ship wasn't placed with full health.";
    for(int i = 0; i < battleship1.getLength(); i++)
    {
        board.attack(2, 2 + i);
        EXPECT_EQ(i + 1, battleship1.getDamage())
                  << "Not properly counting damage.";
    }
    EXPECT_EQ(0, board.getNumShipsRemaining())
              << "Ship did not sink properly";
    EXPECT_EQ(true, board.attack(2, 2))
              << "Hitting damaged square not returning true.";
    EXPECT_EQ(0, board.getNumShipsRemaining())
              << "Ship sunk twice.";
    EXPECT_EQ(false, board.attack(0, 0))
              << "Attack returned true when empty square was attacked.";
}


}//namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}