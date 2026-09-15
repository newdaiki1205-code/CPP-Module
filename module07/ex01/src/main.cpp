/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:20:20 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/15 14:20:23 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>
#include <string>
#include <string>

void add(int &num)
{
  num += 1;
}

void show(const std::string &num)
{
  std::cout << num << std::endl;
}

int main(void)
{
    int arr_int[] = {0, 1, 2, 3, 4};
    const int arr_conint[] = {5, 6, 7, 8, 9};
    float arr_float[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f};
    const float arr_confloat[] = {5.6f, 6.7f, 7.8f, 8.9f, 9.8f};
    double arr_double[] = {0.01, 11.2, 22.3, 33.4, 44.5};
    const double arr_condouble[] = {55.6, 66.7, 77.8, 88.9, 99.0};

    iter(arr_int, 5, add);
    iter(arr_conint, 5, add);
    
    return 0;
}
