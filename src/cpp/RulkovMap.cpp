/**
 * @file RulkovMap.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Implementation file in c++ for the class of Rulkov-Map model class
 * @version 0.1
 * @date 2024-10-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/cpp/RulkovMap.h"

#include <cmath>

RulkovMap::RulkovMap(double time_increment, const char *filename, int elements_in_model, float initial_x, float o, float a, float B, float m) : Model(time_increment, filename, elements_in_model)
{
    this->x = initial_x;

    this->o = o;
    this->B = B;
    this->m = m;
    this->a = a;

    this->calculate_stationary_y();

    this->outfile << "x;y;o;time\n";
}

RulkovMap::RulkovMap(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y,  float o, float a, float B, float m) : Model(time_increment, filename, elements_in_model)
{
    this->x = initial_x;
    this->y = initial_y;

    this->o = o;
    this->B = B;
    this->m = m;
    this->a = a;


    this->outfile << "x;y;o;time\n";
}


RulkovMap::RulkovMap(double start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float o, float a, float B, float m) : Model(time_increment, filename, elements_in_model, start_time)
{
    this->x = initial_x;

    this->o = o;
    this->B = B;
    this->m = m;
    this->a = a;

    this->calculate_stationary_y();

    this->outfile << "x;y;o;time\n";
}

RulkovMap::RulkovMap(double start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y,  float o, float a, float B, float m) : Model(time_increment, filename, elements_in_model, start_time)
{
    this->x = initial_x;
    this->y = initial_y;

    this->o = o;
    this->B = B;
    this->m = m;
    this->a = a;


    this->outfile << "x;y;o;time\n";
}


void RulkovMap::calculate_stationary_y()
{
    y =  (-m*(x+1)+(m*o)) ;
}

void RulkovMap::calculate(int index)
{

    float aux_x, aux_y, aux_z;

    this->data[index*this->data_cols+0] = x;
    this->data[index*this->data_cols+1] = y;
    this->data[index*this->data_cols+2] = o;
    this->data[index*this->data_cols+3] = (float)this->time;

    if (x <= 0)
    {
        aux_x = (a / (1 - x)) + (y+B);
    }
    else if (x < (a + (y+B)))
    {
        aux_x = a + (y+B);
    }
    else
    {
        aux_x = -1;
    }
    // aux_x= (a/(1+x*x)) + y;

    aux_y =y  -m * (x + 1) + m * o;

    this->x = aux_x;
    this->y = aux_y;

    this->time = this->time + time_increment;

}
