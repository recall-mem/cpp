#include <iostream>
#include <ncurses.h> 
#include <string.h>
#include <thread>


#define MAX_SCORE__EASY    10
#define MAX_SCORE__MEDIUM  15
#define MAX_SCORE__HARD    20

#define SLOW    350
#define MEDIUM  250
#define FAST    150


class SnakeGame
{
public:
    SnakeGame(char* diff)
    {
        if(!strcmp(diff, "hard")){
            max_score = MAX_SCORE__HARD;
            snake_speed = FAST;
        }
        else if(!strcmp(diff, "medium")){
            max_score = MAX_SCORE__MEDIUM;
            snake_speed = MEDIUM;
        }
        else if(!strcmp(diff, "easy")){
            max_score = MAX_SCORE__EASY;
            snake_speed = SLOW;
        }
        else {
            throw std::invalid_argument("Invalid difficulty");
        }

        initscr();

        noecho();    
        curs_set(0); 

        timeout(snake_speed); // wait for input 
        keypad(stdscr, FALSE);

        xyfurit = get_furit();
        xyhead = new int[2]{5,5};
        nxytail = new int[max_score][2];
        for (int i = 0; i < max_score; ++i)
            for (int j = 0; j < 2; ++j)
                nxytail[i][j] = -1;
    }

    ~SnakeGame() 
    {
    delete[] xyhead;
    delete[] xyfurit;
    delete[] nxytail;

    endwin(); // close window
    }

    void start()
    {
        while(true)
        {
            print_board();
            move_snake(); 
            if(xyhead[0]==xyfurit[0] && xyhead[1]==xyfurit[1]){
                ++score;
                delete[] xyfurit;
                xyfurit = get_furit();
            }
        
            if(score >= max_score) {
                mvprintw(h+4, 0, "\n/////YOU WIN/////\n");
                refresh();
                timeout(-1);
                printw("Press any key to exit");
                timeout(-1);
                getch();
                break;
            }
        }
    }

private:
    int score = 0;
    int max_score;
    int snake_speed;
    const int w=12, h=7;
    int* xyhead;        // xy -> [0] = x, [1] = y
    int (*nxytail)[2];  // nxy -> [n][0] = x, [n][1] = y
    int* xyfurit;       // xy -> [0] = x, [1] = y
    char direction = 'd';

    int *get_furit()
    {
        return new int[2]{(rand() % 12 + 1), (rand() % 7 + 1)};
    }

    void print_board()
    {
        // system("clear");
        clear();
        mvprintw(0, 0, "controls: wasd, score: %d", score);
        mvprintw(1, 0, "###############");

        for (int hi = 0; hi <= h; hi++)
        {
            mvprintw(hi + 2, 0, "#");

            for (int wi=0; wi<=w; wi++)
            {
                if(wi==xyhead[0] && hi==xyhead[1]) 
                {
                    mvaddch(hi + 2, wi + 1, '0');
                    continue;
                }
                else if(wi==xyfurit[0] && hi==xyfurit[1]) 
                {
                    mvaddch(hi + 2, wi + 1, 'F');
                    continue;
                }
                bool tail_found=false;
                for(int n=0; n<score;n++)
                {
                    if(wi==nxytail[n][0] && hi==nxytail[n][1])
                    {
                        mvaddch(hi + 2, wi + 1, 'o'); tail_found=true; break;
                    }
                }
                if(!tail_found)
                    mvaddch(hi + 2, wi + 1, '*');
            }//for windex

            mvprintw(hi + 2, w + 2, "#\n");
        }//for hindex

        mvprintw(h + 3, 0, "###############");
        refresh();
    }

    void move_snake()
    {
        char ch;
        
        // std::cout << "move(s): ";
        // std::cin >> ch;
        
        ch = getch();

        if(strchr("wsda", ch)!=nullptr)
            direction = ch;

        for(int n=score; n>=1; n--) {
            // it's just a prank bro... the prank:
            //**(nxytail+n) = **(nxytail+(n-1));  
            //*(nxytail+n)[1] = (*(nxytail+(n-1)))[1]; 
            nxytail[n][0] = nxytail[n - 1][0];
            nxytail[n][1] = nxytail[n - 1][1];
        }
        **nxytail = xyhead[0];
        (*nxytail)[1] = xyhead[1];

        switch(direction)
        {
            case 'w': 
                if(--xyhead[1]<0){xyhead[1]=h;}
                break;
            case 's':
                if(++xyhead[1]>h){xyhead[1]=0;} 
                break;
            case 'd': 
                if(++xyhead[0]>w){xyhead[0]=0;}
                break;
            case 'a':  
                if(--xyhead[0]<0){xyhead[0]=w;}
                break;
        }
    }
};

int main(int argc, char* argv[])
{
    if(argc != 2) {
        std::cerr << "How to start: SnakeGame <difficulty>\n";
        return 1;
    }

    try{

        SnakeGame g(argv[1]);
        
        g.start();
    }
    catch(const std::exception& ex){
        
        std::cerr << ex.what() << '\n';
    }


    return 0;
}
