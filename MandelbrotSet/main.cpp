#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Complex.h"
#include <iostream>
#include <array>
#include <memory>

const int WHEIGHT = 480;
const int WWIDTH = 640;
//const int MAXITER = 100;
int color_no;

int main()
{
	int MAXITER = 1;
	int MAXMAXITER = 100;
	sf::RenderWindow window(sf::VideoMode(WWIDTH, WHEIGHT), "Mandelbrot Set");
	sf::Texture texture;
	sf::Image image;
	sf::Sprite sprite;
	image.create(WWIDTH, WHEIGHT, sf::Color::White);
	
	Complex min(-2.0, -1.2);
	Complex max(1.0, 1.05);

	float Re_factor = (max.real - min.real)/(WWIDTH-1);
	float Im_factor = (max.imag - min.imag)/(WHEIGHT-1);
/*
	for(unsigned y=0; y<WHEIGHT; ++y)
	{
		color_no = -1;
		float c_im = min.imag + y*Im_factor;

		for(unsigned x=0; x<WWIDTH; ++x)
		{
			color_no = -1;
			float c_re = min.real + x*Re_factor;

			Complex c(c_re, c_im);
			Complex c_const(c_re, c_im);
			bool isInside = true;

			for(unsigned n=0; n<MAXITER; ++n)
			{
				if(c.abs_squared() > 4.0) //if the absolute value of the complex number is greater than 2, then it escapes to infinity, and is not part of set
				{
					//Complex number is not part of the set
					//or, it is outside the black inside area
					color_no = n; //save the number of iterations it took to reach this point(infinity)
					isInside = false;
					break;
				}
				//z = z^2 + c
				Complex c2 = c.cube();
				c = c2.add(c_const);
			}

			if(isInside == true)
			{
				//Color pixels belonging to set black
				image.setPixel(x, y, sf::Color::Black);
			} 
			if(color_no >= 0 && color_no < MAXITER/2-1)
			{
				image.setPixel(x, y, sf::Color((5*color_no)%255, 0, 0));
			} else if (color_no >= MAXITER/2 && color_no < MAXITER)
			{
				image.setPixel(x, y, sf::Color((color_no)%255, (color_no)%255, (color_no)%255));
			}
		}
	}
*/
	while(window.isOpen())
	{
		//Check events on window
		sf::Event evt;
		window.pollEvent(evt);
		window.setFramerateLimit(20);

		if((evt.type == sf::Event::Closed) || 
		   (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape))
		{
			window.close();
		} 


		for(unsigned y=0; y<WHEIGHT; ++y)
		{
			color_no = -1;
			float c_im = min.imag + y*Im_factor;

			for(unsigned x=0; x<WWIDTH; ++x)
			{
				color_no = -1;
				float c_re = min.real + x*Re_factor;
	
				Complex c(c_re, c_im);
				Complex c_const(c_re, c_im);
				bool isInside = true;
	
				for(unsigned n=0; n<MAXITER; ++n)
				{
					if(c.abs_squared() > 4.0) //if the absolute value of the complex number is greater than 2, then it escapes to infinity, and is not part of set
					{
						//Complex number is not part of the set
						//or, it is outside the black inside area
						color_no = n; //save the number of iterations it took to reach this point(infinity)
						isInside = false;
						break;
					}
					//z = z^2 + c
					Complex c2 = c.square();
					//z = z^3 + c
					//Complex c2 = c.cube();
					c = c2.add(c_const);
				}
	
				if(isInside == true)
				{
					//Color pixels belonging to set black
					image.setPixel(x, y, sf::Color::Black);
				} 
				if(color_no >= 0 && color_no < MAXITER/2-1)
				{
					image.setPixel(x, y, sf::Color((5*color_no)%255, 0, 0));
				} else if (color_no >= MAXITER/2 && color_no < MAXITER)
				{
					image.setPixel(x, y, sf::Color((color_no)%255, (color_no)%255, (color_no)%255));
				}
			}
		}
		//if(MAXITER <= MAXMAXITER)
			MAXITER++;
		//else
		//	MAXITER = MAXMAXITER;


		texture.loadFromImage(image);
		sprite.setTexture(texture);

		window.clear(sf::Color(255,255,255));
		window.draw(sprite);
		window.display();
	}

    return 0;
}
