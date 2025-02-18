#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Grid {
    int** grid;
    void set_grid();
   
public:
    int no_of_mines;
    bool game_over;
    int** grid_d;
    Grid();
    void display_grid();
    void checker();
    void openEmptyCell(int row,int col);
    int return_value(int row, int col);
    ~Grid();
};

void Grid::set_grid() {
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> uni(0, 8);
    no_of_mines = 10;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
            grid_d[i][j] = 10;
        }
    }
    int row = 0, col = 0;
    for (int i = 0; i < no_of_mines; i++) {
        row = uni(rng);
        col = uni(rng);
        grid[row][col] = 9;
    }
}

void Grid::display_grid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Grid::Grid() {
    grid = new int* [9];
    grid_d = new int* [9];
    for (int i = 0; i < 9; i++) {
        grid[i] = new int[9];
        grid_d[i] = new int[9];
    }
    set_grid();
    checker();
    display_grid();
}


void Grid::checker() {
    int mine_count = 0;

    //col 0

    for (int row_index = 0; row_index < 9; row_index++) {

        if (grid[row_index][0] == 9) {

            continue;

        }

        if (row_index >= 1 && row_index <= 7) {

            for (int i = 0; i < 5; i++) {

                if (i == 0) {

                    if (grid[row_index - 1][0] == 9) {

                        mine_count++;


                    }
                }

                if (i == 1) {

                    if (grid[row_index - 1][1] == 9) {


                        mine_count++;

                    }
                }

                if (i == 2) {

                    if (grid[row_index][1] == 9) {


                        mine_count++;

                    }
                }

                if (i == 3) {

                    if (grid[row_index + 1][1] == 9) {


                        mine_count++;

                    }
                }

                if (i == 4) {

                    if (grid[row_index + 1][0] == 9) {


                        mine_count++;

                    }
                }
            }

            if (mine_count > 0) {
                grid[row_index][0] = mine_count;
            }
            mine_count = 0;
        }

        if (row_index == 0) {

            for (int i = 0; i < 3; i++) {

                if (i == 0) {

                    if (grid[row_index][1] == 9) {

                        mine_count++;

                    }
                }
                if (i == 1) {
                    if (grid[row_index + 1][1] == 9) {

                        mine_count++;

                    }
                }
                if (i == 2) {
                    if (grid[row_index + 1][0] == 9) {

                        mine_count++;

                    }
                }

            }
            if (mine_count > 0) {
                grid[row_index][0] = mine_count;
            }
            mine_count = 0;
        }

        else if (row_index == 8) {

            for (int i = 0; i < 3; i++) {
                if (i == 0) {
                    if (grid[row_index - 1][0] == 9) {

                        mine_count++;


                    }
                }

                if (i == 1) {

                    if (grid[row_index - 1][1] == 9) {

                        mine_count++;

                    }
                }

                if (i == 2) {
                    if (grid[row_index][1] == 9) {


                        mine_count++;

                    }
                }
            }
            if (mine_count > 0) {
                grid[row_index][0] = mine_count;
            }
            mine_count = 0;
        }
    }

    //col 8

    for (int row_index = 0; row_index < 9; row_index++) {

        if (grid[row_index][8] == 9) {

            continue;


        }

        if (row_index >= 1 && row_index <= 7) {

            for (int i = 0; i < 5; i++) {

                if (i == 0) {
                    if (grid[row_index - 1][8] == 9) {
                        mine_count++;
                    }
                }

                if (i == 1) {
                    if (grid[row_index - 1][7] == 9) {
                        mine_count++;
                    }
                }

                if (i == 2) {
                    if (grid[row_index][7] == 9) {
                        mine_count++;
                    }
                }

                if (i == 3) {
                    if (grid[row_index + 1][7] == 9) {
                        mine_count++;
                    }
                }

                if (i == 4) {
                    if (grid[row_index + 1][8] == 9) {
                        mine_count++;
                    }
                }
            }
            if (mine_count > 0) {
                grid[row_index][8] = mine_count;
            }
            mine_count = 0;
        }

        else if (row_index == 0) {


            for (int i = 0; i < 3; i++) {

                if (i == 0) {

                    if (grid[row_index][7] == 9) {

                        mine_count++;


                    }
                }

                if (i == 1) {

                    if (grid[row_index + 1][7] == 9) {

                        mine_count++;

                    }
                }

                if (i == 2) {

                    if (grid[row_index + 1][8] == 9) {

                        mine_count++;

                    }
                }

            }
            if (mine_count > 0) {
                grid[row_index][8] = mine_count;
            }
            mine_count = 0;


        }

        else if (row_index == 8) {


            for (int i = 0; i < 3; i++) {

                if (i == 0) {

                    if (grid[row_index - 1][8] == 9) {

                        mine_count++;


                    }

                }

                if (i == 1) {

                    if (grid[row_index - 1][7] == 9) {

                        mine_count++;

                    }
                }

                if (i == 2) {

                    if (grid[row_index][7] == 9) {

                        mine_count++;

                    }
                }



            }
            if (mine_count > 0) {
                grid[row_index][8] = mine_count;
            }
            mine_count++;
        }

    }

    //row 0

    for (int col_index = 1; col_index < 8; col_index++) {

        if (grid[0][col_index] == 9) {

            continue;


        }

        for (int i = 0; i < 5; i++) {

            if (i == 0) {

                if (grid[0][col_index - 1] == 9) {

                    mine_count++;

                }
            }

            if (i == 1) {

                if (grid[1][col_index - 1] == 9) {

                    mine_count++;

                }
            }
            if (i == 2) {
                if (grid[1][col_index] == 9) {

                    mine_count++;

                }
            }

            if (i == 3) {

                if (grid[1][col_index + 1] == 9) {

                    mine_count++;

                }
            }

            if (i == 4) {
                if (grid[0][col_index + 1] == 9) {

                    mine_count++;

                }
            }

        }
        if (mine_count > 0) {
            grid[0][col_index] = mine_count;
        }
        mine_count = 0;
    }


    //row 8

    for (int col_index = 1; col_index < 8; col_index++) {

        if (grid[8][col_index] == 9) {
            continue;
        }




        for (int i = 0; i < 5; i++) {

            if (i == 0) {
                if (grid[8][col_index - 1] == 9) {

                    mine_count++;

                }
            }

            if (i == 1) {

                if (grid[7][col_index - 1] == 9) {

                    mine_count++;

                }
            }

            if (i == 2) {

                if (grid[7][col_index] == 9) {

                    mine_count++;

                }
            }

            if (i == 3) {

                if (grid[7][col_index + 1] == 9) {

                    mine_count++;

                }
            }

            if (i == 4) {

                if (grid[8][col_index + 1] == 9) {

                    mine_count++;

                }
            }

        }

        if (mine_count > 0) {
            grid[8][col_index] = mine_count;
        }
        mine_count = 0;


    }



    for (int row = 1; row < 8; row++) {
        for (int col = 1; col < 8; col++) {

            if (grid[row][col] == 9) {

                continue;

            }

            for (int i = 0; i < 8; i++) {

                if (i == 0) {

                    if (grid[row - 1][col - 1] == 9) {

                        mine_count++;

                    }


                }

                if (i == 1) {

                    if (grid[row - 1][col] == 9) {

                        mine_count++;

                    }

                }

                if (i == 2) {

                    if (grid[row - 1][col + 1] == 9) {

                        mine_count++;

                    }

                }

                if (i == 3) {

                    if (grid[row][col - 1] == 9) {

                        mine_count++;

                    }


                }

                if (i == 4) {

                    if (grid[row][col + 1] == 9) {

                        mine_count++;

                    }


                }

                if (i == 5) {

                    if (grid[row + 1][col - 1] == 9) {

                        mine_count++;

                    }


                }

                if (i == 6) {

                    if (grid[row + 1][col] == 9) {

                        mine_count++;

                    }

                }

                if (i == 7) {

                    if (grid[row + 1][col + 1] == 9) {

                        mine_count++;

                    }

                }
            }
            if (mine_count > 0) {
                grid[row][col] = mine_count;
            }
            mine_count = 0;
        }
    }
}

