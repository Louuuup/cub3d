/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:17 by adube             #+#    #+#             */
/*   Updated: 2025/01/14 13:50:22 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the idea is to check at every side of a wall the ray will encounter. We give each
//square width 1, so each side of a wall is an integer value and the places in between
//have a value after the point. Now the step size isn't constant, it depends on the
//distance to the next side. 

// USE DDA: Digital Differential Analysis

//note to fix fisheye effect: correct the distance by reducing it according to
//the given ray's angle delta. Rays that go away from the camera center will result
//in a bigger distance so you will need the delta (i.e. the angle difference between
//the most central ray (FOV/2) and the given ray that you're trying to perform correction to).

// posX et posY doit etre la position de depart du player!
// initial direction vector TO CHANGE FROM n, s , e ,w 

// if (direction = N) dirX = 0 et dirY = -1;
// if (direction = S) dirX = 0 et dirY = 1;
// if (direction = E) dirX = 1 et dirY = 0;
// if (direction = W) dirX = -1 et dirY = 0;

#include "cub3d.h"

//needs to init to these values
double planeX = 0;
double planeY = 0.66; //the 2d raycaster version of camera plane PLANE_Y is FOV 0.66 = 66 degres

// double time = 0; time of current frame
// double oldTime = 0; time of previous frame

void	raycasting()
{
	double	deltaDistX;
    double	deltaDistY;
	double	cameraX;
	double	cameraY;
	double	rayDirX;
	double	rayDirY;
    double	dirX;
	double	dirY;
	int		playerX;
	int		playerY;
	int		mapX;
	int		mapY;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = playerX; //change from pixel pos, playerX, to square pos mapX
		int mapY = playerY; // change from pixel pos, playerY, to square pos mapY
		//use m_co.x / m_co.y and co.x / co.y /// how to find which box were in??
		if (rayDirX == 0)
        	deltaDistX = 1e30;
      	else
        	deltaDistX = abs(1 / rayDirX);
      	if (rayDirY == 0)
        	deltaDistY = 1e30;
      	else
        	deltaDistY = abs(1 / rayDirY);
		x++;
	}
}

//	calculate step and initial sideDist
  double  get_sideDist(double rayDirX, double rayDirY, double deltaDistX, double deltaDistY, int posX, int posY, int mapX, int mapY)
  {
    //put the step and dist infos in the struct not declared in the function like here
	//what direction to step in x or y-direction (either +1 or -1)
    int stepX;
    int stepY;
    double sideDistX;
    double sideDistY;

      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
  }

int	DDA_algo(int stepX, int stepY, int mapX, int mapY, double sideDistX, double sideDistY, int hit, double deltaDistX, double deltaDistY)
{
	int side;
	//side was a NS or a EW wall hit? (x or y is used)

	//hit could be a bool. it has to be in struct

	while(hit == 0)
	{
    	//prochain carre de la grille direction x ou y
    	if(sideDistX < sideDistY)
    	{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
        }
        else
        {
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
        }
	//Check if ray has hit a wall - double check if checkup is good (if the square is a 1 = wall = hit)
	//how gets pixels pos to square to check the hit, aka get accurate mapX and mapY
	//        if(data->map->map[mapY][mapX] > 0)
	//			hit = 1;
    }
	return (side);
}

double get_perpWallDist(double sideDistX, double sideDistY, double deltaDistX, double deltaDistY, int side)
{
  double perpWallDist;
  
  if(side == 0) 
    perpWallDist = (sideDistX - deltaDistX);
  else          
    perpWallDist = (sideDistY - deltaDistY);
  return (perpWallDist);
}

int get_lineInfo(double perpWallDist)
{
	//change so it doesnt return int but the line Info struct
	int	lineHeight;
	int	drawStart;
	int	drawEnd;

	lineHeight = (int)(HEIGHT/ perpWallDist);
	// calculate lowest and highest pixel to fill in current stripe
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if(drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	return (0);
//  return (drawStart and drawEnd and lineHeight in a small struct), then draw frame from what we got;
}

  //after getting lineInfo draw the pixels of the stripe as a vertical line with pos of drawstart and drawEnd + color chosen
  //add right mlx function here

  
  //   //timing for input and FPS counter
  //   oldTime = time;
  //   time = getTicks();
  //   double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
  //   print(1.0 / frameTime); //FPS counter
 
  //   //speed modifiers
  //   double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
  //   double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

  //   rotate to the right
  //   if //pressing right arrow
  //   {
  //     //both camera direction and camera plane must be rotated
  //     double oldDirX = dirX;
  //     dirX = oldDirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
  //     dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
  //     double oldPlaneX = planeX;
  //     planeX = oldPlaneX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
  //     planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
  //   }
  //   rotate to the left
  //   if pressing left arrow
  //   {
  //     both camera direction and camera plane must be rotated
  //     double oldDirX = dirX;
  //     dirX = oldDirX * cos(rotSpeed) - dirY * sin(rotSpeed);
  //     dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
  //     double oldPlaneX = planeX;
  //     planeX = oldPlaneX * cos(rotSpeed) - planeY * sin(rotSpeed);
  //     planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
  //   }