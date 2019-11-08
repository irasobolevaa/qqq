#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;



class classBall
{
    public:
        float x;
        float y;
        float r;
        float vx;
        float vy;
        float R;
        float G;
        float B;
        const float dt=0.1;
};

void drawBall(classBall Ball, RenderWindow* window)
{
    
    for(float i=Ball.r; Ball.r>0; Ball.r--)
    {

        float R1=Ball.R-(Ball.R*Ball.r/i); 
        float G1=Ball.G-(Ball.G*Ball.r/i);
        float B1=Ball.B-(Ball.B*Ball.r/i);


        CircleShape okruzhnost(100);
        okruzhnost.setRadius(i);
        okruzhnost.setFillColor(Color(R1,G1,B1));
        okruzhnost.setPosition(Ball.x, Ball.y);
        window->draw(okruzhnost); //Рисует шар//
        window->display(); ///Выводит его на экран/
        window->clear(); ///Чистит экран от изображения предыдущего положения шара/


    }
}


void crashBall(classBall *BallFirst, classBall *BallSecond)
    {
        if (sqrt(((*BallFirst).x - (*BallSecond).x)*((*BallFirst).x - (*BallSecond).x)+((*BallFirst).y - (*BallSecond).y)*((*BallFirst).y - (*BallSecond).y)) < 2*(*BallFirst).r)
            {
                (*BallFirst).vx= -((*BallFirst).vx);
                (*BallFirst).vy= -((*BallFirst).vy);
                (*BallSecond).vx= -((*BallSecond).vx);
                (*BallSecond).vy= -((*BallSecond).vy);

            }

    }

void moveBall(classBall *Ball)

    {
        (*Ball).x += (*Ball).vx * (*Ball).dt;
        (*Ball).y += (*Ball).vy * (*Ball).dt;
        if((*Ball).y>500 || (*Ball).y< 100)
            (*Ball).vy = -(*Ball).vy;
        if((*Ball).x>700 ||(*Ball).x<100)
            (*Ball).vx=-(*Ball).vx;
    }


int main()
{   
    srand(time(NULL));

    

    classBall Ball1;
        Ball1.x = 300;
        Ball1.y = 300;
        Ball1.vx = 30;
        Ball1.vy = 30;
        Ball1.r = 50;
        Ball1.R = 245;
        Ball1.G = 192;
        Ball1.B = 203;
        
    classBall Ball2;
        Ball2.x = 400;
        Ball2.y = 400;
        Ball2.vx = 10;
        Ball2.vy = 40;
        Ball2.r = 50;
        Ball2.R = 245;
        Ball2.G = 192;
        Ball2.B = 203;  
    
        RenderWindow window(VideoMode(800, 600), "SFML Works!");
            for(;;)
            {
                
                drawBall(Ball1, &window);
                drawBall(Ball2, &window);
                moveBall(&Ball1);
                moveBall(&Ball2);
                crashBall(&Ball1, &Ball2);
            }    
    CircleShape okruzhnost(100);
    window.clear(Color::White);
    window.display();
        
    while (window.isOpen())
    {   
        
        
        Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == Event::Closed)
                window.close();
        } 

        window.clear(Color::White);
        window.display();
  
    }

    return 0;
}