void Grid::openEmptyCell(int row, int col) {

    if (grid[row][col] == 0) {

        grid_d[row][col] = grid[row][col];

    }


    for (int i = -1; i <= 2; i++) {


        for (int j = -1; j <= 2; j++) {

            row = row + i;
            col = col + i;

            if (row >= 0 && row < 9 && col >= 0 && col < 9 && grid[row][col] == 0) {

                openEmptyCell(row,col);


            }


        }



    }





}

int Grid::return_value(int row, int col) {
    return grid[row][col];
}



Grid::~Grid() {
    for (int i = 0; i < 9; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}




int main(){

	int Cell_size = 32, rows = 9, cols = 9;

	sf::RenderWindow window(sf::VideoMode(288,360), "Minesweeper");

    int w = 72;

	sf::Texture cell_text, zero_t,one_t,two_t,three_t,four_t,five_t,six_t,seven_t,eight_t, mine_t,flag_t, smile_t, frown_t, cool_t;
	cell_text.loadFromFile("Minesweeper Images/tile_hidden.png");
    zero_t.loadFromFile("Minesweeper Images/tile_revealed.png");
    one_t.loadFromFile("Minesweeper Images/number_1.png");
    two_t.loadFromFile("Minesweeper Images/number_2.png");
    three_t.loadFromFile("Minesweeper Images/number_3.png");
    four_t.loadFromFile("Minesweeper Images/number_4.png");
    five_t.loadFromFile("Minesweeper Images/number_5.png");
    six_t.loadFromFile("Minesweeper Images/number_6.png");
    seven_t.loadFromFile("Minesweeper Images/number_7.png");
    eight_t.loadFromFile("Minesweeper Images/number_8.png");
    mine_t.loadFromFile("Minesweeper Images/mine.png");
    flag_t.loadFromFile("Minesweeper Images/flag.png");
    smile_t.loadFromFile("Minesweeper Images/face_happy.png");
    frown_t.loadFromFile("Minesweeper Images/face_lose.png");
    cool_t.loadFromFile("Minesweeper Images/face_win.png");
   

	if (!cell_text.loadFromFile("Minesweeper Images/tile_hidden.png") || !one_t.loadFromFile("Minesweeper Images/number_1.png"))
	{
		std::cout << "Error" << std::endl;
	}

	sf::Sprite cell;
	cell.setTexture(cell_text);

    sf::Sprite zero, one, two, three, four, five, six, seven, eight, mine,flag, smile,frown, cool;
    zero.setTexture(zero_t);
    one.setTexture(one_t);
    two.setTexture(two_t);
    three.setTexture(three_t);
    four.setTexture(four_t);
    five.setTexture(five_t);
    six.setTexture(six_t);
    seven.setTexture(seven_t);
    eight.setTexture(eight_t);
    mine.setTexture(mine_t);
    flag.setTexture(flag_t);
    smile.setTexture(smile_t);
    frown.setTexture(frown_t);
    cool.setTexture(cool_t);
   
    //clock 


    sf::Clock stopwatch;
    sf::RectangleShape stopwatch_bg(sf::Vector2f(112.f,64.f)), smile_bg(sf::Vector2f(64.f, 64.f)), count_bg(sf::Vector2f(112.f, 64.f));

    stopwatch_bg.setFillColor(sf::Color::Black);
    stopwatch_bg.setOutlineColor(sf::Color::Black);
    stopwatch_bg.setOutlineThickness(2.f);
    stopwatch_bg.setPosition(0.f, 0.f);

    count_bg.setFillColor(sf::Color::Black);
    count_bg.setOutlineColor(sf::Color::Black);
    count_bg.setOutlineThickness(2.f);
    count_bg.setPosition(178.f, 0.f);


    smile_bg.setFillColor(sf::Color::Black);
    smile_bg.setPosition(128.f, 0.f);

    sf::Font font;

    font.loadFromFile("Minesweeper Images/mine-sweeper.otf");

    sf::Text stopwatchText("", font, 20), counterText("", font, 20);

    stopwatchText.setCharacterSize(30);
    counterText.setCharacterSize(30);
    stopwatchText.setPosition(39.f, 19.f);
    stopwatchText.setFillColor(sf::Color::Red);
    counterText.setPosition(178.f, 0.f);
    counterText.setFillColor(sf::Color::Red);

    Grid g1;

    bool game_over = 0;

    int x = 0, y = 0;

	while (window.isOpen()) {

        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int x_mouse = pos.x / Cell_size;
        int y_mouse = (pos.y - w) / Cell_size;

        

		sf::Event event;

		while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }


            if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {

                int row = x_mouse;
                int col = y_mouse;
                

                if (g1.grid_d[row][col] == 0) {
                    g1.openEmptyCell(row, col);
                }


                else {
                    g1.grid_d[row][col] = g1.return_value(row, col);
                }
            }

            else if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Right) {
                
                int row = x_mouse;
                int col = y_mouse;
                g1.grid_d[row][col] = 11;
            }

 

		}
		window.clear(sf::Color::White);

        sf::Time elapsed = stopwatch.getElapsedTime();

        int seconds = static_cast<int>(elapsed.asSeconds());
        
        std::string timeString = std::to_string(seconds);
        std::string counterString = std::to_string(g1.no_of_mines);
        stopwatchText.setString(timeString);
        counterText.setString(counterString);

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {

                    if (g1.grid_d[x_mouse][y_mouse] == 9) {
                        g1.grid_d[i][j] = g1.return_value(i, j);
                    }


                    if (g1.grid_d[i][j] == 10) {


                        cell.setPosition(i * Cell_size, (j * Cell_size) + w);

                        window.draw(cell);

                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    if(g1.grid_d[i][j] == 0) {
                        zero.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(zero);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
              
                    }

                    else if (g1.grid_d[i][j] == 1) {
                        one.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(one);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                    }

                    else if (g1.grid_d[i][j] == 2) {
                        two.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(two);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                    }

                    else if (g1.grid_d[i][j] == 3) {
                        three.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(three);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
               
                    }

                    else if (g1.grid_d[i][j] == 4) {
                        four.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(four);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                      
                    }

                    else if (g1.grid_d[i][j] == 5) {
                        five.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(five);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                      
                    }

                    else if (g1.grid_d[i][j] == 6) {
                        six.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(six);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                        
                    }

                    else if (g1.grid_d[i][j] == 7) {
                        seven.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(seven);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                        
                    }

                    else if (g1.grid_d[i][j] == 8) {
                        eight.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(eight);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                       
                    }

               
                    else if (g1.grid_d[i][j] == 9) {
                        mine.setPosition(i * Cell_size, (j* Cell_size) + w);
                        window.draw(mine);

                        frown.setPosition(114.f, 0.f);

                        g1.game_over = 1;
                        
                        window.draw(frown);

                        sf::Time final_time = stopwatch.getElapsedTime();

                        int endTime = int(final_time.asSeconds());

                        timeString = std::to_string(endTime);
                        
                        stopwatchText.setString(timeString);


                        window.draw(stopwatchText);

                        break;

                    }

                    else if (g1.grid_d[i][j] == 11) {
                        flag.setPosition(i * Cell_size, (j* Cell_size) + w);
                        window.draw(flag);

                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }




                }



            }

            counterText.setPosition(200.f, 19.f);

        window.draw(stopwatch_bg);
        window.draw(count_bg);


        
        if (g1.game_over == 0) {
            window.draw(stopwatchText);
            window.draw(counterText);
        }

        else {

            for (int i = 0; i < 9; i++) {

                for (int j = 0; j < 9; j++) {

                    if (g1.grid_d[x_mouse][y_mouse] == 9) {
                        g1.grid_d[i][j] = g1.return_value(i, j);
                    }


                    if (g1.grid_d[i][j] == 10) {


                        cell.setPosition(i * Cell_size, (j * Cell_size) + w);

                        window.draw(cell);

                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    if (g1.grid_d[i][j] == 0) {
                        zero.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(zero);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    else if (g1.grid_d[i][j] == 1) {
                        one.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(one);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                    }

                    else if (g1.grid_d[i][j] == 2) {
                        two.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(two);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);
                    }

                    else if (g1.grid_d[i][j] == 3) {
                        three.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(three);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    else if (g1.grid_d[i][j] == 4) {
                        four.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(four);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    else if (g1.grid_d[i][j] == 5) {
                        five.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(five);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    else if (g1.grid_d[i][j] == 6) {
                        six.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(six);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    else if (g1.grid_d[i][j] == 7) {
                        seven.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(seven);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }

                    else if (g1.grid_d[i][j] == 8) {
                        eight.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(eight);
                        smile.setPosition(114.f, 0.f);
                        window.draw(smile);

                    }


                    else if (g1.grid_d[i][j] == 9) {
                        mine.setPosition(i * Cell_size, (j * Cell_size) + w);
                        window.draw(mine);

                        frown.setPosition(114.f, 0.f);
                        window.draw(frown);

                    }




                }



            }



        }
		window.display();


       

		
	}



	return 0;
}